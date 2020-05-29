// Author : Abdallah Hemdan
// For Hassanosama, ICPC next year ISA.
#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif
#include <bits/stdc++.h>
#define vll vector<ll>
#define vi vector<int>
#define all(v) ((v).begin()), ((v).end())
#define rall(v) ((v).rbegin()), ((v).rend())
#define mms(a,val) memset(a,val,sizeof(a))
#define endl '\n'
#define sz size()
#define pii pair<int,int>
#define pll pair<ll,ll>


using namespace std;
using ll = long long int;
using ld = long double;

struct Point {
  int x, y;
};

double calc_dist(Point p1, Point p2) {
  return sqrt(pow((p1.x - p2.x), 2) + pow((p1.y - p2.y), 2));
}

double brute_force(Point P[], int n) {
  double ret = FLT_MAX;
  for (int i = 0; i < n; ++i)
    for (int j = i + 1; j < n; ++j)
      ret = min(ret, calc_dist(P[i], P[j]));
  return ret;
}

int compareY(const void *a, const void *b) {
  Point *p1 = (Point *)a, *p2 = (Point *)b;
  return (p1->y - p2->y);
}

double stripping(Point strip[], int size, double d) {
  double ret = d;
  qsort(strip, size, sizeof(Point), compareY);
  for (int i = 0; i < size; ++i)
    for (int j = i + 1; j < size && (strip[j].y - strip[i].y) < ret; ++j)
      ret = min(ret, calc_dist(strip[i], strip[j]));
  return ret;
}

double colsest_point_rec(Point points[], int n) {
  if (n < 4)
    return brute_force(points, n);
  int mid = n / 2;
  Point midPoint = points[mid];
  double dl = colsest_point_rec(points, mid);
  double dr = colsest_point_rec(points + mid, n - mid);
  double dist = min(dl, dr);
  Point strip[n];
  int j = 0;
  for (int i = 0; i < n; ++i)
    if (abs(points[i].x - midPoint.x) < dist)
      strip[j] = points[i], j++;
  return min(dist, stripping(strip, j, dist));
}

int compareX(const void *a, const void *b) {
  Point *p1 = (Point *)a, *p2 = (Point *)b;
  return (p1->x - p2->x);
}

double closest_point(Point points[], int n) {
  qsort(points, n, sizeof(Point), compareX);
  return colsest_point_rec(points, n);
}


int main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#ifndef ONLINE_JUDGE
	freopen("In.txt", "r", stdin);
#endif
  	
    int n;
    cin >> n;
    int x, y;
    Point points[n];
    for (int i = 0; i < n; ++i) {
        cin >> x >> y;
        points[i] = {x, y};
    }
    printf("%.4lf", closest_point(points, n));
    return 0;
}
