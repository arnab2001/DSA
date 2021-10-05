# Write a function that takes in a string made up of brackets (0000, and and other optional characters. The function. should return a boolean representing whether the string is balanced with regards to brackets.
# A string is said to be balanced if it has as many opening brackets of a certain type as it has closing brackets of that type and if no bracket is unmatched. Note that an opening bracket can't match a corresponding closing bracket that comes before it, and similarly, a closing bracket can't match a corresponding opening bracket that comes after it. Also, brackets can't overlap each other as in [(1)

# -------- Partially working solution | 18/23 cases--------


def balancedBrackets(string):
	dict = {"{":"}", "[":"]", "(":")"}
	opening = '({['
	close = ')}]'
	stack = []
	for char in string:
		if char in opening:
			stack.append(dict[char])
		elif char in close:
			if not stack or stack.pop() != char:
				return False
	return True if stack == [] else False
		