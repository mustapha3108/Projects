import numpy as np
import matplotlib.pyplot as plt
import math

primes = [1000003, 2000003, 4000037, 8000009, 16000057, 32000011, 64000031, 128000003, 256000001, 512000009, 1024000009, 2048000011]
algo1 = [0.006574, 0.012352, 0.023153, 0.040919, 0.078068, 0.141548, 0.276811, 0.555268, 1.095261, 2.192690, 4.288282, 8.570064]
algo2 = [0.002130, 0.004130, 0.009280, 0.018480, 0.037052, 0.075450, 0.138789, 0.268515, 0.529700, 1.054868, 2.104714, 4.167153]
algo3 = [0.000011, 0.000013, 0.000016, 0.000021, 0.000041, 0.000058, 0.000086, 0.000115, 0.000147, 0.000211, 0.000260, 0.000358]
algo4 = [0.000007, 0.000011, 0.000012, 0.000014, 0.000019, 0.000025, 0.000034, 0.000047, 0.000065, 0.000091, 0.000129, 0.000181]

#algo1 = 8n - 8
#algo2 = 4n
#algo3 = 8 sqrt(n)
#algo4 = 4 sqrt(n) +7 

td1=[]
td2=[]
td3=[]
td4=[]

for prime in primes:
    td1.append((8*prime - 8)/1000000)
    td2.append((4*prime)/1000000)
    td3.append(8*math.sqrt(prime))
    td4.append(4*math.sqrt(prime) + 7)

print(td1, td2, td3, td4)

# --- Graph 1 ---
plt.plot(primes, algo1, 'o-', label='algo1 tp')
plt.plot(primes, td1, 'o-', label='td1 estimation')
plt.title('Graph 1: sin(x) + points')
plt.legend()
plt.grid(True)
plt.savefig('graph_algo_1.png', dpi=300, bbox_inches='tight')
plt.close()

# --- Graph 2 ---
#y_func2 = np.exp(-x**2)
## another simple array
#x_points2 = [-10, -5, 0, 5, 10]
#y_points2 = [0, 0.1, 1, 0.1, 0]
#
#plt.plot(x, y_func2, label='exp(-x²)')
#plt.plot(x_points2, y_points2, 's--', label='Custom points 2')
#plt.title('Graph 2: exp(-x²) + points')
#plt.legend()
#plt.grid(True)
#plt.savefig('graph2.png', dpi=300, bbox_inches='tight')
#plt.close()
#
#print("✅ Saved graph1.png and graph2.png")
