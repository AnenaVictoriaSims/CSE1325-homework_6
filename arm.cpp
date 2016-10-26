#include "std_lib_facilities.h"
#include "arm.h"
#include <fstream>

void Arm::setPowerConsumed(double power){
  powerConsumed = power;
}
double Arm::getPowerConsumed(){
  return powerConsumed;
}
void Arm::displayArm()
{
  cout << "\nName: " << RobotParts::getName() << endl;
  cout << "Part #: " << RobotParts::getPartNumber() << endl;
  cout << "Type: " << RobotParts::getType() << endl;
  cout << "Weight: " << RobotParts::getWeight() << endl;
  cout << "Cost: " << RobotParts::getCost() << endl;
  cout << "Description: " << RobotParts::getDescription() << endl;
  cout << "Power Consumed: " << getPowerConsumed() << endl;
}

void Arm::saveArmToFile(fstream& myFile)
{
  myFile << "\nName: " << RobotParts::getName() << endl;
  myFile << "Part #: " << RobotParts::getPartNumber() << endl;
  myFile << "Type: " << RobotParts::getType() << endl;
  myFile << "Weight: " << RobotParts::getWeight() << endl;
  myFile << "Cost: " << RobotParts::getCost() << endl;
  myFile << "Description: " << RobotParts::getDescription() << endl;
  myFile << "Power Consumed: " << getPowerConsumed() << endl;
}
void Arm::saveArmToProgramFile(fstream& myFile)       // save all to a file that only this program can read from to retrieve data
{
  myFile << "#" << endl;            // # is used to figure out when to start and stop grabbing data
  myFile << RobotParts::getType() << endl;
  myFile << RobotParts::getPartNumber() << endl;
  myFile << RobotParts::getName() << endl;
  myFile << RobotParts::getWeight() << endl;
  myFile << RobotParts::getCost() << endl;
  myFile << RobotParts::getDescription() << endl;
  myFile << getPowerConsumed() << endl;
}
