/*
 * RandomDriftOscillator.h
 *
 *  Created on: Jul 15, 2022
 *      Author: sugar
 */

#ifndef OSCILLATOR_RANDOMDRIFTOSCILLATOR_H_
#define OSCILLATOR_RANDOMDRIFTOSCILLATOR_H_

class RandomDriftOscillator final
{
private:
    int frequency;
    omnetpp::simtime_t offset;
    omnetpp::simtime_t oscillator_time;
    omnetpp::cMessage* rising_edge_signal;

public:
    RandomDriftOscillator();
    virtual ~RandomDriftOscillator();
    void initialize() override;
    void handleMessage(omnetpp::cMessage*) override;

    inline omnetpp::simtime_t getSimTime() {return oscillator_time;}

protected:
    inline void scheduleNextRisingSignal();
};

#endif /* OSCILLATOR_RANDOMDRIFTOSCILLATOR_H_ */
