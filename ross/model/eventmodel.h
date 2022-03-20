#ifndef EVENTMODEL_H
#define EVENTMODEL_H

#include <QAbstractTableModel>
#include <QDateTime>
#include <QList>

#include <QLoggingCategory>
Q_DECLARE_LOGGING_CATEGORY(eventModel)

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

    struct EventModelItem {
        QString event;
        QString path;
        bool folder;
        QDateTime dateTime;

        QVariant operator[](const int role) {
            switch (static_cast<Column>(role)) {
                case Column::Event:
                    return event;
                case Column::Path:
                    return path;
                case Column::Folder:
                    return folder;
                case Column::DateTime:
                    return dateTime;
                default:
                    return QVariant();
            }

            return QVariant();
        };
    };


    EventModel(QObject *parent=nullptr);

    QHash<int, QByteArray> roleNames() const override;
    int columnCount(const QModelIndex &index=QModelIndex()) const override;
    int rowCount(const QModelIndex &index=QModelIndex()) const override;
    QVariant data(const QModelIndex &index, int role) const override;

    void insert(const EventModelItem &);

private:
    static const QHash<int, QByteArray> ROLE_NAMES;

    QList<EventModelItem> m_events;
};

#endif // EVENTMODEL_H
