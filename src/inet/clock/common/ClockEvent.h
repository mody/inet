//
// Copyright (C) 2021 OpenSim Ltd.
//
// SPDX-License-Identifier: LGPL-3.0-or-later
//


#ifndef __INET_COMMON_CLOCKEVENT_H
#define __INET_COMMON_CLOCKEVENT_H

#include "inet/clock/common/ClockEvent_m.h"

namespace inet {

class ClockBase;

static int compareClockTimes(clocktime_t c1, clocktime_t c2, int64_t d = 100) // TODO: make this 1 or even 0?
{
    std::cout << "compareClockTimes(" << c1 << ", " << c2 << ")" << std::endl;
    if (llabs(c1.raw() - c2.raw()) <= d)
        return 0;
    else if (c1.raw() < c2.raw())
        return -1;
    else if (c1.raw() > c2.raw())
        return 1;
    else
        throw cRuntimeError("Unreachable code");
}

static int compareSimulationTimes(simtime_t c1, simtime_t c2, int64_t d = 100) // TODO: make this 1 or even 0?
{
    std::cout << "compareSimulationTimes(" << c1 << ", " << c2 << ")" << std::endl;
    if (llabs(c1.raw() - c2.raw()) <= d)
        return 0;
    else if (c1.raw() < c2.raw())
        return -1;
    else if (c1.raw() > c2.raw())
        return 1;
    else
        throw cRuntimeError("Unreachable code");
}

class INET_API ClockEvent : public ClockEvent_Base
{
  friend ClockBase;

  protected:
    virtual void execute() override;

    void callBaseExecute() { ClockEvent_Base::execute(); }

  public:
    ClockEvent(const char *name = nullptr, short kind = 0) : ClockEvent_Base(name, kind) {}
    ClockEvent(const ClockEvent& other) : ClockEvent_Base(other) {}

    ClockEvent& operator=(const ClockEvent& other) {
        if (this == &other) return *this;
        ClockEvent_Base::operator=(other);
        return *this;
    }
    virtual ClockEvent *dup() const override { return new ClockEvent(*this); }
};

} // namespace inet

#endif

