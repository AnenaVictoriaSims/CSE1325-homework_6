#ifndef __HEAD_H
#define __HEAD_H

#include "robotParts.h"
//INHERITS FROM ROBOTPARTS
class Head : public RobotParts
{
public:
  Head()
  {
    
  };
 	Head(string n, int p, string t, double w, double c, string d) : RobotParts(n, p, t, w, c, d){};
 	void displayHeads();
  void saveHeadToFile(fstream& myFile);
  void saveHeadToProgramFile(fstream& myFile);     // save head to a separate file, so that program can retrieve data later
};
#endif
