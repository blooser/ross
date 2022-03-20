#include "paths.h"

#include <QUrl>

#include <QLoggingCategory>

Q_LOGGING_CATEGORY(paths, "paths");


struct clean_path {
    clean_path(const QString &url) : path(url) {
        path = path.replace("file:///", "");
    }

    QString path;
};


Paths::Paths(QObject *parent)
    : QObject(parent) {

}

// NOTE: We can suppose that the `url` argument will be always a path to folder
void Paths::watch(const QString &url) {
    const auto clean = clean_path(url);

    if (m_pathModel.contains(clean.path)) {
        qCWarning(paths) << clean.path << "is readly watched";

        return;
    }

    auto pathWatcher = std::unique_ptr<FolderChanges>(new FolderChanges(clean.path));

    connect(pathWatcher.get(), &FolderChanges::newEvent,
            this, &Paths::handleEvent);

    m_pathModel.insert(clean.path);

    m_watchers.push_back(std::move(pathWatcher));

    qCInfo(paths) << "Watching" << clean.path;
}

void Paths::unwatch(const QString &url) {
    const auto clean = clean_path(url);

    const auto it = std::find_if(m_watchers.begin(), m_watchers.end(), [path=clean.path](std::unique_ptr<FolderChanges> &watcher) {
        return (*watcher).path() == path;
    });

    if (it != m_watchers.end()) {
        m_watchers.erase(it);

        qCInfo(paths) << "Removed watcher";
    }

    m_pathModel.remove(clean.path);

    qCInfo(paths) << "Unwatching" << clean.path;
}

QObject* Paths::watching() {
    return &m_pathModel;
}

void Paths::handleEvent(const EventModel::EventModelItem &event) {
    qCInfo(paths) << "new event";

    m_eventModel.insert(event);
}

QObject* Paths::events() {
    return &m_eventModel;
}


