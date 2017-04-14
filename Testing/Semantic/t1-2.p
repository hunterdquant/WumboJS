(* LEGAL: local names should hide non-local names *)
program main( input, output );
  var a,d: integer;
  procedure boo(a: integer);
    var b: real;
  begin
    b := 1.23
  end;
begin
  boo(d+2+2+2) 
end.

