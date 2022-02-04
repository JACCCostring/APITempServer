#include "jscontroller.h"
#include <QVariant>
//initializing static members out of class
double jsController::dayTemp = 0;
double jsController::nightTemp = 0;
double jsController::dewPoint = 0;
double jsController::humidity = 0;

jsController::jsController(QObject *parent) : QObject(parent) {}

void jsController::setInitValues(double dTemp, double nTemp, double dPoint, double h)
{
    dayTemp = dTemp;
    nightTemp = nTemp;
    dewPoint = dPoint;
    humidity = h;
}

/*const QByteArray jsController::toJson()
{
    QJsonDocument doc;
    QJsonObject jsonObj;
    QByteArray jsonData;
    //parsing
    jsonObj["dayTemp"] = dayTemp;
    jsonObj["nightTemp"] = nightTemp;
    jsonObj["dewPoint"] = dewPoint;
    jsonObj["humidity"] = humidity;
    //setting json object to QJsonDocument
    doc.setObject(jsonObj);
    //getting json format from QJsonDocument
    jsonData = doc.toJson();
    //restarting values since to avoid statics values
    dayTemp = 0;
    nightTemp = 0;
    dewPoint = 0;
    humidity = 0;
    //returning json
    return jsonData;
}*/

const QByteArray jsController::toJson()
{
    QJsonDocument doc;
    QJsonObject jsonObj;
    QByteArray toJson;
    //parsing
    jsonObj["dayTemp"] = dayTemp;
    jsonObj["nightTemp"] = nightTemp;
    jsonObj["dewPoint"] = dewPoint;
    jsonObj["humidity"] = humidity;
    //setting json object to QJsonDocument
    doc.setObject(jsonObj);
    //getting json format from QJsonDocument
    toJson = doc.toJson();
    //returning json
    return toJson;
}

const QByteArray jsController::toJsonValue(const QString &key, const QVariant &value)
{
    QJsonDocument doc;
    QJsonObject jsonObj;
    QByteArray toJson;
    //checking if can convert to double
    if(value.canConvert(QMetaType::Double)){ // or value.canConvert<double>() return a bool
    //parsing
    jsonObj[key] = value.toDouble();
    }
    //setting json object to QJsonDocument
    doc.setObject(jsonObj);
    //getting json format from QJsonDocument
    toJson = doc.toJson();
    //returning json
    return toJson;
}

void jsController::restartValues()
{
    //restarting values since to avoid statics values
    dayTemp = 0;
    nightTemp = 0;
    dewPoint = 0;
    humidity = 0;
}

double jsController::getDTemp()
{
    return dayTemp;
}

double jsController::getDPoint()
{
    return dewPoint;
}

double jsController::getNTemp()
{
    return nightTemp;
}

double jsController::getHumidity()
{
    return humidity;
}

/*void jsController::showJson(const QByteArray &jsonData)
{
    qDebug()<<jsonData;
}*/
