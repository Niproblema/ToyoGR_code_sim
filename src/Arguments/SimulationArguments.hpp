#pragma once

namespace Simulator::Arguments
{

enum class SimulatorModel
{
    Constant,
    Newtonian,
};

struct SimulatorArguments
{
    /// @brief Simulation duration [s]
    double simulation_duration = 10;
    /// @brief Simulation step [s]
    double simulation_step = 0.1;

    /// @brief Model selection
    SimulatorModel model = SimulatorModel::Newtonian;

    // Drag parameters
    /// @brief Drag coeficient Cp
    double drag_coefficient = 0.2;
    /// @brief  Fluid density ρ  [kg/m^3]
    double fluid_density = 1.2;

    // Ball parameters
    /// @brief  Ball radius r [m]
    double ball_radius = 1;
    /// @brief  Ball mass m [kg]
    double ball_mass = 10;
    /// @brief  Initial ball position x0 [m]
    double ball_initial_position_x = 0;
    /// @brief  Initial ball velocity [m/s]
    double ball_initial_velocity = 0;


    // Model 1 parameters
    /// @brief  Gravity acceleration g [m/s^2]
    double gravity = 9.81;

    // Model 2 parameters
    /// @brief  Graviational constant G [Nm^2 / kg^2]
    double gravitational_constant = 6.67e-11;
    /// @brief  Planet radius R [m]
    double planet_radius = 6371000;
    /// @brief  Planet mass M [kg]
    double planet_mass = 5.972e+24;
};

}; // namespace Simulator::Parameters
