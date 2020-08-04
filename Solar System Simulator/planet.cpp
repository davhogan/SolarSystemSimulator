#include "planet.h"
using namespace std;

const int MAX_DIST = 6000;//Max Distance of from the sun in million kms
const int MAX_OUTER_RADI=70000;//Max radius of an outer planet in kms
const int MAX_INNER_RADI=6500;//Max radius of inner planets in kms
const int MAX_ATMO=3;//Max amount of diferent atmospheres
const int MAX_OUTER_MOONS=70;//Max amount of moons an outer planet can have
const int MAX_INNER_MOONS=2;//Maximum amount of moons an inner planet can have 
const int MAX_RINGS=4;//Maximum amount of rings an outer planet can have



//Pnode default constructor
pnode::pnode()
{

   next=NULL;
   prev=NULL;
}

//virtual void pnode::test=0;
//Wrapper funtions.
//These functions will get the information of the planets 

//Get the name of the planet
bool pnode::getName(const pnode * a_planet, char * & name)
{
   if(a_planet==NULL)
     return false;

   name=new char[strlen(a_planet->name)+1];
   strcpy(name,a_planet->name);
   return true;
}
//Get the number of moons a planet has
bool pnode::getNumMoons(const pnode * a_planet, int & nMoons)
{  
   if(a_planet==NULL)
      return false;

   nMoons=a_planet->numMoons;
   return true;
}
//Get the planets distance from the sun
bool pnode::getDistance(const pnode * a_planet, int & a_distance)
{ 
   if(a_planet==NULL)
      return false;

   a_distance=a_planet->distance;
   return true;
}
//Get the atmoshere of the planet
bool pnode::getAtmo(const pnode* a_planet, int & an_atmo)
{
    if(a_planet==NULL)
      return false;

    an_atmo=a_planet->atmo;
    return true;
} 
//Get the radius of the planet 
bool pnode::getRadius(const pnode * a_planet, int & a_radius)
{
     if(a_planet==NULL)
      return false;

    a_radius=a_planet->radius;
    return true;
}
//Get the type of planet
bool pnode::getType(const pnode * a_planet, char a_type[6])
{
    if(a_planet==NULL)
      return false;

    strcpy(a_type,a_planet->type);
    return true;
}
//Find if planet is habitable
bool pnode::getHabitable(const pnode * a_planet, bool & is_habitable)
{
    if(a_planet==NULL)
     return false;

    is_habitable=a_planet->habitable;
    return true;
}
//Get the number of rings for an outer planet.
bool pnode::getNumRings(const pnode * a_outer,int & rings)
{
   if(a_outer==NULL)
     return false;

   rings=a_outer->rings;
   return true;
}

//Set location
bool pnode::setDegree(pnode * &a_planet,const float &a_degree )
{
    a_planet->degree=a_degree;
    return true;
}

//Get the degree coord of the planet
bool pnode::getDegree(const pnode * a_planet, float &a_degree)
{
   a_degree=a_planet->degree;
   return true;
}

//Get the orbital velocity of the planet
bool pnode::getRate(const pnode * a_planet, float &a_rate)
{
    a_rate=a_planet->rate;
    return true;
}

//Set the degree coord for the planet
bool pnode::setDegree(float a_degree)
{
  degree=a_degree;
}

//Default constructor for inner
inner::inner()
{
}

void inner::test()
{
 cout<<"TEST IN INNER"<<endl;
 return;
}
//Constructor for an inner planet that takes in the distance and the name of the planet.
//The distance and the planets name will be randomly generated when making the planet
inner::inner(int a_distance, char * a_name, float sun_mass)
{
   name=new char[strlen(a_name)+1];//Allocate memory for the planet's name
   strcpy(name, a_name);//Assign the planet's name to the passed in name
   distance=a_distance; //Assign the planet's distance to passed in distance
   radius=rand()%MAX_INNER_RADI+2500;//range from 2500-6500 km radius
   strcpy(type,"Inner"); //Type of planet is inner
   atmo=rand()%MAX_ATMO;//range from 0-2. 0 equals an absence of an atmosphere. 1 is breathable. 2 is poisionous.
   numMoons=rand()%MAX_INNER_MOONS+1;//range from 1 to 2  moons

   if(distance> 134 && distance< 226 && atmo==1)//distance is set up for the habitable zone based on our solar system 
      habitable=true;//Is in the habitabe zone and has a breathable atmosphere
   else
      habitable=false;

    degree=rand()%360;//get a degree value from 0-359
    rate=sun_mass/distance;//generate a orbital velocity
}

//Default constructor for outer
outer::outer()
{
}

void outer::test()
{
  cout<<"IN OUTER TEST"<<endl;
  return;
}
//Constructor for an outer planet that takes in the distance and the name of the planet.
//The distance and the planets name will be randomly generated when making the planet
outer::outer(int a_distance,char * a_name,float sun_mass)
{
   name=new char[strlen(a_name)+1];//Allocate memory for the planet's name 
   strcpy(name, a_name);//Assign the planet's name to the passed in name 
   distance=a_distance;//Assign the planet's distance to passed in distance
   radius=rand()%MAX_OUTER_RADI+20000;//range from 20000-70000 km radius
   strcpy(type,"Outer"); //Assign the type to 
   atmo=2;//Atmosphere is 2 to represent poisonious
   numMoons=rand()%MAX_OUTER_MOONS+10;//range from 10 to 70 moons
   habitable=false;//Outer planet not habitable
   degree=rand()%360;//get a degree value from 0-359
   rate=sun_mass/distance;//generate a orbital velocity 
   rings=rand()%MAX_RINGS+1;//range of rings from 1-4
 
}

ship::ship()
{
  velocity=1;//velocity of 1000 km per hour
  rad=25;//start at 25 thousand km from the sun
  degree=0;//start at 0 degree
}

//This function sets the r coord of the ship
bool ship::setRad(int r)
{
   rad=r;
   return true;
}

//This function sets the degree coord of the ship
bool ship::setDegree(float a_degree)
{
   degree=a_degree;
   return true;
}
//This function gets the velocity of the ship
bool ship::getVelocity(const ship *a_ship, float &vel)
{
   vel=a_ship->velocity;
  return true;
}
//This function gets the r coord of the ship
bool ship::getRad(const ship *a_ship, int &r)
{
   r=a_ship->rad;
   return true;
}
//This function gets the degree coord of the ship
bool ship::getDegree(const ship *a_ship, float &a_degree)
{
  a_degree=a_ship->degree;
  return true;
}
