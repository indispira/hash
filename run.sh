#!/bin/bash

clear
make && make clean && clear && \
./ft_ssl && echo "" && ./ft_ssl foobar && echo "" && \
\
echo "" && echo "TESTS OF MD5 HASH:" && \
echo "qwertyuiop[]asdfghjkl;'zxcvbnm,./1234567890-=QWERTYUIOPASDFGHJKLZXCVBNM:" && \
echo "qwertyuiop[]asdfghjkl;'zxcvbnm,./1234567890-=QWERTYUIOPASDFGHJKLZXCVBNM" | openssl md5 && \
echo "qwertyuiop[]asdfghjkl;'zxcvbnm,./1234567890-=QWERTYUIOPASDFGHJKLZXCVBNM" | md5 && \
echo "qwertyuiop[]asdfghjkl;'zxcvbnm,./1234567890-=QWERTYUIOPASDFGHJKLZXCVBNM" | ./ft_ssl md5 && \
echo "pickle rick:" && \
echo "pickle rick" | openssl md5 && \
echo "pickle rick" | md5 && \
echo "pickle rick" | ./ft_ssl md5 && \
# echo "Do not pity the dead, Harry.: -p" && \
# echo "Do not pity the dead, Harry." && echo "2d95365bc44bf0a298e09a3ab7b34d2f" && \
# echo "Do not pity the dead, Harry." | ./ft_ssl md5 -p && \
# echo "Pity the living.: -q -r" && echo "e20c3b973f63482a778f3fd1869b7f25" && \
# echo "Pity the living." | ./ft_ssl md5 -q -r && \
# echo "And above all,: file" && echo "And above all," > file && \
# echo "MD5 (file) = 53d53ea94217b259c11a5a2d104ec58a" && \
# ./ft_ssl md5 file && \
# echo "And above all,: -r file" && echo ":53d53ea94217b259c11a5a2d104ec58a file" && \
# ./ft_ssl md5 -r file && \
# echo "pity those that aren't following baerista on spotify.: -s ..." && \
# echo "MD5 (\"pity those that aren't following baerista on spotify.\") = a3c990a1964705d9bf0e602f44572f5f" && \
# ./ft_ssl md5 -s "pity those that aren't following baerista on spotify." && \
# echo "be sure to handle edge cases carefully: -p file" && \
# echo "be sure to handle edge cases carefully" && echo "3553dc7dc5963b583c056d1b9fa3349c" && \
# echo "MD5 (file) = 53d53ea94217b259c11a5a2d104ec58a" && \
# echo "be sure to handle edge cases carefully" | ./ft_ssl md5 -p file && \
# echo "some of this will not make sense at first: file" && \
# echo "MD5 (file) = 53d53ea94217b259c11a5a2d104ec58a" && \
# echo "some of this will not make sense at first" | ./ft_ssl md5 file
# echo "but eventually you will understand: -p -r file" && \
# echo "but eventually you will understand" && echo "dcdd84e0f635694d2a943fa8d3905281" && \
# echo "53d53ea94217b259c11a5a2d104ec58a file" && \
# echo "but eventually you will understand" | ./ft_ssl md5 -p -r file && \
# echo "GL HF let's go: -p -s 'foo' file" && echo "GL HF let's go" && \
# echo "d1e3cc342b6da09480b27ec57ff243e2" && echo "MD5 ("foo") = acbd18db4cc2f85cedef654fccc4a4d8" && \
# echo "MD5 (file) = 53d53ea94217b259c11a5a2d104ec58ai" && \
# echo "GL HF let's go" | ./ft_ssl md5 -p -s "foo" file && \
# echo "one more thing: -r -p -s 'foo' file -s 'bar" && \
# echo "one more thing" && echo "a0bd1876c6f011dd50fae52827f445f5" && \
# echo "acbd18db4cc2f85cedef654fccc4a4d8 'foo'" && echo "53d53ea94217b259c11a5a2d104ec58a file" && \
# echo "ft_ssl: md5: -s: No such file or directory" && echo "ft_ssl: md5: bar: No such file or directory" && \
# echo "one more thing" | ./ft_ssl md5 -r -p -s "foo" file -s "bar"
# echo "just to be extra clear: -r -q -p -s 'foo' file" && \
# echo "just to be extra clear" && echo "3ba35f1ea0d170cb3b9a752e3360286c" && \
# echo "acbd18db4cc2f85cedef654fccc4a4d8" && echo "53d53ea94217b259c11a5a2d104ec58a" && \
# echo "just to be extra clear" | ./ft_ssl md5 -r -q -p -s "foo" file && \
\
# > echo "https://www.youtube.com/watch?v=w-5yAtMtrSM" > big_smoke_order_remix
# > ./ft_ssl sha256 -q big_smoke_order_remix
# a8dc621c3dcf18a8a2eddae1845e8e5f6498970a867056ac5f7121ac3d66cfd9
# >
# > openssl sha -sha256 big_smoke_order_remix
# SHA256 (big_smoke_order_remix) = a8dc621c3dcf18a8a2eddae1845e8e5f6498970a867056ac5f7121ac3d66cfd9
# >
# > ./ft_ssl sha256 -s "wubba lubba dub dub"
# SHA256 ("wubba lubba dub dub") = 23a0944d11b5a54f1970492b5265c732044ae824b7d5656acb193e7f0e51e5fa
echo "Test finished"
