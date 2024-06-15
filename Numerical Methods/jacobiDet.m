% Define symbolic variables
syms x y

% Define the system of equations
f = 4 - y - 2*x^2;
g = 8 - y^2 - 4*x;

% Create a vector of the two equations
F = [f; g];

% Create a vector of the variables x and y
X = [x; y];

% Compute the Jacobian matrix of the system
Jacobian = jacobian(F, X);

% Substitute the initial guesses
x0 = 1.5;
y0 = 3.5;
Jacobian_at_initial_guess = subs(Jacobian, [x, y], [x0, y0]);

% Calculate the determinant of the Jacobian matrix
determinant = det(Jacobian_at_initial_guess);

% Display the determinant
fprintf('Determinant of Jacobian at initial guess: %.6f\n', determinant);