#include "paths.h"

#include <QUrl>

#include <QLoggingCategory>

Q_LOGGING_CATEGORY(paths, "paths");

Paths::Paths(QObject *parent)
    : QObject(parent) {

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
        qCWarning(paths) << "Failed to watch: " << url;

        return;
    }

    m_pathModel.insert(clean.path);

    emit watchingChanged(&m_pathModel);

    qCInfo(paths) << "Watching: " << url;
}

void Paths::unwatch(const QString &url) {
    const auto clean = clean_path(url);

    if (!m_watcher.removePath(clean.path)) {
        qCWarning(paths) << "Failed to unwatch: " << url;

        return;
    }

     qCInfo(paths) << "Unwatching: " << url;
}

QObject* Paths::watching() {
    return &m_pathModel;
}


