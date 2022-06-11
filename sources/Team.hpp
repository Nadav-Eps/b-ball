#pragma once
#include <iostream>
#include <vector>
#include <random>
#include <cmath>
#include <fstream>
#include <sstream>
#include <stdexcept>
using std::string;
using std::vector;
using std::invalid_argument;

namespace arieleauge{
    class Team{
        private:

        string name;
        int wins;
        int loses;
        int differnce;
        double level;
        int winStreak;
        int max_winStreak;
        int loseStreak;
        int max_loseStreak;
        int winOutStreak;
        int max_winOutStreak;
        int loseHomeStreak;
        int max_loseHomeStreak;
        
        public:

        Team();
        Team(string namei ,double lvl);

        string getName(){return name;};
        
        int getWins()const{return wins;};
        
        void setWins(){wins++;};
        
        int getLoses()const{return loses;};
        
        void setLoses(){loses++;};
        
        int getDif()const{return differnce;};
        
        void setDif(int dif){differnce+=dif;};
        
        double getLvl()const{return level;};

        int getWinStreak()const{return winStreak;};
        
        void setWinStreak(){winStreak++;};
        
        void resetWinStreak(){if(winStreak>max_winStreak){max_winStreak=winStreak;}winStreak=0;}
        
        int getLoseStreak()const{return loseStreak;};

        void setLoseStreak(){loseStreak++;};
        
        void resetLoseStreak(){if(loseStreak>max_loseStreak){max_loseStreak=loseStreak;}loseStreak=0;}

        int getWinOutStreak()const{return winOutStreak;};
        
        void setWinOutStreak(){winOutStreak++;
        if(winOutStreak>max_winOutStreak){max_winOutStreak=winOutStreak;}};
        
        void resetWinOutStreak(){if(winOutStreak>max_winOutStreak){max_winOutStreak=winOutStreak;}winOutStreak=0;}
        
        int getLoseHomeStreak()const{return loseHomeStreak;};

        void setLoseHomeStreak(){loseHomeStreak++;
        if(max_loseHomeStreak<loseHomeStreak){max_loseHomeStreak=loseHomeStreak;}};
        
        void resetLoseHomeStreak(){if(loseHomeStreak>max_loseHomeStreak){max_loseHomeStreak=loseHomeStreak;}loseHomeStreak=0;}
        
        void combineWin(int dif);
        
        void combineLose(int dif);

        static bool comp (const Team *a,const Team *b);
        



    };
};