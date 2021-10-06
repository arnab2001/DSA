# Write a MinMaxStack class for a Min Max Stack. The class should support:  
# • Pushing and popping values on and off the stack.  
# • Peeking at the value at the top of the stack.  
# • Getting both the minimum and the maximum values in the stack at any given point in time.  

# All class methods, when considered independently, should run in constant time and with constant space.
class MinMaxStack:
    def __init__(self):
        self.arr = []
        self.minMax = [[float('inf'),float('-inf')]]

    def peek(self):
        return self.arr[-1]

    def pop(self):
        self.minMax.pop()
		return self.arr.pop()        
		
    def push(self, number):
		maxi = self.minMax[-1][1]
		mini = self.minMax[-1][0]
        self.arr.append(number)
        if number > self.minMax[-1][1]:
			maxi = number
        if number < self.minMax[-1][0]:
			mini = number
        self.minMax.append([mini,maxi])

    def getMin(self):
        return self.minMax[-1][0]
            
    def getMax(self):
        return self.minMax[-1][1]
