#include "rl_tictac.h"

RLTicTac::RLTicTac(Agent &PX, Agent &P0):
    PX(PX),
    PO(P0)
{
    env_board.assign(9, '-');
    curAgentTurn =(Agent::agentChar)randi(0,2);
    cout << curAgentTurn << endl;
    PX.initAgent('X');
    PO.initAgent('O');

    // for(int i = 0; i < 9; ++i)
    // 	env_board[i] = itoa(i);
}

void RLTicTac::playGame()
{

    while(true)
    {

        Agent *curAgent_p;
        char curChar = '-';
        Agent *nextAgent_p;
        if(this->curAgentTurn == Agent::AgentCharX)
        {
            curAgent_p = &PX;
            nextAgent_p = &PO;
            curChar = 'X';
        }
        else
        {
            curAgent_p = &PO;
            nextAgent_p = &PX;
            curChar = 'O';
        }
        Agent &curAgent = *curAgent_p;
        Agent &nextAgent = *nextAgent_p;

        if(curAgent.type == Agent::AgentHuman) printEnv();

        int space = curAgent.takeNextAction(env_board);

        if(env_board[space - 1] != '-')
        {
            curAgent.reward(-99, env_board);
            cout << "invalid move\n";
            break;
        }

        env_board[ space -1 ] = curChar;
        if(agentWins(curChar))
        {
            curAgent.reward(1, env_board);
            nextAgent.reward(-1, env_board);
            break;
        }

        if(isGameTie())
        {
            curAgent.reward(0.5, env_board);
            nextAgent.reward(0.5, env_board);
            break;
        }

        nextAgent.reward(0, env_board);
        curAgentTurn = curAgentTurn == Agent::AgentCharX ? Agent::AgentCharO : Agent::AgentCharX ;

    }
}

bool RLTicTac::agentWins(char inputChar)
{
    vector<tuple < int, int, int > > winning_pos = {
        make_tuple(0,1,2), make_tuple(3,4,5), make_tuple(6,7,8),
        make_tuple(0,3,6), make_tuple(1,4,7), make_tuple(2,5,8),
        make_tuple(0,4,8), make_tuple(2,4,6)
    };

    for(auto &pos: winning_pos)
    {
        if((inputChar == env_board[get<0>(pos)])
                && (inputChar == env_board[get<1>(pos)])
                && (inputChar == env_board[get<2>(pos)]))
        {
            cout << "\n*****************\n"<< curAgentTurn << " wins" << "\n****************"<< endl;
            return true;
        }
    }
    return false;
}

bool RLTicTac::isGameTie()
{
    if (std::find(env_board.begin(), env_board.end(), '-') != env_board.end())
        return false;
    cout << "env_board full. Noone won. \n";
    return true;
}

void RLTicTac::printEnv()
{
    cout << endl;
    for(int i = 0; i < 3; ++i)
    {
        for(int j =0; j < 3; ++j)
        {
            if(env_board[i*3+j] == '-')
                cout << (i*3+j + 1)  << " ";
            else
                cout << env_board[i*3+j] << " ";
        }
        cout << endl;
    }
}
