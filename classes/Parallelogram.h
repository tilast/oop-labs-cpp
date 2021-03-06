#ifndef Parallelogram_h_
#define Parallelogram_h_

#include "colorRGB.h"
#include "Border.h"
#include "Point.h"

#include "Rectangle.h"

/**
* class Paralellogram
*/
class Parallelogram: public Figure {
    private :
        Point _controlPoint;
    public:
        Parallelogram(Point topLeft, Point bottomRight, double controlPoint, Border border, colorRGB background):Figure() {
            this->_topLeft = topLeft;
            this->_bottomRight = bottomRight;
            this->_border = border;
            this->_backgroundRGB = background;
            this->_insurality = true;
            this->setControlPoint(controlPoint);
            this->_type = 2;
        }
        Parallelogram(Point topLeft, Point bottomRight, double controlPoint):Figure() {
            this->_topLeft = topLeft;
            this->_bottomRight = bottomRight;
            this->setControlPoint(controlPoint);
            this->_type = 2;
        }
        Parallelogram(Point topLeft, Point bottomRight) {
            this->_topLeft = topLeft;
            this->_bottomRight = bottomRight;
            this->setControlPoint();
            this->_type = 2;
        }
        Parallelogram(const Parallelogram& orig) {
            this->_topLeft = orig._topLeft;
            this->_bottomRight = orig._bottomRight;
            this->_border = orig._border;
            this->_backgroundRGB = orig._backgroundRGB;
            this->_insurality = true;
            
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
