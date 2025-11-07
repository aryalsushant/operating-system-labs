#Sushant Aryal
#W10166204

.data
vals:        .word 6, 17, 12, 32, 42, 11, 7, 8, 90, 10
count:       .word 10

msg_prompt:  .asciiz "Enter the key to search: "
msg_iter:    .asciiz ">> Iterative Search:\n"
msg_rec:     .asciiz ">> Recursive Search:\n"
msg_yes:     .asciiz "Key found!\n"
msg_no:      .asciiz "Key not found.\n"

.text
.globl main

main:
    li $v0, 4
    la $a0, msg_prompt
    syscall

    li $v0, 5
    syscall
    move $s0, $v0

    li $v0, 4
    la $a0, msg_iter
    syscall

    la $a0, vals
    lw $a1, count
    move $a2, $s0
    jal iter_search

    beqz $v0, .iter_notfound
    li $v0, 4
    la $a0, msg_yes
    syscall
    j .after_iter

.iter_notfound:
    li $v0, 4
    la $a0, msg_no
    syscall

.after_iter:
    li $v0, 4
    la $a0, msg_rec
    syscall

    la $a0, vals
    lw $a1, count
    move $a2, $s0
    jal rec_search

    beqz $v0, .rec_notfound
    li $v0, 4
    la $a0, msg_yes
    syscall
    j .finish

.rec_notfound:
    li $v0, 4
    la $a0, msg_no
    syscall

.finish:
    li $v0, 10
    syscall

iter_search:
    addi $t0, $zero, 0
.it_loop:
    beq  $t0, $a1, .it_not_found
    sll  $t1, $t0, 2
    add  $t2, $a0, $t1
    lw   $t3, 0($t2)
    beq  $t3, $a2, .it_found
    addi $t0, $t0, 1
    j .it_loop

.it_found:
    li $v0, 1
    jr $ra

.it_not_found:
    li $v0, 0
    jr $ra

rec_search:
    addi $sp, $sp, -8
    sw   $ra, 4($sp)
    sw   $s1, 0($sp)
    beqz $a1, .rec_base_notfound
    lw   $t0, 0($a0)
    beq  $t0, $a2, .rec_base_found
    addi $a0, $a0, 4
    addi $a1, $a1, -1
    jal rec_search
    lw   $s1, 0($sp)
    lw   $ra, 4($sp)
    addi $sp, $sp, 8
    jr   $ra

.rec_base_found:
    li $v0, 1
    lw   $s1, 0($sp)
    lw   $ra, 4($sp)
    addi $sp, $sp, 8
    jr   $ra

.rec_base_notfound:
    li $v0, 0
    lw   $s1, 0($sp)
    lw   $ra, 4($sp)
    addi $sp, $sp, 8
    jr   $ra
