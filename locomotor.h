#ifndef __LOCOMOTOR_H
#define __LOCOMOTOR_H
#include "robotParts.h"

class Locomotor : public RobotParts
{
private:
  double powerConsumed;
  int maxSpeed;
public:
  Locomotor()
  {
    
  };
  Locomotor(string n, int p, string t, double w, double c, string d, double power, int speed) : RobotParts(n, p, t, w, c, d){
    powerConsumed = power;
    maxSpeed = speed;
  };
  void setPowerConsumed(double power);
  double getPowerConsumed();
  void setMaxSpeed(int speed);
  int getMaxSpeed();
  void displayLocomotor();
  void saveLocomotorToFile(fstream& myFile);
  void saveLocomotorToProgramFile(fstream& myFile);
};
#endif
