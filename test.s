.data
err_msg1:   .asciiz "Error division by zero\n"
.text
.globl main
div_by_zero:
li $v0, 4
la $a0, err_msg1
syscall
li $v0, 10
syscall
a:
sub $fp, $sp, 4
lw $8, 4($fp)
li $9, 1
add $8, $8, $9
move $v0, $8
# Cleanning stack
add $sp, $sp, 0
jr $ra
# rule p12 Statements -> Statement
# rule p4 FuncDecl -> RetType ID LPAREN Formals RPAREN LBRACE Statements RBRACE
# Cleanning stack
add $sp, $sp, 0
jr $ra
f:
sub $fp, $sp, 4
lw $10, 4($fp)
lw $11, 8($fp)
add $10, $10, $11
lw $12, 12($fp)
# rule p34 Call a(expList)
# Storing registers
sub $sp, $sp, 4
sw $8, ($sp)
sub $sp, $sp, 4
sw $10, ($sp)
sub $sp, $sp, 4
sw $12, ($sp)
sub $sp, $sp, 4
sw $ra, ($sp)
# Storing 1 arguments
sub $sp, $sp, 4
sw $12, ($sp)
jal a
# Poping arguments
add $sp, $sp, 4
lw $ra, ($sp)
add $sp, $sp, 4
# Restoring registers
lw $12, ($sp)
add $sp, $sp, 4
lw $10, ($sp)
add $sp, $sp, 4
lw $8, ($sp)
add $sp, $sp, 4
move $13 $v0
add $10, $10, $13
# declaring i with the value in $10
sub $sp, $sp, 4
sw $10, ($sp)
# rule p12 Statements -> Statement
# rule p54 M->quad...
label_59:
lw $14, 0($fp)
move $v0, $14
# Cleanning stack
add $sp, $sp, 4
jr $ra
# rule p13 Statements -> Statements Statement
# back-patching stmts->nextlist with label_59
# rule p4 FuncDecl -> RetType ID LPAREN Formals RPAREN LBRACE Statements RBRACE
# Cleanning stack
add $sp, $sp, 4
jr $ra
main:
sub $fp, $sp, 4
li $15, 30
li $16, 23
li $17, 1
# rule p34 Call f(expList)
# Storing registers
sub $sp, $sp, 4
sw $8, ($sp)
sub $sp, $sp, 4
sw $12, ($sp)
sub $sp, $sp, 4
sw $14, ($sp)
sub $sp, $sp, 4
sw $15, ($sp)
sub $sp, $sp, 4
sw $16, ($sp)
sub $sp, $sp, 4
sw $17, ($sp)
sub $sp, $sp, 4
sw $ra, ($sp)
# Storing 3 arguments
sub $sp, $sp, 4
sw $15, ($sp)
sub $sp, $sp, 4
sw $16, ($sp)
sub $sp, $sp, 4
sw $17, ($sp)
jal f
# Poping arguments
add $sp, $sp, 12
lw $ra, ($sp)
add $sp, $sp, 4
# Restoring registers
lw $17, ($sp)
add $sp, $sp, 4
lw $16, ($sp)
add $sp, $sp, 4
lw $15, ($sp)
add $sp, $sp, 4
lw $14, ($sp)
add $sp, $sp, 4
lw $12, ($sp)
add $sp, $sp, 4
lw $8, ($sp)
add $sp, $sp, 4
move $18 $v0
# rule p34 Call printi(expList)
li $v0, 1
move $a0, $18
syscall
# rule p12 Statements -> Statement
# rule p4 FuncDecl -> RetType ID LPAREN Formals RPAREN LBRACE Statements RBRACE
# Cleanning stack
add $sp, $sp, 0
jr $ra
