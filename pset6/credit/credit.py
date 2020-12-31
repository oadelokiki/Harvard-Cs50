class card(str):
    def __init__(self):
        self.str = str()
        self.ind = 0
        self.vali = bool
        self.type = str()
creditcard = card()
def luhnsalg(obj):
    obj.str = input("Please Enter a Valid Card Number:")
    obj.ind = len(obj.str) - 1
    everyother = []
    remaining = []
    checksum = 0
    lencheck = 0
    if(obj.ind > 14 or (obj.str[0] == 5 or obj.str[0] == 3)):
        lencheck += 1
    
    while(obj.ind > -2):
        remaining.append(obj.str[obj.ind])
        obj.ind = obj.ind - 1
        everyother.extend(str(int(obj.str[obj.ind]) * 2))
        obj.ind = obj.ind - 1
    remaining.extend(everyother)
   
    for i in range(lencheck, len(remaining) - 1):
        checksum += int(remaining[i])
    
    print(remaining)
    print(checksum)
    if(checksum % 10 == 0):
        if(len(obj.str) >= 13 and len(obj.str) <= 16):
            if(int(obj.str[0]) == 4):
                obj.type = "VISA"
                print(obj.type)
                return True
            if(int(obj.str[0]) == 3 and (int(obj.str[1]) == 3 or int(obj.str[1]) == 7)):
                obj.type = "AMEX"
                print(obj.type)
                return True
            if(int(obj.str[0]) == 5):
                obj.type = "MASTERCARD"
                print(obj.type)
                return True
        else:
            print("INVALID")
            return False
    else:
        print("INVALID")
        return False
    """^performs luhns algorithm on objects of type "card"^"""
    
luhnsalg(creditcard)