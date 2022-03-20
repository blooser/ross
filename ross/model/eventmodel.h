#ifndef EVENTMODEL_H
#define EVENTMODEL_H

#include <QAbstractTableModel>
#include <QDateTime>
#include <QList>

struct EventModelItem {
    QString event;
    QString path;
    bool folder;
    QDateTime dateTime;
};

class EventModel : public QAbstractTableModel {
    Q_OBJECT

public:
    enum Column {
        Event = Qt::UserRole + 1,
        Path,
        Folder,
        DateTime,

        Last
    };

    EventModel(QObject *parent=nullptr);

    QHash<int, QByteArray> roleNames() const override;
    int columnCount(const QModelIndex &index) const override;
    int rowCount(const QModelIndex &index) const override;
    QVariant data(const QModelIndex &index, int role) const override;

private:
    static const QHash<int, QByteArray> ROLE_NAMES;

    QList<EventModelItem> m_events;
};

#endif // EVENTMODEL_H
