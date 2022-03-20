#ifndef PATHWATCHER_H
#define PATHWATCHER_H

#include "model/eventmodel.h"

#include <QObject>
#include <QFileSystemWatcher>
#include <QFileInfo>
#include <QDateTime>

#include <QLoggingCategory>
Q_DECLARE_LOGGING_CATEGORY(folderChanges)


class FolderChanges : public QObject {
    Q_OBJECT

public:
    FolderChanges(const QString &path, QObject *parent=nullptr);

    const QString path();

signals:
    void newEvent(const EventModel::EventModelItem&);

private slots:
    void scanDirectory(const QString &path);

protected:
    void scanCreated(QList<QFileInfo> files);
    void scanDeleted(QList<QFileInfo> files);
    void scanEdited(QList<QFileInfo> files);

private:
    QString m_path;
    QList<QFileInfo> m_files;
    QFileSystemWatcher m_watcher;



};

#endif // PATHWATCHER_H
