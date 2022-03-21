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
    : QObject(parent),
      m_watching(false) {

}

// NOTE: We can suppose that the `url` argument will be always a path to folder
void Paths::watch(const QString &url) {
    const auto clean = clean_path(url);

    if (m_pathModel.contains(clean.path)) {
        qCWarning(paths) << clean.path << "is already watched";

        return;
    }

    auto folderChanges = std::unique_ptr<FolderChanges>(new FolderChanges(clean.path));

    connect(folderChanges.get(), &FolderChanges::newChange,
            this, &Paths::handleChange);

    m_pathModel.insert(clean.path);

    m_folderChanges.push_back(std::move(folderChanges));

    qCInfo(paths) << "Watching" << clean.path;
}

void Paths::unwatch(const QString &url) {
    const auto clean = clean_path(url);

    const auto it = std::find_if(m_folderChanges.begin(), m_folderChanges.end(), [path=clean.path](std::unique_ptr<FolderChanges> &watcher) {
        return (*watcher).path() == path;
    });

    if (it != m_folderChanges.end()) {
        m_folderChanges.erase(it);

        qCInfo(paths) << "Removed folder";
    }

    m_pathModel.remove(clean.path);

    qCInfo(paths) << "Unwatching" << clean.path;
}

QObject* Paths::watched() {
    return &m_pathModel;
}

void Paths::handleChange(const EventModel::EventModelItem &event) {
    if (not m_watching) {
        // NOTE: Block all events
        return;
    }

    qCInfo(paths) << "new event";

    m_eventModel.insert(event);
}

QObject* Paths::events() {
    return &m_eventModel;
}

bool Paths::watching() {
    return m_watching;
}

void Paths::setWatching(const bool newWatching) {
    if (m_watching == newWatching) {
        return;
    }

    m_watching = newWatching;
    emit watchingChanged(m_watching);
}


