#ifndef FiguresConsole_h_
#define FiguresConsole_h_
/**
* class FiguresConsole
* class for work with console
*/
class FiguresConsole {
	private :
		bool _wrongCommand;
    public :

        double getDouble() {
            double tpm;
            cin >> tpm;
            

            return tpm;
        }
        
        int getInt() {
        	int tmp;
        	cin >> tmp;
        	
        	return tmp;
        }

        Point getPoint() {
        	Point point;
			cout << "Х:" << endl;
            cin >> point.x;
            cout << "Y:" << endl;
            cin >> point.y;	
			
            return point;
        }

        colorRGB getRGB() {
            colorRGB color;
            cout << "r: ";
            cin >> color.r;
            cout << "g: ";
            cin >> color.g;
            cout << "b: ";
            cin >> color.b;

            return color;
        }

        Border getBorder() {
            Border tmp;

            cout << "Властивості границь. Введіть товщину: " << endl;
            cin >> tmp.width;
            cout << "Введіть тип: " << endl;
            cin >> tmp.type;
            cout << "Введіть колір: " << endl;
            tmp.RGB = this->getRGB();

            return tmp;
        }
        int getId() {
        	int id = -1;
        	cout << "Введіть id: " << endl;
        	cin >> id;
        	
        	return id;
        }
        
        double getControlPoint() {
        	cout << "X: " << endl;
			double point;
        	cin >> point;
        	
        	return point;
        }
		void outHello() {
			cout << "Вас вітає консольний векторний редактор примітивів" << endl;
		}
		void outInputCommand() {
			cout << "Введіть команду" << endl;
		}
		
		void outWrongCommand(string command, bool *wrongCommand) {
            cout << "Невірна команда '" << command << "'" << endl;
            *wrongCommand = true;
        }
		
		void outControlPoint() {
			cout << "Введіть контрольну точку" << endl;
		}

        void outTopLeft() {
            cout << "Введіть координати верхньої лівої точки: " << endl;
        }

        void outBottomRight() {
            cout << "Введіть координати правої нижньої точки: " << endl;
        }
        void outNeedBorder() {
            cout << "Потрібно задавати границі?(1/0)" << endl;
        }
        void outNeedBackground() {
            cout << "Потрібно задавати колір?(1/0)" << endl;
        }
        void outHowMuchPoints() {
        	cout << "Скільки точок у зигзагу?" << endl;
        }
        
        void outIgnore(int amount) {
        	cin.ignore(amount);
        }
        void outIgnoreNL() {
        	cin.ignore('\n');
        }
        void outFigureId(Figure * figure) {
        	cout << "ID фігури: " << figure->getId() << endl;
        }
        
        void outFigureInfo(Figure * figure, bool * excessiveSymbol) {
        	switch(figure->getType()) {
        		case 1 :
        			this->outRectangleInfo((Rectangle*)figure);
        			break;
        		case 2 :
        			this->outParallelogramInfo((Parallelogram*)figure);
        			break;
        		case 3 :
        			this->outZigzagInfo((Zigzag*)figure);
        			break;
        		default :
        			cout << "Незнайома фігура" << endl;
        	}
        	
        	*excessiveSymbol = true;
        }
        
        void outPoint(string what, Point point) {
        	cout << what << "x: " << point.x << "; y: " << point.y << endl;
        }
        void outBorder(Border border) {
			cout << "Товщина лінії: " << border.width << ", " << "тип лінії: " << border.type << ", ";
			this->outColor(border.RGB);
		}
		void outColor(colorRGB color) {
			cout << "r: " << color.r << ", g: " << color.g << ", b: " << color.b << endl;
		}
        
        void outRectangleInfo(Rectangle * figure) {
        	this->outPoint("Верхня ліва точка: ", figure->getTopLeft());
        	this->outPoint("Нижня права точка: ", figure->getBottomRight());
        	this->outBorder(figure->getBorder());
		}
		void outParallelogramInfo(Parallelogram * figure) {
        	
		}
		void outZigzagInfo(Zigzag * figure) {
        	
		}
		
		void outEmptyCurrentFigure(bool *wrongCommand) {
			cout << "Ви не обрали фігуру" << endl;
			*wrongCommand = true;
		}
};
#endif
