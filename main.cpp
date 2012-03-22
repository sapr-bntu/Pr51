#include <QtGui/QApplication>
#include <QtDeclarative/QDeclarativeContext>
#include "qmlapplicationviewer.h"
#include "application.h"

Q_DECL_EXPORT int main(int argc, char *argv[])
{
    QScopedPointer<QApplication> app(createApplication(argc, argv));

    QmlApplicationViewer viewer;
    viewer.rootContext()->setContextProperty("imgapp",new Application);

    viewer.setOrientation(QmlApplicationViewer::ScreenOrientationAuto);
    viewer.setMainQmlFile(QLatin1String("qml/pr55/main.qml"));
    viewer.showExpanded();

    return app->exec();
}
