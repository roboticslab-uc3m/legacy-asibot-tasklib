// -*- mode:C++; tab-width:4; c-basic-offset:4; indent-tabs-mode:nil -*-

#ifndef __TASK_GRAB_CAN_HPP__
#define __TASK_GRAB_CAN_HPP__

#include "TaskBase.hpp"

#include "CartesianClient.h"

/**
 * @ingroup TaskGrabCan
 *
 * The TaskGrabCan class implements a client part that connects to a remote
 * \ref cartesianServer module. Warning: Be careful with NUM_AXES, depends on angle representation!
 * 
 */
class TaskGrabCan : TaskBase {
  protected:
    CartesianClient cartesianClient;

  public:
    virtual bool configure(yarp::os::Searchable& config);
    virtual bool run();
    virtual bool close();
};

#endif  // __TASK_GRAB_CAN_HPP__

