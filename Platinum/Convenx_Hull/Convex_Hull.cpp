#include<bits/stdc++.h>
using namespace std;
#define makeIO ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define FOR(i, a, b) for (int i = (a); i < (b); i++)
#define FORE(i, a, b) for (int i = (a); i <= (b); i++)
#define F0R(i, a) for (int i = 0; i < (a); i++)
#define EDL std::cout<<endl;
typedef long long ll;

int n; //# of points

template <class T>
class Point{
public:
    int x, y;
    Point(int x, int y) {
        this->x = x;
        this->y = y;
    }
    Point() {
        this->x = 0;
        this->y = 0;
    }
};

Point<int>* points; //array of points

//compute the slope
double computeK(Point<int> p1, Point<int> p2) {
    if (p1.x == p2.x) {
        return DBL_MAX;
    }
    return (double)(p2.y - p1.y) / (p2.x - p1.x);
}

//determine whether p1 is on the left of p2
bool isLeft(Point<int> p1, Point<int> p2) {
    return p1.x < p2.x || (p1.x == p2.x && p1.y < p2.y);
}

//determine whether p1 p2 p3 is on the same line
bool isCollinear(Point<int> p1, Point<int> p2, Point<int> p3) {
    return computeK(p1, p2) == computeK(p2, p3);
}

int orientation(Point<int> p, Point<int> q, Point<int> r) {
    int val = (q.y - p.y) * (r.x - q.x) - (q.x - p.x) * (r.y - q.y);
    if (val == 0) return 0;  // collinear
    return (val > 0)? 1: 2; // clock or counterclock wise
}

double dist(Point<int> p1, Point<int> p2) {
    return (p1.x - p2.x) * (p1.x - p2.x) + (p1.y - p2.y) * (p1.y - p2.y);
}


template<class T>
class ConvexHull{
public:
    Point<int>* points;
    int maxN;
    int index;

    ConvexHull(int maxN){
        this->maxN = maxN;
        points = new Point<int>[maxN];
        index = 0;
    }

    ~ConvexHull(){
        delete[] points;
    }

    void push(Point<int> p){
        points[index++] = p;
    }

    Point<int> pop(){
        return points[--index];
    }

    void print(){
        FOR(i, 0, index){
            cout << "(" << points[i].x << ", " << points[i].y << ") ";
        }
        EDL;
    }

    void takeEndpoint(){
        Point<int> p1 = points[0];
        Point<int> p2 = points[index - 1];
        int i = index - 2;
        while(i >= 0 && isCollinear(p1, p2, points[i])){
            i--;
        }
        i++;
        FOR(j, i, index){
            points[j - i] = points[j];
        }
        index -= i;
    }
};

/*
 * Graham Scan Algorithm
 * O(nlogn)
 */

int main(){
    makeIO;
    cin >> n;
    points = new Point<int>[n];
    F0R(i, n) {
        int x, y;
        cin >> x >> y;
        points[i] = Point<int>(x, y);
    }
    int minY = points[0].y, minIndex = 0;
    FOR(i, 1, n){
        int y = points[i].y;
        if((y < minY) || (minY == y && points[i].x < points[minIndex].x)){
            minY = points[i].y;
            minIndex = i;
        }
    }

    //sort the points according to the polar angle
    Point<int> startPoint = points[minIndex];
    swap(points[0], points[minIndex]);
    sort(points + 1, points + n, [&](Point<int> p1, Point<int> p2) {
        int o = orientation(startPoint, p1, p2);
        if (o == 0)
            return dist(startPoint, p1) < dist(startPoint, p2);
        return o == 2;
    });

    //print points after sorted
    FOR(i, 0, n){
        cout << "(" << points[i].x << ", " << points[i].y << ") ";
    }
    EDL;

    ConvexHull<int> hull(n);
    hull.push(points[0]);
    hull.push(points[1]);
    hull.push(points[2]);

    FOR(i, 3, n){
        while(hull.index >= 2 && orientation(hull.points[hull.index - 2], hull.points[hull.index - 1], points[i]) != 2){
            hull.pop();
        }
        hull.push(points[i]);
    }

    //hull.takeEndpoint();
    hull.print();
}
