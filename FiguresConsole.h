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
};
#endif
