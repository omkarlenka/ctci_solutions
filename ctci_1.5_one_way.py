def isOneEditAway(s1, s2):
    '''
    Allowed Edits: Replace,Remove,Insert
    '''
    if len(s1) == len(s2):
        i =0
        count = 0
        while i < len(s1):
            if s1[i] != s2[i]:
                count+=1
                if count > 1:
                    return False
            i+=1
    else:
        count = 0
        len_s1 = len(s1)
        len_s2 = len(s2)
        if abs(len_s1 - len_s2) > 1:
            return False

        if len_s2 < len_s1:
            count = 0
            i = 0 #smaller sting
            j = 0 #longer string
            while i < len_s2:
                if s2[i] == s1[j]:
                    i+=1
                    j+=1
                else:
                    count +=1
                    j+=1

                    if count > 1:
                        return False
        else:
            count = 0
            i = 0  # smaller sting
            j = 0  # longer string
            while i < len_s1:
                if s1[i] == s2[j]:
                    i += 1
                    j += 1
                else:
                    count += 1
                    j += 1

                    if count > 1:
                        return False
    return True

print isOneEditAway('pies', 'ple')
print isOneEditAway('pale', 'bale')
print isOneEditAway('pales', 'pale')
