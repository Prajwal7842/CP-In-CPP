#include<bits/stdc++.h>
using namespace std;

struct Point{
    int x, y;
};

double getArea(vector<Point>& points) {
    double res = 0.0;
    int n = points.size();
    for(int i = 1; i < n; i ++) {
        res += (points[i - 1].x - points[i].x) * (points[i-1].y + points[i].y);
    }
    res += (points[n-1].x - points[0].x) * (points[n-1].y + points[0].y);
    return fabs(res)/2;
}


int32_t main() {
	int n; cin >> n;
	vector<Point> arr(n);
	for(int i = 0; i < n; i ++) {
		cin >> arr[i].x >> arr[i].y;
 	}
 	double area = getArea(arr);
 	cout << area << endl;
	return 0;
}