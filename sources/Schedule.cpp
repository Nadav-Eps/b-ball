#include "Schedule.hpp"
// #include "Team.hpp"
// #include "Leauge.hpp"
// #include "Game.hpp"
using namespace std;

namespace arieleauge{
    Schedule::Schedule(vector<Team*> tes){ 
        W_S = nullptr;
        L_S = nullptr;
        M_W_O = nullptr;
        M_L_H = nullptr;
        Score_M = 0;
        leg_t = tes;
        for (size_t i = 0; i < tes.size(); i++)
        {
            for (size_t j = i+1; j < tes.size(); j++)
            {
                home = tes.at(i);
                away = tes.at(j);
                Game tmp = Game(home,away);
                Game tmp1 = Game(away,home);
                tmp.Play();
                tmp1.Play();
                
            }
            
        }
       
        sorted_t = sort_t(leg_t);
        win_strk();
        lose_strk();
        score_more();
        win_out_strk();
        lose_home_strk();
        // get_stat();

    };

    void Schedule::get_stat(){
        cout<<"Some of the statics of the Nadav's leauge : "<<endl;
        cout<<"___________________________________________"<<endl;
        cout<<"Leauge Table :"<<endl;
        for (size_t i = 0; i < sorted_t.size(); i++)
        {
            cout<<i+1<<") "<<sorted_t.at(i)->getName()<<", Wins-Loses : "<<sorted_t.at(i)->getWins()<<"-"<<sorted_t.at(i)->getLoses()<<", Score difference : "<<sorted_t.at(i)->getDif()<<endl;
        }
        cout<<endl;
        cout<<"Longest win streak was for the "<<W_S->getName()<<" team and he lasted "<<W_S->getWinStreak()<<" games!"<<endl;
        cout<<endl;
        cout<<"Longest lose streak was for the "<<L_S->getName()<<" team and he lasted "<<L_S->getLoseStreak()<<" games!"<<endl;
        cout<<endl;
        cout<<"Number of clubs that scored more then concided is : "<<Score_M<<endl;
        cout<<endl;
        cout<<"We bring you some more statics this year such as longest win streak playing away and longest lose streak playing home :"<<endl;
        cout<<endl;
        cout<<"Longest lose streak playing home "<<M_L_H->getName()<<" team and he lasted "<<M_L_H->getLoseHomeStreak()<<endl;
        cout<<endl;
        cout<<"Longest win streak playing away "<<M_W_O->getName()<<" team and he lasted "<<M_W_O->getWinOutStreak()<<endl;
        
    }

    vector<Team*> Schedule::sort_t(vector<Team*> tim){
        vector<Team*> tmp = std::move(tim);
        std::sort(tmp.begin(),tmp.end(),Team::comp);
     
        return tmp;    
    }

    void Schedule::win_strk(){
        int tmp = 0;
        for (size_t i = 0; i < leg_t.size(); i++)
        {
            if(leg_t.at(i)->getWinStreak()>tmp){
                tmp = leg_t.at(i)->getWinStreak();
                W_S = leg_t.at(i);
            }
        }
        
    }

    void Schedule::lose_strk(){
        int tmp = 0;
        for (size_t i = 0; i < leg_t.size(); i++)
        {
            if(leg_t.at(i)->getLoseStreak()>tmp){
                tmp = leg_t.at(i)->getLoseStreak();
                L_S = leg_t.at(i);
            }
        }
        
    }

    void Schedule::score_more(){
        int ans = 0;
        for (size_t i = 0; i <leg_t.size() ; i++)
        {
            if(leg_t.at(i)->getDif()>0){ans++;}
        }
        Score_M = ans;
         
    }
    void Schedule::win_out_strk(){
        int tmp = 0;
        for (size_t i = 0; i < leg_t.size(); i++)
        {
            if(leg_t.at(i)->getWinOutStreak()>tmp){
                tmp = leg_t.at(i)->getWinOutStreak();
                M_W_O = leg_t.at(i);
            }
        }
        
    }

    void Schedule::lose_home_strk(){
        int tmp = 0;
        for (size_t i = 0; i < leg_t.size(); i++)
        {
            if(leg_t.at(i)->getLoseHomeStreak()>tmp){
                tmp = leg_t.at(i)->getLoseHomeStreak();
                M_L_H = leg_t.at(i);
            }
        }
      
    }

    void Schedule::leaders(int x){
        cout<<"The top "<<x<<" teams in the league are "<<endl;
        for (size_t i = 0; i < x; i++)
        {
           if(i!=x-1){ 
           cout<<sorted_t.at(i)->getName()<<", ";
           }
           else{
               cout<<sorted_t.at(i)->getName()<<endl;
           }       
        }
        
    }
   
}