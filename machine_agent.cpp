#include "machine_agent.h"

using namespace  std;

MachineAgent::MachineAgent(double epsilon, double alpha, double gamma):
    Agent(Agent::AgentMachine),
    epsilon (epsilon),
    alpha (alpha),
    gamma (gamma)
{
    last_board.assign(9, '-');
}

double MachineAgent::getQ(MachineAgent::state_ state, MachineAgent::action_ action)
{
    state_action_pair map_key = make_pair(state, action);
    auto val = Q.find(map_key);
    if(val == Q.end())
        Q[map_key] = 1;
    //        cout << Q.size() << " ";
    return Q[map_key];
}

int MachineAgent::takeNextAction(vector<char> &env_board)
{
    std::vector<action_> actions = validActions(env_board);
    int r;
    if(randd(0,100)/100.0 < epsilon)
    {
        last_move = actions [ randi(0,actions.size()) ];
        return last_move;
    }

    std::vector<double> qs;
    for(auto a:actions) qs.push_back(getQ(last_board, a));
    for(auto a:qs) cout << a << " ";
    cout << endl;
    auto maxQ_ = std::max_element(qs.begin(), qs.end());
    auto maxQ = *maxQ_;
    if(std::count(qs.begin(), qs.end(), maxQ) > 1)
    {
        std::vector<int> temp;
        for(size_t i = 0; i < qs.size(); ++i)
            if(qs[i] == maxQ)
                temp.push_back(i);
        r = randi(0,temp.size());

    }
    else
    {
        r = std::distance(qs.begin(), maxQ_);
    }

    last_move = actions[r];
    return actions[r];
}

void MachineAgent::reward(double value, std::vector<char> &env_board)
{
    if(last_move > -1)
        updateQValue(last_board,last_move,value,env_board);
}

void MachineAgent::updateQValue(MachineAgent::state_ state, MachineAgent::action_ action, double reward_cur, MachineAgent::state_ result_state)
{
    auto prev = getQ(result_state,action);
    std::vector<action_> actions = validActions(state);
    std::vector<double> qs;
    for(auto a:actions) qs.push_back(getQ(result_state, a));

    auto maxQ_ = max_element(qs.begin(), qs.end());
    double maxQnew = *maxQ_;
    double Qup = prev + alpha * (( reward_cur + gamma *maxQnew ) - prev);
    Q[make_pair(state, action)] = Qup;

}
