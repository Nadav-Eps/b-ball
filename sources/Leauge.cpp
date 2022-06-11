#include "Leauge.hpp"
const vector<string> v = {"Tel-Aviv","Holon","Ariel","Modiin","Kasem","Eilat","Jeruz","Bat-Yam","Hertzelia","Nadav","Yosii","CPP","Python","Java","Java-scr","Html","CSS","Messi","Ronaldo","Neymar"};
const int MAX_TEAMS = 20;

namespace arieleauge{
    Leauge::Leauge(vector<Team*>&tims){//CHECK CHANGES HERE &!!!!!!!!!!@@@@@@@
        if(tims.size()>MAX_TEAMS){throw invalid_argument("There are more then 20 teams !! need 20 or less to init the leauge");}

        if(tims.size()==MAX_TEAMS){teams = tims;}

        else{
            teams = tims;
            int adds = (int)(MAX_TEAMS - tims.size());
            size_t idx = 0;
            while(adds>0){
                if(check_t(v.at(idx))){
                    Team* tmp = new Team(v.at(idx),((double) rand() / (RAND_MAX)));
                    teams.push_back(tmp);
                    adds--;
                }
                idx++;
            }
        }
        }

    Leauge::Leauge(){
        for (size_t i = 0; i < MAX_TEAMS; i++)
        {
            Team *tmp = new Team(v.at(i),((double) rand() / (RAND_MAX)));
                    teams.push_back(tmp);
        }
        
    }

    bool Leauge::check_t(string const &s)const{
        bool flag = true;
        for (size_t i = 0; i < teams.size(); i++)
        {
            if(teams.at(i)->getName()==s){
                flag = false;
            }
        }
        
        return flag;
    }
}

