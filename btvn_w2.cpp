#include <iostream>
#include <string>
#include <vector>
using namespace std;

// ===== Abstract Base Class =====
class Vehicle {
protected:
    string licensePlate;     // Biển số xe
    int maxSpeed;            // Tốc độ tối đa
    string fuelType;         // Loại nhiên liệu (xăng, dầu...)
    int yearOfManufacture;   // Năm sản xuất
    int mileage;             // Số km đã chạy
    string status;           // Trạng thái xe (Active, Maintenance)
    string driverName;       // Tên tài xế

public:
    // Constructor khởi tạo đối tượng Vehicle
    Vehicle(string plate, int speed, string fuel, int year)
        : licensePlate(plate), maxSpeed(speed), fuelType(fuel),
        yearOfManufacture(year), mileage(0), status("Active"), driverName("None") {
    }

    virtual ~Vehicle() {} // Destructor ảo để hỗ trợ đa hình

    // Gán tên tài xế cho xe
    void assignDriver(const string& name) { driverName = name; }

    // Cập nhật quãng đường đã chạy (chỉ cộng thêm nếu km > 0)
    void updateMileage(int km) { if (km > 0) mileage += km; }

    // Đánh dấu xe đang bảo dưỡng
    void sendForMaintenance() { status = "Maintenance"; }

    // Phương thức ảo thuần túy => bắt buộc các lớp con phải override
    virtual void accelerate() const = 0;

    // Phương thức ảo thuần túy => các lớp con tự định nghĩa cách hiển thị thông tin
    virtual void displayInfo() const = 0;
};

// ===== Derived Class Car =====
class Car : public Vehicle {
private:
    int numberOfSeats; // Số chỗ ngồi

public:
    Car(string plate, int speed, string fuel, int year, int seats)
        : Vehicle(plate, speed, fuel, year), numberOfSeats(seats) {
    }

    // Override accelerate()
    void accelerate() const override {
        cout << "Car " << licensePlate << " is accelerating to " << maxSpeed << " km/h.\n";
    }

    // Override displayInfo() để in thông tin chi tiết
    void displayInfo() const override {
        cout << "\n--- Car Info ---\n";
        cout << "License Plate: " << licensePlate << "\n";
        cout << "Max Speed: " << maxSpeed << " km/h\n";
        cout << "Fuel Type: " << fuelType << "\n";
        cout << "Year: " << yearOfManufacture << "\n";
        cout << "Seats: " << numberOfSeats << "\n";
        cout << "Mileage: " << mileage << " km\n";
        cout << "Status: " << status << "\n";
        cout << "Driver: " << driverName << "\n";
    }
};

// ===== Derived Class Truck =====
class Truck : public Vehicle {
private:
    int capacity; // Tải trọng (tấn)

public:
    Truck(string plate, int speed, string fuel, int year, int cap)
        : Vehicle(plate, speed, fuel, year), capacity(cap) {
    }

    void accelerate() const override {
        cout << "Truck " << licensePlate << " is accelerating up to " << maxSpeed << " km/h.\n";
    }

    void displayInfo() const override {
        cout << "\n--- Truck Info ---\n";
        cout << "License Plate: " << licensePlate << "\n";
        cout << "Max Speed: " << maxSpeed << " km/h\n";
        cout << "Fuel Type: " << fuelType << "\n";
        cout << "Year: " << yearOfManufacture << "\n";
        cout << "Capacity: " << capacity << " tons\n";
        cout << "Mileage: " << mileage << " km\n";
        cout << "Status: " << status << "\n";
        cout << "Driver: " << driverName << "\n";
    }
};

// ===== Derived Class Motorcycle =====
class Motorcycle : public Vehicle {
private:
    int engineCapacity; // Dung tích xi-lanh (cc)

public:
    Motorcycle(string plate, int speed, string fuel, int year, int cc)
        : Vehicle(plate, speed, fuel, year), engineCapacity(cc) {
    }

    void accelerate() const override {
        cout << "Motorcycle " << licensePlate << " zooms to " << maxSpeed << " km/h.\n";
    }

    void displayInfo() const override {
        cout << "\n--- Motorcycle Info ---\n";
        cout << "License Plate: " << licensePlate << "\n";
        cout << "Max Speed: " << maxSpeed << " km/h\n";
        cout << "Fuel Type: " << fuelType << "\n";
        cout << "Year: " << yearOfManufacture << "\n";
        cout << "Engine: " << engineCapacity << " cc\n";
        cout << "Mileage: " << mileage << " km\n";
        cout << "Status: " << status << "\n";
        cout << "Driver: " << driverName << "\n";
    }
};

// ===== Main Function =====
int main() {
    vector<Vehicle*> fleet; // Danh sách xe quản lý bằng con trỏ đa hình
    int choice;

    while (true) {
        // Menu chính
        cout << "\n--- Vehicle Management Menu ---\n";
        cout << "1. Add Car\n";
        cout << "2. Add Truck\n";
        cout << "3. Add Motorcycle\n";
        cout << "4. Exit and Show All Vehicles\n";
        cout << "Choose an option: ";
        cin >> choice;

        if (choice == 4) break; // Người dùng chọn thoát

        // Các biến nhập chung
        string plate, fuel, driver;
        int speed, year;

        if (choice == 1) {
            // Nhập thông tin Car
            int seats;
            cout << "\n--- Enter Car Details ---\n";
            cout << "License plate: ";
            cin >> plate;
            cout << "Max speed (km/h): ";
            cin >> speed;
            cout << "Fuel type: ";
            cin >> fuel;
            cout << "Year of manufacture: ";
            cin >> year;
            cout << "Number of seats: ";
            cin >> seats;
            cout << "Driver name: ";
            cin >> driver;

            Vehicle* v = new Car(plate, speed, fuel, year, seats);
            v->assignDriver(driver);
            fleet.push_back(v); // Thêm vào danh sách
        }
        else if (choice == 2) {
            // Nhập thông tin Truck
            int capacity;
            cout << "\n--- Enter Truck Details ---\n";
            cout << "License plate: ";
            cin >> plate;
            cout << "Max speed (km/h): ";
            cin >> speed;
            cout << "Fuel type: ";
            cin >> fuel;
            cout << "Year of manufacture: ";
            cin >> year;
            cout << "Capacity (tons): ";
            cin >> capacity;
            cout << "Driver name: ";
            cin >> driver;

            Vehicle* v = new Truck(plate, speed, fuel, year, capacity);
            v->assignDriver(driver);
            fleet.push_back(v);
        }
        else if (choice == 3) {
            // Nhập thông tin Motorcycle
            int cc;
            cout << "\n--- Enter Motorcycle Details ---\n";
            cout << "License plate: ";
            cin >> plate;
            cout << "Max speed (km/h): ";
            cin >> speed;
            cout << "Fuel type: ";
            cin >> fuel;
            cout << "Year of manufacture: ";
            cin >> year;
            cout << "Engine capacity (cc): ";
            cin >> cc;
            cout << "Driver name: ";
            cin >> driver;

            Vehicle* v = new Motorcycle(plate, speed, fuel, year, cc);
            v->assignDriver(driver);
            fleet.push_back(v);
        }
        else {
            cout << "Invalid choice! Try again.\n";
        }
    }

    // Hiển thị toàn bộ xe đã nhập
    cout << "\n=== All Vehicles in Fleet ===\n";
    for (auto v : fleet) {
        v->accelerate();   // Gọi phương thức accelerate() đa hình
        v->displayInfo();  // Gọi phương thức displayInfo() đa hình
    }

    // Giải phóng bộ nhớ động
    for (auto v : fleet) delete v;

    return 0;
}
