int signed_area_parallelogram(point2d p1, point2d p2, point2d p3) {
  return cross(p2 - p1, p3 - p2);
}
double triangle_area(point2d p1, point2d p2, point2d p3) {
  return abs(signed_area_parallelogram(p1, p2, p3)) / 2.0;
}
bool clockwise(point2d p1, point2d p2, point2d p3) {
  return signed_area_parallelogram(p1, p2, p3) < 0;
}
bool counter_clockwise(point2d p1, point2d p2, point2d p3) {
  return signed_area_parallelogram(p1, p2, p3) > 0;
}
double area(const vector<point>& fig) {
  double res = 0;
  for (unsigned i = 0; i < fig.size(); i++) {
    point p = i ? fig[i - 1] : fig.back();
    point q = fig[i];
    res += (p.x - q.x) * (p.y + q.y);
  }
  return fabs(res) / 2;
}