/**
* Simple Virtual Vector Graphic Editor
* @date 09.09.2013
* @author Ihor Kroosh, IASA, DA-21 <ihor.kroosh@gmail.com>
*/
#include <iostream>
#include <fstream>
#include <sstream>

#include <vector>

#include <cmath>
#include <clocale>

using namespace std;

#include "colorRGB.h"
#include "Border.h"
#include "Point.h"

#include "Figure.h"
#include "Rectangle.h"
#include "Parallelogram.h"
#include "Zigzag.h"

#include "FiguresGroup.h"
#include "FiguresStorage.h"

#include "FiguresConsole.h"

int main()
{
	// setting of locale
    setlocale(LC_ALL, "Ukrainian");
    // create objects for storage and console
	FiguresStorage* storage = new FiguresStorage();
    FiguresConsole *console = new FiguresConsole();
    // variable for working loop
	bool exit = false;
    
	console->outHello();
    console->outInputCommand();
    
	while(!exit) {
		// string for command
        string command;
        //console->outInputCommand();
        // take command
		getline(cin, command);
        
        // split string by white-space
		stringstream tmp(command);
        string tmpStr;
        vector<string> commands;

        while(!tmp.eof()) {
            getline(tmp, tmpStr, ' ');
            commands.push_back(tmpStr);
        }

		// choose command
        if(!commands[0].compare("add")) {
            if(!commands[1].compare("figure")) {
                console->outTopLeft();
                Point topLeft = console->getPoint();
                console->outBottomRight();
                Point bottomRight = console->getPoint();

				if(!commands[2].compare("rectangle")) {
                    bool needBorder = false;
                    bool needBackground = false;

                    console->outNeedBorder();
                    cin >> needBorder;
                    Border border;
                    if(needBorder) {
                        border = console->getBorder();
                    }

                    console->outNeedBackground();
                    cin >> needBackground;
                    colorRGB background;
                    if(needBackground) {
                        background = console->getRGB();
                    }

                    int id = storage->addRectangle(topLeft, bottomRight, border, background);

                    cout << "ID фігури: " << id << endl;
                }
                else if(!commands[2].compare("parallelogram")) {
                	console->outControlPoint();
                	double controlPoint = console->getControlPoint();
					
					bool needBorder = false;
                    bool needBackground = false;

                    console->outNeedBorder();
                    cin >> needBorder;
                    Border border;
                    if(needBorder) {
                        border = console->getBorder();
                    }

                    console->outNeedBackground();
                    cin >> needBackground;
                    colorRGB background;
                    if(needBackground) {
                        background = console->getRGB();
                    }

                    int id = storage->addParallelogram(topLeft, bottomRight, controlPoint, border, background);

                    cout << "ID фігури: " << id << endl;
                }
                else if(!commands[2].compare("zigzag")) {

                }
            }
            else if(!commands[1].compare("group")) {
            	FiguresGroup * group = storage->addGroup();
            }
        } else if(!commands[0].compare("get")) {
            if(!commands[1].compare("figures")) {
                if(!commands[2].compare("count")) {
                    cout << storage->getAmount() << endl;
                }
                if(!commands[2].compare("id")) {
                    int id = console->getId();
                    Figure* requiredFigure = storage->find(id);
                    cout << requiredFigure->getType() << endl;
                }
            }
        } else if(!commands[0].compare("exit")) {
            exit = true;
            break;
        } else {
            cout << "Невірна команда" << endl;
            //exit = true;
        }

        //cout << "Вийти?(1/0)" << endl;
        //cin >> exit;
        //cin.ignore(1);
    }
    
    return 0;
}

