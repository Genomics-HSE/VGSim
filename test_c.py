import VGsim

# pip install --editable .

simulator = VGsim.Simulator(0, 1, 1, 1234)
simulator.Debug()
simulator.Simulate(10)
simulator.Debug()
# simulator.Genealogy()