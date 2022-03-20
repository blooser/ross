#include "paths.h"

#include <QUrl>

#include <QLoggingCategory>

Q_LOGGING_CATEGORY(paths, "paths");

Paths::Paths(QObject *parent)
    : QObject(parent) {

}

void Paths::watch(const QString &url) {
    qCInfo(paths) << "Watching: " << url;

    m_pathModel.insert(url);

    emit watchingChanged(&m_pathModel);
}

void Paths::unwatch(const QString &url) {
    qCInfo(paths) << "Unwatching: " << url;
}

QObject* Paths::watching() {
    return &m_pathModel;
}


