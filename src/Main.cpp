#include <iostream>
#include <vector>

#include "Arguments/SimulationArguments.hpp"
#include "Objects/SimulatorEntity.hpp"
#include "Objects/Ball.hpp"
#include "Runner/SimulationRunner.hpp"


#include "Objects/Ball.cpp"
#include "Runner/SimulationRunner.cpp"
#include "Visualize/TrajectoryVisualize.cpp"

int main()
{
    // Setup
    const auto sim_args = Simulator::Arguments::SimulatorArguments{};

    auto sim_ball = new Simulator::Objects::Ball(sim_args);

    auto sim_objects = std::vector<Simulator::Objects::SimulatorEntity*>{ sim_ball };

    auto sim_runner = Simulator::SimulationRunner(sim_args);

    // Simulate
    sim_runner.run_sim(sim_objects);

    // Visualize
    Simulator::Visualize::visualize_entity_trajectory(sim_ball);

    // Dispose
    delete sim_ball;

    return 0;
}
