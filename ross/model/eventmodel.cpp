#include "eventmodel.h"

const QHash<int, QByteArray> EventModel::ROLE_NAMES = {
    { Column::Event, QByteArrayLiteral("event") },
    { Column::Path, QByteArrayLiteral("path") },
    { Column::Folder, QByteArrayLiteral("folder") },
    { Column::DateTime, QByteArrayLiteral("datetime") },
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
        default:
            return QVariant();

    }

    return QVariant();
}

