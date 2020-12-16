declare i32 @printf(i8* %format.0, ...)
@a1.0.addr = global i32 0
define void @compute.a1.0() {
%e.0 = add i32 0, 9
store i32 %e.0, i32* @a1.0.addr
ret void
}

@b.0.addr = global i32 0
define void @compute.b.0() {
%e.1 = load i32, i32* @a1.0.addr
%e.2 = add i32 0, 3
%e.3 = add i32 %e.1, %e.2
store i32 %e.3, i32* @b.0.addr
ret void
}

@c.0.addr = global float 0.0
define void @compute.c.0() {
%e.4 = and i1 true, true
%e.5 = sitofp i1 %e.4 to float
store float %e.5, float* @c.0.addr
ret void
}

define void @empty(i32* %c.1) { 
entry: 
%c.1.addr = alloca i32*
store i32* %c.1, i32** %c.1.addr
%e.6 = add i32 0, 4
%a.0.addr = alloca i32
store i32 %e.6, i32* %a.0.addr
%e.8 = load i32, i32* %a.0.addr
%e.7 = call i32 ( i8*, ... ) @printf(i8* getelementptr inbounds ([ 4 x i8 ], [ 4 x i8 ]* @str.9, i64 0, i64 0), i32 %e.8)
%e.10 = load i32, i32* @b.0.addr
%e.11 = add i32 0, 1
%e.12 = add i32 %e.10, %e.11
store i32 %e.12, i32* @b.0.addr
%e.14 = load i32, i32* @b.0.addr
%e.13 = call i32 ( i8*, ... ) @printf(i8* getelementptr inbounds ([ 4 x i8 ], [ 4 x i8 ]* @str.15, i64 0, i64 0), i32 %e.14)
ret void
}

define i32 @main() { 
entry: 
%a.0.addr = alloca i32
call void @empty( i32* %a.0.addr)
ret i32 undef
}


@str.15 =  private constant [ 4 x i8 ] c"%d\0A\00"
@str.9 =  private constant [ 4 x i8 ] c"%d\0A\00"
