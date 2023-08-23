#include <iostream>
using namespace std;

class Vehicle {
protected:
    int vehicleID;
    float maxSpeed;

public:
    Vehicle(int id, float speed) : vehicleID(id), maxSpeed(speed) {}

    void displayVehicleDetails() {
        cout << "Vehicle ID: " << vehicleID << std::endl;
        cout << "Max Speed: " << maxSpeed << " km/h" << std::endl;
    }
};

class PassengerVehicle : virtual public Vehicle {
public:
    PassengerVehicle(int id, float speed) : Vehicle(id, speed) {}

    void transportPassengers() {
        cout << "Transporting passengers." << std::endl;
    }
};

class GoodsVehicle : virtual public Vehicle {
public:
    GoodsVehicle(int id, float speed) : Vehicle(id, speed) {}

    void transportGoods() {
        cout << "Transporting goods." << std::endl;
    }
};

class Truck : public PassengerVehicle, public GoodsVehicle {
public:
    Truck(int id, float speed) : Vehicle(id, speed), PassengerVehicle(id, speed), GoodsVehicle(id, speed) {}

    void tow() {
        cout << "Truck is towing." << std::endl;
    }
};

int main() {
    // Create a pointer to the Truck class and pass values using the constructor
    Truck* truckPtr = new Truck(1234, 80.0);

    // Access and test the functionality of the classes
    truckPtr->displayVehicleDetails();
    truckPtr->transportPassengers();
    truckPtr->transportGoods();
    truckPtr->tow();

    delete truckPtr;  // Clean up the dynamically allocated memory

    return 0;
}

