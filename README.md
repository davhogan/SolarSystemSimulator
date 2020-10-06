# Solar System Simulator

The purpose of this program is to simulate a galaxy. The galaxy will have a random number of solar systems.  
Each solar system will have a random amount of planets in it. A planet can either be an inner or outer planet.  
The program uses inheritance with both inner and outer planets sharing the same base class. This parent class holds all the data of a node in a DLL.  
The solar system itself is represented by a DLL of planets ordered by distance from the sun.  
A planet is defined as either inner or outer by its distance from the sun  
All data from number of solar systems to the information of the planet is randomly generated. The ranges for a planet's information varries depending if it is an inner or outer planet.  
The galaxy is represented by an array of solar systems. Each of these solar systems has a head pointer to a DLL of planets. This DLL is the representation of the solar system.
Each solar system has a planet that has a location. 
This location is represented in polar coordinates. Where the distance from the sun is the r value and the degree difference from the sun is the degree value.  
The user is given a space ship to travel around the solar system in. The user enters a coordinate to travel to , then the time it takes to get there is calculated.  
The planets are all then moved based on their orbital speed and the amount of time taken to travel.  
If a planet is within range of a spaceship then the planets informations is displayed.
