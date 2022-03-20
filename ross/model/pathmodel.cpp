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

    qCInfo(pathModel) << "Inserted path -" << "paths:" << rowCount();
}

void PathModel::remove(const QString &path) {
    const int row = m_paths.indexOf(path);

    if (row == -1) {
        qCWarning(pathModel) << "Failed to find row of" << path;

        return;
    }

    beginRemoveRows(QModelIndex(), row, row);
    m_paths.removeAt(row);
    endRemoveRows();

    qCInfo(pathModel) << "Removed path -" << "paths:" << rowCount();
}

bool PathModel::contains(const QString &path) {
    return m_paths.contains(path);
}
