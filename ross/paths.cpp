#include "paths.h"

#include <QUrl>

#include <QLoggingCategory>

Q_LOGGING_CATEGORY(paths, "paths");

Paths::Paths(QObject *parent)
    : QObject(parent) {

    connect(&m_watcher, &QFileSystemWatcher::directoryChanged,
            this, &Paths::handleFileChanged);
}

struct clean_path {
    clean_path(const QString &url) : path(url) {
        path = path.replace("file:///", "");
    }

    QString path;
};

void Paths::watch(const QString &url) {
    const auto clean = clean_path(url);

    if (!m_watcher.addPath(clean.path)) {
        qCWarning(paths) << "Failed to watch: " << clean.path;

        return;
    }

    m_pathModel.insert(clean.path);

    emit watchingChanged(&m_pathModel);

    qCInfo(paths) << "Watching: " << clean.path;
}

void Paths::unwatch(const QString &url) {
    const auto clean = clean_path(url);

    if (!m_watcher.removePath(clean.path)) {
        qCWarning(paths) << "Failed to unwatch: " << url;

        return;
    }

    m_pathModel.remove(clean.path);

    qCInfo(paths) << "Unwatching: " << clean.path;
}

QObject* Paths::watching() {
    return &m_pathModel;
}

void Paths::handleFileChanged(const QString &path) {
    qCInfo(paths) << path << "changed";

    m_eventModel.insert(EventModel::EventModelItem{
                            "created",
                            path,
                            true,
                            QDateTime::currentDateTime()
                        });
}

QObject* Paths::events() {
    return &m_eventModel;
}


