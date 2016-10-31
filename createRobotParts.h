#ifndef __CREATEROBOTPARTS_H
#define __CREATEROBOTPARTS_H

#include "std_lib_facilities.h"
#include "robotParts.h"
#include "head.h"
#include "torso.h"
#include "arm.h"
#include "locomotor.h"
#include "battery.h"
//INHERITS FROM ROBOTPARTS
class CreateRobotParts
{
private:
 	vector<Head> allHeads;
 	vector<Torso> allTorsos;
 	vector<Arm> allArms;
 	vector<Locomotor> allLocomotors;
 	vector<Battery> allBatteries;
public:
  CreateRobotParts() {}
 	void createHead();
 	void createTorso();
 	void createArm();
 	void createLocomotor();
 	void createBattery();
 	void showHeads();
 	void showTorsos();
 	void showArms();
 	void showLocomotors();
 	void showBatteries();
 	Torso getTorsoAt(int i);
 	Head getHeadAt(int i);
 	Arm getArmAt(int i);
 	Locomotor getLocomotorAt(int i);
 	Battery getBatteryAt(int i);
 	int getSizeOfHead();
 	int getSizeOfTorso();
 	int getSizeOfArm();
 	int getSizeOfLocomotor();
 	int getSizeOfBattery();
 	void displayParts();
  void saveParts();
  void saveProgramParts();    // this method will store information only for the the program to retrieve data from
  void retrieveParts();       // method retrieve the data that is saved in savedProgramParts()
  
};

inline Torso CreateRobotParts::getTorsoAt(int i)
{
  return allTorsos.at(i);
}
inline Head CreateRobotParts::getHeadAt(int i)
{
  return allHeads.at(i);
}
inline Arm CreateRobotParts::getArmAt(int i)
{
  return allArms.at(i);
}
inline Locomotor CreateRobotParts::getLocomotorAt(int i)
{
  return allLocomotors.at(i);
}
inline Battery CreateRobotParts::getBatteryAt(int i)
{
  return allBatteries.at(i);
}
inline int CreateRobotParts::getSizeOfHead()
{
  return allHeads.size();
}
inline int CreateRobotParts::getSizeOfTorso()
{
  return allTorsos.size();
}
inline int CreateRobotParts::getSizeOfArm()
{
  return allArms.size();
}
inline int CreateRobotParts::getSizeOfLocomotor()
{
  return allLocomotors.size();
}
inline int CreateRobotParts::getSizeOfBattery()
{
  return allBatteries.size();
}

#endif
