#ifndef __TORSO_H
#define __TORSO_H
#include "robotParts.h"
#include "std_lib_facilities.h"

class Torso : public RobotParts
{
private:
  int batteryCompartments;
public:
  Torso(string n, int p, string t, double w, double c, string d, int b) : RobotParts(n, p, t, w, c, d){
    batteryCompartments = b;
  };
  void setBatteryCompartments(int b);
  int getBatteryCompartments();
  Torso()
  {
    batteryCompartments = -1;
  }
  //friend ostream &operator<<(ostream &output, const Torso &t);
  void displayTorso(ostream &output, Torso &t);
  void displayTorso();
  void saveTorsoToFile(fstream& myFile);
  void saveTorsoToProgramFile(fstream& myFile);
};

#endif
