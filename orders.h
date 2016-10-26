#ifndef _ORDERS_H_
#define _ORDERS_H_

#include "std_lib_facilities.h"
#include "salesAssociate.h"
#include "customer.h"
#include "robotModels.h"
#include <ctime>

class Orders
{
public:
  double getTotalPrice();
  void setTotalPrice(double price);
  double calculateShipping();
  void createOrders(RobotModels models, SalesAssociate associate);
  void getTime();
  int getOrderNumber();
  void setOrderNumber();
  void displayOrders();
  int orderHistory( string n );                                //add
  void viewCustBill( string n, RobotModels models);                                    //add
  double printOrderHistory( int i, int j );                         //add
  int salesHistory( string n );                                //add
  
private:
  double totalPrice = 0;
  double shippingCost;
  SalesAssociate associate;
  Customer customer;            //added
  
  int orderNumber;         // let the system generate a order # using random() or some function like that
  vector <int> quantities;
  vector<int> cart;
  string custName;
  vector <Orders> allOrders;
  string token;                     //add
  int index = 0;                    //add
  
};

#endif // _ORDERS_H_
