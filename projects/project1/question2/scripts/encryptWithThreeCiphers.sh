#!/bin/bash

mkdir -p output/threecipher

for count in 1 2 3
do
  openssl enc -aes-256-cfb -e -in "test${count}.txt" -out "output/threecipher/test${count}-cipher1.bin" -K 00112233445566778889aabbccddeeff -iv f12322165afed1232102030405060708
  openssl enc -aes256 -e -in "test${count}.txt" -out "output/threecipher/test${count}-cipher2.bin" -K 00112233445566778889aabbccddeeff -iv f12322165afed1232102030405060708
  openssl enc -des-ede3-ofb -e -in "test${count}.txt" -out "output/threecipher/test${count}-cipher3.bin" -K 00112233445566778889aabbccddeeff -iv f12322165afed1232102030405060708
done
