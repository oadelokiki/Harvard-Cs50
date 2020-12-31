usernumber = int(input("Please specify a Height for your pyramid:"))
def pyramidgen(inty):

    if(inty >= 1 and inty <= 8):
        for i in range(0,inty):
            print(" " * (inty-i-1), "#" * (i+1), " ", "#"* (i+1), " " * (inty-1))
    else:
        while(inty < 0 or inty > 8):
            inty = int(input("Please select a number between 1 and 8:"))

pyramidgen(usernumber)
