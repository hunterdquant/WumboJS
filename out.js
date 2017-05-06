function main() {
let x, y;
function gcd(a, b) {
let tmp1, tmp2;
if (b<1) {
return a;
} else {
tmp1 = Math.floor(a/b);
tmp2 = a-b*tmp1;
return gcd(b, tmp2);
}
}
x = prompt("Enter your input:");
y = prompt("Enter your input:");
alert(gcd(x, y));
}
