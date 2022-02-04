#include "restserver.h"
#include "routecontroller.h"
#include "jscontroller.h"

restServer::restServer(QObject *parent) : QObject(parent)
{
    server = new QTcpServer(this);
    connect(server, &QTcpServer::newConnection, this, &restServer::newConn);
}

void restServer::startRestServer(qint16 newPort)
{
    if(server->isListening()){
        qDebug() << "already listening ! ...";
        return;
    }
    server->listen(QHostAddress::Any, newPort);
    qDebug() << "server listening ...";
}

void restServer::loadJsonToServer(const QByteArray &toCopy)
{
    dataToSend = toCopy;
}

void restServer::newConn()
{  //getting obj reference from QTcpServer* caller
    QTcpSocket *newSocket = server->nextPendingConnection();
    qDebug()<< "new connection";
    //sending http header
    newSocket->write("HTTP/1.1 200 ok\r\n\r\n");
    //connecting signal to check when new data arrives
    connect(newSocket, &QTcpSocket::readyRead, this, [=](){
        //get content in variable allowingg working with the request
        //otherwise content is lost after first read, QByteArray in IODevices
        //work asynchronous
        QByteArray request = newSocket->readAll();
        //creating route obj
        routeController routes;
        //setting route
        routes.setRoute(request);
        //if GET
        if(request.startsWith("GET")){
            qDebug()<< "GET request ..." ;
            //if request is routed
            if(routeController::validateRoute()){ //if route passed is valid then
                QString key = routeController::getRoute(); //retrieving key
                QVariant value = routeController::executeRoute(); //retrieving value
                //sending json content to client
                newSocket->write(jsController::toJsonValue(key, value));
            }
            else{
                newSocket->write(dataToSend); //if not then send hole json response
            }
        }
        //if POST
        else if(request.startsWith("POST")){
            qDebug()<<"POST request";
            QString processString = request;
            QString jsonConverted = processString.section("\r\n\r\n", 1, 1);
            jsonPosts.append(jsonConverted.toUtf8());
            //looping data in container
            for(const QByteArray &data: qAsConst(jsonPosts))
            newSocket->write(data);
        }
        else{
            qDebug()<<"client no spacifiying valid request !";
            newSocket->write("must spacified COMMAND: PUT, POST, GET or DELETE\n");
        }
        newSocket->close(); //disconnecting from server to avoid unspectected behavior
    });
}
