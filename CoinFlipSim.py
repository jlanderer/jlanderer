import numpy as np
import matplotlib.pyplot as plt
import math
import time
from random import random
def GraphOfPoissonDistribution():        # This function graphs the Poisson distribution for [0, 170],
   l = np.arange(171)                    # satisfying part A of the assignment.
   PofL = []                             # Factorial(i) cannot be computed for values more than 170,
   for i in l:                           # so that will be the maximum x value in the graph
       PofL.append(np.exp(-8) * (8 ^ i)/math.factorial(i)) # Poisson Formula for probability of 8%  
   plt.plot(PofL)
   plt.title('Probability of Heads x Times in 170 According to the Poisson Formula')
   plt.show()
   return PofL
        
def CoinFlip():    # This method runs the simulation, satisfying parts B and C
 StringTrials = input("How many trials would you like to run? Each trial flips 100 coins.")
 numTrials = int(StringTrials)
 ArrayHeadsPerTrial = [0] * numTrials
 numCoins = 100  # The number of coins per trial is always 100
 for i in range (numTrials):              # For all trials
       ArrayCoins = [False] * 100         # Make an array for the states of coins
       for j in range (numCoins):         # For all coins
           if random() < .08:             # determine state according to randomly generated probability 
               ArrayCoins[j] = True       # If heads, add 1 to the number of heads per trial of trial i
               ArrayHeadsPerTrial[i] = ArrayHeadsPerTrial[i] + 1  
                  
 plt.hist(ArrayHeadsPerTrial) # plot a histogram of the simualtion results (Part C)
 plt.title('Frequency of Heads Count Across Trials')
 plt.xlabel('Number of Heads in All Trials (Resultant Values of Simulation)')
 plt.ylabel('# of Trials With X Occurences of Heads')
 plt.show()
 return ArrayHeadsPerTrial, numTrials               
                 
def GraphPoissonTimesNumTrials(PofL, numTrials):  # This method multiplies values from the Poisson Formula
    for i in range (len(PofL)):                   # by the total number of trials and graphs the results,
        PofL[i] = (PofL[i] * numTrials)           # satisfying Part D of the assignment
    plt.plot(PofL)
    plt.title('Applied Poisson Formula')
    plt.xlabel('# of Trials up to 170')
    plt.ylabel('Probability of Heads (Out of Total Number of Trials)')
    plt.show()
    print("Notice that the applied function has the same shape as the unmodified Poisson distribution,")
    print("but the Y values are larger. The axes still represent the same as they did before.")
    
def ShotNoise(): # Second part of the assignment, wating times
    print("\n\nThis part of the problem requires an array of size 1000 whose odds of '1' are 8%, as they are in the simulation.")
    print("The distances from one occurence of 1 to the next are calculated and graphed as 'shot noise'")
    array = [0] * 1000   # make an array of length 1000
    for i in range (len(array)):
        if random() < .08:
            array[i] = 1       # randomly determine state of coin with same probability as simulation
    PositionOfHeadsElements = np.nonzero(array)  # Mark the array elements of all heads
    DifferenceBetweenHeadsPositions = np.diff(PositionOfHeadsElements) # calculate distances between those elements
    WaitingTimes = DifferenceBetweenHeadsPositions.flatten('F') # Change dimensions of array (Because np.diff changed those)
    plt.plot(WaitingTimes)  # graph of distance between occurences of heads
    plt.title('Shot Noise')
    plt.xlabel('Total # of Heads in Array')
    plt.ylabel('Distance From One Head to the Next')
    plt.show()
        
    plt.semilogy(WaitingTimes)       # semilog graph of waiting times
    plt.title('Shot Noise (Semilog Graph)')
    plt.ylabel('Logarithmic Scale')
    plt.show()
    AverageWaitingTime = sum(WaitingTimes)/len(WaitingTimes)
    print("The average time between occurences of heads is", round(AverageWaitingTime), " elements")
    
    
Pofl = GraphOfPoissonDistribution() # Part 1A
ArrayHeadsPerTrial, numTrials = CoinFlip() # Parts 1B and 1C
GraphPoissonTimesNumTrials(Pofl, numTrials) # Part 1D
time.sleep(10)
ShotNoise() # Part 2
