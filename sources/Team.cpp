#include "Team.hpp"
using namespace std;
namespace arieleauge{
Team::Team(string namei, double lvl){
    if((lvl<=0)||(lvl>=1)){throw invalid_argument("Level must be a number between zero to one");}
    name =std::move(namei);
    wins = 0;
    loses = 0;
    differnce = 0;
    level = lvl;
    winStreak = 0;
    max_winStreak = 0;
    loseStreak = 0;
    max_loseStreak = 0;
    winOutStreak = 0;
    max_winOutStreak = 0;
    loseHomeStreak = 0;
    max_loseHomeStreak = 0;
    }

void Team::combineLose(int dif){
    setDif(-dif);
    setLoses();
    setLoseStreak();
    if(max_loseStreak<loseStreak){max_loseStreak=loseStreak;}
    resetWinStreak();

}

void Team::combineWin(int dif){
    setDif(dif);
    setWins();
    setWinStreak();
    if(max_winStreak<winStreak){max_winStreak=winStreak;}
    resetLoseStreak();

}
 bool Team::comp(const Team *a,const Team *b){
     bool flag = true;
    if(a->wins==b->wins){flag=a->differnce>b->differnce;}
    else{
        flag = (a->wins>b->wins);
    }
    return flag;
}

}