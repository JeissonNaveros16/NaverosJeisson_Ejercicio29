import numpy as np
import matplotlib.pylab as plt
from mpl_toolkits.mplot3d import Axes3D
import matplotlib.pyplot as plt

data = np.loadtxt("EDP.dat");

t = data[::30,0]
x = data[:30,1]
aux = data[:,2]

X, T = np.meshgrid(x, t)

z = []

for i in range(len(t)):
	temp = list(aux[i*30:(i*30+30)])
	z.append(temp)
	
Z = np.array(z)
X, T = np.meshgrid(x, t)

fig = plt.figure()
ax = fig.gca(projection='3d')

ax.plot_surface(X, T, Z, cmap="coolwarm", linewidth=0, antialiased=False)
plt.title("Solución a ecuación diferencial parcial")
plt.xlabel("Posición (x)")
plt.ylabel("Tiempo (t)")

plt.savefig("EDP(Primera Parte).png")

plt.figure(figsize=(15,8))
plt.imshow(Z)
plt.savefig("evolve_A.png")