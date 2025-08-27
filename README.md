# 🚚 Vehicle Management System (OOP in C++)

## 📌 Introduction
This project demonstrates how to apply **Object-Oriented Programming (OOP)** principles in C++ to manage a transportation company’s vehicles.  
The system allows users to:
- Add **Cars, Trucks, and Motorcycles**.
- Store details such as license plate, max speed, fuel type, year, driver name, etc.
- Perform actions like accelerating and displaying vehicle information.
- Use a **menu-based input system** for dynamic data entry.

This project highlights **Encapsulation, Inheritance, Polymorphism, and Abstraction** in practice.

---

## 🛠 Features
1. **Vehicle Base Class** with shared attributes (license plate, speed, fuel type, etc.).
2. **Derived Classes**:
   - `Car` → adds number of seats.
   - `Truck` → adds capacity (tons).
   - `Motorcycle` → adds engine capacity (cc).
3. **Dynamic Input**: Users select the type of vehicle and then enter details step by step.
4. **Driver Assignment**: Each vehicle can be assigned a driver.
5. **Polymorphic Actions**: `accelerate()` and `displayInfo()` behave differently for each vehicle type.
6. **Fleet Management**: All vehicles stored in a list and displayed at the end.

---

## ⚙️ How to Run
```bash
g++ vehicle_management.cpp -o vehicle
./vehicle
````

When you run the program:

1. Choose a vehicle type (Car / Truck / Motorcycle).
2. Enter details step by step (plate, speed, fuel type, etc.).
3. The system saves it into the fleet.
4. Choose exit to display all entered vehicles.

---

## ✅ Example Input & Output

### Example Run

```
--- Vehicle Management Menu ---
1. Add Car
2. Add Truck
3. Add Motorcycle
4. Exit and Show All Vehicles
Choose an option: 1

--- Enter Car Details ---
License plate: 51A-12345
Max speed (km/h): 200
Fuel type: Gasoline
Year of manufacture: 2022
Number of seats: 5
Driver name: John

--- Vehicle Management Menu ---
1. Add Car
2. Add Truck
3. Add Motorcycle
4. Exit and Show All Vehicles
Choose an option: 4

=== All Vehicles in Fleet ===
Car 51A-12345 is accelerating to 200 km/h.

--- Car Info ---
License Plate: 51A-12345
Max Speed: 200 km/h
Fuel Type: Gasoline
Year: 2022
Seats: 5
Mileage: 0 km
Status: Active
Driver: John
```

---

## 🧑‍💻 OOP Principles Applied

### 1. Encapsulation (Đóng gói)

* Attributes like `licensePlate`, `maxSpeed`, `fuelType`, etc. are declared as **protected/private**.
* Access is controlled using **methods** (`assignDriver()`, `updateMileage()`), preventing direct modification.
* Example: mileage can only be updated via `updateMileage()` to ensure data integrity.

### 2. Inheritance (Kế thừa)

* `Car`, `Truck`, and `Motorcycle` **inherit** from the abstract base class `Vehicle`.
* This avoids code duplication and ensures all vehicles share common properties.
* Example: All vehicles automatically have licensePlate, fuelType, etc., without rewriting code.

### 3. Polymorphism (Đa hình)

* Methods like `accelerate()` and `displayInfo()` are declared as **virtual** in the base class and overridden in subclasses.
* At runtime, the correct method is called based on the **object type** (Car/Truck/Motorcycle).
* Example: `Car` accelerates differently from `Truck`.

### 4. Abstraction (Trừu tượng)

* The `Vehicle` class is declared **abstract** using pure virtual functions (`= 0`).
* Users cannot create a generic `Vehicle`; they must instantiate specific types (Car, Truck, Motorcycle).
* This hides implementation details and focuses only on essential behaviors.

---

## 📑 Reflection Report

While building this project, I learned how to break down real-world requirements into **OOP concepts**:

* First, I identified the common entity (**Vehicle**) and its shared attributes/behaviors.
* Then, I extended it into specialized classes (**Car, Truck, Motorcycle**) using **inheritance**.
* I applied **polymorphism** to allow different behaviors while keeping the same method interface.
* I enforced **abstraction** by designing an abstract base class, ensuring each vehicle must define its own details.
* **Encapsulation** was applied by protecting attributes and exposing only safe public methods.

**Challenges** included deciding which attributes should belong to the base class vs. subclasses, and ensuring input/output flows were user-friendly.

This project showed how OOP makes the system **flexible, reusable, and easier to extend**. For example, adding a new vehicle type (like Bus) requires minimal changes because the design already supports polymorphism.

---

#
