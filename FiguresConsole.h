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
            double tmp;
            cin >> tmp;
            
            while(cin.fail()) {
                cin.clear();
                cin.ignore(100000, '\n');
                cin >> tmp;
            }

            return tmp;
        }
        
        int getInt() {
            int tmp;
            cin >> tmp;

            while(cin.fail()) {
                cin.clear();
                cin.ignore(100000, '\n');
                cin >> tmp;
            }
            
            return tmp;
        }

        Point getPoint() {
            Point point;
            cout << "Х:" << endl;
            cin >> point.x;
            cout << "Y:" << endl;
            cin >> point.y;

            while(cin.fail()) {
                cin.clear();
                cin.ignore(100000, '\n');
                cout << "Х:" << endl;
                cin >> point.x;
                cout << "Y:" << endl;
                cin >> point.y;
            }
            /*
            cin.clear();
            cin.ignore(1);*/
            
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


            while(cin.fail()) {
                cin.clear();
                cin.ignore(100000, '\n');
                cout << "r: ";
                cin >> color.r;
                cout << "g: ";
                cin >> color.g;
                cout << "b: ";
                cin >> color.b;
            }

            return color;
        }

        Border getBorder() {
            Border tmp;

            cout << "Властивості границь. Введіть товщину: " << endl;
            cin >> tmp.width;

            while(cin.fail()) {
                cin.clear();
                cin.ignore(100000, '\n');
                cin >> tmp.width;                
            }

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
            
            while(cin.fail()) {
                cin.clear();
                cin.ignore(100000, '\n');
                cin >> id;                
            }

            return id;
        }
        
        double getControlPoint() {
            cout << "X: " << endl;
            double point = this->getDouble();
            
            return point;
        }
        void outHello() {
            cout << "Вас вітає консольний векторний редактор примітивів" << endl;
        }
        void outInputCommand() {
            cout << "Введіть команду" << endl;
        }

        void outGetNumber() {
            cout << "Введіть номер: " << endl;
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
        
        void outBackground() {
            cout << "Введіть колір тла: " << endl;
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
            this->outFigureId(figure);
            if(figure->getType() != 3) {
                this->outPoint("Верхня ліва точка: ", figure->getTopLeft());
                this->outPoint("Нижня права точка: ", figure->getBottomRight());
            }
            this->outBorder(figure->getBorder());
            
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
            cout << "Колір тла: ";
            this->outColor(figure->getBackground());
        }
        void outParallelogramInfo(Parallelogram * figure) {
            this->outPoint("Контрольна точка: ", figure->getControlPoint());
            cout << "Колір тла: ";
            this->outColor(figure->getBackground());
        }
        void outZigzagInfo(Zigzag * figure) {
            cout << "Точки: " << endl;
            vector<Point> points = figure->getPoints();
            for(int i = 0; i < points.size(); i++) {
                this->outPoint("", points[i]);
            }
        }
        void outEmptyCurrentGroup(bool *wrongCommand) {
            cout << "Ви не обрали групу" << endl;
            *wrongCommand = true;
        }
        void outEmptyCurrentFigure(bool *wrongCommand) {
            cout << "Ви не обрали фігуру" << endl;
            *wrongCommand = true;
        }
        void outEmptyCurrentFigure() {
            cout << "Ви не обрали фігуру" << endl;
        }
        void outRemoveFigure(Figure * figure) {
            cout << "Видаляємо фігуру з id: " << figure->getId() << "..." << endl;
        }
        void outRemoveFigureSucces() {
            cout << "Видалено" << endl;
        }

        void outId(int id, string type) {
            cout << "ID " << type << ": " << id << endl;
        }

        void outGroupFigures(vector<Figure*> figures) {
            for(int i = 0; i < figures.size(); i++) {
                cout << figures[i]->getId() << " ";
            }

            cout << endl;
        }
};
#endif