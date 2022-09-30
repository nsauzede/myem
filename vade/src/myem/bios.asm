times 65536 - 16 db 0x90
org 0xfff0
reset:
;mov ax,1
;mov ax,2
jmp 0xf000:reset
end:
times (16 - (end - reset)) db 0xff
;db 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16