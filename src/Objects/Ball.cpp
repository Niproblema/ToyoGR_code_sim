#include <iostream>
#include <numbers>
#include <optional>

#include "../Arguments/SimulationArguments.hpp"
#include "Ball.hpp"
#include "SimulatorEntity.hpp"

using namespace Simulator::Arguments;

namespace Simulator::Objects
{

void Ball::update(double time_delta)
{
    double new_time = 0;
    double new_velocity = 0;
    double new_position = 0;

    // Set initial position this is the first state.
    if (entity_trajectory.empty())
    {
        new_velocity = ball_initial_velocity;
        new_position = ball_initial_position_x;
    }
    // Otherwise calculate it based on previous state.
    else
    {
        auto prev_state = entity_trajectory.back();

        new_velocity = prev_state.velocity + (prev_state.acceleration * time_delta);
        new_position = prev_state.position + (prev_state.velocity * time_delta) +
                       (0.5 * prev_state.acceleration * pow(time_delta, 2));
        new_time = prev_state.time + time_delta;
    }

    // Calculate new forces and acceleration.
    auto force_sum_opt = get_force_sum(new_velocity, new_position);
    EntityState new_state;
    if (force_sum_opt.has_value())
    {
        double new_acceleration = force_sum_opt.value() / ball_mass;
        new_state = EntityState{.position = new_position,
                                .velocity = new_velocity,
                                .acceleration = new_acceleration,
                                .time = new_time};
    }
    else
    {
        new_state = EntityState{.position = new_position, .velocity = 0, .acceleration = 0, .time = new_time};
    }

    entity_trajectory.push_back(new_state);
}


std::optional<double> Ball::get_force_sum(double velocity, double position) const
{
    if (model == SimulatorModel::Newtonian)
    {
        // Check for (R+x)=0 edge case end condition.
        if (std::fabs(position) >= planet_radius)
        {
            // return nullopt
            return {};
        }

        return get_drag_force(velocity) - get_gravity_force_newtonian(position);
    }
    else
    {
        return get_drag_force(velocity) - get_gravity_force_static();
    }
}

double Ball::get_drag_force(double velocity) const
{
    return pow(velocity, 2) * drag_force_constant_component;
}

double Ball::get_gravity_force_static() const
{
    return gravity_force;
}

double Ball::get_gravity_force_newtonian(double position) const
{
    return newtonian_gravity_force_constant_component / pow((planet_radius + position), 2);
}

} // namespace Simulator::Objects
