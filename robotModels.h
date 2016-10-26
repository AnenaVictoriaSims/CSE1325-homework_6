#ifndef __CREATEROBOTMODELS_H
#define __CREATEROBOTMODELS_H

#include "createRobotParts.h"
class RobotModels
{
  friend class Orders;
private:
  struct model
 	{
    string modelName;
    string modelNumber;
    double modelPrice;
    Torso torso;
    Locomotor locomotor;
    Head head;
    vector<Arm> arms;
    vector<int> batteries;
 	};
 	vector <model> allModel;
 	int armSize;
 	int batterySize;
 	vector<double> partsCost;
 	double totalPartsCost;
  vector<int> fileIndexes;        // these indexes are store to a file for later use to access data
public:
  RobotModels();
  void createRobotModels(CreateRobotParts&);
  void displayRobotModel();
  double getTotalPartsCost();
  void calculateTotalPartsCost();
  void display(int index);
  double getModelPrice(int i);
  void saveModel();
  void saveProgramModel();
  void retrieveModel(CreateRobotParts &p);
  
};
inline double RobotModels::getTotalPartsCost()
{
  return totalPartsCost;
}
#endif
