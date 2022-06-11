#include "Team.hpp"
#include "Leauge.hpp"
#include "Game.hpp"

#include <algorithm>

namespace arieleauge{
    class Schedule{
        private :
        Team *home;
        Team *away;
        vector<Team*> leg_t;
        vector<Team*> sorted_t;
        Team* W_S;
        Team* L_S;
        Team* M_W_O;
        Team* M_L_H;
        int Score_M;


        

        public :
        Schedule(vector<Team*> tes);
        void get_stat();
        static vector<Team*> sort_t(vector<Team*> tim);
        void win_strk();
        void lose_strk();
        void score_more();
        void win_out_strk();
        void lose_home_strk();
        void leaders(int x);

    };
};