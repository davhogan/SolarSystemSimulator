#include "galaxy.h"
#include <time.h>
const int MAX_SOLAR = 4;//Maximum amount of solar systems - 1
using namespace std;

galaxy::galaxy()
{

   numSolars = rand()%MAX_SOLAR+2;//Generate 2 - 5 number of solar systems.
   solar_list = new solarSys[numSolars];  //Initalize the list of solar systems
}

//Wrapper function
//Takes in a galaxy object and an integer of the number of solar systems passed by reference
//The number of solar systems from the galaxy is assigned to the passed in umber of solar systems.
bool galaxy::getNumSolars(const galaxy & a_galaxy, int & numSolar)
{

      numSolar=a_galaxy.numSolars;
      return true;
}
