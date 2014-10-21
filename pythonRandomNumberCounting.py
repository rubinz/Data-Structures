import random
#runNumber = 100
i = 0
output = open("random.txt", "w")
runNumber = input("Enter how many numbers you want to generate: ") 

while (i<runNumber):


	randomNum = random.randint(1,9)
	print randomNum
	output.write(str(randomNum))
	i = i + 1

print "Done"
output.close()