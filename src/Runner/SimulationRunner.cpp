#include <iostream>

#include <vector>

#include "../Objects/SimulatorEntity.hpp"
#include "SimulationRunner.hpp"

namespace Simulator
{

void SimulationRunner::run_sim(std::vector<Simulator::Objects::SimulatorEntity *> &sim_objects) const
{
    for (double current_step = 0; current_step < simulation_duration; current_step += simulation_step)
    {
        for (auto entity : sim_objects)
        {
            entity->update(simulation_step);
        }
    }
}

} // namespace Simulator
