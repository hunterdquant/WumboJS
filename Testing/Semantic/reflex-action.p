program main( input, output );
   var x, y: integer;
   function gcd(a,b: integer):integer;
      var tmp1, tmp2: integer;
   begin
      if ( b < 1  ) then
         gcd:= a
      else
      begin
         tmp1:=a/b;
         tmp2:=a-(b*tmp1);
         gcd:=gcd(b,tmp2)
      end
   end;
begin
   read(x);
   read(y);
   write(gcd(x,y))
end.