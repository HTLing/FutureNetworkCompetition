/*
 * IdealOscillator.cpp
 *
 *  Created on: Jul 15, 2022
 *      Author: sugar
 */

#include "IdealOscillator.h"

IdealOscillator::IdealOscillator() {
    frequency = 0;
    offset = 0.0;
    oscillator_time = 0.0;
    rising_edge_signal = nullptr;
}

IdealOscillator::~IdealOscillator() {
    cancelAndDelete(rising_edge_signal);
}

void IdealOscillator::initialize()
{
    frequency = par("oscillator_frequency");
    offset = 1/frequency;
    rising_edge_signal = new omnetpp::cMessage();
    scheduleNextRisingSignal();
}

void IdealOscillator::handleMessage(omnetpp::cMessage* msg)
{
    delete(msg);
    oscillator_time += offset;
    rising_edge_signal = new omnetpp::cMessage();
    scheduleNextRisingSignal();
}

inline void IdealOscillator::scheduleNextRisingSignal()
{
    scheduleAt(omnetpp::simTime()+offset, rising_edge_signal);
}
