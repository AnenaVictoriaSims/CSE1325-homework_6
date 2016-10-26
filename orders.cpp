#include "orders.h"

void Orders::createOrders(RobotModels models, SalesAssociate associate)  //add
{
  Orders ordr;
  ordr.associate = associate;
  
  string name;
  int choice, key, quantity;
  cout <<"\n\n******* CREATING ORDER **********\n";
  cout << "\nEnter customer Name: ";
  cin.ignore();
  getline(cin, name);
  
  ordr.customer.setName( name );                         //chgd
  //custName = customer.getName();                    //chgd
  
  
  while(key != 2)
  {
    //cin.ignore();
    cout << endl;
    cout << "What would you like to do?" << endl;
    cout << "1) Select from catalog" << endl;
    cout << "2) Checkout" << endl;
    cout << "Command: ";
    cin >> key;
    
    if(key == 1)
    {
      models.displayRobotModel();
      cout << "Enter catalog number: ";
      cin >> choice;
      cout << "Enter quantity: ";
      cin >> quantity;
      ordr.quantities.push_back(quantity);
      ordr.cart.push_back(choice);
    }
    else if(key == 2)
    {
      cout << "\n\n******* CHECKOUT SUMMARY *******" << endl;
      cout << "Customer: " << name << endl;
      ordr.setOrderNumber();
      cout << "Order number: " << ordr.getOrderNumber() << endl;
      cout << "Date: ";
      getTime();
      
      for(int i = 0; i < ordr.cart.size(); i++)
      {
        double price = 0;
        price = models.getModelPrice(ordr.cart[i]) * ordr.quantities[i];
        ordr.setTotalPrice(price);
        models.display(ordr.cart[i]);
        cout << "\tQuantity: x" << ordr.quantities[i] << endl;
        cout << endl;
        
      }
      
      cout << "\nSubTotal: $" << ordr.getTotalPrice();
      allOrders.push_back(ordr);
    }
    else
      cout <<"\nXXXXX Invalid key, Try again XXXXX"<< endl;
  }
  
  
}

void Orders::setTotalPrice(double price)
{
  totalPrice += price;
}

double Orders::getTotalPrice()
{
  return totalPrice;
}

void Orders::getTime()
{
  // current date/time based on current system
  time_t now = time(0);
  
  // convert now to string form
  char* dt = ctime(&now);
  
  cout  << dt << endl;
  
}

void Orders::setOrderNumber()
{
  orderNumber = rand() % 100000000;
}
int Orders::getOrderNumber()
{
  return orderNumber;
  
}

void Orders::displayOrders()
{
  cout << endl;
  cout << "_____________________________________________" << endl;
  cout << "\t******** Display Orders ********" << endl;
  cout << "_____________________________________________" << endl;
  for (int i = 0; i < allOrders.size(); i++)
  {
    cout << endl;
    cout << i << ". ";
    cout << "Customer Name: " << allOrders[i].customer.getName() << endl;             //chgd
    cout << endl;
    cout << "   Order Number: " << allOrders[i].orderNumber << endl;
    cout << "   Sold By: " << allOrders[i].associate.getName()<< endl;
    /*   for(int j = 0; j < allOrders[i].cart.size(); j++)
     {
     cout << "   Products: " << allOrders[i].cart[j] << endl;
     cout << "   Quantity: " << allOrders[i].quantities[j] << endl;
     }
     
     */
    cout << "   Total Price: " << allOrders[i].totalPrice << endl;
    
  }
  if (allOrders.size() == 0)
    cout << "\nNo model created" << endl;
}

/*----------------------------------------------------------------------------------------------------------------------*/
int Orders::orderHistory( string n )
{
  token = n;
  double total = 0;
  int cnt = 0;
  int cmd = 0; //for next function to determine if user is BC or SA
  
  cout << endl;
  cout << "----------------------------------------" << endl;
  cout << "|      Robbie Robot Shop Order         |" << endl;
  cout << "________________________________________" << endl;
  cout << endl;
  cout << "Customer Name: " << n << endl;
  
  for ( int i = 0; i < allOrders.size(); i++ )
  {
    string custName = allOrders[i].customer.getName();
    if ( token.compare( custName ) == 0)              //chgd
    {
      total += printOrderHistory( i, cmd );
      cnt++;
      index = 1;
    }
  }
  
  if( index != 1 && allOrders.size() != 0 )
  {
    cout << "You have no orders. ";
    return 1;
  }
  else if ( index != 1 && allOrders.size() == 0 )             //check if any orders are stored
  {
    cout << endl << "No sales have been made." << endl << endl << "Returning to user selection Menu..." << endl;
    return 1;
  }
  
  cout << endl << "Total Orders: " << cnt << "     Total Balance Due: " << total << endl << endl;
  return 0;
}


/*----------------------------------------------------------------------------------------------------------------------*/

int Orders::salesHistory( string n )
{
  token = n;
  int cnt = 0;
  double total = 0;
  int cmd = 1; //for next function to determine if user is BC or SA
  
  cout << endl;
  cout << "----------------------------------------" << endl;
  cout << "|       Staff Sales Report             |" << endl;
  cout << "________________________________________" << endl;
  cout << endl;
  cout << "Employee: " << n << endl;
  
  for ( int i = 0; i < allOrders.size(); i++ )
  {
    string custName = allOrders[i].associate.getName();
    if ( token.compare( custName ) == 0)              //chgd
    {
      total += printOrderHistory( i, cmd );
      cnt++;
      index = 1;
    }
  }
  
  if( index != 1 && allOrders.size() != 0 )
  {
    cout << "You made no sales. ";
    return 1;
  }
  else if ( index != 1 && allOrders.size() == 0 )             //check if any orders are stored
  {
    cout << endl << "The company made no sales." << endl << endl << "Returning to user selection Menu..." << endl;
    return 1;
  }
  
  cout << endl << "Total Sales: " << cnt << "     Total Sales Revenue: " << total << endl << endl;
  return 0;
}

double Orders::printOrderHistory( int x, int y )
{
  if ( y == 1 ) //SA
  {
    cout << endl;
    cout << "   Order Number: " << allOrders[x].orderNumber << endl;
    cout << "   Total Price: " << allOrders[x].totalPrice << endl;
    cout << endl;
    return allOrders[x].totalPrice;
  }
  else if ( y == 0 ) //BC
  {
    cout << endl;
    cout << x << ". ";
    cout << endl;
    cout << "   Order Number: " << allOrders[x].orderNumber << endl;
    cout << "   Sold By: " << allOrders[x].associate.getName()<< endl;
    cout << "   Total Price: " << allOrders[x].totalPrice << endl;
    return allOrders[x].totalPrice;
  }
}
/*----------------------------------------------------------------------------------------------------------------------*/
void Orders::viewCustBill( string n, RobotModels models)
{
  int cmd = orderHistory( n );
  
  if ( cmd == 1 )
    return;
  
  cout << endl << endl << "Enter index of the order to view: ";
  cin >> cmd;
  
  cout << endl;
  cout << "----------------------------------------" << endl;
  cout << "|      Robbie Robot Shop Invoice       |" << endl;
  cout << "________________________________________" << endl;
  cout << endl;
  cout << "Customer Name: " << allOrders[cmd].customer.getName() << endl;
  cout << "   Order Number: " << allOrders[cmd].orderNumber << endl;
  cout << "   Products: " << endl;
  for(int j = 0; j < allOrders[cmd].cart.size(); j++)
  {
    //cout << "   Products: " << allOrders[cmd].cart[j] << endl;
   // cout << "   Quantity: " << allOrders[cmd].quantities[j] << endl;
    models.display(allOrders[cmd].cart[j]);
    cout << "\tQuantity: x" << allOrders[cmd].quantities[j] << endl;
    cout << endl;
  }
  cout << "   Total Price: " << allOrders[cmd].totalPrice << endl;
}
