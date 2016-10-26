
CXXFLAGS =

all: executable

debug: CXXFLAGS += -g
debug: executable

rebuild: clean executable
executable: shop.o robotParts.o view.o torso.o robotModels.o orders.o locomotor.o head.o customer.o createRobotParts.o controller.o battery.o arm.o salesAssociate.o
	$(CXX) $(CXXFLAGS) shop.o robotParts.o view.o torso.o robotModels.o orders.o locomotor.o head.o customer.o createRobotParts.o controller.o battery.o arm.o salesAssociate.o
shop.o: shop.cpp std_lib_facilities.h view.h robotparts.h createRobotParts.h controller.h robotModels.h
	$(CXX) $(CXXFLAGS) -w -c shop.cpp
torso.o: torso.cpp torso.h std_lib_facilities.h
	$(CXX) $(CXXFLAGS) -w -c torso.cpp
view.o: view.cpp view.h std_lib_facilities.h
	$(CXX) $(CXXFLAGS) -w -c view.cpp
robotParts.o: robotParts.cpp std_lib_facilities.h robotParts.h
	$(CXX) $(CXXFLAGS) -w -c robotParts.cpp
robotModels.o: robotModels.cpp std_lib_facilities.h robotModels.h
	$(CXX) $(CXXFLAGS) -w -c robotModels.cpp 
orders.o: orders.cpp orders.h
	$(CXX) $(CXXFLAGS) -w -c orders.cpp 
locomotor.o: locomotor.cpp std_lib_facilities.h locomotor.h
	$(CXX) $(CXXFLAGS) -w -c locomotor.cpp 
head.o: head.cpp std_lib_facilities.h head.h robotParts.h
	$(CXX) $(CXXFLAGS) -w -c head.cpp 
customer.o: customer.cpp std_lib_facilities.h customer.h
	$(CXX) $(CXXFLAGS) -w -c customer.cpp 
createRobotParts.o: createRobotParts.cpp std_lib_facilities.h createRobotParts.h
	$(CXX) $(CXXFLAGS) -w -c createRobotParts.cpp 
controller.o: controller.cpp std_lib_facilities.h controller.h view.h
	$(CXX) $(CXXFLAGS) -w -c controller.cpp
battery.o: battery.cpp std_lib_facilities.h battery.h
	$(CXX) $(CXXFLAGS) -w -c battery.cpp
arm.o: arm.cpp std_lib_facilities.h arm.h
	$(CXX) $(CXXFLAGS) -w -c arm.cpp
salesAssociate.o: salesAssociate.cpp std_lib_facilities.h salesAssociate.h
	$(CXX) $(CXXFLAGS) -w -c salesAssociate.cpp
clean:
	rm -f *.o a.out
