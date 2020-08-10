import crpropa
from crpropa import *
import expcutoff

print("My Simulation\n")

ml = crpropa.ModuleList()

ml.add(crpropa.SimplePropagation(1*crpropa.parsec, 100*crpropa.parsec))
ml.add(crpropa.MaximumTrajectoryLength(1000*crpropa.parsec))

print("+++ List of modules")
print(ml.getDescription())

output2 = TextOutput('events.txt', Output.Event1D)
print("+++ Preparing source")
source = crpropa.Source()
source.add( SourceParticleType(22))
source.add(blazartools.SourcePowerLawExpCutoffSpectrum(100*GeV, 20000*GeV, -1.5, 2080*GeV))
#source.add(SourcePowerLawSpectrum(100*GeV, 20000*GeV, -1.5))
c = source.getCandidate()
print c.current.getEnergy()
print(source.getDescription())

print ("+++ Preparing observer")
obs = Observer()
obs.add( ObserverPoint() )  # observer at x = 0
obs.onDetection(output2)
ml.add(obs)
print (obs)

print("+++ Starting Simulation of 100 particles")

ml.run(source, 100)


print("+++ Done")
