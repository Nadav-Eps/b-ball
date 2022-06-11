#pragma once
#include "Team.hpp"

namespace arieleauge{
    class Leauge{
        private : 
        vector<Team*> teams;

        public :
        Leauge(vector<Team*>&tims);
        Leauge();
        bool check_t(string const &s) const;
        vector<Team*> get_teams(){return teams;}
        
    };
}