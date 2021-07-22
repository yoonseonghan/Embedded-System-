#!/bin/bash

gdb-multiarch \
        -ex "target remote :3333" \
        -s "out.elf" \
    	-ex "load" \
    	-ex "b EXTI0_IRQHandler" \
    	-ex "set arc arm" \
        -ex "monitor system_reset" \
        -ex "continue" 
