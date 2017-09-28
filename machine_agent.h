#ifndef MACHINE_AGENT_H
#define MACHINE_AGENT_H

#include "agent.h"

class MachineAgent: public Agent
{
public:
    using state_ =  std::vector<char >;
    using action_ =  int;
    using state_action_pair = std::pair<state_, action_> ;


    MachineAgent(double epsilon,
        double alpha,
        double gamma);

    double getQ(state_ state, action_ action);

    virtual int takeNextAction(std::vector<char> &env_board);

    void reward(double value, std::vector<char> &env_board);

    void updateQValue(state_ state, action_ action, double reward_cur, state_ result_state);


    double epsilon ;
    double alpha;
    double gamma;
private:
    std::vector<char> last_board;
    int last_move = -1;
    // vector<state_> states;
    // vector<int> actions;
    // vector<int, int> state_actions_pair

    std::map< state_action_pair , double> Q;
};

#endif
