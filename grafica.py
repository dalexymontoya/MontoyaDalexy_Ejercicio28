import matplotlib.pyplot as plt
import numpy as np

h = np.genfromtxt("datos.dat")
#len(h)

t,x,y,vx,vy=h.T

plt.figure()
plt.plot(x, y)
plt.ylim([0,10])
plt.savefig("lomasdificildelmundo.png")
