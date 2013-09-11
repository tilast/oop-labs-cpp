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
    Figure * currentFigure = NULL;
    FiguresGroup * currentGroup = NULL;
    // variable for working loop
	bool exit = false, excessiveSymbol = false;
    
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
        
        if(commands.size() < 4) {
        	for(int i = commands.size() -1; i < 4; i++) {
        		commands.push_back("");
        	}
        }

		// choose command
        if(!commands[0].compare("add")) {
            if(!commands[1].compare("figure")) {
				if(!commands[2].compare("rectangle")) {
					console->outTopLeft();
        	        Point topLeft = console->getPoint();
    	            console->outBottomRight();
	                Point bottomRight = console->getPoint();
	                
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

                    currentFigure = storage->addRectangle(topLeft, bottomRight, border, background);

                    console->outFigureId(currentFigure);
                }
                else if(!commands[2].compare("parallelogram")) {
                	console->outTopLeft();
        	        Point topLeft = console->getPoint();
    	            console->outBottomRight();
	                Point bottomRight = console->getPoint();
	                
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

                    currentFigure = storage->addParallelogram(topLeft, bottomRight, controlPoint, border, background);

                    console->outFigureId(currentFigure);
                } else if(!commands[2].compare("zigzag")) {
                	console->outHowMuchPoints();
                	int howMuchPoints = console->getInt();
                	
					console->outTopLeft();
        	        Point topLeft = console->getPoint();
    	            console->outBottomRight();
	                Point bottomRight = console->getPoint();
	                
	                vector<Point> zigzagPoints;
	                for(int i = 0; i < howMuchPoints - 2; i++) {
	                	zigzagPoints.push_back(console->getPoint());
	                	console->outIgnore(1);
	                }
                	
					bool needBorder = false;
					
                    console->outNeedBorder();
                    cin >> needBorder;
                    Border border;
                    if(needBorder) {
                        border = console->getBorder();
                    }

                    currentFigure = storage->addZigzag(topLeft, bottomRight, howMuchPoints, zigzagPoints, border);

                    console->outFigureId(currentFigure);
                } else {
                	console->outWrongCommand(command, &excessiveSymbol);
                }
            }
            else if(!commands[1].compare("group")) {
            	currentGroup = storage->addGroup();
            } else {
            	console->outWrongCommand(command, &excessiveSymbol);
            }
        } else if(!commands[0].compare("get")) {
            if(!commands[1].compare("figure")) {
                if(!commands[2].compare("count")) {
                    cout << storage->getAmount() << endl;
                } else if(!commands[2].compare("id")) {
                	int id = console->getId();
                    currentFigure = storage->find(id);
                } else if(!commands[2].compare("info")) {
                	if(currentFigure) {
                		console->outFigureInfo(currentFigure, &excessiveSymbol);
                	} else {
                		console->outEmptyCurrentFigure(&excessiveSymbol);
                	}
                }
            }
        } else if(!commands[0].compare("exit")) {
            exit = true;
            break;
        } else {
            console->outWrongCommand(command, &excessiveSymbol);
        }

        if(!excessiveSymbol) {
        	console->outIgnore(1);
        } else {
        	excessiveSymbol = false;
        }
    }
    
    return 0;
}

