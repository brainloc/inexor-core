/*
 * Point.h
 *
 *  Created on: 27.01.2015
 *      Author: aschaeffer
 */

#ifndef SRC_ENGINE_ENTITY_SUBSYSTEM_PARTICLE_EMITTER_POINT_H_
#define SRC_ENGINE_ENTITY_SUBSYSTEM_PARTICLE_EMITTER_POINT_H_

#include "inexor/entity/EntitySystemBase.hpp"
#include "inexor/entity/EntitySystem.hpp"
#include "inexor/entity/domain/graph/EntityFunction.hpp"
#include "inexor/particle/subsystem/ParticleSubsystem.hpp"
#include "inexor/util/Logging.hpp"

namespace inexor {
namespace entity {
namespace particle {

    /**
     * The point emitter emits particle at the position of the emitter. The point
     * emitter is an EntityFunction which accepts the particle type and the emitter
     * instance as parameters.
     */
    class Point : public EntityFunction
    {
        public:

            Point();
            virtual ~Point();

            AttributeRefPtr Execute(TimeStep time_step, std::shared_ptr<EntityInstance> emitter_inst, std::shared_ptr<EntityInstance> particle_inst);

        private:
            /**
             * The relationship type:
             *
             *     particle--[:emitted_by]-->emitter
             *
             */
            TypeRefPtr<RelationshipType> emitted_by;

            // Include the default reference counting implementation.
            IMPLEMENT_REFCOUNTING(Point);
    };

}
}
}

#endif /* SRC_ENGINE_ENTITY_SUBSYSTEM_PARTICLE_EMITTER_POINT_H_ */
