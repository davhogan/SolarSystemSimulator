#include "solar.h"
///This is the galaxy class.
//The class has a randomly generated amount of solar sytems(between 1-5). A galaxy also has an array of all the solar systems generated.
class galaxy
{
   public:
          galaxy();
          bool getNumSolars(const galaxy & a_galaxy, int & numSolar);//Wrapper function to retrieve the amount of solar systems
          solarSys *solar_list;//Array of solar systems
   protected:
         int  numSolars; //Number of solar systems in the galaxy.
       
};
