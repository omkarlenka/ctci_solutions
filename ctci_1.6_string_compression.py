def compressString(s1):
    s2 = []
    i1 = 1
    count = 1
    isCompressed = False
    len_s1 = len(s1)

    while i1 < len_s1:
        if s1[i1] == s1[i1-1]:
            count+=1

            if i1 == len_s1 - 1:
                s2.append(s1[i1])
                s2.append(count)

            if (count > 1) and (not isCompressed):
                isCompressed = True

        else:
            s2.append(s1[i1-1])
            s2.append(count)
            count = 1

            if i1 == len_s1 - 1:
                s2.append(s1[i1])
                s2.append(count)

        i1+=1

    if isCompressed:
        return ''.join(map(str,s2))
    else:
        return s1

print compressString('aaaa')
print compressString('aaaabbbccc')
print compressString('aaaabc')
print compressString('abc')
print compressString('a')
print compressString(' ')
print compressString('aabccdde')
