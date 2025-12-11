startup_rvc

world_time_step=0.0315/(4*12);

x1_touch = [-0.56, 0.00, 2.09];
x2_touch = [ 0.40, 0.40, 2.09];
x3_touch = [ 0.56, 0.00, 2.09];
x4_touch = [-0.40,-0.40, 2.09];

% qd_initial_touch =  [0 -187.9896   18.2599   18.2599         0    0.3313   -0.5836   -0.5836         0 -251.8334  151.3861  151.3861         0   -0.3344   -0.1740    -0.1740];
% qd_initial_touch =  [0 0.3655   -0.5897   -0.5897...
%     0    -0.3313   +0.5836   +0.5836    ...
%     0 -0.3655   --0.5897   --0.5897     ...
%     0   -0.3313   +0.5836   +0.5836];
qd_initial_touch =  [0 0.3655   -0.5897   -0.5897...
    0       -0.3333   +0.5942   +0.5942    ...
    0       -0.298   --0.5226   --0.5226      ...
    0       -0.3333   +0.5942   +0.5942];




% qd_initial_touch =  [0  0.2649   -0.5665   -0.5665         0   -0.3254   0.5823  0.5823        0  -0.2649   --0.5665   --0.5665        0   -0.3254   0.5823   0.5823];

x_touch=[x1_touch;x2_touch;x3_touch;x4_touch];

% Q_touch = ikine_Hand(x);

tx=0;
ty=0;
tz=0;
q=zeros(1,16);

x_angle_desired =0;
y_angle_desired =0; 
z_angle_desired =0;

x_O_desired = (1/4)*sum(x_i(qd_initial_touch));
% R_O_Desired = trotx(x_angle_desired)*troty(y_angle_desired)*trotz(z_angle_desired);
R_O_Desired = R_O(x_i(qd_initial_touch));



R_O_Desired_new = R_O_Desired*rotz(0.3);


% K_tx = 0;
% K_ty = 0;
% K_tz = 0;
% K_Ot=[K_tx 0 0;0 K_ty 0;0 0 K_tz];

% K_rx = 0;
% K_ry = 0;
% K_rz = 0;
% K_Or=[K_rx 0 0;0 K_ry 0;0 0 K_rz];

k_Ot =700;
% k_Ot =0;
K_Ot = eye(3)*k_Ot;


k_Or =200;
% k_Or = 0;
K_Or = eye(3)*k_Or;

k_conn=800;
% k_conn=0;
K_Conn=eye(4)*k_conn;

f_normal =350;
F_normal=ones(1,4)*f_normal;

Kx =diag([diag(K_Ot)' diag(K_Or)' diag(K_Conn)']);

l1_des = 0.15;
l2_des = 0.15;
l3_des = 0.15;
l4_des = 0.15;

l_des = [l1_des; l2_des; l3_des; l4_des];

g=9.81;

DOFs = 16;

L1 = 0.10;
L2 = 1.10;
L3 = 0.60;
L4 = 0.55;

force_step =20;

ksi=2.0;

caspule1mass = 1.00;
caspule2mass = 0.50;
caspule3mass = 0.50;

sphere_mass=0.8;
sphere_radius=0.54;

Mo=diag([sphere_mass*ones(1,3) (2/5)*sphere_mass*sphere_radius^2*ones(1,3)]);

K_P=350;
K_D=30;

%Experiments--Measurements

t_f_start=2.5;
f_step=0.7;
force_step =20;
torque_step=60;
