declare i32 @printf(i8* %format.0, ...)
define i32 @main(i32 %argc.0, i8** %argv.0) { 
entry: 
%argc.0.addr = alloca i32
store i32 %argc.0, i32* %argc.0.addr
%argv.0.addr = alloca i8**
store i8** %argv.0, i8*** %argv.0.addr
%e.0 = call i32 ( i8*, ... ) @printf(i8* getelementptr inbounds ([ 29 x i8 ], [ 29 x i8 ]* @str.1, i64 0, i64 0))
%e.2 = add i32 0, 0
ret i32 %e.2
ret i32 undef
}


@str.1 =  private constant [ 29 x i8 ] c"hello, aditya. hw are you?\n\00"
