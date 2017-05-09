program main( input, output );
  var n: integer;
  function mod(a,b:integer):integer;
    var x: integer;
  begin
    x := a/b;
    mod := a - x*b
  end;
  procedure cct;
  begin
    write(n);
    if (mod(n, 2) = 0) then
      n := n/2
    else
      n := 3*n + 1
  end;
begin
    read(n);
    while (n <> 1) do
      cct;
    write(n)
end.