#include "../../lib/signalsmith_plot.h"
#include "../Objects/SimulatorEntity.hpp"

namespace Simulator::Visualize
{

const void visualize_entity_trajectory(Simulator::Objects::SimulatorEntity *entity)
{
    signalsmith::plot::Plot2D v_plot(900, 900);
    signalsmith::plot::Plot2D p_plot(900, 900);
    signalsmith::plot::Plot2D a_plot(900, 900);

    v_plot.x.label("time").autoSetup();
    v_plot.y.label("velocity").autoSetup();

    p_plot.x.label("time").autoSetup();
    p_plot.y.label("position").autoSetup();

    a_plot.x.label("time").autoSetup();
    a_plot.y.label("acceleration").autoSetup();

    auto &vel_line = v_plot.line();
    auto &pos_line = p_plot.line();
    auto &acc_line = a_plot.line();
    for (auto &state : entity->entity_trajectory)
    {
        vel_line.add(state.time, abs(state.velocity));
        pos_line.add(state.time, abs(state.position));
        acc_line.add(state.time, abs(state.acceleration));
    }

    v_plot.write("../output/velocity.svg");
    p_plot.write("../output/position.svg");
    a_plot.write("../output/acceleration.svg");
}

} // namespace Simulator::Visualize
