 #ifndef __ROBOTPARTS_H
 #define __ROBOTPARTS_H

//BASE CLASS FOR DIFFERENT ROBOT PARTS. EVERYTHING IN HERE IS GOING TO BE INHERITED TO THE INDIVUAL PART NAMES
 class RobotParts
{
   protected:
   	string name;
   	int partNumber;
   	string type;
   	double weight;
   	double cost;
   	string description;

   public:
   	RobotParts(string n, int p, string t, double w, double c, string d);
   	RobotParts();
   	void setName(string n);
   	void setPartNumber(int p);
   	void setType(string t);
   	void setWeight(double w);
   	void setCost(double c);
   	void setDescription(string d);
   	string getName();
   	int getPartNumber();
   	string getType();
   	double getWeight();
   	double getCost();
   	string getDescription();

 };
 #endif
