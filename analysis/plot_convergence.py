import matplotlib.pyplot as plt
import pandas as pd

df = pd.read_csv("results.csv")



X = df['i'].tolist()[0:100]
Y = df['loss'].tolist()[0:100]


plt.plot(X, Y)

plt.title("Training Loss vs. Iterations")
plt.xlabel("Iterations")
plt.ylabel("Loss L(a,b,r)")


plt.show()