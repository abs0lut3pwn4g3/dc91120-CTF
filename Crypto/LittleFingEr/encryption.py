#!/usr/bin/env python

from Crypto.PublicKey import RSA
from Crypto.Util.number import *
import gmpy2
import flag

p = getPrime(1024)
q = getPrime(1024)
e = 5
n = p*q
ciphertext = pow(bytes_to_long(flag),5,n)
s = pow(2,0xdeadbeef,n)
pubkey = RSA.construct((long(s), long(e)))
keyex = open('./pub.pem','wb')
keyex.write(pubkey.exportKey('PEM'))
keyex.close()

print 'ciphertext: ' + long_to_bytes(ciphertext).encode('base64')
