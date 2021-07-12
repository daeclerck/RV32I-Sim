## Compiler commands

g++ -g -ansi -pedantic -Wall -Werror -std=c++14 -c -o main.o main.cpp

g++ -g -ansi -pedantic -Wall -Werror -std=c++14 -c -o rv32i_decode.o rv32i_decode.cpp

g++ -g -ansi -pedantic -Wall -Werror -std=c++14 -c -o memory.o memory.cpp

g++ -g -ansi -pedantic -Wall -Werror -std=c++14 -c -o hex.o hex.cpp

g++ -g -ansi -pedantic -Wall -Werror -std=c++14 -c -o registerfile.o registerfile.cpp

g++ -g -ansi -pedantic -Wall -Werror -std=c++14 -c -o rv32i_hart.o rv32i_hart.cpp

g++ -g -ansi -pedantic -Wall -Werror -std=c++14 -c -o cpu_single_hart.o cpu_single_hart.cpp

g++ -g -ansi -pedantic -Wall -Werror -std=c++14 -o rv32i main.o rv32i_decode.o memory.o hex.o registerfile.o rv32i_hart.o cpu_single_hart.o

## Output commands

./rv32i -i handouts5/allinsns5.bin > handouts5/allinsns5-i.out

./rv32i -X handouts5/allinsns5.bin > handouts5/allinsns5-X.out 2>&1 || true

./rv32i -dirz handouts5/allinsns5.bin > handouts5/allinsns5-dirz.out

./rv32i -dz handouts5/allinsns5.bin > handouts5/allinsns5-dz.out

./rv32i -m100 -iz handouts5/allinsns5.bin > handouts5/allinsns5-iz-m100.out

./rv32i -m100 -ir handouts5/allinsns5.bin > handouts5/allinsns5-ir-m100.out

./rv32i -m100 -irl2 handouts5/allinsns5.bin > handouts5/allinsns5-irl2-m100.out

./rv32i -dirz -m8500 handouts5/torture5.bin > handouts5/torture5-dirz-m8500.out

./rv32i -iz -m8500 handouts5/torture5.bin > handouts5/torture5-iz-m8500.out

./rv32i -z -m8500 handouts5/torture5.bin > handouts5/torture5-z-m8500.out

./rv32i -m8500 handouts5/torture5.bin > handouts5/torture5-m8500.out

./rv32i -z -m50000 handouts5/sieve.bin | head -10 > handouts5/sieve-z-m50000-head-10.log

./rv32i -z -m50000 handouts5/sieve.bin | grep "^00034[01]" > handouts5/sieve-z-m50000-grep-0003401.log
