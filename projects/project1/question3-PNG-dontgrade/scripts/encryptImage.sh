#!/bin/bash

input_png_name=$1

mkdir -p output

openssl enc -aes-256-cbc -e -in "${input_png_name}.png" -out "output/${input_png_name}.enc.png" -K 00112233445566778889aabbccddeeff -iv f12322165afed1232102030405060708
head -c 4 ${input_png_name}.png > output/header
tail -c +5 output/${input_png_name}.enc.png > output/body
cat output/header output/body > output/${input_png_name}-enc.png

openssl enc -aes-256-cbc -d -in "output/${input_png_name}.enc.png" -out "output/${input_png_name}.dec.png" -K 00112233445566778889aabbccddeeff -iv f12322165afed1232102030405060708
