#ifndef PATHS_H
#define PATHS_H

#include <QObject>
#include <QFileSystemWatcher>

#include "model/pathmodel.h"
#include "model/eventmodel.h"

#include <QLoggingCategory>
Q_DECLARE_LOGGING_CATEGORY(paths)


class Paths : public QObject {
    Q_OBJECT
    Q_PROPERTY(QObject* watching READ watching NOTIFY watchingChanged)
    Q_PROPERTY(QObject* events READ events NOTIFY eventsChanged)

public:
    Paths(QObject *parent=nullptr);

    QObject* watching();
    QObject* events();

    Q_INVOKABLE void watch(const QString &url);
    Q_INVOKABLE void unwatch(const QString& url);

signals:
    void watchingChanged(QObject*);
    void eventsChanged(QObject*);

private slots:
    void handleFileChanged(const QString& path);

private:
    PathModel m_pathModel;
    EventModel m_eventModel;

    QFileSystemWatcher m_watcher;

};

#endif // PATHS_H
