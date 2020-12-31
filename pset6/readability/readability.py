class text(str):
    def __init__(self):
        self.read = str()
        self.words = float()
        self.letters = float()
        self.sentences = float()
alphabet = list('abcdefghijklmnopqrstuvwxyz')
upper = list('ABCDEFGHIJKLMNOPQRSTUVWXYZ')
punct = list('.!?')

def main():
    tsource = text()
    tsource.read = input("Text:")
    if(len(tsource.read) > 0):
        tsource.words += 1
    for i in range(len(tsource.read)):
        if(tsource.read[i] == ' '):
            tsource.words += 1
        if((tsource.read[i] in alphabet) == True) or ((tsource.read[i] in upper) == True):
            tsource.letters += 1
        if((tsource.read[i] in punct) == True and ((tsource.read[i-1] in punct) == False)):
            tsource.sentences += 1
    """these lines use the in operators and their boolean operators to evaluate every chracter of the user input against some preset global lists"""
    if(tsource.words > 100):
        tsource.words /= 100

    if(tsource.words < 100):
        tsource.words  = 100 / tsource.words

    grade = 0.0588 * (tsource.letters * tsource.words) - 0.296 * (tsource.sentences * tsource.words) - 15.8
    grade = round(grade)

    if(grade >= 16):
        print("Grade 16+\n")
        return 0
    if(grade <= 1):
        print("Before Grade 1\n")
        return 0
    else:
        print("Grade " + str(grade),"\n")
        return 0

main()