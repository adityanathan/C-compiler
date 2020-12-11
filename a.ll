define void @empty() { 
entry: 
ret void
}
define void @simple_arith() { 
entry: 
%e.0 = add i64 0, 10
%e.1 = add i64 0, 10
%e.2 = add i64 0, 3
%e.3 = sdiv i64 %e.1, %e.2
%e.4 = sub i64 %e.0, %e.3
%e.5 = add i64 0, 3
%e.6 = shl i64 %e.4, %e.5
%e.7 = add i64 0, 23
%e.8 = add i64 0, 8
%e.9 = add i64 0, 12
%e.10 = mul i64 %e.8, %e.9
%e.11 = add i64 %e.7, %e.10
%e.12 = add i64 0, 1024
%e.13 = and i64 %e.11, %e.12
%e.14 = or i64 %e.6, %e.13
ret void
}
define void @simple_arith_with_arg(i32 %d.0) { 
entry: 
%d.0.addr = alloca i32
store i32 %d.0, i32* %d.0.addr
%e.15 = load i32, i32* %d.0.addr
%e.16 = load i32, i32* %d.0.addr
%e.17 = add i64 0, 2
%e.18 = sext i32 %e.16 to i64
%e.19 = sdiv i64 %e.18, %e.17
%e.20 = sext i32 %e.15 to i64
%e.21 = icmp sgt i64 %e.20, %e.19
%e.22 = load i32, i32* %d.0.addr
%e.23 = add i64 0, 100
%e.24 = sext i32 %e.22 to i64
%e.25 = icmp sge i64 %e.24, %e.23
%e.26 = load i32, i32* %d.0.addr
%e.27 = add i64 0, 99
%e.28 = sext i32 %e.26 to i64
%e.29 = icmp slt i64 %e.28, %e.27
%e.30 = and i1 %e.25, %e.29
%e.31 = or i1 %e.21, %e.30
ret void
}
