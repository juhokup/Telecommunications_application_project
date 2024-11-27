import numpy as np
import matplotlib.pyplot as plt
import pandas as pd
from matplotlib import cm
from mpl_toolkits.mplot3d import Axes3D
import plotly.graph_objs as pgo
import plotly.express as px

points = pd.read_csv('mittausdata.csv', delimiter=';')

figs = plt.figure()
ax = figs.add_subplot(111, projection='3d')

x = points['X'].values #numpy ja pandas ei tykänny dataframesta
y = points['Y'].values
z = points['Z'].values

ax.scatter(x, y, z, c='pink',alpha = 0.1, marker='.')

plt.show()

def KmeansA(points, centralpoints, iterations): 

    # Valitaan vain 'X', 'Y', ja 'Z' sarakkeet laskutoimituksiin
    points_xyz = points[['X', 'Y', 'Z']].values 

    max_values = np.max(points_xyz, axis=0)
    min_values = np.min(points_xyz, axis=0)

    #random arvot min-max välille, arvotaan 6 kpl 3d arvoja
    randomPoints = (max_values - min_values) * np.random.rand(centralpoints, 3) + min_values 

    for _ in range(iterations): #kumulatiivinen summa + montako pistettä voittaa
        CumSum = np.zeros((centralpoints, 3))
        Counts = np.zeros((1, centralpoints))
        for point in points_xyz: # Iterate over numeric values of X, Y, Z
            distances = np.linalg.norm(randomPoints - point, axis=1) #randompisteestä data pisteisiin etäisyys, np.linalg.norm on sama kuin pythagoras

            winner = np.argmin(distances) #voittaja on se random piste jolla lyhin matka pisteeseen

            CumSum[winner] += point #voittavalle keskipisteelle lisätään pojo
            Counts[0, winner] += 1 #counts alussa nolla, siihen lisätään sitä mukaa kun voittaa.
            for i in range(centralpoints):
                if Counts[0, i] > 0:
                    randomPoints[i] = CumSum[i] / Counts[0, i] #randompisteiden siirto jos muuttuu
                else:
                    randomPoints[i] = (max_values - min_values) * np.random.rand(1, 3) + min_values
    return randomPoints


centralpoints = 6 #keskipisteiden määrä
iterations = 10   #montako kertaa luuppi ajetaan

lopulliset_keskipisteet = KmeansA(points, centralpoints, iterations)

# Kirjoitetaan keskipisteet.h ********************************************************
Filename = 'keskipisteet.h'

with open(Filename, 'w') as File:
    File.write('int CP[{}][3]={{\n'.format(len(lopulliset_keskipisteet)))

    for i, centralpoints in enumerate(lopulliset_keskipisteet):
        File.write('{{{},{},{}}}, // keskipiste {}, missa x={}, y={}, z={}\n'.format(
            int(centralpoints[0]), int(centralpoints[1]), int(centralpoints[2]),
            i + 1, int(centralpoints[0]), int(centralpoints[1]), int(centralpoints[2])
        ))

    File.write('};\n')
#*************************************************************************************

fig = plt.figure()
ax = fig.add_subplot(111, projection='3d')

ax.scatter(points['X'], points['Y'], points['Z'], c='purple',alpha=0.01, marker='.', label='Data')
ax.scatter(lopulliset_keskipisteet[:, 0], lopulliset_keskipisteet[:, 1], lopulliset_keskipisteet[:, 2], c='black', marker='x', s=100, label='Keskipisteet')

ax.set_xlabel('X')
ax.set_ylabel('Y')
ax.set_zlabel('Z')
ax.legend()

sorted_indices = np.argsort((lopulliset_keskipisteet[:, 0]))
lopulliset_keskipisteet = lopulliset_keskipisteet[sorted_indices]

plt.show()