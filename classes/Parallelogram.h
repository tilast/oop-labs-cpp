#ifndef Parallelogram_h_
#define Parallelogram_h_

#include "colorRGB.h"
#include "Border.h"
#include "Point.h"

#include "Rectangle.h"

/**
* class Paralellogram
*/
class Parallelogram: public Rectangle {
    private :
        Point _controlPoint;
    public:
        Parallelogram(Point topLeft, Point bottomRight, double controlPoint, Border border, colorRGB background):Rectangle(topLeft, bottomRight, border, background) {
            this->setControlPoint(controlPoint);
            this->_type = 2;
        }
        Parallelogram(Point topLeft, Point bottomRight, double controlPoint):Rectangle(topLeft, bottomRight) {
            this->setControlPoint(controlPoint);
            this->_type = 2;
        }
        Parallelogram(Point topLeft, Point bottomRight):Rectangle(topLeft, bottomRight) {
            this->setControlPoint();
            this->_type = 2;
        }
        Parallelogram(const Parallelogram& orig):Rectangle(orig) {
            this->_controlPoint = orig._controlPoint;
            this->_type = 2;
        }
        /**
        * transfer
        * @param double x
        * @param double y
        * @return void
        */
        void transfer(double x, double y) {
            Point transfer = {x: x, y: y};
            this->_topLeft += transfer;
            this->_bottomRight += transfer;
            this->_controlPoint += transfer;
        }

        void setControlPoint(double x) {
            this->_controlPoint.x = x;
            this->_controlPoint.y = this->_topLeft.y;
        }
        void setControlPoint() {
            this->_controlPoint = this->_topLeft;
        }
        Point getControlPoint() {
            return this->_controlPoint;
        }
        void reflectVertical() {
            double distance  = fabs(this->_controlPoint.x - this->_topLeft.x);
            this->_controlPoint.x = this->_topLeft.x - distance;
        }
};
#endif
