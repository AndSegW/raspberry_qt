#include <QGuiApplication>
#include <QQmlApplicationEngine>

int main(int argc, char *argv[])
{
    // Forza Qt a usare il plugin EGLFS (embedded, senza X11)
    qputenv("QT_QPA_PLATFORM", QByteArray("eglfs"));

    // Forza UTF-8
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
