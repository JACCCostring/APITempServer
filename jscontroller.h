#ifndef JSCONTROLLER_H
#define JSCONTROLLER_H

#include <QObject>
#include <QJsonDocument>
#include <QJsonObject>

class jsController : public QObject
{
    Q_OBJECT
public:
    explicit jsController(QObject *parent = nullptr);
    //obj initializer
    void setInitValues(double, double, double, double);
    //convert to json method
    //const QByteArray toJson();
    //converto to json raw data, but its overloading method with parameter
    static const QByteArray toJson();
    //debuging pourpus
    void showJson(const QByteArray &);

private:
    //all private members are static because toJson() method
    //it need it to be called without an instance
    static double dayTemp;
    static double nightTemp;
    static double dewPoint;
    static double humidity;
};

#endif // JSCONTROLLER_H
