define void @empty() { 
entry: 
ret void
}

define void @simple_arith() { 
entry: 
%e.0 = add i32 0, 56
%e.1 = and i1 true, true
ret void
}

define void @simple_arith_with_arg(i32 %d.0) { 
entry: 
%d.0.addr = alloca i32
store i32 %d.0, i32* %d.0.addr
%e.2 = load i32, i32* %d.0.addr
%e.3 = load i32, i32* %d.0.addr
%e.4 = add i32 0, 2
%e.5 = sdiv i32 %e.3, %e.4
%e.6 = icmp sgt i32 %e.2, %e.5
%e.7 = load i32, i32* %d.0.addr
%e.8 = add i32 0, 100
%e.9 = icmp sge i32 %e.7, %e.8
%e.10 = load i32, i32* %d.0.addr
%e.11 = add i32 0, 99
%e.12 = icmp slt i32 %e.10, %e.11
%e.13 = and i1 %e.9, %e.12
%e.14 = or i1 %e.6, %e.13
ret void
}


