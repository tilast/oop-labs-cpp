#ifndef Point_h_
#define Point_h_
/**
* class Point
* class for work with points
*/
class Point {
    public:
        double x, y;
        Point& operator *= (double times) {
            this->x *= times;
            this->y *= times;
        }
        Point& operator += (Point transfer) {
            this->x += transfer.x;
            this->y += transfer.y;
        }
};
#endif
