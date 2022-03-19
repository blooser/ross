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

int EventModel::columnCount(QModelIndex &index) const {
    return static_cast<int>(Column::Last - Column::Event);
}

