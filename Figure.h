#ifndef Figure_h_
#define Figure_h_
/**
* class Figure
* abstract class for all geometric figures
*/
class Figure {
    protected :
        Point _topLeft, _bottomRight;
        bool _insurality;
        Border _border;
        colorRGB _backgroundRGB;
        int _id;
        int _type;
    public :
        static int lastId;
        /**
        * getTopLeft
        * @return double
        */
        Point getTopLeft() {
            return this->_topLeft;
        }

        /**
        * setTopLeft
        * @param double coordinate - coordinate of this point
        * @return void
        */
        void setTopLeft(Point point) {
            this->_topLeft.x = point.x;
            this->_topLeft.y = point.y;
        }

        /**
        * getBottomRight
        * @return double
        */
        Point getBottomRight() {
            return this->_bottomRight;
        }

        /**
        * setBottomRight
        * @param double coordinate - coordinate of this point
        * @return void
        */
        void setBottomRight(Point point) {
            this->_bottomRight.x = point.x;
            this->_bottomRight.y = point.y;
        }

        /**
        * getPerimeter
        * @return double
        */
        virtual double getPerimeter() {}

        /**
        * getArea
        * @return double
        */
        virtual double getArea() {}

        /**
        * setBorder
        * @param width - width of border
        * @param type - type of border
        * @param RGB - array of RGB color
        */
        void setBorder(double width, string type, colorRGB RGB) {
            this->_border.width = width;
            this->_border.type = type;
            this->_border.RGB = RGB;
        }

        void setBorder(Border border) {
            this->_border = border;
        }
        
        Border getBorder() {
        	return this->_border;
        }

        /**
        * setBackground
        * @param RGB - color of background in rgb
        */
        void setBackground(colorRGB RGB) {
            this->_backgroundRGB = RGB;
        }
        
        colorRGB getBackground() {
        	return this->_backgroundRGB;
        }

        virtual void horizontalReflect(){}
        virtual void verticalReflect(){}

        /**
        * getId
        * @return int
        */
        int getId() {
            return this->_id;
        }

        bool inLimitingRectangle(Point point) {
            return point.x >= this->_topLeft.x && point.x <= this->_bottomRight.x && point.y >= this->_topLeft.y && point.y <= this->_bottomRight.y;
        }

		int getType() {
			return this->_type;
		}
		
        /**
        * Figure
        * default constructor
        */
        Figure() {
            colorRGB borderRGB, backRGB;

            borderRGB.r = 255;
            borderRGB.g = 255;
            borderRGB.b = 255;

            backRGB.r = 255;
            backRGB.g = 0;
            backRGB.b = 0;

            this->setBorder(1.0, "solid", borderRGB);
            this->setBackground(backRGB);

            this->_id = ++Figure::lastId;
        }
};
int Figure::lastId = 0;
#endif
