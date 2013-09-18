#ifndef Zigzag_h_
#define Zigzag_h_

#include "colorRGB.h"
#include "Border.h"
#include "Point.h"

#include "Figure.h"

/**
* class Zigzag
*/
class Zigzag: public Figure {
    private :
        int _stepsAmount;
        vector<Point> _points;
    public :
        Zigzag(int stepsAmount, vector<Point> points, Border border):Figure() {
            this->setPoints(points);
			this->_stepsAmount = stepsAmount;
            this->_border = border;
            this->_insurality = false;
            this->_type = 3;
        }
        Zigzag(int stepsAmount, vector<Point> points):Figure() {
			this->_stepsAmount = stepsAmount;
            this->_insurality = false;
            this->_type = 3;
        }

        /**
        * getTopLeft
        * @return double
        */
        void getTopLeft() {
        }

        /**
        * setTopLeft
        * @param double coordinate - coordinate of this point
        * @return void
        */
        void setTopLeft(Point point) {
        }

        /**
        * getBottomRight
        * @return double
        */
        void getBottomRight() {
        }

        /**
        * setBottomRight
        * @param double coordinate - coordinate of this point
        * @return void
        */
        void setBottomRight(Point point) {
        }

        void setPoints(vector<Point> points) {
            this->_points = points;
        }
        vector<Point> getPoints() {
            return this->_points;
        }

        void changeSteps(int stepsAmount) {
            this->_stepsAmount = stepsAmount;
            this->_points.erase(this->_points.begin(), this->_points.begin() + stepsAmount);
        }
        
        void deletePoint(int number) {
        	this->_points.erase(this->_points.begin() + number);
        	this->_stepsAmount--;
        }
        void addPoint(Point point) {
            this->_points.push_back(point);
        }
        void setBackground() {}
        int resize(int size) {
            int oldSize = this->_stepsAmount;
            this->_stepsAmount = size;
            this->_points.resize(size);
            
            return size - oldSize;
        }

        int getSize() {
            return this->_stepsAmount;
        }
        void changePoint(Point point, int number) {
            this->_points[number-1] = point;
        }
};
#endif
