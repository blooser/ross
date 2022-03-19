#ifndef EVENTMODEL_H
#define EVENTMODEL_H

#include <QAbstractTableModel>


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
    int columnCount(QModelIndex &index) const;
   // QVariant data(const QModelIndex &index, int role) const override;

private:
    static const QHash<int, QByteArray> ROLE_NAMES;
};

#endif // EVENTMODEL_H
