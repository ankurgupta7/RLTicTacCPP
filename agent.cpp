#include "agent.h"

int randi(int a, int b)
{
    return (a + rand()%(b-a));
}
double randd(int a, int b)
{
    std::random_device rd;
    std::mt19937 mt(rd());
    std::uniform_real_distribution<double> dist(a,b);
    return dist(mt);
}

using namespace std;

Agent::Agent()
{
    type = AgentHuman;
}

Agent::Agent(Agent::agentType type):
    type(type)
{

}

void Agent::initAgent(char inputChar)
{
    switch(inputChar)
    {
    case 'X' : repChar = AgentCharX;
        break;
    case 'O' : repChar = AgentCharO;
        break;
    default : cerr << "agent can only be X or O";
        exit(1);
    }
}

int Agent::takeNextAction(vector<char> &env_board)
{
    env_board;
    int pos;
    cout << "take your turn. choose from numbers on-screen" ;
    cin >> pos;
    return pos;
}

void Agent::reward(double value, vector<char> &env_board)
{
    env_board;
    //        cout << repChar << "rewarded " << value << endl;
}

vector<int> Agent::validActions(std::vector<char> &env_board)
{
    std::vector<int> v;
    for(int i = 0; i < 9; ++i)
        if(env_board[i] == '-')
            v.push_back(i+1);

    return v;
}
