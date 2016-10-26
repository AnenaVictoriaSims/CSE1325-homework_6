#include "std_lib_facilities.h"
#include "robotModels.h"

RobotModels::RobotModels()
{
  // these are the default values if it is not changed
  int armSize = 0;
 	int batterySize = 0;
 	double totalPartsCost = 0;
}
int readInput()
{
  int index;
  
  cout << "\nSelect: ";
  cin >> index;
  return index;
}
void RobotModels::createRobotModels(CreateRobotParts &p){
  
  model mdl;
  int index;
  char ch;
  
  cin.ignore();
  cout << endl;
  cout <<"What is your Model Name?: ";
  getline(cin, mdl.modelName);
  cout <<"What is your Model Number?: ";
  cin >> mdl.modelNumber;
  cin.ignore();
  
  
  cout << "\nPlease choose a head: " << endl;
  p.showHeads();
  if (p.getSizeOfHead() != 0)
  {
    index = readInput();
    mdl.head = p.getHeadAt(index);
    mdl.batteries.push_back(0);             // push_back(0) because head doesn't need a battery
    partsCost.push_back(p.getHeadAt(index).getCost());
    fileIndexes.push_back(index);
  }
  
  cout << "\nPlease choose arms: " << endl;
  int counter = 2;
  p.showArms();
  if (p.getSizeOfArm() != 0)
  {
    cout << "Select 2 arms " << endl;
    do{
      index = readInput();
      while (index < 0 || index > p.getSizeOfArm())
      {
        cout << index << " is out of range.\nTry again...\n" << endl;
        p.showArms();
        cout << "Select 2 arms " << endl;
        index = readInput();
      }
      mdl.arms.push_back(p.getArmAt(index));
      partsCost.push_back(p.getArmAt(index).getCost());
      fileIndexes.push_back(index);
      counter--;
    }while(counter > 0 && counter < 2);
    mdl.batteries.push_back(0);
  }
  
  cout << "\nPlease choose a torso: " << endl;
  p.showTorsos();
  if (p.getSizeOfTorso() != 0)
  {
    index = readInput();
    mdl.batteries.push_back(p.getTorsoAt(index).getBatteryCompartments());   // this is the number of batteries that can fit in torso
    mdl.torso = p.getTorsoAt(index);
    partsCost.push_back(p.getTorsoAt(index).getCost());
    fileIndexes.push_back(index);
  }
  
  cout << "\nPlease choose a locomotor: " << endl;
  p.showLocomotors();
  if (p.getSizeOfLocomotor() != 0)
  {
    index = readInput();
    mdl.locomotor = p.getLocomotorAt(index);
    mdl.batteries.push_back(0);
    partsCost.push_back(p.getLocomotorAt(index).getCost());
    fileIndexes.push_back(index);
    
  }
  
  
  
  /*
   cout << "Do you need battery for robot model? ";
   cin >> ch;
   if (ch == 'y' || ch == 'Y')
   {
   p.showBatteries();
   index = readInput();
   mdl.batteries = p.getBatteryAt(index);
   }
   else
   cout << "Okay...\n" << endl;
   */
  calculateTotalPartsCost();
  cout << "\nThe total cost of all components for model " << mdl.modelName << " is " << totalPartsCost << "." << endl;
  cout << "What price would you like to sell " << mdl.modelName << " for? ";
  cin >> mdl.modelPrice;
  if(mdl.modelPrice < totalPartsCost)
  {
    cout << "\nWARNING! " << "You will NOT make any profit if you set " << mdl.modelName << " price to $" << mdl.modelPrice << endl;
    cout << "Are you sure that's what you want to set model price to (y/n): ";
    cin >> ch;
    if (ch == 'n' || ch == 'N')
    {
      cout << "\nWhat price would you like to sell " << mdl.modelName << " for? ";
      cin >> mdl.modelPrice;
    }
  }
  allModel.push_back(mdl);
  armSize = mdl.arms.size();
  batterySize = mdl.batteries.size();
  fileIndexes.push_back(-1);          // -1 is pushed to keep track of when a model ended
  // fileIndexes.push_back(index);
  
  
  
  
  
}
void RobotModels::calculateTotalPartsCost()
{
  totalPartsCost = 0;                        // ensure totalPartsCost is zero before start adding
  for(int i = 0; i < partsCost.size(); i++)
    totalPartsCost += partsCost[i];
  while (partsCost.size() != 0) // delete all elements that was in partsCost, so partsCost can store next model cost
    partsCost.pop_back();
}
void RobotModels::displayRobotModel()
{
  cout << endl;
  cout << "_____________________________________________" << endl;
  cout << "\t******** Display Models ********" << endl;
  cout << "_____________________________________________" << endl;
  for (int i = 0; i < allModel.size(); i++)
  {
    cout << endl;
    cout << i << ". ";
    cout << "Model Name: " << allModel[i].modelName << endl;
    cout << "   Model Number: " << allModel[i].modelNumber << endl;
    cout << "   Types of components that made up model " << allModel[i].modelName << endl;
    cout << "\tHead: " << allModel[i].head.getName() << endl;
    if (armSize == 0)
      cout << "Arms: None " << endl;
    else
      for (int j = 0; j < armSize; j++)
        cout << "\tArms: " << allModel[i].arms[j].getName() << endl;
    cout << "\tTorso: " << allModel[i].torso.getName() << endl;
    cout << "\tLocomotor: " << allModel[i].locomotor.getName() << endl;
    if (batterySize != 0)
      cout << "\tBatteries: " << allModel[i].batteries[i] << endl;
    else
      cout << "\tBatteries: None" << endl;
    cout << "   Model Price: $" << allModel[i].modelPrice << endl;
  }
  if (allModel.size() == 0)
    cout << "\nNo model created" << endl;
}

void RobotModels::display(int i)
{
  cout << "\tModel Name: " << allModel[i].modelName << endl;
  cout << "\tModel Number: " << allModel[i].modelNumber << endl;
  cout << "\tModel Price: $" << allModel[i].modelPrice << endl;
}

double RobotModels::getModelPrice(int i)
{
  return allModel[i].modelPrice;
}

void RobotModels::saveModel()
{
  string fileName;
  fstream myFile;
  
  // cout << "What is the file name to save robot parts: ";
  //getline(cin, fileName);
  //myFile.open(fileName.c_str(), ios::out | ios::app);      // write to file and append to end
  myFile.open("Robot_Model.txt", ios::out | ios::in | ios::trunc);
  if (!myFile)       // if myFile stream is corrupted
    throw runtime_error("canít open output file " + fileName);
  
  myFile << endl;
  myFile << "_____________________________________________" << endl;
  myFile << "\t******** Display Models ********" << endl;
  myFile << "_____________________________________________" << endl;
  for (int i = 0; i < allModel.size(); i++)
  {
    myFile << endl;
    myFile << "Model Name: " << allModel[i].modelName << endl;
    myFile << "Model Number: " << allModel[i].modelNumber << endl;
    myFile << "Types of components that made up model " << allModel[i].modelName << endl;
    myFile << "\tHead: " << allModel[i].head.getName() << endl;
    if (armSize == 0)
      myFile << "Arms: None " << endl;
    else
      for (int j = 0; j < armSize; j++)
        myFile << "\tArms: " << allModel[i].arms[j].getName() << endl;
    myFile << "\tTorso: " << allModel[i].torso.getName() << endl;
    myFile << "\tLocomotor: " << allModel[i].locomotor.getName() << endl;
    if (batterySize != 0)
      myFile << "\tBatteries: " << allModel[i].batteries[i] << endl;
    else
      myFile << "\tBatteries: None" << endl;
    myFile << "Model Price: $" << allModel[i].modelPrice << endl;
  }
  if (allModel.size() == 0)
    myFile << "\nNo model created" << endl;
  myFile.close();  // close file after use
}

void RobotModels::saveProgramModel()
{
  string fileName;
  fstream myFile;
  
  myFile.open("Model_Program_File.txt", ios::out | ios::in | ios::trunc);
  if (!myFile)       // if myFile stream is corrupted
    throw runtime_error("canít open output file " + fileName);
  
  int lastIndexRead = 0;        // stores last index when it reach -1, so the index for -1 is store in lastIndexRead
  for (int i = 0; i < allModel.size(); i++)
  {
    myFile << "#" << endl;                  // prints # to signal when a new model starts
    myFile << allModel[i].modelName << endl;
    myFile << allModel[i].modelNumber << endl;
    
    for(int j = lastIndexRead; j < fileIndexes.size(); j++)
    {
      if(fileIndexes[j] == -1)       // exit loop if reach to the end of a model
      {
        lastIndexRead = j;         // stores index for -1, so that we can keep track of when the first model created
        lastIndexRead++;           // add 1 so that we can go to the next index for the next model stored
        break;
      }
      myFile << fileIndexes[j] << endl;
    }
    myFile << allModel[i].batteries[i] << endl;
    myFile << allModel[i].modelPrice << endl;
  }
  
  myFile.close();  // close file after use
  
}
void RobotModels::retrieveModel(CreateRobotParts &p)
{
  string line;
  ifstream readFile;
  model mdl;
  int index;
  double price;
  armSize = 2;         // this is the number of arms read and created
  batterySize = 0;     // stores the number of batteries encounter
  
  readFile.open("Model_Program_File.txt", ios::in);     // open the file to read from
  if (readFile)       // if myFile stream is corrupted, throw an exception to the runtime_error
  {
    while (getline(readFile, line))     // read data from the file -> Model_Program_File.txt
    {
      if(line == "#")
        continue;                           // continue onto next line
      mdl.modelName = line;                   // set model name to the line just get, which it should modelName
      getline(readFile, line);                // get the next line after modelName-> should be the model number
      mdl.modelNumber = line;                 // set modelNumber to line
      getline(readFile, line);                // should be an index of the head selected be user-> this information will
      // be pass to head to get whatever the user selected initially
      
      index = atoi(line.c_str());             // since line came in as a string, we need to first convert it to an integer
      mdl.head = p.getHeadAt(index);          // pass the index to head and set the head in model to whatever the user select initially
      fileIndexes.push_back(index);
      
      getline(readFile, line);                // this should get the next index for the first arm
      index = atoi(line.c_str());             // again, convert string to an integer
      mdl.arms.push_back(p.getArmAt(index));  // store the arm into the model vector
      fileIndexes.push_back(index);
      
      getline(readFile, line);                // this should get the next index for the second arm
      index = atoi(line.c_str());             // again, convert string to an integer
      mdl.arms.push_back(p.getArmAt(index));  // store the arm into the model
      fileIndexes.push_back(index);
      
      getline(readFile, line);                // get the next line, this line should be torso
      index = atoi(line.c_str());             // since line came in as a string, we need to first convert it to an integer
      mdl.torso = p.getTorsoAt(index);        // pass the index to torso and set the torso in model to whatever the user select initially
      fileIndexes.push_back(index);
      
      getline(readFile, line);                // get the next line, this line should be Locomotor
      index = atoi(line.c_str());             // since line came in as a string, we need to first convert it to an integer
      mdl.locomotor = p.getLocomotorAt(index);// pass the index to locomotor and set the locomotor in model to whatever the user select initially
      fileIndexes.push_back(index);
      
      getline(readFile, line);                // next information that comes into line is battery
      index = atoi(line.c_str());             // since line came in as a string, we need to first convert it to an integer
      mdl.batteries.push_back(index);         // stores battery into model
      batterySize++;
      getline(readFile, line);                // this is the final line that should be get, and it should be the model price
      price = atof(line.c_str());             // convert the price to double
      mdl.modelPrice = price;                 // set the model price to price
      allModel.push_back(mdl);                // push created model onto allModel
      fileIndexes.push_back(-1);              // keep track of when a model is created
    }
    readFile.close();       // close file after finish using
  }
  else
    cout << "There was no file to retrieve data from for robot model." << endl;
  
}
