import matplotlib.pyplot as plt
def PrintGraph():
    
    plt.plot(range(10), 'o')
    plt.show()
    PrintGraph()
PrintGraph()