declare i32 @printf(i8* %format.0, ...)
define void @empty(i32* %c.0) { 
entry: 
%c.0.addr = alloca i32*
store i32* %c.0, i32** %c.0.addr
%e.0 = and i1 true, true
%e.1 = and i1 true, false
%e.2 = and i1 true, true
%e.3 = and i1 %e.1, %e.2
%e.4 = or i1 %e.0, %e.3
%e.5 = sext i1 %e.4 to i32
%a.0.addr = alloca i32
store i32 %e.5, i32* %a.0.addr
%e.7 = load i32, i32* %a.0.addr
%e.6 = call i32 ( i8*, ... ) @printf(i8* getelementptr inbounds ([ 3 x i8 ], [ 3 x i8 ]* @str.8, i64 0, i64 0), i32 %e.7)
ret void
}

define i32 @main() { 
entry: 
%a.0.addr = alloca i32
call void @empty( i32* %a.0.addr)
ret i32 undef
}


@str.8 =  private constant [ 3 x i8 ] c"%d\00"
