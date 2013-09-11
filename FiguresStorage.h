#ifndef FiguresStorage_h_
#define FiguresStorage_h_
/**
* class FiguresStorage
*/
class FiguresStorage {
    private :
        vector<Figure*> _figures;
        vector<FiguresGroup*> _groups;

        int _findNumber(int id) {
            int requiredId = -1;
            for(int i = 0; i < this->_figures.size(); i++) {
                if(this->_figures[i]->getId() == id) {
                    requiredId = i;
                    break;
                }
            }

            return requiredId;
        }

        int _findGroupNumber(int id) {
            int result = -1;
            for(int i = 0; i < this->_groups.size(); i++) {
                if(id == this->_groups[i]->getId()) {
                    result = i;
                }
            }

            return result;
        }
    public :
        /**
        * addRectangle
        * @param Point topLeft
        * @param Point bottomRight
        * @param Point controlPoint
        * @param Border border
        * @param vector<int> background
        * @return void
        */
        Rectangle* addRectangle(Point topLeft, Point bottomRight, Border border, colorRGB background) {
            Rectangle * newRect = new Rectangle(topLeft, bottomRight, border, background);
            this->_figures.push_back(newRect);
            return newRect;
        }
        Rectangle* addRectangle(Point topLeft, Point bottomRight) {
            Rectangle * newRect = new Rectangle(topLeft, bottomRight);
            this->_figures.push_back(newRect);
            return newRect;
        }

        Parallelogram* addParallelogram(Point topLeft, Point bottomRight, double controlPoint, Border border, colorRGB background) {
            Parallelogram * newPar = new Parallelogram(topLeft, bottomRight, controlPoint, border, background);
            this->_figures.push_back(newPar);
            return newPar;
        }
        Parallelogram* addParallelogram(Point topLeft, Point bottomRight, double controlPoint) {
            Parallelogram * newPar = new Parallelogram(topLeft, bottomRight, controlPoint);
            this->_figures.push_back(newPar);
            return newPar;
        }
        Parallelogram* addParallelogram(Point topLeft, Point bottomRight) {
            Parallelogram * newPar = new Parallelogram(topLeft, bottomRight);
            this->_figures.push_back(newPar);
            return newPar;
        }
        Zigzag* addZigzag(Point topLeft, Point bottomRight, int stepsAmount, vector<Point> points, Border border) {
        	Zigzag * newZig = new Zigzag(topLeft, bottomRight, stepsAmount, points, border);
        	this->_figures.push_back(newZig);
        	return newZig;
        }
        /**
        * getAmount
        * return int
        */
        int getAmount() {
            return this->_figures.size();
        }

        /**
        * find
        * @param int id
        * @return Figure
        */

        Figure* find(int id) {
            Figure* result = NULL;
            for(int i = 0; i < this->_figures.size(); i++) {
                if(this->_figures[i]->getId() == id) {
                    result = this->_figures[i];
                    break;
                }
            }

            return result;
        }
        /**
        * find
        * @param Point
        * @return vector<Figure*>
        */
        vector<Figure*> find(Point point) {
            vector<Figure*> result;
            for(int i = 0; i < this->_figures.size(); i++) {
                if(this->_figures[i]->inLimitingRectangle(point)) {
                    result.push_back(this->_figures[i]);
                }
            }

            return result;
        }

        void remove(int id) {
            Figure * forRemove = this->find(id);
            int number = this->_findNumber(id);
            delete forRemove;
            this->_figures.erase(this->_figures.begin() + number);
        }

        FiguresGroup * addGroup() {
            FiguresGroup* newGroup = new FiguresGroup();
            this->_groups.push_back(newGroup);
            return newGroup;
        }
        void removeGroup(int id) {
            int number = this->_findGroupNumber(id);
            delete this->_groups[number];
            this->_groups.erase(this->_groups.begin() + number);
        }
};
#endif
