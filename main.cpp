#include <QCoreApplication>
#include <QTimer>
#include <QObject>
#include "jscontroller.h"
#include "restserver.h"
#include "randomgenerator.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    restServer rServer;

    QTimer *timer = new QTimer;

    QObject::connect(timer, &QTimer::timeout, [&](){

        jsController jsC;
        randomGenerator dGen;

        jsC.setInitValues(dGen.genTemp(), dGen.genTemp(), dGen.genDewPoint(), dGen.genHumidity());
        rServer.loadJsonToServer(jsController::toJson());
    });

    timer->start(1000);

    rServer.startRestServer(5555);

    //jsC.showJson(jsC.toJson());

    return a.exec();
}
