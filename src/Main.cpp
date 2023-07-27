#include <iostream>
#include <vector>

#include "Arguments/SimulationArguments.hpp"
#include "Objects/Ball.hpp"
#include "Objects/SimulatorEntity.hpp"
#include "Runner/SimulationRunner.hpp"


#include "Objects/Ball.cpp"
#include "Runner/SimulationRunner.cpp"
#include "Visualize/TrajectoryVisualize.cpp"

using namespace Simulator::Arguments;

int main()
{
    // Setup
    const auto sim_args_static = SimulatorArguments{.model = SimulatorModel::Constant};
    const auto sim_args_newtonian = SimulatorArguments{.model = SimulatorModel::Newtonian};

    auto sim_ball_static = new Simulator::Objects::Ball(sim_args_static);
    auto sim_ball_newtonian = new Simulator::Objects::Ball(sim_args_newtonian);

    auto sim_objects = std::vector<Simulator::Objects::SimulatorEntity *>{sim_ball_static, sim_ball_newtonian};

    auto sim_runner = Simulator::SimulationRunner(SimulatorArguments{});

    // Simulate
    sim_runner.run_sim(sim_objects);

    // Visualize
    Simulator::Visualize::visualize_entity_trajectory(sim_ball_static, "static");
    Simulator::Visualize::visualize_entity_trajectory(sim_ball_newtonian, "newtonian");

    // Dispose
    delete sim_ball_static;
    delete sim_ball_newtonian;

    return 0;
}
