import matplotlib.pyplot as plt
def PoissonFormula():
    xValues = [0,1,2,3,4,5,6,7,8,9,10]
    yValues = [2,4,6,8,10,12,14,16,18,20]
    plt.hist(yValues)
    plt.xlabel('xValues')
    plt.ylabel("yValue")
    plt.show()
    
PoissonFormula()