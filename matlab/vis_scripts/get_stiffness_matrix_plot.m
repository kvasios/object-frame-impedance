x=get_stiffness(importdata('tau_x_rotational_error.mat'));
y=get_stiffness(importdata('tau_y_rotational_error.mat'));
z=get_stiffness(importdata('tau_z_rotational_error.mat'));

% hold on
createfigure5(abs(x(8:8+6)),x(1:7));
createfigure5(abs(y(15:15+6)),x(1:7));
createfigure5(abs(z(22:22+6)),x(1:7));

Kx=pinv(x(8:8+6)')*x(1:7)';
Ky=pinv(y(15:15+6)')*x(1:7)';
Kz=pinv(z(22:22+6)')*x(1:7)';

K_translational=diag([Kx Ky Kz]);

matrix2latex(K_translational,'K_rotational.tex','alignment', 'c');