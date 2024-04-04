//
// Copyright (C) 2024 OpenSim Ltd.
//
// SPDX-License-Identifier: LGPL-3.0-or-later
//


#ifndef __INET_TRACED_H
#define __INET_TRACED_H

#include "inet/common/INETDefs.h"

namespace inet {

/**
 * @brief A template class that wraps a variable of type T (usually an primitive type like int,
 * double, enum, etc.), and monitors its value for changes. On each change, the new value is
 * emitted in the specified simulation signal. This class is particularly useful for automatic
 * recording of state variables in a module.
 */
template<typename T>
class Traced {
  private:
    T value_;
    cComponent *component_ = nullptr;
    simsignal_t signal_ = SIMSIGNAL_NULL;

    void setValue(const T& newValue) {
        value_ = newValue;
        if (signal_ != SIMSIGNAL_NULL)
            component_->emit(signal_, newValue);
    }

  public:
    Traced() = default;

    Traced(const T& value) : value_(value) {}

    // Set up target signal
    void configure(cComponent *component, simsignal_t signal) {
        component_ = component;
        signal_ = signal;
    }

    // Overload assignment operator
    Traced& operator=(const T& value) {
        setValue(value);
        return *this;
    }

    // Overload for += operator
    Traced& operator+=(const T& rhs) {
        setValue(value_ + rhs);
        return *this;
    }

    // Overload for -= operator
    Traced& operator-=(const T& rhs) {
        setValue(value_ - rhs);
        return *this;
    }

    // Overload for *= operator
    Traced& operator*=(const T& rhs) {
        setValue(value_ * rhs);
        return *this;
    }

    // Overload for /= operator
    Traced& operator/=(const T& rhs) {
        setValue(value_ / rhs);
        return *this;
    }

    // Overload for %= operator (only for integral types)
    template<typename U = T>
    typename std::enable_if<std::is_integral<U>::value, Traced&>::type operator%=(const T& rhs) {
        setValue(value_ % rhs);
        return *this;
    }

    // Overload for &= operator (only for integral types)
    template<typename U = T>
    typename std::enable_if<std::is_integral<U>::value, Traced&>::type operator&=(const T& rhs) {
        setValue(value_ & rhs);
        return *this;
    }

    // Overload for |= operator (only for integral types)
    template<typename U = T>
    typename std::enable_if<std::is_integral<U>::value, Traced&>::type operator|=(const T& rhs) {
        setValue(value_ | rhs);
        return *this;
    }

    // Overload for ^= operator (only for integral types)
    template<typename U = T>
    typename std::enable_if<std::is_integral<U>::value, Traced&>::type operator^=(const T& rhs) {
        setValue(value_ ^ rhs);
        return *this;
    }

    // Overload for <<= operator (only for integral types)
    template<typename U = T>
    typename std::enable_if<std::is_integral<U>::value, Traced&>::type operator<<=(const T& rhs) {
        setValue(value_ << rhs);
        return *this;
    }

    // Overload for >>= operator (only for integral types)
    template<typename U = T>
    typename std::enable_if<std::is_integral<U>::value, Traced&>::type operator>>=(const T& rhs) {
        setValue(value_ >> rhs);
        return *this;
    }

    // Overload type conversion operator to allow transparent use as T
    operator T() const {
        return value_;
    }

};

} // namespace inet

#endif

