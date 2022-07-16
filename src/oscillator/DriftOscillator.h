/*
 * DriftOscillator.h
 *
 *  Created on: Jul 15, 2022
 *      Author: sugar
 */

#ifndef OSCILLATOR_DRIFTOSCILLATOR_H_
#define OSCILLATOR_DRIFTOSCILLATOR_H_

#include <omnetpp.h>

class DriftOscillator final : public omnetpp::cSimpleModule
{
private:
    double frequency;
    double drift;
    omnetpp::simtime_t offset_normal;
    omnetpp::simtime_t offset_drift;
    omnetpp::simtime_t oscillator_time;
    omnetpp::cMessage* rising_edge_signal;

public:
    DriftOscillator();
    virtual ~DriftOscillator();
    void initialize() override;
    void handleMessage(omnetpp::cMessage*) override;

    inline omnetpp::simtime_t getSimTime() {return oscillator_time;}

protected:
    inline void scheduleNextRisingSignal();
};

Define_Module(DriftOscillator);
#endif /* OSCILLATOR_DRIFTOSCILLATOR_H_ */
