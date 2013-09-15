#ifndef FiguresGroup_h_
#define FiguresGroup_h_
/**
* class Figure Group
*/
class FiguresGroup {
    private :
        vector<Figure*> _figures;
        int _id;
    public :
        static int lastId;

        FiguresGroup() {
            this->_id = ++Figure::lastId;
        }

        int getId() {
            return this->_id;
        }
        /**
        * add
        */
        void add(Figure* figure) {
            if(this->inGroup(figure) >= 0) {
                this->_figures.push_back(figure);
            }
        }

        /**
        * add
        */
        void add(vector<Figure*> fgrs) {
            for(int j = 0; j < fgrs.size(); j++) {
                if(inGroup(fgrs[j]) >= 0) {
                    this->_figures.push_back(fgrs[j]);
                }
            }
        }

        /**
        * remove
        */
        void remove(Figure* figure) {
            int number = this->inGroup(figure);
            if(number >= 0) {
                this->_figures.erase(this->_figures.begin() + number);
            }
        }

        /**
        * remove
        */
        void remove(vector<Figure*> fgrs) {
            for(int i = 0; i < fgrs.size(); i++) {
                int number = this->inGroup(fgrs[i]);
                if(number >= 0) {
                    this->_figures.erase(this->_figures.begin() + number);
                }
            }
        }

        void setBorder(Border border) {
            for(int i = 0; i < this->_figures.size(); i++) {
                this->_figures[i]->setBorder(border);
            }
        }

        void setBackground(colorRGB color) {
            for(int i = 0; i < this->_figures.size(); i++) {
                this->_figures[i]->setBackground(color);
            }
        }

        /**
        * inGroup
        */
        int inGroup(Figure* figure) {
            for(int i = 0; i < this->_figures.size(); i++) {
                if(this->_figures[i] == figure) {
                    return i;
                }
            }

            return -1;
        }

        vector<Figure*> getGroup() {
            return this->_figures;
        }
};
int FiguresGroup::lastId = 0;
#endif