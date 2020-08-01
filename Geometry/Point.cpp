#include<bits/stdc++.h>
using namespace std;

/* 

ccw(point1, point2) returns val
<0 if point1 is ccw of point2
=0 if point1 is collinear to point2
>0 else
ccw([10, 0], [0, 10]) > 0
*/

// 2D Point 
template<class T>
struct Point{
    T x, y;
    Point() : x(0), y(0) {}
    Point(const T& x, const T& y): x(x), y(y) {}
    void swap(Point& other){
        using std::swap; swap(x, other.x); swap(y, other.y);
    }

    //Unary Operator
    template<class U> explicit operator Point<U>() const {
        return Point<U>(static_cast<U>(x), static_cast<U>(y));
    }
    template<class U> Point& operator =(const Point<U>& other){
        x = other.x; y = other.y; return *this;
    }
    template<class U> Point& operator += (const Point<U>& other){
        x += other.x; y += other.y; return *this;
    }
    template<class U> Point& operator -=(const Point<U>& other){
        x -= other.x; y -= other.y; return *this;
    }
    template<class U> Point& operator *=(const U& factor){
        x *= factor; y *= factor; return *this;
    }
    template<class U> Point& operator /=(const U& factor){
        x /= factor; y /= factor; return *this;
    }
};

template<class T> ostream& operator <<(ostream& os, const Point<T>& point){
    return os << "(" << point.x << ", " << point.y << ")";
}

template<class F> inline Point<F> makePoint(const F& x, const F& y){
    return Point<F>(x, y);
}
template<class T> void swap(Point<T>& point1, Point<T>& point2){
    point1.swap(point2);
}

//Binary Operator
template<class U, class V, class Z> Point<Z>& operator +(const Point<U>& point1, const Point<V>& point2){
    Point<Z> result; result.x = point1.x + point2.x; result.y = point1.y + point2.y;
    return result;
}
template<class U, class V, class Z> Point<Z>& operator -(const Point<U>& point1, const Point<V>& point2){
    Point<Z> result; result.x = point1.x - point2.x; result.y = point1.y - point2.y;
    return result;
}
template<class U, class V, class Z> Point<Z>& operator *(const Point<U>& point, V& factor){
    Point<Z> result; result.x = point.x*factor; result.y = point.y*factor;
    return result;
}
template<class U, class V, class Z> Point<Z>& operator /(const Point<U>& point, V& factor){
    Point<Z> result; result.x = point.x/factor; result.y = point.y/factor;
    return result;
}
template<class U, class V> auto operator *(const Point<U>& point1, const Point<V>& point2){
    return (point1.x*point2.x) + (point1.y*point2.y);
}
template<class U, class V> auto operator ^(const Point<U>& point1, const Point<V>& point2){
    return (point1.x*point2.y) - (point1.y*point2.x);
}
template<class U> bool operator ==(const Point<U>& point1, const Point<U>& point2){
    return ((point1.x == point2.x) && (point1.y == point2.y));
}
template<class U> bool operator !=(const Point<U>& point1, const Point<U>& point2){
    return !(point1 == point2);
}
template<class U> bool operator <(Point<U>& point1, const Point<U>& point2){
    return ((point1.y < point2.y) || (point1.y==point2.y && point1.x < point2.x));
}
template<class U> bool operator >(Point<U>& point1, const Point<U>& point2){
    return point2 < point1;
}
template<class U> bool operator <=(Point<U>& point1, const Point<U>& point2){
    return !(point1>point2);
}
template<class U> bool operator >=(Point<U>& point1, const Point<U>& point2){
    return !(point1<point2);
}

//Orientation
template<class U, class V> auto ccw(Point<U>& point1, Point<V>& point2){
    return point1^point2;
}
template<class U, class V, class W> auto ccw(Point<U>& point1, Point<V>& point2, Point<W>& origin){
    return ccw(point1-origin, point2-origin);
}

//Angles and Rotations (counter-clockwise)
template<class U> auto angle(Point<U>& point){
    return atan2(point.y, point.x);
}
template<class U, class V> auto angle(Point<U>& point1, Point<V>& point2){
    return atan2(point1^point2, point1*point2);
}
template<class U, class V, class W> auto angle(Point<U>& point1, Point<V>& point2, Point<W>& origin){
    return angle(point1-origin, point2-origin);
}
template<class U, class V, class W, class Z> auto rotate(Point<U>& point, V& sintheta, W& costheta){
    Point<Z> result; result.x = costheta*point.x - sintheta*point.y;
    result.y = sintheta*point.x + costheta*point.y;
    return result;
}
template<class U, class V, class Z> auto rotate(Point<U>& point, V& angle){
    Point<Z> result = rotate(point, sin(angle), cost(angle));
    return result;
}
template<class U, class V, class W, class Z> auto rotate(Point<U>& point, V& angle, Point<W>& origin){
    Point<Z> result = rotate(point, sin(angle), cos(angle));
    return (origin+result);
}

//Distances
template<class U> auto abs(Point<U>& point){
    return point*point;
}
template<class U> auto norm(Point<U>& point){
    return sqrt(abs(point));
}
template<class U, class V> auto dist(Point<U>& point1, Point<V>& point2){
    return norm(point1-point2);
}
template<class U, class V> auto dist2(Point<U>& point1, Point<V>& point2){
    return abs(point1-point2);
}
template<class U, class V> auto bisector(Point<U>& point1, Point<V>& point2){
    return (point1*(norm(point2)))+(point2*(norm(point1)));
}


//---------------------------------------------------------------------------------------------------------------
//Line
// Representation : Parametric Equation : A + t.(AB)

template<class T>
struct Line{
    Point<T> a;
    Point<T> ab;
    Line(): a(), ab() {}
    Line(const Point<T>& a, const Point<T>& b bool twoPoints = true): a(a), ab(twoPoints:b-a:b) {}
    Line(T& xa, T& ya, T& xab, T& yab): a(xa, ya), ab(xab, yab){}
    void swap(Line& other){
        using std::swap; swap(a, other.a); swap(ab, other.ab);
    } 
    template<class U> explicit operator Line<U>() const {
        return Line<U>(Point<U>(a), Point<U>(ab), false);
    }
    template<class U> Line& operator =(const Line<U>& other){
        a = other.a; ab = other.ab; return *this;
    }
    Point<T> b() const { return a + ab; }
    operator bool () const { return ab != Point<T>(); }
}; 
template<class U, class V>
bool onLine(const Point<U>& point, Line<V>& line){
    if(!line) return point == line.a;
    return ((point-line.a)^line.ab) == 0;
}

template<class U, class V>
bool onSegment(const Point<U>& point, Line<V>& line){
    if(!line) return point == seg.a;
    auto vectora = seg.a-point; auto vectorb = seg.b() - point;
    return ((vectora^vectorb) == 0) && ((vectora*vectorb) <= 0);
}


int main(){
    return 0;
}