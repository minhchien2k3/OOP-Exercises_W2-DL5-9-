Vehicle Management System (OOP in C++)
Overview

This project is a simple vehicle management system built in C++ to practice object-oriented programming (OOP) concepts. It models different types of vehicles, their maximum speeds, and fuel types, and demonstrates how OOP principles can be applied to real-world problems.

The program includes:

A Vehicle class with attributes type, maxSpeed, and fuelType.

Methods for accelerating, displaying information, and accessing attributes through getters.

Predefined objects (Car, Truck, Motorcycle) and user-defined input to create a custom vehicle.

Reflection

In this assignment, I started by analyzing the real-world requirement of managing different types of vehicles in a transportation company. The first step was to identify the main entity, which is the Vehicle. From the problem description, I derived its core attributes such as type (e.g., Car, Truck), maxSpeed, and later extended the design with fuelType. Then I defined its behaviors, including accelerate() to simulate the action of a vehicle and displayInfo() to print all attributes clearly.

One of the challenges I faced was ensuring that the class design remained simple yet flexible enough to represent different vehicles. For example, when extending the class with an additional attribute (fuelType), I needed to adjust the constructor and methods while keeping the code clean. Another challenge was testing edge cases, such as a vehicle with maxSpeed = 0, and verifying that the program still runs without errors.

Object-oriented programming principles provided an effective framework to solve this problem. Encapsulation allowed me to keep attributes private while providing getters to access them safely. Abstraction helped me focus only on essential details of a vehicle, such as type and speed, while ignoring irrelevant complexity. Reusability was demonstrated when I created multiple Vehicle objects (Car, Truck, Motorcycle, and a user-defined vehicle) with the same class structure.

Overall, this assignment helped me connect OOP theory with practice. I learned how to analyze a requirement, design and implement a class, test its functionality, and extend it step by step. I now feel more confident in using C++ classes and objects to model real-world problems.
