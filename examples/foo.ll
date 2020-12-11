declare void @printf(i32* %format)

define void @empty() {
  entry:
    

    %ptr = alloca i32
    %e1 = load i32, i32* %ptr
    store i32 2, i32* %ptr

    sdiv float 2, 3

    ret void
    ret void
}

define void @simple_arith() {
  entry:
    %e2 = sdiv i32 10, 3
    ret void
}

define void @simple_arith_with_arg(i32 %d) {
  entry:
    %e2 = sdiv i32 %d, 2
    %e1 = icmp ugt i32 %d, %e2
    %e4 = icmp sge i32 %d, 100
    %e5 = icmp slt i32 %d, 99
    %e3 = and i1 %e4, %e5
    %e0 = or i1 %e1, %e3
    ret void
}
