#ifndef PATHS_H
#define PATHS_H

#include <memory>

#include <QObject>
#include <QFileSystemWatcher>

#include "model/pathmodel.h"
#include "model/eventmodel.h"

#include "pathwatcher.h"

#include <QLoggingCategory>
Q_DECLARE_LOGGING_CATEGORY(paths)


class Paths : public QObject {
    Q_OBJECT
    Q_PROPERTY(QObject* watched READ watched NOTIFY watchedChanged)
    Q_PROPERTY(QObject* events READ events NOTIFY eventsChanged)
    Q_PROPERTY(bool watching READ watching WRITE setWatching NOTIFY watchingChanged)


public:
    Paths(QObject *parent=nullptr);

    QObject* watched();
    QObject* events();

    bool watching();
    void setWatching(const bool);

    Q_INVOKABLE void watch(const QString &url);
    Q_INVOKABLE void unwatch(const QString& url);

signals:
    void watchedChanged(QObject*);
    void eventsChanged(QObject*);
    void watchingChanged(bool);

private slots:
    void handleEvent(const EventModel::EventModelItem&);

private:
    PathModel m_pathModel;
    EventModel m_eventModel;
    bool m_watching;

    std::vector<std::unique_ptr<FolderChanges>> m_watchers;
};

#endif // PATHS_H
