// main.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <array>
#include "raft.h"
#include "canoe.h"
#include "sailboat.h"

#define _CRTDBG_MAP_ALLOC  
#include <crtdbg.h>  

int main()
{
	{
		const Chart chart;
		Raft raft{ chart };
		Canoe canoe{ chart };
		Sailboat sailboat{ chart };
		std::array<Boat* const, 3> boats{ &raft, &canoe, &sailboat };

		Wind wind;
		Water water;
		for (auto boat : boats)
		{
			if (boat != nullptr)
			{
				try
				{
					boat->testVoyage(wind, water);
					// Boat was successful
				}
				catch (const std::runtime_error e)
				{
					const auto what = e.what(); // Technically useless, but makes it easier to watch what error message is returned
					// Boat was unsuccessful
				}
			}
		}
	}

	_CrtDumpMemoryLeaks();
	return 0;
}

