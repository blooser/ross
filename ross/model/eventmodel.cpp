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
            return item.m_event;
        case Column::Path:
            return item.m_path;
        case Column::Folder:
            return item.m_folder;
        case Column::DateTime:
            return item.m_dateTime;
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

void EventModel::clear() {
    if (not rowCount()) {
        qCWarning(eventModel) << "Nothing to clear";

        return;
    }

    beginResetModel();
    m_events.clear();
    endResetModel();

    qCInfo(eventModel) << "Model has been cleared";
}

