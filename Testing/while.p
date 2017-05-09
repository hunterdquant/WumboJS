program main( input, output );
  var a: integer;
begin
  a := 2;
  while (10 * a < 10 * 10 * (10 * 10 * (10 + (10)+2) + 10) + (10 * (10+1) * 10) * 10) do
  begin
    a := a + 1;
    write(a)
  end;
  write(a)
end.