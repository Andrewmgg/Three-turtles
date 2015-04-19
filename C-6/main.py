line = raw_input()
text = ''
for i in xrange(len(line) / 2):
    temp = line[i * 2] + line[i * 2 + 1]
    text += chr(int(temp, 16))
    
text = text.decode('utf-8')
text = text.encode('cp1251')

ans = ''

for c in text:
    ans += hex(ord(c)).split('x')[1]
    
print ans 
