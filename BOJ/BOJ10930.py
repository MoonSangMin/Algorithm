import hashlib

pt = input() #plaintext
ct = hashlib.sha256(pt.encode()) #encrypted text

print(ct.hexdigest())