program main( input, output );
  var x, y, z: real;
  function avg(x, y, z:real):real;
  begin
	avg := (((x+y)+(z))/3.0)
  end;
begin
    read(x);
    read(y);
    read(z);
    write(avg(x, y, z))
end.
