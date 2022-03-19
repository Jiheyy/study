sentence = input()
sentence = sentence.split(' ')
answer = 0
for s in sentence:
    if s is '':
        continue
    answer+=1;
print(answer)
