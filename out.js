function main() {
let n;
function fib(n) {
if ((n<=1)) {
return 1;
} else {
return fib(n-1)+fib(n-2);
}
}
n = parseInt(prompt("Enter your input:"));
alert(fib(n));
}
