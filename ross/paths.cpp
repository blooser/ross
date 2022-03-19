#include "paths.h"

#include <QUrl>

#include <QLoggingCategory>

Q_LOGGING_CATEGORY(paths, "paths");

Paths::Paths(QObject *parent)
    : QObject(parent) {

}

void Paths::watch(const QUrl &url) {
    qCInfo(paths) << "Watching: " << url;

    m_pathModel.insert(url.path());

    emit watchingChanged(&m_pathModel);
}

QObject* Paths::watching() {
    return &m_pathModel;
}


