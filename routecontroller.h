#ifndef ROUTECONTROLLER_H
#define ROUTECONTROLLER_H

#include <QtCore>

class routeController
{
public:
    //constructor
    routeController();
    //setter and getter
    void setRoute(const QString &);
    static const QString getRoute();
    //normal methods
    static bool validateRoute();
    static double executeRoute();

private:
    static QString request;
    static QString absoluteRoute;

};

#endif // ROUTECONTROLLER_H
