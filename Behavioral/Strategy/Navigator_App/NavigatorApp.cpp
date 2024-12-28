#include <iostream>

using namespace std;

// Create an interface for route strategies
class RouteStrategy
{
public:
    virtual string getRoute(string locA, string locB) = 0;
};

// Create concrete classes
// 1. Road Strategy
class RoadStrategy : public RouteStrategy
{
public:
    string getRoute(string locA, string locB)
    {
        return "This is Road route from " + locA + " to " + locB;
    }
};

// 2. Walk Strategy
class WalkStrategy : public RouteStrategy
{
public:
    string getRoute(string locA, string locB)
    {
        return "This is Walk route from " + locA + " to " + locB;
    }
};

// 3. Public Transport Strategy
class PublicTransportStrategy : public RouteStrategy
{
public:
    string getRoute(string locA, string locB)
    {
        return "This is Public Transport route from " + locA + " to " + locB;
    }
};

// Create a class for navigation
class Navigator
{
    RouteStrategy* routeStrategy;
public:
    void setRouteStrategy(RouteStrategy* strategy)
    {
        routeStrategy = strategy;
    }

    string getRoute(string locA, string locB)
    {
        return routeStrategy->getRoute(locA, locB);
    }
};

int main()
{
    // Clients code
    RouteStrategy* strategy1 = new RoadStrategy();
    RouteStrategy* strategy2 = new WalkStrategy();
    RouteStrategy* strategy3 = new PublicTransportStrategy();


    Navigator nav;
    nav.setRouteStrategy(strategy1);
    cout << nav.getRoute("A", "B") << endl;

    nav.setRouteStrategy(strategy2);
    cout << nav.getRoute("A", "B") << endl;

    nav.setRouteStrategy(strategy3);
    cout << nav.getRoute("A", "B") << endl;

    // Release memeory
    delete strategy1;
    delete strategy2;
    delete strategy3;

    return 0;
}