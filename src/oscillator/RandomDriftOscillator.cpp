/*
 * RandomDriftOscillator.cpp
 *
 *  Created on: Jul 15, 2022
 *      Author: sugar
 */

#include "RandomDriftOscillator.h"
#include "cstdlib"
#include "ctime"

RandomDriftOscillator::RandomDriftOscillator()
{
    frequency = 0;
    drift = 1.0;
    delta_f = 0.0;
    offset_normal = 0.0;
    offset_drift = 0.0;
    oscillator_time = 0.0;
    rising_edge_signal = nullptr;
}

RandomDriftOscillator::~RandomDriftOscillator()
{
    cancelAndDelete(rising_edge_signal);
}

void RandomDriftOscillator::initialize()
{
    frequency = par("oscillator_frequency");
    drift = par("oscillator_drift");
    delta_f = frequency*drift;
    offset_normal = 1/frequency;
    rising_edge_signal = new omnetpp::cMessage();
    scheduleNextRisingSignal();
}

void RandomDriftOscillator::handleMessage(omnetpp::cMessage* msg)
{
    delete(msg);
    oscillator_time += offset_normal;
    rising_edge_signal = new omnetpp::cMessage();
    scheduleNextRisingSignal();
}

inline void RandomDriftOscillator::scheduleNextRisingSignal()
{
    srand(time(0));
    offset_drift = 1/(frequency + (rand()%9999/10000 - 0.5)*delta_f );
    scheduleAt(omnetpp::simTime()+offset_drift, rising_edge_signal);
}
