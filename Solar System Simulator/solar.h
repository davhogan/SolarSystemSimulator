#include "planet.h"
const int NUM_WORDS=50;//Max number of words in the list of planet names
const int MAX_LEN=25;//Max length of a planets name

//The puropse of this class is create a solar system containing a random amount of planets. The system will be represented with a DLL of planets. The solar system will also have a sun reprsented by a random radius for the sun.
class solarSys
{
   public:
          solarSys();
          bool generateName(char * &name, char list[NUM_WORDS][MAX_LEN]);//Get a name for a planet from a list of planet names
          bool insertPlanet(pnode * &head, pnode * current, pnode * to_add);//Insert a planet into the DLL
          bool movePlanets(pnode * a_planet, int moves);
          void display(pnode * head);//Display a  planets info the solar system.
          void displayLocations(pnode * head,ship * a_ship);//Display the planet locations in polar coordinates 
         //Wrapper functions
         bool getSunRadius(const solarSys &a_solarSys, int & sun_radi);//Get the radius of the sun
         bool getNumPlanets(const solarSys &a_solarSys, int & num_Planets);//Get the number of planets in the solar system
         bool getSunMass(const solarSys &a_solarSys, float & mass);//get the mass of the sun
                 
          pnode * head;
   protected:
          int numPlanets;//number of planets in the solar system
          int  sun_radius;//the sun's radius
          float sun_mass;//The mass of the sun         
};
