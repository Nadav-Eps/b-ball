#include "Game.hpp"
const int MAX_P_H = 46;
const int MAX_P_A = 51;
const int MIN_H = 55;
const int MIN_A = 50;
const int SKILL_P = 10;
const int AVG_A = 75;
const double AVG_H = 77.5;
const int Hound = 100;
const double tmp = 0.5;
using namespace std;

namespace arieleauge{
    Game::Game(Team *home, Team *away){
        if(home->getName()==away->getName()){throw invalid_argument("Teams with the same name cant play toghether!");}
        Home_T = home;
        Away_T = away;
        Winner_T =home;
        Loser_T = away;
    }

    void Game::Play(){
        std::random_device rd{};
        std::mt19937 gen{rd()};
        std::normal_distribution<> Awy (AVG_A,SKILL_P);
        std::normal_distribution<> Hom (AVG_H,SKILL_P);// CHECK IF NEEDS TO TO MORE RANDOM DEVICE AND MT19937

        int home_score = (int)(Hom(gen));
        int away_score = (int)(Awy(gen));
        

        if(home_score>Hound){home_score=Hound;}
        if(away_score>Hound){away_score=Hound;}
        if(home_score<MIN_H){home_score=MIN_H;}
        if(away_score<MIN_A){away_score=MIN_A;}

        int dif = 0;

        home_score += (int)(SKILL_P*Home_T->getLvl());
        away_score += (int)(SKILL_P*Away_T->getLvl());
        
        if(home_score>away_score){
            Winner_T = Home_T;
            Winner_T->resetLoseHomeStreak();
            Loser_T = Away_T;
            Loser_T->resetWinOutStreak();
            dif = home_score - away_score;
        }

        else if(away_score>home_score){
            Winner_T = Away_T;
            Winner_T->setWinOutStreak();
            Loser_T = Home_T;
            Loser_T->setLoseHomeStreak();
            dif = away_score - home_score;
        }

        else{
            bool flag = true;
            while(flag){
                int overTimeH = rand() % SKILL_P + 1;
                int overTimeA = rand() % SKILL_P + 1;
                if(overTimeA!=overTimeH){
                    flag=false;
                    if(overTimeA>overTimeH)
                        {
                        Winner_T = Away_T;
                        Winner_T->setWinOutStreak();
                        Loser_T = Home_T;
                        Loser_T->setLoseHomeStreak();
                        }
                    else
                        {
                        Winner_T = Home_T;
                        Loser_T->resetLoseHomeStreak();
                        Loser_T = Away_T;
                        Loser_T->resetWinOutStreak();
                        }
                    }

            }
            
        }
        Winner_T->combineWin(dif);
        Loser_T->combineLose(dif);
        // cout<<Winner_T->getName()<<" Wins vs : "<<Loser_T->getName()<<endl;
        // int w_s=0;
        // int l_s=0;
        // if(home_score>away_score){w_s=home_score;l_s=away_score;}
        // else{
        //     w_s=away_score;
        //     l_s=home_score;
        // }
        // cout<<"score is : "<< w_s<<"---"<<l_s<<endl; 

    }

}