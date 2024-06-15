clear all;
clc;
L = 0.4; 
n = 40; 
dx = 0.01;
dt = 0.5;  
Tg = 100; 
Td = 50; 
T0 = 0; 
Cp = 900;
lambda = 237; 
p = 2700; 
a = lambda / (Cp * p); 

T = zeros(n+1, 1);
T(1) = Tg; 
T(n+1) = Td; 

steps = 1000;
time = 0:dt:dt*steps;
temperature = zeros(n+1, steps+1);
temperature(:, 1) = T;
temperature_at_middle = zeros(steps+1, 1);

for i = 2:steps+1
    for j = 2:n
        T(j) = T(j) + a * dt / (dx^2) * (T(j+1) - 2*T(j) + T(j-1));
    end
    temperature(:, i) = T;
    temperature_at_middle(i) = T(round(n/2) + 1);
end

x = linspace(0, L, n+1);
t = 1:5:700; 

figure;
box on;
hold on;
plot(x, temperature(:, t+1), 'b-', 'LineWidth', 0.00000001);
xlabel('x');
ylabel('T');
legend('T', 'Location', 'NorthEast');
legend boxoff;
title('Evolution of the temperature in bar');
hold off;

figure;
box on;
hold on;
plot(time, temperature_at_middle, 'r-', 'LineWidth', 0.0000001);
xlabel('t');
ylabel('T');
title('Temperature at Middle Point');
grid on;
hold off;