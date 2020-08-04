#include "galaxy.h"
#include <time.h>
using namespace std;

const int MAX_DIST=6000;
//The purpose of this program is to simulate a galaxy. The galaxy will have a random number of solar systems.
//Each solar system will have a random amount of planets in it. A planet can either be an inner or outer planet.
//The program uses inheritance with both inner and outer planets sharing the same base class. This parent class holds all the data of a node in a DLL.
//The solar system itself is represented by a DLL of planets ordered by distance from the sun. A planet is defined as either inner or outer by its distance from the sun
//All data from number of solar systems to the information of the planet is randomly generated. The ranges for a planet's information varries depending if it is an inner or outer planet.
//The galaxy is represented by an array of solar systems. Each of these solar systems has a head pointer to a DLL of planets. This DLL is the representation of the solar system.
//Each solar system has a planet that has a location. This location is represented in polar coordinates. Where the distance from the sun is the r value and the degree difference from the sun is the degree value. The user is given a space ship to travel around the solar system in. The user enters a coordinate to travel to , then the time it takes to get there is calculated. The planets are all then moved based on their orbital speed and the amount of time taken to travel. If a planet is within range of a spaceship then the planets informations is displayed.
int main()
{
   srand(time(NULL));//Seed the rand
   
   int numP;//Number of planets in a solar system
   int sRad;//Suns radius
   int dist;//distance from the sun
   int numS;//number of Solar systems
   int curr_r;//current r coordinate for the ship's location
   int r;//r coordinate for the ships desired location
   int s_choice=-1;//Which solar system in the array to show
   char user_res;
   char * a_name;//name of a planet
   float mass;//mass of the sun of a solar system
   float curr_deg;//degree coordinate for the space ship's location
   float deg;//degree coordinate for spaceship
   float rate;//rate at which the ship travels
   float hours;
   pnode * my_p=NULL;
   galaxy my_galaxy;//galaxy obj
   solarSys my_solar;//solar obj
   ship *my_ship=new ship;   
   my_galaxy.getNumSolars(my_galaxy,numS);//Get the number of solar systems in the galaxy object
   //List of char[] containing planet names      
   char list[NUM_WORDS][MAX_LEN]={"Alphabetrium","Bird World","Parblesnops", "Gazorpazorp","Gear World", "Snorlab", "Dwarf Terrace", "Flarbellon-7", "Gromflom Prime", "Planet Squanch","Vulcan","Andoria","Risa","Caldik Prime","Draylax","Endicor","Nibiru","Wolf 359","Remus","Vendikar","Decapod 10","Nylar 4","Chapek 9","Amazonia","Cygnus 5","Omicron Persei 8","Neutral Planet","Spheron 1","Tarantulon 6","Eternium","Terminus","Eos","Helicon","Libair","Trantor","NeoTra","Anacreon","Comporellon","Kalgan","Sayshell","Zanzabar","Mesklin","Nacre","Pandora","Reach","Arrakis","Caladan","Zyrgon","Ulgethon","Solaris"};
  
//Fill the galaxy
//Goes through the array of solar systems in a galaxy and generates a DLL of planets for each solar system
  for(int i=0;i<numS;++i)
 { 
    my_solar.getNumPlanets(my_galaxy.solar_list[i],numP);//Get the number of planets in the current solar system
    my_solar.getSunMass(my_galaxy.solar_list[i],mass);
    //Fill the current solar system with planets.
    for(int j=0;j<numP;++j)
    {  
       dist=rand()%MAX_DIST+35;//generate a distance between 35-6000 million km
       my_galaxy.solar_list[i].generateName(a_name,list);//Get a name from the list of names
       //Genertate a new planet
       if(dist<500)//Planet is within the terra zone limit
       {
          my_p=new inner(dist,a_name,mass);//create an inner planet
       }
       else//Planet is outside the terra zone limit
       {
          my_p=new outer(dist,a_name,mass);//create an outer planet
       }
       my_galaxy.solar_list[i].insertPlanet(my_galaxy.solar_list[i].head,my_galaxy.solar_list[i].head,my_p);//Insert newly generated planet into the solar system
    }
  }

   cout<<"The number of Solar Systems in the galaxy are: "<<numS<<endl<<endl;
     //Let the user decide which solar system to explore
     while(s_choice!=0)
     {
       s_choice=-1;
       for(int i=0; i<numS;i++)
         cout<<"Solar System["<<i+1<<"]"<<endl;
      
        while(s_choice<1 || s_choice>numS+1)//check for correct index
        {
          cout<<endl<<"Please enter the number for which solar system you would like to explore. Or enter zero to quit"<<endl;
          cin>>s_choice;
          cin.ignore(100,'\n');
            
           if(s_choice==0)
            {   
                 cout<<"Program ending"<<endl;
                 return 1;
            }

           if(s_choice<1 || s_choice>numS+1)
            cout<<"Please enter a number between 1-"<<numS<<endl;
        }
        
           
       my_solar.getSunRadius(my_galaxy.solar_list[s_choice-1],sRad);  //Get the radius of the current solar system's sun
       my_solar.getNumPlanets(my_galaxy.solar_list[s_choice-1],numP); //Get the amount of planets in the current solar system
       my_ship->getVelocity(my_ship,rate);//Get the velocity of the ship.

       cout<<"The Sun's radius is: "<<sRad<<"kms"<<endl;
       cout<<"The number of planets in the solar system are: "<<numP<<endl;
       cout<<"Ship rate is: "<<rate<<" thousand km/h"<<endl<<endl; 

       user_res='X';//reset the user's response

        while(user_res!='2')
        {
            my_ship->getDegree(my_ship,curr_deg); //get the coordinates of the ship
            my_ship->getRad(my_ship,curr_r);//get the coordinates of the ship
            cout<<"Ship coords are: "<<curr_r<<","<<curr_deg<<" degrees"<<endl<<endl;
      
            cout<<"The current locations of the planets are:"<<endl;
            my_solar.displayLocations(my_galaxy.solar_list[s_choice-1].head,my_ship);//Display all locations of the planets in the current solar system.
            
            cout<<endl<<"[1] To go to a new location. Planet will automatially be scanned when the ship is within 10 million kms"<<endl;
            cout<<"[2] To go back to the list of solar systems"<<endl; 
            cin>>user_res;
            cin.ignore(100,'\n');

            if(user_res=='1')
            {
               cout<<"Enter the radius for your polar coordinate: "; 
               cin>>r;
               cin.ignore(100,'\n');

               cout<<"Enter the degree for your polar coordinate: ";
               cin>>deg;
               cin.ignore(100,'\n');
               
               hours=sqrt((curr_r*curr_r+r*r)-2*curr_r*r*cos(curr_deg-deg))/10;//Get the number of hours it takes to travel
 
               cout<<"The number of hours to travel to new location are: "<<hours<<endl<<endl;

               my_galaxy.solar_list[s_choice].movePlanets(my_galaxy.solar_list[s_choice-1].head,hours);//rotate planets around the sun
        
               my_ship->setRad(r);//move the ship
               my_ship->setDegree(deg);//move the ship

               my_ship->getDegree(my_ship,curr_deg); //get new location of the ship 
               my_ship->getRad(my_ship,curr_r);//get new location of the ship
               cout<<"Ship coords are: "<<r<<","<<deg<<" degrees"<<endl;
      
               user_res=-1;//reset the user's response
            }
           
           if(user_res=='2')//get out of while loop
              break;
        }
     }  
return 1;

}
