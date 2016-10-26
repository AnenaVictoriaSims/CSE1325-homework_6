#include "std_lib_facilities.h"
#include "robotParts.h"

    RobotParts::RobotParts()
    {
        name = "None";
        partNumber = -1;
        type = "None";
        weight = 0.0;
        cost = 0.0;
        description = "None";

    }
	RobotParts::RobotParts(string n, int p, string t, double w, double c, string d){
   		name = n;
   		partNumber = p;
   		type = t;
   		weight = w;
   		cost = c;
   		description = d;
   	}

   	void RobotParts::setName(string n){
   		name =n;
   	}
   	void RobotParts::setPartNumber(int p){
   		partNumber = p;
   	}
   	void RobotParts::setType(string t){
   		type = t;
   	}
   	void RobotParts::setWeight(double w){
   		weight =w;
   	}
   	void RobotParts::setCost(double c){
   		cost = c;
   	}
   	void RobotParts::setDescription(string d){
   		description = d;
   	}
   	string RobotParts::getName(){
   		return name;
   	}
   	int RobotParts::getPartNumber(){
   		return partNumber;
   	}
   	string RobotParts::getType(){
   		return type;
   	}
   	double RobotParts::getWeight(){
   		return weight;
   	}
   	double RobotParts::getCost(){
   		return cost;
   	}
   	string RobotParts::getDescription(){
   		return description;
   	}

