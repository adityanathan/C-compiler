declare i32 @printf(i8* %format.0, ...)
@a1.0.addr = global i32 9
@b.0.addr = global i32 0
define void @compute.b.0() {
%e.0 = load i32, i32* @a1.0.addr
%e.1 = add i32 0, 3
%e.2 = add i32 %e.0, %e.1
store i32 %e.2, i32* @b.0.addr
ret void
}

@c.0.addr = global float 0.0
define void @compute.c.0() {
%e.3 = and i1 true, true
%e.4 = sitofp i1 %e.3 to float
store float %e.4, float* @c.0.addr
ret void
}

define void @empty(i32* %c.1) { 
entry: 
%c.1.addr = alloca i32*
store i32* %c.1, i32** %c.1.addr
%e.5 = add i32 0, 4
%a.0.addr = alloca i32
store i32 %e.5, i32* %a.0.addr
%e.7 = load i32, i32* %a.0.addr
%e.6 = call i32 ( i8*, ... ) @printf(i8* getelementptr inbounds ([ 5 x i8 ], [ 5 x i8 ]* @str.8, i64 0, i64 0), i32 %e.7)
%e.9 = load i32, i32* @b.0.addr
%e.10 = add i32 0, 1
%e.11 = add i32 %e.9, %e.10
store i32 %e.11, i32* @b.0.addr
%e.13 = load i32, i32* @b.0.addr
%e.12 = call i32 ( i8*, ... ) @printf(i8* getelementptr inbounds ([ 5 x i8 ], [ 5 x i8 ]* @str.14, i64 0, i64 0), i32 %e.13)
ret void
}

define i32 @main() { 
entry: 
%a.0.addr = alloca i32
call void @empty( i32* %a.0.addr)
ret i32 undef
}


@str.14 =  private constant [ 5 x i8 ] c"%d\n\00"
@str.8 =  private constant [ 5 x i8 ] c"%d\n\00"
