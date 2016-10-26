#ifndef __BATTERY_H
#define __BATTERY_H
#include "robotParts.h"

class Battery : public RobotParts
{
private:
  double energyContained;
  
public:
  Battery(string n, int p, string t, double w, double c, string d, double energy) : RobotParts(n, p, t, w, c, d){
    energyContained = energy;
  };
  void setEnergyContained(double energy);
  double getEnergyContained();
  void displayBattery();
  void saveBatteryToFile(fstream& myFile);
  void saveBatteryToProgramFile(fstream& myFile);
};
#endif
