#ifndef PATHS_H
#define PATHS_H

#include <QObject>

#include "model/pathmodel.h"

#include <QLoggingCategory>
Q_DECLARE_LOGGING_CATEGORY(paths)


class Paths : public QObject {
    Q_OBJECT
    Q_PROPERTY(QObject* watching READ watching NOTIFY watchingChanged)
public:
    Paths(QObject *parent=nullptr);

    QObject* watching();

    Q_INVOKABLE void watch(const QString &url);
    Q_INVOKABLE void unwatch(const QString& url);

signals:
    void watchingChanged(QObject*);

private:
    PathModel m_pathModel;
};

#endif // PATHS_H
