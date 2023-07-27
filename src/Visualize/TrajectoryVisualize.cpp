#include <iostream>

#include "../../lib/signalsmith_plot.h"
#include "../Objects/SimulatorEntity.hpp"

namespace Simulator::Visualize
{

const void visualize_entity_trajectory(Simulator::Objects::SimulatorEntity *entity, std::string file_suffix)
{
    signalsmith::plot::Plot2D v_plot(900, 900);
    signalsmith::plot::Plot2D p_plot(900, 900);
    signalsmith::plot::Plot2D a_plot(900, 900);

    v_plot.x.label("time [s]").autoSetup();
    v_plot.y.label("velocity [m/s]").autoSetup();

    p_plot.x.label("time [s]").autoSetup();
    p_plot.y.label("position [m]").autoSetup();

    a_plot.x.label("time [s]").autoSetup();
    a_plot.y.label("acceleration [m/s^2]").autoSetup();

    auto &vel_line = v_plot.line();
    auto &pos_line = p_plot.line();
    auto &acc_line = a_plot.line();
    for (auto &state : entity->entity_trajectory)
    {
        vel_line.add(state.time, std::fabs(state.velocity));
        pos_line.add(state.time, std::fabs(state.position));
        acc_line.add(state.time, std::fabs(state.acceleration));
    }

    v_plot.write("../output/velocity_" + file_suffix + ".svg");
    p_plot.write("../output/position_" + file_suffix + ".svg");
    a_plot.write("../output/acceleration_" + file_suffix + ".svg");
}

} // namespace Simulator::Visualize
