# Greedy Approach

class KnapsackPackage(object): 
    """ Knapsack Package Data Class """
    def __init__(self, weight, value): 
        self.weight = weight 
        self.value = value 
        self.cost = value / weight 
 
    def __lt__(self, other): 
        return self.cost < other.cost
 
class FractionalKnapsack(object):
    def __init__(self):
        pass
 
    def knapsackGreProc(self, W, V, M, n):
        packs = []
        for i in range(n): 
            packs.append(KnapsackPackage(W[i], V[i]))
        packs.sort(reverse = True)
        remain = M
        result = 0
        i = 0
        stopProc = False
        while (stopProc != True):
            if (packs[i].weight <= remain):
                remain -= packs[i].weight;
                result += packs[i].value;
            print("Pack ", i, " - Weight ", packs[i].weight, " - Value ", packs[i].value)
            if (packs[i].weight > remain):
                i += 1
            if (i == n):
                stopProc = True           
        print("Max Value:\t", result)
 
if __name__ == "__main__": 
    W = [15, 10, 2, 4] 
    V = [30, 25, 2, 6] 
    M = 37
    n = 4
    proc = FractionalKnapsack()
    proc.knapsackGreProc(W, V, M, n)

# Dynamic Programming Approach
def knapSack(W, wt, val, n): 
    K = [[0 for x in range(W + 1)] for x in range(n + 1)] 
   
    # Build table K[][] in bottom up manner 
    for i in range(n + 1): 
        for w in range(W + 1): 
            if i == 0 or w == 0: 
                K[i][w] = 0
            elif wt[i-1] <= w: 
                K[i][w] = max(val[i-1] 
                          + K[i-1][w-wt[i-1]],   
                              K[i-1][w]) 
            else: 
                K[i][w] = K[i-1][w] 
   
    return K[n][W] 
    
val = [60, 100, 120] 
wt = [10, 20, 30] 
W = 50
n = len(val) 
print(knapSack(W, wt, val, n))