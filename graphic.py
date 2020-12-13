import subprocess
import shlex
import numpy as np
from matplotlib import pyplot as plt


unsortedTexts = open('input.txt', 'r').read().split('\n')
sortedTexts = open('output.txt', 'r').read().split('\n')

results = {}

for i in range(0, int(len(unsortedTexts) - 3)):
    cmd = '../a ' + unsortedTexts[i] + ' ' + sortedTexts[i]
    args = shlex.split(cmd)
    p = subprocess.Popen(args, stdout=subprocess.PIPE, stderr=subprocess.STDOUT)
    result = p.communicate()[0]
    try:
        result = int(str(result)[2: -1])

        print(result)
        if(int(result) >= 0):
            results[str(len(unsortedTexts[i]))] = result
    except:
        print(result)


print(list(results.keys()))
plt.plot(list(results.keys())[:-1], list(results.values())[:-1])
plt.xticks(np.arange(len(unsortedTexts)), ('1', '', '', '', '', '', '', '', '', '', '200', '', '', '', '', '', '', '', '', '', '', '', '', '', '', '500', '', '', '', '', '', '', '', '', '', '', '', '', '', '', '800', '', '', '', '', '', '', '', '', '', '1000'))
plt.ylabel("Мллисекунды")
plt.xlabel("Размер")
plt.show()