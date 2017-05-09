program main( input, output );
  var a: integer;
begin
  read(a);
  if (a < 10) then
    a := 1
  else
    a := 2;
  write(a)
end.