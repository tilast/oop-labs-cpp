#ifndef Zigzag_h_
#define Zigzag_h_
/**
* class Zigzag
*/
class Zigzag: public Figure {
    private :
        int _stepsAmount;
        vector<Point> _points;
    public :
        Zigzag(Point topLeft, Point bottomRight, int stepsAmount, vector<Point> points, Border border):Figure() {
            this->setTopLeft(topLeft);
            this->setBottomRight(bottomRight);
			this->_stepsAmount = stepsAmount;
            this->_border = border;
            this->_insurality = false;
            this->_type = 3;
        }
        Zigzag(Point topLeft, Point bottomRight, int stepsAmount, vector<Point> points):Figure() {
            this->setTopLeft(topLeft);
            this->setBottomRight(bottomRight);
			this->_stepsAmount = stepsAmount;
            this->_insurality = false;
            this->_type = 3;
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
};
#endif
