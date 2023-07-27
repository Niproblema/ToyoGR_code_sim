#pragma once

#include <vector>

#include "../Arguments/SimulationArguments.hpp"
#include "../Objects/SimulatorEntity.hpp"

namespace Simulator
{
class SimulationRunner
{
public:
    SimulationRunner(const Simulator::Arguments::SimulatorArguments &sim_args)
        : simulation_duration(sim_args.simulation_duration), simulation_step(sim_args.simulation_step){};

    ~SimulationRunner() noexcept = default;

    void run_sim(std::vector<Simulator::Objects::SimulatorEntity *> &sim_objects) const;

private:
    double simulation_duration;
    double simulation_step;
};

} // namespace Simulator
