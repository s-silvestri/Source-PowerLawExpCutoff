/// Example plugin for CRPropa.
///
/// Please consider sharing the awesome plugin with you fellow researchers by
/// creating a eperate repository for your project. We maintain a list of
/// plugins to CRPropa on our webpage and are happy to add a link to your
/// project, just send us: (name of the plugin, short description, url)

#include <crpropa/Module.h>
#include <crpropa/Random.h>
#include <crpropa/Source.h>


namespace crpropa{
class ParticleStateExt : public ParticleState{};
class SourceFeatureExt : public SourceFeature{};

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

class Randext : public Random{
	public:
	Randext();
	double randPowerLawExpCutoff(double index, double min, double max, double ecut);
	static Randext& instance();
};
}