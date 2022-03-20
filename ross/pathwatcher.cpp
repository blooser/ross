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
}

void FolderChanges::scanCreated(QList<QFileInfo> files) {
    for (const auto &file : qAsConst(files)) {
        if (!m_files.contains(file)) {
            emit newEvent(EventModel::EventModelItem("Created", file.absoluteFilePath(), false));

            m_files.append(file);
        }
    }
}

void FolderChanges::scanDeleted(QList<QFileInfo> files) {
    for (const auto &file : qAsConst(m_files)) {
        if (!files.contains(file)) {
            emit newEvent(EventModel::EventModelItem("Deleted", file.absoluteFilePath(), false));

            m_files.removeOne(file);
        }
    }
}






