def isRotation(s1, s2):
    len1 = len(s1)
    len2 = len(s2)

    if len1 == len2 and len1 > 0:
        if s2 in s1+s1:
            return True

    return False

print isRotation('waterbottle', 'erbottlewat')
print isRotation('waterbottle', 'erbottlewa')
print isRotation('waterbottle', 'bottlewater')
print isRotation('ww', 'w')


