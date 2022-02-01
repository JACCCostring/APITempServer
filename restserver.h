#ifndef RESTSERVER_H
#define RESTSERVER_H

#include <QTcpServer>
#include <QTcpSocket>

class restServer : public QObject
{
    Q_OBJECT
public:
    explicit restServer(QObject *parent = nullptr);
    //start server
    void startRestServer(qint16);
    //method to copy json data from jsController
    void loadJsonToServer(const QByteArray &);

private slots:
    void newConn();

private:
    QTcpServer *server;
    QList<QByteArray> jsonPosts; //QList of restServer type for post request
    QByteArray dataToSend;
};

#endif // RESTSERVER_H
