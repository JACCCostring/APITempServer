#include <QCoreApplication>
#include <QTimer>
#include <QObject>
#include "jscontroller.h"
#include "restserver.h"
#include "randomgenerator.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    //converting char argv[] to integer
    int port = std::atoi(argv[1]);
    //creating obj
    restServer rServer;

    QTimer *timer = new QTimer;

    QObject::connect(timer, &QTimer::timeout, [&](){

        jsController jsC;
        randomGenerator dGen;

        jsC.setInitValues(dGen.genTemp(), dGen.genTemp(), dGen.genDewPoint(), dGen.genHumidity());
        rServer.loadJsonToServer(jsController::toJson());
    });

    timer->start(1000);

    rServer.startRestServer(port);

    //jsC.showJson(jsC.toJson());

    return a.exec();
}
