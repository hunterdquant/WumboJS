program main( input, output );
  var n: integer;
  function fact(n:integer):integer;
  begin
	if (n <= 0) then
    begin
        fact := 1
    end
    else
    begin
        fact := n*fact(n-1)
    end
  end;
begin
    read(n);
    write(fact(n))
end.
