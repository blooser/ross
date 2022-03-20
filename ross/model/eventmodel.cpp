#include "eventmodel.h"

Q_LOGGING_CATEGORY(eventModel, "event.model")

const QHash<int, QByteArray> EventModel::ROLE_NAMES = {
    { Column::Event, QByteArrayLiteral("event") },
    { Column::Path, QByteArrayLiteral("path") },
    { Column::Folder, QByteArrayLiteral("folder") },
    { Column::DateTime, QByteArrayLiteral("datetime") },
    { Qt::DisplayRole, QByteArrayLiteral("display") }
};

EventModel::EventModel(QObject *parent)
    : QAbstractTableModel(parent) {

}

QHash<int, QByteArray> EventModel::roleNames() const {
    return ROLE_NAMES;
}

int EventModel::columnCount(const QModelIndex &index) const {
    return static_cast<int>(Column::Last - Column::Event);
}

int EventModel::rowCount(const QModelIndex &index) const {
    return m_events.size();
}

QVariant EventModel::data(const QModelIndex &index, int role) const {
    if (not index.isValid()) {
        return QVariant();
    }

    const auto row = index.row();
    auto item = m_events.at(row);

    switch (role) {
        case Column::Event:
            return item.event;
        case Column::Path:
            return item.path;
        case Column::Folder:
            return item.folder;
        case Column::DateTime:
            return item.dateTime;
        case Qt::DisplayRole:
            return item[Qt::UserRole + 1 + index.column()];
        default:
            return QVariant();

    }

    return QVariant();
}

void EventModel::insert(const EventModelItem &item) {
    beginInsertRows(QModelIndex(), rowCount(), rowCount());
    m_events.append(item);
    endInsertRows();

    qCInfo(eventModel) << "Inserted event -" << "events:" << rowCount();
}

