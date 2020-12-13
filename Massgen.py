import random

def createArray(length):
    localLength = length * 4
    array = [x for x in range(0, localLength)]
    random.shuffle(array)
    returnArray = []
    for i in range(0, localLength):
        if(i % 4 == 0):
            returnArray.append(array[i])
    return returnArray



unsortedFile = open("input.txt", "a")
sortedFile = open("output.txt", "a")

for i in range(1, 1000, 20):   
    arr = createArray(i)
    unsortedArray = ' '.join(list(map(str, arr))) + '\n'
    sortedArray = ' '.join(list(map(str,sorted(arr)))) + '\n'
    unsortedFile.write(str(unsortedArray))
    sortedFile.write(str(sortedArray))

unsortedFile.close()
sortedFile.close()