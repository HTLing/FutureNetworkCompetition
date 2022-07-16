/*
 * IdealOscillator.h
 *
 *  Created on: Jul 15, 2022
 *      Author: sugar
 */

#ifndef OSCILLATOR_IDEALOSCILLATOR_H_
#define OSCILLATOR_IDEALOSCILLATOR_H_

#include <omnetpp.h>

class IdealOscillator final: public omnetpp::cSimpleModule
{
private:
    double frequency;
    omnetpp::simtime_t offset;
    omnetpp::simtime_t oscillator_time;
    omnetpp::cMessage* rising_edge_signal;

public:
    IdealOscillator();
    virtual ~IdealOscillator();

    void initialize() override;
    void handleMessage(omnetpp::cMessage*) override;

    inline omnetpp::simtime_t getSimTime() {return oscillator_time;}

protected:
    inline void scheduleNextRisingSignal();
};

Define_Module(IdealOscillator);
#endif /* OSCILLATOR_IDEALOSCILLATOR_H_ */
