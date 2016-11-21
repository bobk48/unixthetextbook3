filename = "data.txt"
collection=[]
for line in open(filename):
    fields = line.split(",")        #splits line by commas
    name = fields[0]                #create the fields
    uses = int(fields[1])
    value = float(fields[2])
    card = (name,uses,value)        #create the tuple
    collection.append(card)
print collection[0]
print collection[3][2]
sum = 0.0
for name, uses, value in collection:
    sum += uses / value
print sum
