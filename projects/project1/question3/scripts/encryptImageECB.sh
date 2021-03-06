#!/bin/bash

input_bmp_name=$1

mkdir -p output

openssl enc -aes-256-ecb -e -in "${input_bmp_name}.bmp" -out "output/${input_bmp_name}.enc.bmp" -K 00112233445566778889aabbccddeeff -iv f12322165afed1232102030405060708
head -c 54 ${input_bmp_name}.bmp > output/header
tail -c +55 output/${input_bmp_name}.enc.bmp > output/body
cat output/header output/body > output/${input_bmp_name}-enc-ecb.bmp

rm output/${input_bmp_name}.enc.bmp
rm output/header
rm output/body
