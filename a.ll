define i32 @factorial(i32 %n.0) { 
entry: 
%n.0.addr = alloca i32
store i32 %n.0, i32* %n.0.addr
%e.0 = load i32, i32* %n.0.addr
%e.1 = add i32 0, 0
%e.2 = icmp sle i32 %e.0, %e.1
br i1 %e.2, label %btrue.0, label %bfalse.0

btrue.0:
%e.3 = add i32 0, 1
ret i32 %e.3
br label %bend.0

bfalse.0:
%e.4 = load i32, i32* %n.0.addr
%e.6 = load i32, i32* %n.0.addr
%e.7 = add i32 0, 1
%e.8 = sub i32 %e.6, %e.7
%e.5 = call i32 @factorial( i32 %e.8)
%e.9 = mul i32 %e.4, %e.5
ret i32 %e.9
br label %bend.0

bend.0:
ret i32 undef
}

define i32 @fibonacci(i32 %a.0, i32 %b.0, i32 %n.0) { 
entry: 
%a.0.addr = alloca i32
store i32 %a.0, i32* %a.0.addr
%b.0.addr = alloca i32
store i32 %b.0, i32* %b.0.addr
%n.0.addr = alloca i32
store i32 %n.0, i32* %n.0.addr
%e.10 = load i32, i32* %n.0.addr
%e.11 = add i32 0, 0
%e.12 = icmp sle i32 %e.10, %e.11
br i1 %e.12, label %btrue.1, label %bend.1

btrue.1:
%e.13 = load i32, i32* %a.0.addr
ret i32 %e.13
br label %bend.1

bend.1:
br label %while_condition.0

while_condition.0:
%e.14 = load i32, i32* %n.0.addr
%e.15 = add i32 0, 0
%e.16 = icmp sgt i32 %e.14, %e.15
br i1 %e.16, label %while_body.0, label %while_end.0

while_body.0:
%e.17 = add i32 0, 2
%a1.0.addr = alloca i32
store i32 %e.17, i32* %a1.0.addr
%e.18 = add i32 0, 2
%b2.0.addr = alloca i32
store i32 %e.18, i32* %b2.0.addr
%t.0.addr = alloca i32
%e.19 = load i32, i32* %b.0.addr
store i32 %e.19, i32* %t.0.addr
%e.20 = load i32, i32* %a.0.addr
%e.21 = load i32, i32* %b.0.addr
%e.22 = add i32 %e.20, %e.21
store i32 %e.22, i32* %b.0.addr
%e.23 = load i32, i32* %t.0.addr
store i32 %e.23, i32* %a.0.addr
%e.24 = load i32, i32* %n.0.addr
%e.25 = add i32 0, 1
%e.26 = sub i32 %e.24, %e.25
store i32 %e.26, i32* %n.0.addr
br label %while_condition.0

while_end.0:
%e.27 = fadd float 0.0, 0.5
%c.0.addr = alloca float
store float %e.27, float* %c.0.addr
%e.28 = fadd float 0.0, 0.0
%e.29 = fpext float %e.28 to double
%d.0.addr = alloca double
store double %e.29, double* %d.0.addr
%e.30 = load double, double* %d.0.addr
%e.31 = fptosi double %e.30 to i32
ret i32 %e.31
%e.32 = load i32, i32* %b.0.addr
ret i32 %e.32
ret i32 undef
}

define i32 @main() { 
entry: 
%e.35 = add i32 0, 1
%e.34 = call i32 @factorial( i32 %e.35)
%e.37 = add i32 0, 2
%e.36 = call i32 @factorial( i32 %e.37)
%e.39 = add i32 0, 5
%e.38 = call i32 @factorial( i32 %e.39)
%e.33 = call i32 @fibonacci( i32 %e.34, i32 %e.36, i32 %e.38)
ret i32 %e.33
ret i32 undef
}

