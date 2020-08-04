#include "solar.h"
using namespace std;
const int MAX_NUM_PLANETS=5;
const int MIN_SUN_RADI=600000;

//Solar System
solarSys::solarSys()
{
   numPlanets=rand()%MAX_NUM_PLANETS+5;//Range of planets from 5 to 10
   sun_radius=rand()%100000+MIN_SUN_RADI;//Range of sun radius from 600000-700000
  sun_mass=3000;//trillion kgs
   head=NULL;

}

//The purpose of this function is to get a random name from a list of planet names.
//The function will get a random number in the range of the size of the list, then gets the name at the index. The function will generate a uniquie name for every planet.
bool solarSys::generateName(char * &name, char list[NUM_WORDS][MAX_LEN])
{
   int index;//The index of the array of names in the list
   
  //find a planet name in the list that hasn't been used yet
   do
   {
      index=rand()%NUM_WORDS;//get a number in the range of the size of the array of planet names
   }while(!strcmp(list[index],"NULL"));  
   
   name=new char[strlen(list[index])+1];//allocate memory for name

   strcpy(name,list[index]);//set the name to a random planet name in the list
   strcpy(list[index],"NULL");//set the char[] at the index to NULL
  
   return true;  
}

//The purpose of this function is to insert a new planet(represented as a pnode) into a DLL of planets. The DLL is ordered by the distance a planet is from the sun. Therfore the insertion of the planet will be based on the planet to add's distance fromt the sun.
//The function takes in the head of the list, a current planet pointer for the recurssive step, and the a pointer to the planet to add. The function will recursively go through the DLL until it finds the proper place to insert the planet.
bool solarSys::insertPlanet(pnode * &head, pnode* current, pnode* to_add)
{
  int to_add_dist;//distance from the sun of the planet to add
  int curr_dist;//distance from the sun of the current planet
 
  //Check if the planet to add exists
  if(to_add==NULL)
   return false;
//cout<<"Inside insert before get dist"<<endl;
  to_add->getDistance(to_add,to_add_dist);//Get the distance from the sun of the planet to add
 
  //Check if list is empty
  if(current==NULL)//List is empty
     curr_dist=0;
  else
    current->getDistance(current,curr_dist);//Get the distance from the sun of the current planet
     
  //Check if list is empty
  if(head==NULL)
  {
   to_add->next=NULL;
   to_add->prev=NULL;   
   head=to_add;//Add the planet
   return true;
  }
  //Check if the dist the planet to add is less than the distance of the current planet
  if(to_add_dist < curr_dist)
  {
   to_add->prev=current->prev;//Set planet to add's prev pointer
   to_add->next=current;//Set planet to add's next pointer
   // current->next=to_add;
    //Inserting at the front of a non empty list
    if(current->prev == NULL)
    {   
         head=to_add;//Point head to the new front of the DLL      
         
    }
    
    else//Inserting in the middle of the list
     current->prev->next=to_add;//Point the planet in front of the planet to add to the planet to add
     current->prev=to_add; 
   return true;
  }
  
  //Inserting at the end of the list
  if(current->next==NULL)
   {
     current->next=to_add;//Add the planet to the end of the list
     to_add->next=NULL;//Make sure the end of the list is pointing to NULL
     to_add->prev=current;//Point the planet to add's previous to the current planet
     return true;
  }

  else
    //Recurssive Step
    insertPlanet(head,current->next,to_add);
  return true;
}

//The purpose of this function is to recursivelly go through the list of planet's in a solar system and move them based on how many hours the ship travels for.
bool solarSys::movePlanets(pnode * head,int hours)
{
   float vel;//orbital velocity of planet;
   float deg;

    if(head==NULL)
      return true;

   head->getRate(head,vel);//get the current planet's orbital velocity 
   head->getDegree(head,deg);//get the current planet's degree coord
   deg=deg+(hours*vel);//move the planet 

   //Keep the degreecoordinate between 0-360
   while(deg>=360.0)
  {    
     deg=deg-360.0;
  }

   head->setDegree(deg);//set the new degree coord

   return movePlanets(head->next,hours);//recursive step
}

//The purpise of this function is to recursivelly go through the list of planets and display their current location. If the ship's is coordinates are with in 10 million ms of the planet's coords then the planet's info is displayed
void solarSys::displayLocations(pnode * head, ship * a_ship)
{
   int dist;//distance from the sun also radius coordinate
   int rad;//radius coordinate of the ship 
   char * name;
   float s_degree;//ships degree coordinate
   float p_degree;//planets degree coordinate
   double diff;
  
 //base case
   if(head==NULL)
     return;
  
  head->getName(head,name);//get the name of the planet
  head->getDistance(head,dist);//get the distance from the sun
  head->getDegree(head,p_degree);//get the degree coord

  a_ship->getDegree(a_ship,s_degree);//get the ships degree coord
  a_ship->getRad(a_ship,rad);//get the ships r coord

  cout<<name<<" is at location: "<<dist<<","<<p_degree<<" degrees"<<endl;
  diff=sqrt((rad*rad+dist*dist)-2*rad*dist*cos(s_degree-p_degree));//calculate differnece between planet and ship
 
 if(diff<10)//check if planet is with in scannning distance
{
   cout<<"Planet Scanned"<<endl;
   display(head);//display the planets info
   cout<<endl;
}
 displayLocations(head->next,a_ship);
  

}
//The purpose of this function is to display the information of a single planet.
//This is achieved by taking in the a pointer to a planet in the solar system and then displaying the planet's information
void solarSys::display(pnode * head)
{
  char * name;//Name of the planet
  char type[6];//Type of planet either "Inner" or "Outer"
  int nMoons;//Number of moons the planet has
  int radi;//The radius of the planet
  int dist;//The planet's distance from the sun 
  int atm;//The atmosphere of the planet
  float a_rate;//Oribital velocity of planet
  float a_degree;//degree portion of polar coordinate for location of planet
  bool is_habit;//Is the planet habitable
  
  //base case
  if(head==NULL)
  {
   return;
  }

  head->getName(head,name);//Get planet name
  head->getDistance(head,dist);//Get distance from the sun
  head->getRadius(head,radi);//Get the radius of the planet
  head->getType(head,type);//Get the type of planet
  head->getAtmo(head,atm);//Get the atmospher of the planet
  head->getNumMoons(head,nMoons);//Get the number of moons the planet has
  head->getHabitable(head,is_habit);//Get if the planet is habitable
  head->getRate(head,a_rate);//Get the orbital velocity of the planet;
  head->getDegree(head,a_degree);//Get the degree for the polar  coordinate of the planets location. 
  //Display planet info
  cout<<endl<<"Planet Info:"<<endl;
  cout<<"Name: "<<name<<endl;
  cout<<"Distance from Sun: "<<dist<<" million kms away from sun"<<endl;
  cout<<"Type of planet: "<<type<<endl;
  cout<<"Radius is: "<<radi<<" kms"<<endl;
  //If else to check for tyoe of atmosphere
  if(atm==0)
   cout<<"Atmosphere is: Absent."<<endl;
  else if(atm==1)
   cout<<"Atmosphere is: Breathable."<<endl;
  else if(atm==2)
   cout<<"Atmosphere is: Poisonious."<<endl;

  cout<<"Number of Moons is: "<<nMoons<<endl;
  //Check if the planet is habitable
  if(is_habit)
    cout<<"Is habitable"<<endl;
  else
   cout<<"Isn't habitable"<<endl;
  
  cout<<"Planet's orbital velocity: "<<a_rate<<endl;
  cout<<"Planet's location is: "<<dist<<","<<a_degree<<endl;
}

//Wrapper Functions

//Get the solar systems sun's radius
bool solarSys::getSunRadius(const solarSys &a_solarSys, int & sun_radi)
{
 
    sun_radi=a_solarSys.sun_radius;
    return true;
}

//Get the amount of planets in the solar system 
bool solarSys::getNumPlanets(const solarSys &a_solarSys,int & num_Planets)
{

   num_Planets=a_solarSys.numPlanets;
   return true;
}

bool solarSys::getSunMass(const solarSys &a_solarSys, float & mass)
{
  mass=a_solarSys.sun_mass;
  return true;
}
