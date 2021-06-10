from random import randrange

def load_file_all():
    list = []
    with open('animal.txt','r') as data:
        lines = data.readlines()
    
    for line in lines:
        list.append(line)

    return list

def makeRandomList(N, range):
    list=[]

    i=0
    while i<N:
        x = randrange(0, range)
        dup=0

        for item in list:
            if item==x:
                dup=1
        if dup==0:
            list.append(x)
            i+=1
    print('random List:',list)
    return list

def makeNameList(N, allList=load_file_all() ):
    list = makeRandomList(N, len(allList))
    nameList = []
    for item in list:
        nameList.append(allList[item])
    return nameList
