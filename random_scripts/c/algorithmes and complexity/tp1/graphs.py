import numpy as np
import matplotlib.pyplot as plt
import math

# --- Données ---
primes = [1000003, 2000003, 4000037, 8000009, 16000057, 32000011, 64000031, 128000003, 256000001, 512000009, 1024000009, 2048000011]
algo1 = [0.006574, 0.012352, 0.023153, 0.040919, 0.078068, 0.141548, 0.276811, 0.555268, 1.095261, 2.192690, 4.288282, 8.570064]
algo2 = [0.002130, 0.004130, 0.009280, 0.018480, 0.037052, 0.075450, 0.138789, 0.268515, 0.529700, 1.054868, 2.104714, 4.167153]
algo3 = [0.000011, 0.000013, 0.000016, 0.000021, 0.000041, 0.000058, 0.000086, 0.000115, 0.000147, 0.000211, 0.000260, 0.000358]
algo4 = [0.000007, 0.000011, 0.000012, 0.000014, 0.000019, 0.000025, 0.000034, 0.000047, 0.000065, 0.000091, 0.000129, 0.000181]

# --- Complexité théorique (non normalisée) ---
td1, td2, td3, td4 = [], [], [], []
for prime in primes:
    td1.append((8 * prime - 8) / 1000000)
    td2.append((4 * prime) / 1000000)
    td3.append(8 * math.sqrt(prime))
    td4.append(4 * math.sqrt(prime) + 7)

# --- Mise à l’échelle pour correspondre aux mesures réelles ---
scale1 = algo1[-1] / td1[-1]
scale2 = algo2[-1] / td2[-1]
scale3 = algo3[-1] / td3[-1]
scale4 = algo4[-1] / td4[-1]

td1_scaled = [v * scale1 for v in td1]
td2_scaled = [v * scale2 for v in td2]
td3_scaled = [v * scale3 for v in td3]
td4_scaled = [v * scale4 for v in td4]

# --- Fonction utilitaire pour les graphes individuels ---
def tracer_graphique(x, y1, y2, titre, fichier, etiquette1, etiquette2, couleur):
    plt.plot(x, y1, 'o-', label=etiquette1, color='blue')
    plt.plot(x, y2, 'o--', label=etiquette2, color=couleur)
    plt.title(titre)
    plt.xlabel('n (nombre premier)')
    plt.ylabel('Temps (secondes)')
    plt.legend()
    plt.grid(True)
    plt.savefig(fichier, dpi=300, bbox_inches='tight')
    plt.close()

# --- Graphiques individuels ---
tracer_graphique(primes, algo1, td1_scaled, 'Algorithme 1 : réel vs théorique', 'graph_algo_1.png', 'Algo 1 (mesuré)', 'Algo 1 (théorique)', 'tab:red')
tracer_graphique(primes, algo2, td2_scaled, 'Algorithme 2 : réel vs théorique', 'graph_algo_2.png', 'Algo 2 (mesuré)', 'Algo 2 (théorique)', 'tab:red')
tracer_graphique(primes, algo3, td3_scaled, 'Algorithme 3 : réel vs théorique', 'graph_algo_3.png', 'Algo 3 (mesuré)', 'Algo 3 (théorique)', 'tab:red')
tracer_graphique(primes, algo4, td4_scaled, 'Algorithme 4 : réel vs théorique', 'graph_algo_4.png', 'Algo 4 (mesuré)', 'Algo 4 (théorique)', 'tab:red')

# --- Comparaisons cumulatives ---
plt.plot(primes, algo1, 'o-', color='tab:red', label='Algo 1')
plt.plot(primes, algo2, 'o-', color='tab:orange', label='Algo 2')
plt.title('Comparaison : Algo 1 et Algo 2')
plt.xlabel('n (nombre premier)')
plt.ylabel('Temps (secondes)')
plt.legend()
plt.grid(True)
plt.savefig('graph_algo_1_2.png', dpi=300, bbox_inches='tight')
plt.close()

plt.plot(primes, algo1, 'o-', color='tab:red', label='Algo 1')
plt.plot(primes, algo2, 'o-', color='tab:orange', label='Algo 2')
plt.plot(primes, algo3, 'o-', color='tab:blue', label='Algo 3')
plt.title('Comparaison : Algo 1, 2 et 3')
plt.xlabel('n (nombre premier)')
plt.ylabel('Temps (secondes)')
plt.legend()
plt.grid(True)
plt.savefig('graph_algo_1_2_3.png', dpi=300, bbox_inches='tight')
plt.close()

# --- Comparaison finale : Algo 1 + 2 + 3 + 4 (corrigé) ---
fig, ax1 = plt.subplots(figsize=(8, 5))

offset = 10
# Axe gauche : petits algos (3 et 4)
plt.figure(figsize=(9, 6))
plt.plot(primes, algo1, 'o-', color='tab:red', label='Algo 1 (le plus lent)')
plt.plot(primes, algo2, 's--', color='tab:orange', label='Algo 2')
plt.plot(primes, algo3, 'd-.', color='tab:blue', label='Algo 3')
plt.plot(primes, algo4, 'x-', color='tab:green', label='Algo 4 (le plus rapide)')

plt.yscale('log')
plt.title('Comparaison : Algorithmes 1, 2, 3 et 4\n(normalisés avec log pour visualiser la croissance et la difference)')
plt.xlabel('n (nombre premier)')
plt.ylabel('Temps normalisé')
plt.legend()
plt.grid(True, linestyle=':')
plt.tight_layout()
plt.savefig('graph_algo_1_2_3_4.png', dpi=300, bbox_inches='tight')
plt.close()

print("✅ Tous les graphiques ont été enregistrés avec succès !")
