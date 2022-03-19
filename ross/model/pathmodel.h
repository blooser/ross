#ifndef PATHMODEL_H
#define PATHMODEL_H

#include <QAbstractListModel>
#include <QStringList>

#include <QLoggingCategory>
Q_DECLARE_LOGGING_CATEGORY(pathModel)

class PathModel : public QAbstractListModel {
    Q_OBJECT

public:
    PathModel(QObject *parent=nullptr);

    QHash<int, QByteArray> roleNames() const override;

    QVariant data(const QModelIndex &index, int role) const override;
    int rowCount(const QModelIndex &index=QModelIndex()) const override;

    void insert(const QString &path);

private:
    QStringList m_paths;
};

#endif // PATHMODEL_H
