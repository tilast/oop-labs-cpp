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
			cout << "�:" << endl;
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

            cout << "���������� �������. ������ �������: " << endl;
            cin >> tmp.width;
            cout << "������ ���: " << endl;
            cin >> tmp.type;
            cout << "������ ����: " << endl;
            tmp.RGB = this->getRGB();

            return tmp;
        }
        int getId() {
        	int id = -1;
        	cout << "������ id: " << endl;
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
			cout << "��� ��� ���������� ��������� �������� ��������" << endl;
		}
		void outInputCommand() {
			cout << "������ �������" << endl;
		}
		
		void outWrongCommand(string command, bool *wrongCommand) {
            cout << "������ ������� '" << command << "'" << endl;
            *wrongCommand = true;
        }
		
		void outControlPoint() {
			cout << "������ ���������� �����" << endl;
		}

        void outTopLeft() {
            cout << "������ ���������� ������� ��� �����: " << endl;
        }

        void outBottomRight() {
            cout << "������ ���������� ����� ������ �����: " << endl;
        }
        void outNeedBorder() {
            cout << "������� �������� �������?(1/0)" << endl;
        }
        void outNeedBackground() {
            cout << "������� �������� ����?(1/0)" << endl;
        }
        void outHowMuchPoints() {
        	cout << "������ ����� � �������?" << endl;
        }
        
        void outIgnore(int amount) {
        	cin.ignore(amount);
        }
        void outIgnoreNL() {
        	cin.ignore('\n');
        }
        void outFigureId(Figure * figure) {
        	cout << "ID ������: " << figure->getId() << endl;
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
        			cout << "��������� ������" << endl;
        	}
        	
        	*excessiveSymbol = true;
        }
        
        void outPoint(string what, Point point) {
        	cout << what << "x: " << point.x << "; y: " << point.y << endl;
        }
        void outBorder(Border border) {
			cout << "������� ��: " << border.width << ", " << "��� ��: " << border.type << ", ";
			this->outColor(border.RGB);
		}
		void outColor(colorRGB color) {
			cout << "r: " << color.r << ", g: " << color.g << ", b: " << color.b << endl;
		}
        
        void outRectangleInfo(Rectangle * figure) {
        	this->outPoint("������ ��� �����: ", figure->getTopLeft());
        	this->outPoint("����� ����� �����: ", figure->getBottomRight());
        	this->outBorder(figure->getBorder());
		}
		void outParallelogramInfo(Parallelogram * figure) {
        	
		}
		void outZigzagInfo(Zigzag * figure) {
        	
		}
		
		void outEmptyCurrentFigure(bool *wrongCommand) {
			cout << "�� �� ������ ������" << endl;
			*wrongCommand = true;
		}
};
#endif
