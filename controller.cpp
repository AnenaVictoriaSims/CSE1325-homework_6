#include "std_lib_facilities.h"
#include "controller.h"
#include "robotModels.h"
#include "view.h"
#include <fstream>

void Controller::showControllerMenu()
{
  View newView;
  int key = 0;
  
  parts.retrieveParts();          // retrieve data that is store in file
  model.retrieveModel(parts);     // retrieve data that is store in file
  // retrieveModel needs to see the data of parts in order to retrieve the data
  
  while (true)
  {
    newView.main_menu();
    cin >> key;
    switch (key)
    {
      case 1:
        partsController();
        break;
      case 2:
        modelController();
        break;
      case 3:
        parts.displayParts();
        break;
      case 4:
        model.displayRobotModel();
        break;
      case 5:
        ordersController();
        break;
      case 6:
        parts.saveParts();
        parts.saveProgramParts();
        model.saveModel();
        model.saveProgramModel();
        cout << "Robot parts and robot model have been saved. " << endl;
        break;
      case 7:
        cout << "exiting..." << endl;
        exit(0);
        break;
      case 8:
        newView.print_documentation();
        break;
      default:
        cout << "You didnt enter a valid command. Please try again..." << endl;
    }
  }
}
//USED TO CONTROL PARTS
void Controller::partsController(){
  double cmd = 0;
  View view;
  while (cmd != 1.7){
    view.createParts_menu();
    cin >> cmd;
    if(cmd == 1.1)
      parts.createHead();
    else if(cmd == 1.2)
      parts.createTorso();
    else if(cmd == 1.3)
      parts.createArm();
    else if(cmd == 1.4)
      parts.createLocomotor();
    else if(cmd == 1.5)
      parts.createBattery();
    else if (cmd  == 1.6)
      parts.displayParts();
    else if(cmd == 1.7)
      cout << "returning to main menu...\n";
    else
      cout <<"\nXXXXX Invalid key XXXXX"<<endl;
  }
}
void Controller::modelController(){
  
  double cmd = 0;
  int readKey;
  View view;
  
  model.createRobotModels(parts);
  //model.displayRobotModel();
  
}
void Controller::ordersController()
{
  View newView;
  double key = 0;
  
  while( key != 3)
  {
    newView.userSelection();
    cin >> key;
    if( key == 1 )
    {
      SalesAssociate associate;
      string name;
      cout << "\nAssociate Name: ";
      cin.ignore();
      getline(cin, name);
      associate.setName(name);
      cout << associate.getName();
      
      while(key != 5.4)
      {
        newView.salesOrderOptions();
        cin >> key;
        if (key == 5.1)
        {
          orders.createOrders(model, associate);
        }
        else if(key == 5.2)
        {
          orders.displayOrders();
        }
        else if( key == 5.3 )
          orders.salesHistory( name );
      }
      
    }
    else if( key == 2 )
      customerController();
    else if( key == 3 )
      cout << "returning to main menu...\n";
    else
      cout << "\nXXXXX Invalid key, Try again XXXXX" << endl;
  }
}
void Controller::customerController()
{
  View newView;
  double key = 0;
  int tok;
  
  string name;
  cout << "\nCustomer Name: ";
  cin.ignore();
  getline(cin, name);
  
  while ( key != 5.3 )
  {
    newView.customerOrderOptions();                                                     //add
    cin >> key;
    
    if ( key == 5.1 )
      orders.orderHistory( name );                                    //call Order class to view customer's orders
    else if ( key == 5.2 )
    {
      orders.viewCustBill( name, model );                                         //call Order class to view customer's bill
    }
    else if( key == 5.3 )
      cout << "returning to User Selection Menu...\n";
    else
      cout << "\nXXXXX Invalid key, Try again XXXXX" << endl;                 //basic err chk
  }
}

