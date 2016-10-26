#include "std_lib_facilities.h"
#include "createRobotParts.h"

/*THESE ARE USED TO CREATE PARTS FOR THE ROBOT AND ARE STORED IN VECTOR OF CLASSES*/
void CreateRobotParts::createHead()
{
  string name, type, description;
  int partNumber;
  double weight, cost;
  
   cin.ignore(1000, '\n');
   cout <<"******* CREATING HEAD **********\n";
   cout << "Name?: ";
   getline(cin, name);
   cout<< "Part Number?: ";
   cin >> partNumber;
   //Error handling
   while(cin.fail()){
   cin.clear();
   cin.ignore(1000, '\n');
   cerr <<"Not a valid answer. Try again.\n";
   cout <<"Part Number?: ";
   cin >> partNumber;
   }
   cin.ignore(1000, '\n');
   //cout <<"Type?: ";
   //getline(cin, type);
   type = "Head";
   cout<<"Weight?: ";
   cin >> weight;
   while(cin.fail()){
   cin.clear();
   cin.ignore(1000, '\n');
   cerr <<"Not a valid answer. Try again.\n";
   cout <<"Weight?: ";
   cin >> weight;
   }
   cin.ignore(1000, '\n');
   cout <<"Cost?: ";
   cin >> cost;
   while(cin.fail()){
   cin.clear();
   cin.ignore(1000, '\n');
   cerr <<"Not a valid answer. Try again.\n";
   cout <<"Cost?: ";
   cin >> cost;
   }
   cin.ignore(1000, '\n');
   cout <<"Description?: ";
   getline(cin, description);
   //PUT ALL THESE ANSWERS INTO THE VECTOR allHeads.
   Head h(name, partNumber, type, weight, cost, description);

//  Head h("HEADFDSF", 123, "Head", 4.5, 100, "fsaf");
  allHeads.push_back(h);
  
}
void CreateRobotParts::createTorso(){
  string name, type, description;
  int partNumber, batteries;
  double weight, cost;
  
   cin.ignore();
   cout <<"******* CREATING TORSO **********\n";
   cout << "Name?: ";
   getline(cin, name);
   cout<< "Part Number?: ";
   cin >> partNumber;
   while(cin.fail()){
   cin.clear();
   cin.ignore(1000, '\n');
   cerr <<"Not a valid answer. Try again.\n";
   cout <<"Part Number?: ";
   cin >> partNumber;
   }
   cin.ignore(1000, '\n');
   type = "Torso";
   cout<<"Weight?: ";
   cin >> weight;
   cin.ignore();
   cout <<"Cost?: ";
   cin >> cost;
   while(cin.fail()){
   cin.clear();
   cin.ignore(1000, '\n');
   cerr <<"Not a valid answer. Try again.\n";
   cout <<"Cost?: ";
   cin >> cost;
   }
   cin.ignore();
   cout <<"Descritpion?: ";
   getline(cin, description);
   cout <<"How many battery compartment(s) does torso have (1, 2, or 3)?: ";
   cin >> batteries;
   //ERROR HANDLING OF STRING INPUT
   while(cin.fail()){
   cin.clear();
   cin.ignore(1000, '\n');
   cerr <<"Not a valid answer. Try again.\n";
   cout <<"How many battery compartment(s) does torso have (1, 2, or 3)?: ";
   cin >> batteries;
   while(batteries < 1 || batteries > 3)
   {
   cout << batteries << " is out of range!" << endl;
   cout <<"How many battery compartment(s) does torso have (1, 2, or 3)?: ";
   cin >> batteries;
   }
   }
   cin.ignore();
   Torso t(name, partNumber, type, weight, cost, description, batteries);
  
  //Torso t("TOST", 4233243, "Torso", 333, 200, "sdfas",3);
  allTorsos.push_back(t);
}
void CreateRobotParts::createArm(){
  string name, type, description;
  int partNumber;
  double weight, cost, powerConsumed;
  
   cin.ignore();
   cout <<"******* CREATING Arm **********\n";
   cout << "Name?: ";
   getline(cin, name);
   cout<< "Part Number?: ";
   cin >> partNumber;
   while(cin.fail()){
   cin.clear();
   cin.ignore(1000, '\n');
   cerr <<"Not a valid answer. Try again.\n";
   cout <<"Part Number?: ";
   cin >> partNumber;
   }
   cin.ignore();
   type = "Arm";
   cout<<"Weight?: ";
   cin >> weight;
   while(cin.fail()){
   cin.clear();
   cin.ignore(1000, '\n');
   cerr <<"Not a valid answer. Try again.\n";
   cout <<"Weight?: ";
   cin >> weight;
   }
   cin.ignore();
   cout <<"Cost?: ";
   cin >> cost;
   while(cin.fail()){
   cin.clear();
   cin.ignore(1000, '\n');
   cerr <<"Not a valid answer. Try again.\n";
   cout <<"Cost?: ";
   cin >> cost;
   }
   cin.ignore();
   cout <<"Description?: ";
   getline(cin, description);
   cout <<"Power consumed?: ";
   cin >> powerConsumed;
   while(cin.fail()){
   cin.clear();
   cin.ignore(1000, '\n');
   cerr <<"Not a valid answer. Try again.\n";
   cout <<"Power Consumed?: ";
   cin >> powerConsumed;
   }
   cin.ignore();
   Arm a(name, partNumber, type, weight, cost, description, powerConsumed);
  
  //Arm a("ARMSSSZZZ", 423, "Arm", 777.6, 300, "thh", 444);
  allArms.push_back(a);
}
void CreateRobotParts::createLocomotor(){
  string name, type, description;
  int partNumber, maxSpeed;
  double weight, cost, powerConsumed;
  cin.ignore();
   cout <<"******* CREATING LOCOMOTOR **********\n";
   cout << "Name?: ";
   getline(cin, name);
   cout<< "Part Number?: ";
   cin >> partNumber;
   while(cin.fail()){
   cin.clear();
   cin.ignore(1000, '\n');
   cerr <<"Not a valid answer. Try again.\n";
   cout <<"Part Number?: ";
   cin >> partNumber;
   }
   type = "Locomotor";
   cout<<"Weight?: ";
   cin >> weight;
   while(cin.fail()){
   cin.clear();
   cin.ignore(1000, '\n');
   cerr <<"Not a valid answer. Try again.\n";
   cout <<"Weight?: ";
   cin >> weight;
   }
   cin.ignore();
   cout <<"Cost?: ";
   cin >> cost;
   while(cin.fail()){
   cin.clear();
   cin.ignore(1000, '\n');
   cerr <<"Not a valid answer. Try again.\n";
   cout <<"Cost?: ";
   cin >> cost;
   }
   cin.ignore();
   cout <<"Description?: ";
   getline(cin, description);
   cout <<"Power Consumed?: ";
   cin >> powerConsumed;
   while(cin.fail()){
   cin.clear();
   cin.ignore(1000, '\n');
   cerr <<"Not a valid answer. Try again.\n";
   cout <<"Power Consumed?: ";
   cin >> powerConsumed;
   }
   cin.ignore();
   cout <<"Max Speed?: ";
   cin >> maxSpeed;
   while(cin.fail()){
   cin.clear();
   cin.ignore(1000, '\n');
   cerr <<"Not a valid answer. Try again.\n";
   cout <<"Max Speed?: ";
   cin >> maxSpeed;
   }
   cin.ignore();
   Locomotor l(name, partNumber, type, weight, cost, description, powerConsumed, maxSpeed);
  
  //Locomotor l("LOCOO", 234, "Locomotor", 3, 150, "poi", 123, 321);
  allLocomotors.push_back(l);
}
void CreateRobotParts::createBattery(){
  string name, type, description;
  int partNumber, maxSpeed;
  double weight, cost, energyContained;
  cin.ignore();
   cout <<"******* CREATING BATTERY **********\n";
   cout << "Name?: ";
   getline(cin, name);
   cout<< "Part Number?: ";
   cin >> partNumber;
   while(cin.fail()){
   cin.clear();
   cin.ignore(1000, '\n');
   cerr <<"Not a valid answer. Try again.\n";
   cout <<"Part Number?: ";
   cin >> partNumber;
   }
   cin.ignore();
   type = "Battery";
   cout<<"Weight?: ";
   cin >> weight;
   while(cin.fail()){
   cin.clear();
   cin.ignore(1000, '\n');
   cerr <<"Not a valid answer. Try again.\n";
   cout <<"Weight?: ";
   cin >> weight;
   }
   cin.ignore();
   cout <<"Cost?: ";
   cin >> cost;
   while(cin.fail()){
   cin.clear();
   cin.ignore(1000, '\n');
   cerr <<"Not a valid answer. Try again.\n";
   cout <<"Cost?: ";
   cin >> cost;
   }
   cin.ignore();
   cout <<"Description?: ";
   getline(cin, description);
   cout <<"Energy Contained?: ";
   cin >> energyContained;
   while(cin.fail()){
   cin.clear();
   cin.ignore(1000, '\n');
   cerr <<"Not a valid answer. Try again.\n";
   cout <<"Energy Contained?: ";
   cin >> energyContained;
   }
   cin.ignore();
   Battery b(name, partNumber, type, weight, cost, description, energyContained);
  
  //Battery b("BATTTSHIT", 000, "Battery", 4.4, 90, "fsaf", 234);
  allBatteries.push_back(b);
}

//TO ACCESS THE HEADS IN THE VECTOR ALLHEADS USES THE DIFFERENT GETTER FUNCTIONS EXAMPLE BELOW
//cout << allHeads.at(0).getWeight();
void CreateRobotParts::showHeads(){
  if(allHeads.size() == 0){
 			cout << "No available heads.\n";
  }
  else{
 			int i;
 			for(i=0; i < allHeads.size(); i++)
        cout <<i<<") "<< allHeads.at(i).getName()<<endl;
  }
}
void CreateRobotParts::showTorsos(){
  if(allTorsos.size() == 0){
 			cout << "No available torsos.\n";
  }
  else{
 			int i;
 			for(i=0; i < allTorsos.size(); i++)
        cout <<i<<") "<< allTorsos.at(i).getName()<<endl;
  }
}
void CreateRobotParts::showArms(){
  if(allArms.size() == 0){
 			cout << "No available arms.\n";
  }
  else{
 			int i;
 			for(i=0; i < allArms.size(); i++)
        cout <<i<<") "<<allArms.at(i).getName()<<endl;
  }
}
void CreateRobotParts::showLocomotors(){
  if(allLocomotors.size() == 0){
 			cout << "No available locomotors.\n";
  }
  else{
 			int i;
 			for(i=0; i < allLocomotors.size(); i++)
        cout <<i<<") "<<allLocomotors.at(i).getName()<<endl;
  }
}
void CreateRobotParts::showBatteries(){
  if(allBatteries.size() == 0){
 			cout << "No available batteries.\n";
  }
  else{
 			int i;
 			for(i=0; i < allBatteries.size(); i++)
        cout <<i<<") "<<allBatteries.at(i).getName()<<endl;
  }
}

void CreateRobotParts::displayParts()
{
  cout << "_______________________________________" << endl;
  cout << "\n********  Head Display ************" << endl;
  cout << "_______________________________________" << endl;
  if(allHeads.size() == 0)
    cout << "\nNo head created\n";
  else
    for(int i = 0; i < allHeads.size(); i++)
      allHeads[i].displayHeads();
  cout << "_______________________________________" << endl;
  cout << "\n********  Arm Display ************" << endl;
  cout << "_______________________________________" << endl;
  if(allArms.size() == 0)
    cout << "\nNo Arms created\n";
  else
    for(int i = 0; i < allArms.size(); i++)
      allArms[i].displayArm();
  cout << "_______________________________________" << endl;
  cout << "\n********  Torso Display ************" << endl;
  cout << "_______________________________________" << endl;
  if(allTorsos.size() == 0)
    cout << "\nNo Torso created\n";
  else
    for(int i = 0; i < allTorsos.size(); i++)
      allTorsos[i].displayTorso();
  cout << "_______________________________________" << endl;
  cout << "\n********  Locomotor Display ************" << endl;
  cout << "_______________________________________" << endl;
  if(allLocomotors.size() == 0)
    cout << "\nNo Locomotors created\n";
  else
    for(int i = 0; i < allLocomotors.size(); i++)
      allLocomotors[i].displayLocomotor();
  cout << "_______________________________________" << endl;
  cout << "\n********  Battery Display ************" << endl;
  cout << "_______________________________________" << endl;
  if(allBatteries.size() == 0)
    cout << "\nNo Battery created\n";
  else
    for(int i = 0; i < allBatteries.size(); i++)
      allBatteries[i].displayBattery();
}

void CreateRobotParts::saveParts()
{
  string fileName;
  fstream myFile;
  
  myFile.open("Robot_Parts.txt", ios::out | ios::trunc);     // write to file and append to end
  if (!myFile)       // if myFile stream is corrupted
    throw runtime_error("canít open output file " + fileName);
  
  myFile << "_______________________________________" << endl;
  myFile << "\n********  Head Display ************" << endl;
  myFile << "_______________________________________" << endl;
  if(allHeads.size() == 0)
    myFile << "\nNo head created\n";
  else
    for(int i = 0; i < allHeads.size(); i++)
      allHeads[i].saveHeadToFile(myFile);
  myFile << "_______________________________________" << endl;
  myFile << "\n********  Arm Display ************" << endl;
  myFile << "_______________________________________" << endl;
  if(allArms.size() == 0)
    myFile << "\nNo Arms created\n";
  else
    for(int i = 0; i < allArms.size(); i++)
      allArms[i].saveArmToFile(myFile);
  
  myFile << "_______________________________________" << endl;
  myFile << "\n********  Torso Display ************" << endl;
  myFile << "_______________________________________" << endl;
  if(allTorsos.size() == 0)
    myFile << "\nNo Torso created\n";
  else
    for(int i = 0; i < allTorsos.size(); i++)
      allTorsos[i].saveTorsoToFile(myFile);
  myFile << "_______________________________________" << endl;
  myFile << "\n********  Locomotor Display ************" << endl;
  myFile << "_______________________________________" << endl;
  if(allLocomotors.size() == 0)
    myFile << "\nNo Locomotors created\n";
  else
    for(int i = 0; i < allLocomotors.size(); i++)
      allLocomotors[i].saveLocomotorToFile(myFile);
  myFile << "_______________________________________" << endl;
  myFile << "\n********  Battery Display ************" << endl;
  myFile << "_______________________________________" << endl;
  if(allBatteries.size() == 0)
    myFile << "\nNo Battery created\n";
  else
    for(int i = 0; i < allBatteries.size(); i++)
      allBatteries[i].saveBatteryToFile(myFile);
  myFile << endl;
  myFile.close();  // close file after use
}

void CreateRobotParts::saveProgramParts()
{
  string fileName;
  fstream myFile;
  
  
  myFile.open("Parts_Program_File.txt", ios::out | ios::trunc);     // open the file to read and write from
  if (!myFile)       // if myFile stream is corrupted, throw an exception to the runtime_error
    throw runtime_error("canít open output file " + fileName);
  
  if(allHeads.size() == 0)
  {
    myFile << "#" << endl;
    myFile << "\nNo head created\n";
  }
  else
    for(int i = 0; i < allHeads.size(); i++)
      allHeads[i].saveHeadToProgramFile(myFile);
  
  
  if(allArms.size() == 0)
  {
    myFile << "#" << endl;
    myFile << "\nNo Arms created\n";
  }
  else
    for(int i = 0; i < allArms.size(); i++)
      allArms[i].saveArmToProgramFile(myFile);
  
  if(allTorsos.size() == 0)
  {
    myFile << "#" << endl;
    myFile << "\nNo Torso created\n";
  }
  else
    for(int i = 0; i < allTorsos.size(); i++)
      allTorsos[i].saveTorsoToProgramFile(myFile);
  
  if(allLocomotors.size() == 0)
  {
    myFile << "#" << endl;
    myFile << "\nNo Locomotors created\n";
  }
  else
    for(int i = 0; i < allLocomotors.size(); i++)
      allLocomotors[i].saveLocomotorToProgramFile(myFile);
  
  if(allBatteries.size() == 0)
  {
    myFile << "#" << endl;
    myFile << "\nNo Battery created\n";
  }
  else
    for(int i = 0; i < allBatteries.size(); i++)
      allBatteries[i].saveBatteryToProgramFile(myFile);
  myFile.close();  // close file after use
}
void CreateRobotParts::retrieveParts ()
{
  string line;
  ifstream readFile;
  string name;
  int partNumber;
  string type;
  double weight;
  double cost;
  string description;
  int batteries;
  double energyContained;
  double powerConsumed;
  int maxSpeed;
  
  readFile.open("Parts_Program_File.txt", ios::in);     // open the file to read from
  if (readFile)       // if myFile stream is corrupted, throw an exception to the runtime_error
  {
    while (getline(readFile, line))              // read data from the file -> Parts_Program_File.txt
    {
      if(line == "#")
        continue;                           // continue onto next line
      if(line == "Head")
      {
        type = line;
        getline(readFile, line);
        partNumber = atoi(line.c_str());    // convert string to integer and assign it partNumber
        getline(readFile, line);
        name = line;
        getline(readFile, line);
        weight = atof(line.c_str());        // convert string to double and assign it
        getline(readFile, line);
        cost = atof(line.c_str ());
        getline(readFile, line);
        description = line;
        Head h(name, partNumber, type, weight, cost, description);
        allHeads.push_back(h);
      }
      else if(line == "Torso")
      {
        type = line;
        getline(readFile, line);
        partNumber = atoi(line.c_str());        // convert string to integer and assign it partNumber
        getline(readFile, line);
        name = line;
        getline(readFile, line);
        weight = atof(line.c_str());            // convert string to double and assign it
        getline(readFile, line);
        cost = atof(line.c_str ());
        getline(readFile, line);
        description = line;
        getline(readFile, line);
        batteries = atoi(line.c_str());        // convert string to integer and assign it partNumber
        Torso t(name, partNumber, type, weight, cost, description, batteries);
        allTorsos.push_back(t);
      }
      else if(line == "Battery")
      {
        type = line;
        getline(readFile, line);
        partNumber = atoi(line.c_str());        // convert string to integer and assign it partNumber
        getline(readFile, line);
        name = line;
        getline(readFile, line);
        weight = atof(line.c_str());            // convert string to double and assign it
        getline(readFile, line);
        cost = atof(line.c_str ());
        getline(readFile, line);
        description = line;
        getline(readFile, line);
        energyContained = atof(line.c_str());
        Battery b(name, partNumber, type, weight, cost, description, energyContained);  // create a new instance of battery
        allBatteries.push_back(b);  // push it to all batteries vector
      }
      else if(line == "Arm")
      {
        type = line;
        getline(readFile, line);
        partNumber = atoi(line.c_str());        // convert string to integer and assign it partNumber
        getline(readFile, line);
        name = line;
        getline(readFile, line);
        weight = atof(line.c_str());            // convert string to double and assign it
        getline(readFile, line);
        cost = atof(line.c_str ());
        getline(readFile, line);
        description = line;
        getline(readFile, line);
        powerConsumed = atof(line.c_str());
        Arm a(name, partNumber, type, weight, cost, description, powerConsumed);  // Create new instance of arm
        allArms.push_back(a);   // push new instance of arm to allArms
        
      }
      else if (line == "Locomotor")
      {
        type = line;
        getline(readFile, line);
        partNumber = atoi(line.c_str());        // convert string to integer and assign it partNumber
        getline(readFile, line);
        name = line;
        getline(readFile, line);
        weight = atof(line.c_str());            // convert string to double and assign it
        getline(readFile, line);
        cost = atof(line.c_str ());
        getline(readFile, line);
        description = line;
        getline(readFile, line);
        powerConsumed = atof(line.c_str());
        getline(readFile, line);
        maxSpeed = atoi(line.c_str());
        Locomotor l(name, partNumber, type, weight, cost, description, powerConsumed, maxSpeed); // create new instance
        allLocomotors.push_back(l);     // push newly created locomotor to all locomotor vector
      }
      else;               // do nothing
    }
    readFile.close();       // close file after finish using
  }
  else
    cout << "There was no file to retrieve data from for robot parts." << endl;
}
