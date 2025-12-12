function t = redundancy_controller(q_dq)

 q=q_dq(1:16);
 dq=q_dq(17:32);


L2 = 1.10;
L3 = 0.60;
L4 = 0.55;

% fingers_positions = [-70,   0,  L1;...
%                       60,  40,  L1;...
%                       70,   0,  L1;...
%                       60,  -40, L1];

% J=zeros(6,16);
% J2=zeros(12,16);

% NUM_FINGERS = 4;
% EACH_FINGER_DOFs = 4;


% q=theta;
% x=zeros(3,NUM_FINGERS);
% p=zeros(4);
% l=zeros(3,4);

L(1) = Link([ 0     0      0         pi/2     0], 'standard');
L(2) = Link([ 0     0	   L2         0       0], 'standard');
L(3) = Link([ 0     0      L3         0       0], 'standard');
L(4) = Link([ 0 	0      L4	      0       0], 'standard');


R=SerialLink(L);
R.base=troty(-pi/2);
% R.plot(theta_in);


% c=1;
% c2=1;
% for i=1:4:16,
% J=R.jacob0(theta_in(i:i+3));
% J2(c:c+2,c2:c2+3)=J(1:3,:);
% c=c+3;
% c2=c2+4;
% end

% JH=J2;

J1=R.jacob0(q(1:4));
J2=R.jacob0(q(5:8));
J3=R.jacob0(q(9:12));
J4=R.jacob0(q(13:16));


JH=diagmx(diagmx(diagmx(J1,J2),J3),J4);

% size(JH)
K_P=50;
K_D=0.9;
%  K=0;
a=1;
tau = zeros(1,16);

for i=1:4:16
    tau(i:i+3) = (K_P*(q(i+2)-a*q(i+3)))*[0 0 1 -1]+K_D*(dq(i:i+3));
end

t=(eye(16)-JH'*JH)*tau';

% size(JH')
% size(pinv(JH')*JH')
% size(tau')


