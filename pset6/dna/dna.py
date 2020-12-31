import sys
import csv
"""sys allows me to pass information from the terminal to the script"""
"""sys.argv[x] allows me to access command line arguments"""
def stringparse(file_name, string_to_search):
    """ Check if any line in the file contains given string """
    # Open the file in read only mode
    with open(file_name, 'r') as read_obj:
        # Read all lines in the file one by one
        for line in read_obj:
            # For each line, check if line contains the string
            if string_to_search in line:
                return True
    return False


def usage():
    if(len(sys.argv) > 3):
        print("Error Usage: python dna.py <.csv> <.txt>")
        return 1

class dnaclass():
    def __init__(self):
        self.name = str()
        self.occurences = []
        self.STR = str()
person = dnaclass()

def dnatest(csvf, txt):
    runon = False
    runonlist = []
    csvlist = []
    csvindex = []
    dnastring = str()
    with open(csvf, newline='') as csvfile:
        rfile = csv.reader(csvfile, delimiter = ',', quotechar='|')
        for row in rfile:
            csvlist.append(row)
    with open(txt, 'r') as txtfile:
        for line in txtfile:
            dnastring += line

    countlist =[]
    lastsubstr = str()
    for i in range(len(dnastring) - 1):
        longest = 0

        for j in range(1, len(csvlist[0]) - 1):
            addend = len(csvlist[0][j])
            substr = dnastring[i: (i + addend)]

            if substr == csvlist[0][j] and dnastring[(i + addend): (i + addend + addend)] == csvlist[0][j]:
                addend += addend
                for k in range(int((addend/(len(csvlist[0][j]))))):
                    if dnastring[(i + addend): (i+len(csvlist[0][j]) + addend)] == substr:
                        addend += len(csvlist[0][j])
                i += addend
                countlist.append(substr)
                countlist.append(addend)
                """print(substr, addend)"""
            elif substr == csvlist[0][j] and dnastring[(i + addend): (i + addend + addend)] != csvlist[0][j]:
                i += addend
                countlist.append(substr)
                countlist.append(addend)
                """print(substr, addend)"""
                substr = dnastring[i: (i+addend)]
    print(csvlist)
    print(countlist)
    finalindex = 0
    for i in range(1, len(countlist), 2):
        longest = int(countlist[i] / len(countlist[i-1]))
        print(longest)
        for k in range(1, len(csvlist)):
            for j in range(1, len(csvlist[k])):
                if longest == csvlist[k][j]:
                    print(csvlist[k][0])
                else:
                    print(csvlist[k][0])



usage()
dnatest(sys.argv[1],sys.argv[2])