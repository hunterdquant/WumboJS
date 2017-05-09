program main( input, output );
  var n: integer;
  function foo(n:integer):integer;
  begin
	  foo := n
  end;
  procedure boo(n:integer);
  begin
	  write(2*2*2*foo(n))
  end;
begin
    read(n);
    boo(n)
end.
