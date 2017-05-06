program main( input, output );
  var n: integer;
  function fact(n:integer):integer;
  begin
	if (n <= 0) then
        fact := 1
    else
        fact := n*fact(n-1)
  end;
begin
    read(n);
    write(fact(n))
end.
