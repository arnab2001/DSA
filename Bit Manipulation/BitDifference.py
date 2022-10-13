def countBitsFlip(self,a,b):

        ##Your code here

        count = 0

        xorVal = a^b

        while xorVal != 0:

            if xorVal & 1 == 1:

                count += 1

            xorVal = xorVal >> 1    

        return count