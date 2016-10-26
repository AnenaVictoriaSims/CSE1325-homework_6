#ifndef __ARM_H
#define __ARM_H
#include "robotParts.h"

class Arm : public RobotParts
{
private:
  double powerConsumed;
public:
  Arm()
  {
    
  };
  Arm(string n, int p, string t, double w, double c, string d, double power) : RobotParts(n, p, t, w, c, d){
    powerConsumed = power;
  };
  void setPowerConsumed(double power);
  double getPowerConsumed();
  void displayArm();
  void saveArmToFile(fstream& myFile);
  void saveArmToProgramFile(fstream& myFile);
};
#endif
