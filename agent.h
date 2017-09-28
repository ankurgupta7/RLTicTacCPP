#ifndef AGENT_H
#define AGENT_H

#include "rl_include.h"

class Agent
{
public:
    enum agentType
    {
        AgentHuman = 0,
        AgentMachine
    };
    enum agentChar
    {
        AgentCharX = 0,
        AgentCharO,
    };

    agentChar repChar;
    agentType type;

    Agent();

    Agent(agentType type);


    virtual void initAgent(char inputChar);

    virtual int takeNextAction(std::vector<char> &env_board);

    virtual void reward(double value, std::vector<char> &env_board);

    std::vector<int> validActions(std::vector<char> & env_board);

};

#endif
