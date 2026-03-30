import matplotlib.pyplot as plt

x = [100,200,300,400,500,600,700,800,900,1000,2000,3000,4000,5000,6000,7000,8000,9000,10000]
y = [0.008934 ,  0.062806 ,  0.191228 ,  0.432845 ,  0.823493 ,  1.531348 ,  2.504993 ,  3.869664 ,  5.350861 ,   8.966937 ,  97.818775 ,  334.602784 ,  818.551430 ,  1516.392213 ,  2640.094264 ,  4707.665077 ,  7652.726984 ,  12274.188779,   15930.494307 ]
y2 = [0.000033, 0.000060 ,0.000074 ,0.000138 ,0.000159 ,0.000300 ,0.000244 ,0.000681 ,0.000365 ,0.000771 ,0.000539 ,0.001065 ,0.000670 ,0.001399 ,0.000933 ,0.001705 ,0.001072 ,0.002236 ,0.001137 ,0.002565 ,0.003670 ,0.008599 ,0.008517 ,0.019162 ,0.014253 ,0.033946 ,0.025372 ,0.053714 ,0.039839 ,0.082268 ,0.049066 ,0.108207 ,0.067164 ,0.135675 ,0.080761 ,0.172304 ,0.099204 ,0.213147 ]



# Create the bar chart
plt.figure(figsize=(8, 6))
plt.bar(x, y, color='skyblue')

plt.xlabel("matrix size")
plt.ylabel("time of execution")
plt.title("time of exection for matrix multiplication")

for i, val in enumerate(y):
    plt.text(i, val + 0.5, str(val), ha='center', va='bottom')


plt.savefig("exo1.png", dpi=300, bbox_inches='tight')



plt.figure(figsize=(8, 6))
plt.bar(x, y2, color='skyblue')

plt.xlabel("matrix size")
plt.ylabel("time of execution")
plt.title("time of exection for matrix search")

for i, val in enumerate(y2):
    plt.text(i, val + 0.5, str(val), ha='center', va='bottom')


plt.savefig("exo1.png", dpi=300, bbox_inches='tight')
