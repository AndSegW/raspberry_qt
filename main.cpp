#include <QGuiApplication>
#include <QQmlApplicationEngine>

int main(int argc, char *argv[])
{
    // Forza Qt a usare Wayland
    qputenv("QT_QPA_PLATFORM", QByteArray("wayland"));

    // UTF-8
    qputenv("LC_ALL", QByteArray("en_US.UTF-8"));
    qputenv("LANG", QByteArray("en_US.UTF-8"));

    QGuiApplication app(argc, argv);

    QQmlApplicationEngine engine;
    QObject::connect(
        &engine,
        &QQmlApplicationEngine::objectCreationFailed,
        &app,
        []() { QCoreApplication::exit(-1); },
        Qt::QueuedConnection);
    engine.loadFromModule("Prova", "Main");

    return app.exec();
}
