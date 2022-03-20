#include "pathwatcher.h"

#include <QDir>
#include <QFileInfo>

Q_LOGGING_CATEGORY(folderChanges, "folder.changes")


FolderChanges::FolderChanges(const QString &path, QObject *parent)
    : QObject(parent),
      m_path(path),
      m_files(QDir(m_path).entryInfoList(QDir::Files)) {

    connect(&m_watcher, &QFileSystemWatcher::directoryChanged,
            this, &FolderChanges::scanDirectory);

    if (not m_watcher.addPath(m_path)) {
        qCWarning(folderChanges) << "Failed to watch" << m_path;
    }
}

const QString FolderChanges::path() {
    return m_path;
}

void FolderChanges::scanDirectory(const QString &path) {
    const auto files = QDir(path).entryInfoList(QDir::Files);

    scanCreated(files);
    scanDeleted(files);
    scanEdited(files);
}

void FolderChanges::scanCreated(QList<QFileInfo> files) {
    for (const auto &file : qAsConst(files)) {
        if (!m_files.contains(file)) {
            emit newEvent(EventModel::EventModelItem::Created(file.absoluteFilePath(), file.isDir()));

            m_files.append(file);
        }
    }
}

void FolderChanges::scanDeleted(QList<QFileInfo> files) {
    for (const auto &file : qAsConst(m_files)) {
        if (!files.contains(file)) {
            emit newEvent(EventModel::EventModelItem::Deleted(file.absoluteFilePath(), file.isDir()));

            m_files.removeOne(file);
        }
    }
}

void FolderChanges::scanEdited(QList<QFileInfo> files) {
    for (const auto &file : qAsConst(m_files)) {
        const int index = files.indexOf(file);

        if (index >= 0) {
            const auto target_file = files.at(index);

            if (file.size() != target_file.size()) {
                emit newEvent(EventModel::EventModelItem::Edited(file.absoluteFilePath(), file.isDir()));
            }
        }
    }
}
