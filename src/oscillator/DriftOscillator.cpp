/*
 * DriftOscillator.cpp
 *
 *  Created on: Jul 15, 2022
 *      Author: sugar
 */

#include "DriftOscillator.h"

DriftOscillator::DriftOscillator()
{
    frequency = 0;
    drift = 1.0;
    offset_normal = 0.0;
    offset_drift = 0.0;
    oscillator_time = 0.0;
    rising_edge_signal = nullptr;
}

DriftOscillator::~DriftOscillator() {
    cancelAndDelete(rising_edge_signal);
}

void DriftOscillator::initialize()
{
    frequency = par("oscillator_frequency");
    drift = par("oscillator_drift");
    offset_normal = 1/frequency;
    offset_drift = 1/(frequency*drift);
    rising_edge_signal = new omnetpp::cMessage();
    scheduleNextRisingSignal();
}

void DriftOscillator::handleMessage(omnetpp::cMessage* msg)
{
    delete(msg);
    oscillator_time += offset_normal;
    rising_edge_signal = new omnetpp::cMessage();
    scheduleNextRisingSignal();
}

inline void DriftOscillator::scheduleNextRisingSignal()
{
    scheduleAt(omnetpp::simTime()+offset_drift, rising_edge_signal);
}
