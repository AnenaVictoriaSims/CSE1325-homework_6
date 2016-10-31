//
#include "std_lib_facilities.h"
#include "view.h"
#include "robotParts.h"
#include "createRobotParts.h"
#include "controller.h"
#include "robotModels.h"

int main()
{
    CreateRobotParts robotPartConstruct;
    RobotModels modelsConstruct;
    Orders ordersConst;
    Controller controller(robotPartConstruct, modelsConstruct, ordersConst);

    controller.showControllerMenu();

    return 0;
}
