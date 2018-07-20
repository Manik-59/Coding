numberOfEnteries = int(input())

phoneBook = {}
for x in range(1,numberOfEnteries+1):
    element = input()
    listOfElements = list(element.split())
    print(listOfElements)
    phoneBook[listOfElements[0]] = listOfElements[1]
    print(phoneBook)

queryList = []
for x in range(numberOfEnteries):
    name = input()
    queryList.append(name)
for x in queryList:
    if x in phoneBook.keys():
        print(x,"=",phoneBook[x])
    else:
        print("Not found")
            

    ## Working As expected