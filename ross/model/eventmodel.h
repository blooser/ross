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

    class EventModelItem {
        public:
            EventModelItem(const QString event,
                           const QString path,
                           bool folder,
                           const QDateTime dateTime = QDateTime::currentDateTime())
                : m_event(event),
                  m_path(path),
                  m_folder(folder),
                  m_dateTime(dateTime) {
            }

            static EventModelItem Created(const QString path, bool folder);
            static EventModelItem Deleted(const QString path, bool folder);
            static EventModelItem Edited(const QString path, bool folder);

            QVariant operator[](const int role) {
                switch (static_cast<Column>(role)) {
                    case Column::Event:
                        return m_event;
                    case Column::Path:
                        return m_path;
                    case Column::Folder:
                        return m_folder;
                    case Column::DateTime:
                        return m_dateTime.toString("dd/MM/yyyy HH:mm");
                    default:
                        return QVariant();
                }

                return QVariant();
            };

            friend class EventModel;

        private:
            QString m_event;
            QString m_path;
            bool m_folder;
            QDateTime m_dateTime;
    };


    EventModel(QObject *parent=nullptr);

    QHash<int, QByteArray> roleNames() const override;
    int columnCount(const QModelIndex &index=QModelIndex()) const override;
    int rowCount(const QModelIndex &index=QModelIndex()) const override;
    QVariant data(const QModelIndex &index, int role) const override;

    void insert(const EventModelItem &);

    Q_INVOKABLE void clear();

private:
    static const QHash<int, QByteArray> ROLE_NAMES;

    QList<EventModelItem> m_events;
};

#endif // EVENTMODEL_H
