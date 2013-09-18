#ifndef Rectangle_h_
#define Rectangle_h_

#include "colorRGB.h"
#include "Border.h"
#include "Point.h"

#include "Figure.h"

/**
* class Rectangle
*/
class Rectangle: public Figure {
    public:
        Rectangle(Point topLeft, Point bottomRight, Border border, colorRGB background):Figure() {
            this->_topLeft = topLeft;
            this->_bottomRight = bottomRight;
            this->_border = border;
            this->_backgroundRGB = background;
            this->_insurality = true;
            this->_type = 1;
        }
        Rectangle(Point topLeft, Point bottomRight):Figure() {
            this->_topLeft = topLeft;
            this->_bottomRight = bottomRight;
            this->_insurality = true;
            this->_type = 1;
        }
        Rectangle(const Rectangle& orig) {
            this->_topLeft = orig._topLeft;
            this->_bottomRight = orig._bottomRight;
            this->_border = orig._border;
            this->_backgroundRGB = orig._backgroundRGB;
            this->_insurality = orig._insurality;
            this->_id = ++Figure::lastId;
            this->_type = 1;
        }
        Rectangle& operator *= (double times) {
            this->_bottomRight *= times;
        }

        /**
        * transfer
        * @param double x
        * @param double y
        * @return void
        */
        virtual void transfer(double x, double y) {
            Point transfer = {x: x, y: y};
            this->_topLeft += transfer;
            this->_bottomRight += transfer;
        }
};
#endif
