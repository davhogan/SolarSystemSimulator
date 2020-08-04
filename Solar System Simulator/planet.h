#include <iostream>
#include <cctype>
#include <cstring>
#include <cstdlib>
#include <stdlib.h>
#include <math.h>

//The purpose of this class is to represent a planet in a DLL
//A planet has a name,distance from sun, a radius, a type, an atmosphere, a number of moons.
//The planets information will be randomly generated based on parameters mirrored by planets in our solar system.
class pnode
{
   public:
          pnode();
          virtual void test()=0;//Make the class abstract
          //Wrapper functions
          bool getName(const pnode * a_planet, char * &name);//Get the planet's name
	  bool getDistance(const pnode * a_planet, int & a_distance);//Get the planet's distance from the sun
	  bool getAtmo(const pnode * a_planet, int & atmo);//Get the planet's atmosphere
	  bool getNumMoons(const pnode * a_planet, int & numMoons);//Get the number of moons
          bool getRadius(const pnode * a_planet, int & a_radius);//Get the planet radius 
          bool getType(const pnode * a_planet, char a_type[6]);//Get the type of planet
          bool getHabitable(const pnode * a_planet, bool & is_habitable);//Find out if planet is habitable
          bool getNumRings(const pnode * a_outPlanet, int & rings);//Get amount of rings the planet has
          bool setDegree(pnode * &a_planet,const float &a_degree);//Set the degree coordinate 
          bool getDegree(const pnode * a_planet, float &a_degree);//Get degree coordinate
          bool getRate(const pnode * a_planet, float &a_degree);//Get the orbital velocity
          bool setDegree(float a_degree);//Set the degree coord
         //DLL nodes
          pnode * next;
         pnode * prev;

      
   protected:
          char * name;//The name of the planet
          int distance;//The distance from sun
          int radius;//The radius of the planet
          char type[6];//Set to size six because the word will either be inner or outer;
          int atmo;//Type of atmosphere of the planet
          int numMoons;//Number of moons a planet has
          bool habitable;//If a planet is habitable
          int rings;//number of rings
          float rate;//orbital velocity of planet
         float degree;//degree coordinate                  
};

//The purpose of this class is to represent the data of an inner planet.
//An inner planet is a pnode
class inner: public pnode 
{

   public:
          inner();
          inner(int a_distance,char * name,float sun_mass);//Constructor that takes in a randomly generated distance and name
         void test(); 
};

//The purpose of this class is to represent the data of an outer planet
//An outer planet is a pnode
class outer: public pnode
{

  public:
         outer();
         outer(int a_distance, char * a_name,float sun_mass);//Constructor that takes in a randomly generated distance and name
         void test(); 
  
};

//The purpose of this class is to represent a space ship for the user to control.
//The space ship has a velocity as well as a location in polar coord form
class ship
{
  
   public:
          ship();//constructor
          
         bool  setRad(int r);//set the r coord
         bool setDegree(float a_degree);// set the degree coord

         bool getVelocity(const ship *a_ship,float &vel);//get the velocity of the ship
         bool getRad(const ship *a_ship,int &r);//get the r coord
         bool getDegree(const ship *a_ship, float &a_degree);//get the degree coord
        
         
   private:
         float velocity;
         int rad;
         float degree;
}; 
