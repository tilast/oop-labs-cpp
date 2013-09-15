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
	bool exit = false, excessiveSymbol = false, wrongCommand = false;
    
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
	                vector<Point> zigzagPoints;
	                for(int i = 0; i < howMuchPoints; i++) {
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

                    currentFigure = storage->addZigzag(howMuchPoints, zigzagPoints, border);

                    console->outFigureId(currentFigure);
                } else if(!commands[2].compare("group")) {
                    if(currentFigure != NULL) {
                        if(currentGroup == NULL) {
                            currentGroup = storage->addGroup();
                            console->outId(currentGroup->getId(), "групи");
                            excessiveSymbol = true;
                        }

                        currentGroup->add(currentFigure);
                    } else {
                        console->outEmptyCurrentFigure(&excessiveSymbol);
                    }
                } else {
                    wrongCommand = true;
                }
            }
            else if(!commands[1].compare("group")) {
            	currentGroup = storage->addGroup();
                console->outId(currentGroup->getId(), "групи");
                excessiveSymbol = true;
            } else {
                wrongCommand = true;
            }
        } else if(!commands[0].compare("get")) {
            if(!commands[1].compare("figure")) {
                if(!commands[2].compare("count")) {
                    cout << storage->getAmount() << endl;
                    excessiveSymbol = true;
                } else if(!commands[2].compare("id")) {
                	int id = console->getId();
                    currentFigure = storage->find(id);
                    if(!currentFigure) {
                        console->outEmptyCurrentFigure();
                    }
                } else if(!commands[2].compare("info")) {
                	if(currentFigure) {
                		console->outFigureInfo(currentFigure, &excessiveSymbol);
                	} else {
                		console->outEmptyCurrentFigure(&excessiveSymbol);
                	}
                }
            } else if(!commands[1].compare("group")) {
                if(!commands[2].compare("id")) {
                    int id = console->getId();
                    currentGroup = storage->findGroup(id);
                    if(currentGroup == NULL) {
                        console->outEmptyCurrentGroup(&excessiveSymbol);
                    }
                } else if(!commands[2].compare("figures")) {
                    console->outGroupFigures(currentGroup->getGroup());
                }
            } else {
                wrongCommand = true;
            }
        } else if(!commands[0].compare("do")) {
			if(!commands[1].compare("figure") && currentFigure != NULL) {
        		if(!commands[2].compare("topLeft")) {
        			console->outTopLeft();
                    Point topLeft = console->getPoint();
                    currentFigure->setTopLeft(topLeft);
        		} else if(!commands[2].compare("bottomRight")) {
                    console->outBottomRight();
                    Point bottomRight = console->getPoint();
                    currentFigure->setBottomRight(bottomRight);
        		} else if(!commands[2].compare("border")) {
                    Border border = console->getBorder();
                    currentFigure->setBorder(border);
        		} else if(!commands[2].compare("background") && currentFigure->getType() != 3) {
        			console->outBackground();
                    colorRGB color = console->getRGB();
                    currentFigure->setBackground(color);
        		} else if(!commands[2].compare("controlPoint") && currentFigure->getType() == 2) {
        			double cp = console->getControlPoint();
                    ((Parallelogram*)currentFigure)->setControlPoint(cp);
        		} else if(!commands[2].compare("points") && currentFigure->getType() == 3) {
        			if(!commands[3].compare("resize")) {
        				console->outHowMuchPoints();
                        int howMuchPoints = console->getInt();
                        int howMuchPointsNeedToBeAdded = ((Zigzag*)currentFigure)->resize(howMuchPoints);
                        Point tmpPoint;
                        for(int i = 0; i < howMuchPointsNeedToBeAdded; i++) {
                            tmpPoint = console->getPoint();
                            ((Zigzag*)currentFigure)->addPoint(tmpPoint);
                            console->outIgnore(1);
                        }
        			} else {
        				wrongCommand = true;
        			}
        		} else if(!commands[2].compare("remove")) {
    				console->outRemoveFigure(currentFigure);
    				storage->remove(currentFigure->getId());
    				currentFigure = NULL;
    				console->outRemoveFigureSucces();
    				console->outIgnore(3);
        		} else {
                    wrongCommand = true;
                }
			} else if(currentFigure == NULL) {
                console->outEmptyCurrentFigure(&excessiveSymbol);
            } else if(!commands[1].compare("group") && currentGroup != NULL) {
                if(!commands[2].compare("remove")) {
                    storage->removeGroup(currentGroup->getId());
                }
            } else if(currentGroup == NULL) {
                console->outEmptyCurrentGroup(&excessiveSymbol);
            } else {
                wrongCommand = true;
            }
        } else if(!commands[0].compare("exit")) {
            exit = true;
            break;
        } else {
            wrongCommand = true;
        }

        if(wrongCommand) {
            console->outWrongCommand(command, &excessiveSymbol);
            wrongCommand = false;
        }

        if(!excessiveSymbol) {
        	console->outIgnore(1);
        } else {
        	excessiveSymbol = false;
        }
    }
    
    return 0;
}