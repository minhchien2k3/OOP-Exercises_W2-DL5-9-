//21110756_NguyenDinhMinhChien
#include <iostream>
using namespace std;

// This class represents the real-world "Vehicle" entity with attributes and methods
class Vehicle {
private:
    string type;       // Vehicle type (Car, Truck, Motorcycle, etc.)
    int maxSpeed;      // Maximum speed in km/h
    string fuelType;   // Fuel type (Gasoline, Diesel, etc.)

public:
    // Constructor
    Vehicle(string t, int speed, string fuel) {
        type = t;
        maxSpeed = speed;
        fuelType = fuel;
    }

    // Getter methods
    string getType() { return type; }
    int getMaxSpeed() { return maxSpeed; }
    string getFuelType() { return fuelType; }

    // Behavior: accelerate
    void accelerate() {
        cout << "The " << type << " is accelerating to "
            << maxSpeed << " km/h." << endl;
    }

    // Behavior: display all information
    void displayInfo() {
        cout << "Vehicle Type: " << type
            << ", Max Speed: " << maxSpeed << " km/h"
            << ", Fuel: " << fuelType << endl;
    }
};

int main() {
    // Predefined objects
    Vehicle car("Car", 200, "Gasoline");
    Vehicle truck("Truck", 150, "Diesel");
    Vehicle motorcycle("Motorcycle", 180, "Gasoline");

    cout << "=== Predefined Vehicles ===" << endl;

    // Demonstrate accelerate()
    car.accelerate();
    truck.accelerate();
    motorcycle.accelerate();

    // Demonstrate getters
    cout << car.getType() << " -> Max Speed: " << car.getMaxSpeed()
        << " km/h, Fuel: " << car.getFuelType() << endl;
    cout << truck.getType() << " -> Max Speed: " << truck.getMaxSpeed()
        << " km/h, Fuel: " << truck.getFuelType() << endl;
    cout << motorcycle.getType() << " -> Max Speed: " << motorcycle.getMaxSpeed()
        << " km/h, Fuel: " << motorcycle.getFuelType() << endl;

    // Demonstrate displayInfo()
    car.displayInfo();
    truck.displayInfo();
    motorcycle.displayInfo();

    // User input for dynamic vehicle creation
    string userType, userFuel;
    int userSpeed;
    cout << "\n=== Create Your Own Vehicle ===" << endl;
    cout << "Enter vehicle type: ";
    cin >> userType;
    cout << "Enter max speed: ";
    cin >> userSpeed;
    cout << "Enter fuel type: ";
    cin >> userFuel;

    Vehicle userVehicle(userType, userSpeed, userFuel);

    // Show user vehicle info
    userVehicle.displayInfo();
    userVehicle.accelerate();

    return 0;
}
