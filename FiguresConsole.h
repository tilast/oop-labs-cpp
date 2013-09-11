#ifndef FiguresConsole_h_
#define FiguresConsole_h_
/**
* class FiguresConsole
* class for work with console
*/
class FiguresConsole {
    public :

        double getDouble() {
            double tpm;
            cin >> tpm;

            return tpm;
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
};
#endif
