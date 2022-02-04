#include "routecontroller.h"
#include "jscontroller.h"

//initializing all static class members
QString routeController::request = QString();
QString routeController::absoluteRoute = QString();

routeController::routeController(){}

void routeController::setRoute(const QString &newRequest)
{
    request = newRequest;
}

const QString routeController::getRoute()
{
    return absoluteRoute;
}

bool routeController::validateRoute()
{
    QStringList routeSplitted = request.split("/"); //splitting by / to get right route

    QString route = routeSplitted[1]; //retrieving first command request after GET command

    if( route.startsWith("dayTemp") || route.startsWith("dewPoint") //if any of available command then
    || route.startsWith("nightTemp") || route.startsWith("humidity") ){ //route is valid
        //assigning new valid route
        absoluteRoute = route;
        return true; //returning true if valid command request
    }
    return false; //otherwise false
}

double routeController::executeRoute()
{
    if(absoluteRoute.startsWith("dayTemp")) return jsController::getDTemp();
    if(absoluteRoute.startsWith("dewPoint")) return jsController::getDPoint();
    if(absoluteRoute.startsWith("nightTemp")) return jsController::getNTemp();
    if(absoluteRoute.startsWith("humidity")) return jsController::getHumidity();
    //if non of above then return 0.0
    return 0.0;
}
