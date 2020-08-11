/// Example plugin for CRPropa.
///
/// Please consider sharing the awesome plugin with you fellow researchers by
/// creating a eperate repository for your project. We maintain a list of
/// plugins to CRPropa on our webpage and are happy to add a link to your
/// project, just send us: (name of the plugin, short description, url)

#include <crpropa/Module.h>
#include <crpropa/Random.h>
#include <crpropa/Source.h>
//#include <crpropa/ParticleState.h>

namespace crpropa {
class SourcePowerLawExpCutoffSpectrum : public SourceFeature {
	double Emin;
	double Emax;
	double index;
	double ecut;
public:
	SourcePowerLawExpCutoffSpectrum(double Emin, double Emax, double index, double ecut);
	void prepareParticle(ParticleState &particle) const;
	void setDescription();
};


class Randext : public crpropa::Random{
	public:
	static Randext& instance();
	double randPowerLawExpCutoff(double index, double min, double max, double ecut);
	std::vector <double> CDFbreak(double index, double min, double max, double ecut);
	double stepIntegratePowerLawExpCutoff(double index, double ecut, double min, double max);
};
}