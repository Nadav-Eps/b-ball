#include "doctest.h"
#include <vector>
#include <stdexcept>
#include <string>

#include"Game.hpp"
#include"Leauge.hpp"
#include"Team.hpp"
#include"Schedule.hpp"
//#include "Game.cpp"
const int NUM_T = 20;
const int SOM_T = 10;
using namespace std;
using namespace arieleauge;

TEST_CASE("Good Tests"){
CHECK_NOTHROW(Leauge lg = Leauge());//creates a leauge without giving teams
Leauge lg = Leauge();
CHECK_EQ(NUM_T,lg.get_teams().size());//Checks there are 20 teams in the leauge
vector<Team*> teams = lg.get_teams();

for (size_t i = 0; i < NUM_T; i++) //Checks teams level is  0<lvl<1
{
    CHECK(0<teams.at(0)->getLvl());
    CHECK(teams.at(0)->getLvl()<1);
}

for (size_t i = 0; i < NUM_T-1; i++)//Checks all the names of the teams are diffrent
{
    for (size_t j = i+1; j < NUM_T; j++)
    {
        CHECK_FALSE(teams.at(i)->getName()==teams.at(j)->getName());
    }
    
}

//Now lets try and create vector with less then 20 teams and create a new leauge !
vector<Team*> vec_t;
for (size_t i = 0; i < SOM_T; i++)
{
    string nm = std::to_string(i);
    vec_t.push_back(new Team(nm,0.5));
}

CHECK_EQ(10,vec_t.size()); // Now we have a vector with 10 teams
Leauge lg1 = Leauge(vec_t);
CHECK_EQ(NUM_T,lg1.get_teams().size());//Checks there are 20 teams in the leauge

vector<Team*> teams1 = lg1.get_teams();
//Lets run again the tests we did on the first leauge to check the leauge is valid!
for (size_t i = 0; i < NUM_T; i++) //Checks teams level is  0<lvl<1
{
    CHECK(0<teams1.at(0)->getLvl());
    CHECK(teams1.at(0)->getLvl()<1);
}

for (size_t i = 0; i < NUM_T-1; i++)//Checks all the names of the teams are diffrent
{
    for (size_t j = i+1; j < NUM_T; j++)
    {
        CHECK_FALSE(teams1.at(i)->getName()==teams1.at(j)->getName());
    }
    
}

//now lets add to our vector 10 more teams and try to create the leauge with vector filled by 20 teams!
for (size_t i = 10; i < NUM_T; i++)
{
    string nm = std::to_string(i);
    vec_t.push_back(new Team(nm,0.5));
}

CHECK_EQ(NUM_T,vec_t.size()); // Check that we have vector with 20 teams!
Leauge lg2 = Leauge(vec_t);
CHECK_EQ(NUM_T,lg2.get_teams().size());//Checks there are 20 teams in the leauge

vector<Team*> teams2 = lg2.get_teams();
//Lets run again the tests we did on the first leauge to check the leauge is valid!
for (size_t i = 0; i < NUM_T; i++) //Checks teams level is  0<lvl<1
{
    CHECK(0<teams2.at(0)->getLvl());
    CHECK(teams2.at(0)->getLvl()<1);
}

for (size_t i = 0; i < NUM_T-1; i++)//Checks all the names of the teams are diffrent
{
    for (size_t j = i+1; j < NUM_T; j++)
    {
        CHECK_FALSE(teams2.at(i)->getName()==teams2.at(j)->getName());
    }
    
}
//lets run the leauge games and check that its going 
CHECK_NOTHROW(Schedule(lg.get_teams()));
Schedule s = Schedule(lg.get_teams());
//lets check the Scheduler functions
CHECK_NOTHROW(s.leaders(3)); //checks the leadser function
CHECK_NOTHROW(s.lose_home_strk());
CHECK_NOTHROW(s.lose_strk());
CHECK_NOTHROW(s.score_more());
CHECK_NOTHROW(s.win_out_strk());
CHECK_NOTHROW(s.win_strk());
CHECK_NOTHROW(s.sort_t(lg.get_teams()));

//Lets try a game with two teams
Team a = Team("a",0.5);
Team b = Team("b",0.3);
Game g = Game(&a,&b);
CHECK_NOTHROW(g.Play());



}
TEST_CASE("Bad Tests"){
//lets try and create a leauge with more then 20 teams
vector<Team*> vec_t;
for (size_t i = 0; i < NUM_T+1; i++)
{
    string nm = std::to_string(i);
    vec_t.push_back(new Team(nm,0.5));
}
CHECK_THROWS(Leauge L=Leauge(vec_t));

//lets try to creaete teams with skill <=0 and >=1
CHECK_THROWS(Team tmp = Team("a",2));
CHECK_THROWS(Team tmp = Team("a",-1));
CHECK_THROWS(Team tmp = Team("a",1));
CHECK_THROWS(Team tmp = Team("a",0));

//Lets try to do a game with two teams with the same name

Team a = Team("a",0.5);
Team b = Team("a",0.3);
CHECK_THROWS(Game g = Game(&a,&b));
}