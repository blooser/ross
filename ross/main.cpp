#include <QApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>


int main(int argc, char *argv[]) {
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);

    QApplication app(argc, argv);

    app.setApplicationName(QString("%1: %2").arg(PROJECT_NAME, PROJECT_DESC));
    app.setApplicationVersion(VERSION);
    app.setOrganizationName(ORGANIZATION_NAME);
    app.setOrganizationDomain(ORGANIZATION_DOMAIN);

    QQmlApplicationEngine engine;

    const QUrl url(QStringLiteral("qrc:///main.qml"));
    QObject::connect(&engine, &QQmlApplicationEngine::objectCreated,
                     &app, [url](QObject *obj, const QUrl &objUrl) {
                        if (!obj and url == objUrl) {
                            QCoreApplication::exit(-1);
                        }
                     }, Qt::QueuedConnection);

    engine.load(url);

    return app.exec();
}
