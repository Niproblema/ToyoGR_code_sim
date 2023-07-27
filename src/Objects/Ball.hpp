#pragma once

#include <optional>
#include <numbers>

#include "../Arguments/SimulationArguments.hpp"
#include "EntityState.hpp"
#include "SimulatorEntity.hpp"

namespace Simulator::Objects
{

class Ball : public SimulatorEntity
{
public:
    Ball(const Simulator::Arguments::SimulatorArguments &sim_args)
        : model(sim_args.model), drag_coefficient(sim_args.drag_coefficient), fluid_density(sim_args.fluid_density),
          ball_radius(sim_args.ball_radius), ball_mass(sim_args.ball_mass),
          ball_initial_position_x(sim_args.ball_initial_position_x),
          ball_initial_velocity(sim_args.ball_initial_velocity), gravity(sim_args.gravity),
          gravitational_constant(sim_args.gravitational_constant), planet_radius(sim_args.planet_radius),
          planet_mass(sim_args.planet_mass)
    {
        // Calculate static math compoments in advance.
        gravity_force = ball_mass * gravity;
        drag_force_constant_component = drag_coefficient * fluid_density * std::numbers::pi * pow(ball_radius, 2);
        newtonian_gravity_force_constant_component = gravitational_constant * planet_mass * ball_mass;
    };

    virtual ~Ball() = default;

    void update(double time_delta) final;


protected:
    Simulator::Arguments::SimulatorModel model;
    double drag_coefficient;
    double fluid_density;

    double ball_radius;
    double ball_mass;
    double ball_initial_position_x;
    double ball_initial_velocity;

    double gravity;
    double gravitational_constant;
    double planet_radius;
    double planet_mass;

    std::optional<double> get_force_sum(double velocity, double position) const;
    double get_drag_force(double velocity) const;
    double get_gravity_force_static() const;
    double get_gravity_force_newtonian(double position) const;

private:
    double gravity_force;
    double drag_force_constant_component;
    double newtonian_gravity_force_constant_component;
};

} // namespace Simulator::Objects
