# Given an array of buildings and a direction that all of the buildings face, return an array of the indices of the buildings tha can see the sunset.
# A building can see the sunset if it's strictly taller than all of the buildings that come after it in the direction that it faces.
# The input array named buildings] contains positive, non-zero integers representing the heights of the buildings. A
# building at Index thus has a height denoted by [buildings [1]. All of the buildings face the same direction, and this direction is either east or west, denoted by the input string named direction, which will always be equal to either "EAST" or "WEST". In relation to the input array, you can interpret these directions as right for east and left for west.
# Important note: the indices in the ouput array should be sorted in ascending order.


def sunsetViews(buildings, direction):
	arr = []
	dir = []
	if direction == "EAST":
		dir = range(len(buildings))
	else:
		dir = reversed(range(len(buildings)))
	for i in dir:
		if arr == []:
			arr.append(i)
		else:
			while arr != [] and buildings[arr[-1]] <= buildings[i]:
				arr.pop()
			arr.append(i)
			
	return arr if direction == "EAST" else arr[::-1]
