#include "ExpCutoff.h"
#include <string>
//#include <functional> 
#include "crpropa/Units.h"

// const std::string myPropertyName = "counter";

namespace crpropa{
double Randext::randPowerLawExpCutoff(double index, double min, double max, double ecut) {
	if ((min < 0) || (max < min)) {
		throw std::runtime_error(
				"Power law distribution only possible for 0 <= min <= max");
	}
	//check for index -1!
	else {
		return (160);
	}
}

static Randext _randext;
Randext &Randext::instance() {
	return _randext;
}

SourcePowerLawExpCutoffSpectrum::SourcePowerLawExpCutoffSpectrum(double Emin, double Emax,
		double index, double ecut) :
		Emin(Emin), Emax(Emax), index(index), ecut(ecut) {
	setDescription();
}


void SourcePowerLawExpCutoffSpectrum::prepareParticle(ParticleState& particle) const {
	Randext& randext = Randext::instance();
	double E = randext.randPowerLawExpCutoff(index, Emin, Emax, ecut);
	particle.setEnergy(E);
}

void SourcePowerLawExpCutoffSpectrum::setDescription() {
	std::stringstream ss;
	ss << "SourcePowerLawExpCutoffSpectrum: Random energy ";
	ss << "E = " << Emin / crpropa::GeV << " - " << Emax / crpropa::GeV << " GeV, ";
	ss << "dN/dE ~ E^" << index  << " in power law part, ";
	ss << "Cutoff energy " << ecut / crpropa::GeV<< "GeV \n";
	description = ss.str();
}
}
