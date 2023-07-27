#pragma once

#include <vector>

#include "EntityState.hpp"

namespace Simulator::Objects
{

class SimulatorEntity
{

public:
    SimulatorEntity() = default;
    virtual ~SimulatorEntity() = default;

    virtual void update(double time_delta) = 0;

    /// @brief Collection of entity states
    std::vector<Simulator::Objects::EntityState> entity_trajectory;
};

} // namespace Simulator::Objects
