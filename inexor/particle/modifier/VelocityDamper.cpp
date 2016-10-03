/*
 * VelocityDamper.cpp
 *
 *  Created on: 28.01.2015
 *      Author: aschaeffer
 */

#include "VelocityDamper.hpp"

namespace inexor {
namespace entity {
namespace particle {

    VelocityDamper::VelocityDamper() : EntityFunction(MODIFIER_VELOCITY_TRANSFORMATION_FUNCTION)
    {
    }

    VelocityDamper::~VelocityDamper()
    {
    }

    AttributeRefPtr VelocityDamper::Execute(TimeStep time_step, std::shared_ptr<EntityInstance> modifier, std::shared_ptr<EntityInstance> particle)
    {
        (*particle)[VELOCITY]->vec3Val.mul(1.0f - modifier->GetType()[DAMPER]->floatVal * time_step.time_factor);
        return true;
    }

}
}
}
