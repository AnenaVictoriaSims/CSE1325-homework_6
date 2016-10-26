//10/17/2016 changes made: Added userSelection, customerOrderOptions, & salesOrderOptions functions
#include "std_lib_facilities.h"
#include "view.h"


View::View(){
  //default constructor
}

void View::main_menu(){
  cout << endl<<endl;
  cout << "Main Menu\n**************\n";
  cout << "1) Create Parts\n";
  cout << "2) Create Model\n";
  cout << "3) Display Parts\n";
  cout << "4) Display Model\n";
  cout << "5) Order Menu\n";
  cout << "6) Save\n";
  cout << "7) Quit\n";
  cout << "8) View Documentation.\n";
  cout << "Command?: ";
}
void View::createParts_menu(){
  cout << endl<<endl;
  cout << "Parts Menu\n**************\n";
  cout << "1.1) Create Head\n";
  cout << "1.2) Create Torso\n";
  cout << "1.3) Create Arm\n";
  cout << "1.4) Create Locomotor\n";
  cout << "1.5) Create Battery\n";
  cout << "1.6) Display Parts\n";
  cout << "1.7) Main Menu\n";
  cout << "Command?: ";
}
void View::createModels_menu(){
  cout << endl<<endl;
  cout << "Models Menu\n**************\n";
  cout << "2.1) Choice Head\n";
  cout << "2.2) Choice Torso\n";
  cout << "2.3) Choice Arm\n";
  cout << "2.4) Choice Locomotor\n";
  cout << "2.5) Choice Battery\n";
  cout << "2.6) Main Menu\n";
  cout << "Command?: ";
}
void View::report_menu(){
  cout << endl<<endl;
  cout << "Report Menu\n**************\n";
  cout << "2.1) View Robot Catalog\n";
  cout << "Command?: ";
}
void View::userSelection()
{
  cout << endl<<endl;
  cout << "Select a User Type\n**************\n";
  cout << "1) Sales Associate\n";
  cout << "2) Customer\n";
  cout << "3) Main Menu\n";
  cout << "Command?: ";
}
void View::customerOrderOptions()
{
  cout << endl<<endl;
  cout << "Order Menu\n**************\n";
  cout << "5.1) Print Order History\n";
  cout << "5.2) View Your Bill\n";
  cout << "5.3) User Selection Menu\n";
  cout << "Command?: ";
}
void View::salesOrderOptions()
{
  cout << endl<<endl;
  cout << "Order Menu\n**************\n";
  cout << "5.1) Create New Order\n";
  cout << "5.2) Print Order Log\n";
  cout << "5.3) Print Sales Associates Order Log\n";
  cout << "5.4) User Selection Menu\n";
  cout << "Command?: ";
}
void View::print_documentation(){
  cout << "Robbie Robots Shop Manager is a protoype proposal package, featuring a text menu or command line interface.\n";
  cout <<"IMPORTANT.\n";
  cout <<"You must create a robot part of each (head, torso, arm, locomotor, battery) before you save.\n";
}
