//
// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU Lesser General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
// 
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU Lesser General Public License for more details.
// 
// You should have received a copy of the GNU Lesser General Public License
// along with this program.  If not, see http://www.gnu.org/licenses/.
// 

package futurenetworkcompetition.oscillator;

simple IdealOscillator
{
    parameters:
    	double oscillator_frequency = default(1e6);
}

simple DriftOscillator
{
	parameters:
	    double oscillator_frequency = default(1e6);
	    double oscillator_drift = 0.95;
}

simple RandomDriftOscillator
{
    parameters:
	    double oscillator_frequency = default(1e6);
	    double oscillator_drift = 0.95;
}

network IdealOscillatorTest
{
	submodules:
	    i:IdealOscillator;
	    o:DriftOscillator;
	    r:RandomDriftOscillator;
	    
	connections:
	        
}
