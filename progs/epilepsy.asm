.exec 8
ldi $1, 0x7; on veut pointer sur l'écran en 0x70000
ldi $2, 0x0000
ldi $3, 0xFFF0 ; couloeur : blanc
loop: write $3, $1, $2; on écrit blanc sur l'adresse
addi $2, 0x0008 ; on se déplace sur l'écran
flip; on l'affiche
ldi $4, 0xFFFF
disp $4
sub $4, $2
disp $2
nz $4 ; est ce qu'on est à la fin ?
jf loop ; si non, on continue
