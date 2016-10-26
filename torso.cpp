#include "std_lib_facilities.h"
#include "torso.h"
void Torso::setBatteryCompartments(int b){
  batteryCompartments = b;
}
int Torso::getBatteryCompartments(){
  return batteryCompartments;
}
ostream &operator<<(ostream &output, Torso &t)
{
  output << "Torso Name: " << t.getName() << endl;
  output << "Torso Part #: " << t.getPartNumber() << endl;
  output << "Torso Type: " << t.getType() << endl;
  output << "Torso Weight: " << t.getWeight() << endl;
  output << "Torso Cost: " << t.getCost() << endl;
  output << "Torso Description: " << t.getDescription() << endl;
  output << "Torso Battery Compartments: " << t.getBatteryCompartments() << endl;
  
}
void Torso::displayTorso(ostream &output, Torso &t)
{
  output << t << endl;
}
void Torso::displayTorso()
{
  cout << "\nName: " << RobotParts::getName() << endl;
  cout << "Part #: " << RobotParts::getPartNumber() << endl;
  cout << "Type: " << RobotParts::getType() << endl;
  cout << "Weight: " << RobotParts::getWeight() << endl;
  cout << "Cost: " << RobotParts::getCost() << endl;
  cout << "Description: " << RobotParts::getDescription() << endl;
  cout << "Battery Compartments: " << getBatteryCompartments() << endl;
}
void Torso::saveTorsoToFile(fstream& myFile)
{
  myFile << "\nName: " << RobotParts::getName() << endl;
  myFile << "Part #: " << RobotParts::getPartNumber() << endl;
  myFile << "Type: " << RobotParts::getType() << endl;
  myFile << "Weight: " << RobotParts::getWeight() << endl;
  myFile << "Cost: " << RobotParts::getCost() << endl;
  myFile << "Description: " << RobotParts::getDescription() << endl;
  myFile << "Battery Compartments: " << getBatteryCompartments() << endl;
}
void Torso::saveTorsoToProgramFile(fstream& myFile)       // save all to a file that only this program can read from to retrieve data
{
  myFile << "#" << endl;            // # is used to figure out when to start and stop grabbing data
  myFile << RobotParts::getType() << endl;
  myFile << RobotParts::getPartNumber() << endl;
  myFile << RobotParts::getName() << endl;
  myFile << RobotParts::getWeight() << endl;
  myFile << RobotParts::getCost() << endl;
  myFile << RobotParts::getDescription() << endl;
  myFile << getBatteryCompartments() << endl;
}
