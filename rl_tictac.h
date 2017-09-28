#ifndef RL_TICTAC_H
#define RL_TICTAC_H


#include "agent.h"
using namespace std;

class RLTicTac
{
public:


    RLTicTac(Agent &PX, Agent &P0);

    void playGame();

    bool agentWins(char inputChar);

    bool isGameTie();

    void printEnv();

private:
    vector<char> env_board;
    Agent &PX;
    Agent &PO;
    Agent::agentChar curAgentTurn;
};


#endif
