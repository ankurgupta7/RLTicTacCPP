#include "rl_tictac.h"
#include "agent.h"
#include "machine_agent.h"

int main(int argc, char const *argv[])
{
    argc;argv;

    MachineAgent PX(0.9,0.3,0.9);
    MachineAgent PO(0.9,0.3,0.9);

    for(long long int i = 0 ; i < 200000LL; ++i)
	{
        cout << i << " ";
        auto  T = RLTicTac(PX, PO);
		T.playGame();
	}

    Agent human;
    PO.epsilon = 0;

    while(true){
        auto T = RLTicTac(human, PO);
        T.playGame();
    }

	return 0;
}
