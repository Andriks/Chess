#include <QtGui/QGuiApplication>
#include "qtquick2applicationviewer.h"

#include <QUrl>
#include <QDebug>
#include <QQmlContext>
#include <QQuickItem>

#include "game.h"

int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);

    QtQuick2ApplicationViewer viewer;


    viewer.setSource(QUrl("qrc:/qml/qml/Chess/screens.qml"));
    Game curGame(viewer.rootObject());

    viewer.showExpanded();

    return app.exec();
}
