#pragma once
#include "Team.hpp"

using namespace std;

namespace arieleauge{
    class Game{
    private:
        Team *Home_T;
        Team *Away_T;
        Team *Winner_T;
        Team *Loser_T;
    public:

    Game(Team *home, Team *away);
    void Play();
    
    };
}