#!/bin/bash

gdb-multiarch \
	-ex "set arc arm" \
	-ex "target remote :3333" \
	-ex "file out.elf" \
	-ex "load" \
	-ex "b EXTI0_IRQHandler" \
	-ex "continue"
