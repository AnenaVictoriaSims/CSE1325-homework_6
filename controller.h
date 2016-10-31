 #ifndef __CONTROLLER_H
 #define __CONTROLLER_H


#include "std_lib_facilities.h"
//#include "view.h"
#include "robotParts.h"
#include "createRobotParts.h"
#include "robotModels.h"
#include "torso.h"
#include "head.h"
#include "arm.h"
#include "locomotor.h"
#include "battery.h"
#include "salesAssociate.h"
#include "orders.h"
#include "customer.h"           //added

 class Controller
 {
     private:
        CreateRobotParts& parts;
        RobotModels& model;
        Orders& orders;
   
     public:
        Controller (CreateRobotParts& constructorOf, RobotModels& constructor, Orders& orderConst) : parts(constructorOf), model(constructor), orders(orderConst) {};
        void partsController();
        void modelController();
        void showControllerMenu();
        void ordersController();
        void customerController();
 };
 #endif
