function [ x1,x2 ] = function2(a,b,c)
delta = b^2-4*a*c;
if delta>0
x1=(-b+sqrt(delta))/(2*a);
x2=(-b-sqrt(delta))/(2*a);
else
if delta<0
x1=(-b+i*sqrt(-delta))/(2*a);
x2=(-b-i*sqrt(-delta))/(2*a);
else
x1=-b/(2*a);
x2=-b/(2*a);
end
end
end