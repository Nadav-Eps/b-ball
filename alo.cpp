#include "sources/Schedule.hpp"
#include "sources/Leauge.hpp"
#include "sources/Team.hpp"
#include "sources/Game.hpp"
const int SOM_T = 10;
using namespace std;
using namespace arieleauge;
//clang++-9 -o try alo.cpp sources/Schedule.cpp sources/Game.cpp sources/Leauge.cpp sources/Team.cpp && ./try
int main()
{
        

        Leauge nad = Leauge();

        Schedule s = Schedule(nad.get_teams());
        s.get_stat();


        // vector<Team*> vec_t;
        // for (size_t i = 0; i < SOM_T; i++)
        // {
        //         string nm = std::to_string(i);
        //         vec_t.push_back(new Team(nm,0.5));
        // }
        // Leauge nad1 = Leauge(vec_t); 
        // Schedule s1 = Schedule(nad.get_teams());
        // s1.get_stat();
      
        
        return 0;

}