#include "pathmodel.h"

Q_LOGGING_CATEGORY(pathModel, "path.model")

PathModel::PathModel(QObject *parent)
    : QAbstractListModel(parent) {

}

QHash<int, QByteArray> PathModel::roleNames() const {
    return QHash<int, QByteArray> {
        { Qt::DisplayRole, QByteArrayLiteral("watchedPath") }
    };
}

QVariant PathModel::data(const QModelIndex &index, int) const {
    return m_paths.at(index.row());
}

int PathModel::rowCount(const QModelIndex &index) const {
    return m_paths.size();
}

void PathModel::insert(const QString &path) {
    beginInsertRows(QModelIndex(), rowCount(), rowCount());
    m_paths.append(path);
    endInsertRows();

    qCInfo(pathModel) << "Inserted:" << path << "Size: " << rowCount();
}
