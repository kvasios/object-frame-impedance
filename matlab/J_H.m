function JH = J_H (theta_in)

% L1 = 0.10;
L2 = 1.10;
L3 = 0.60;
L4 = 0.55;

% fingers_positions = [-70,   0,  L1;...
%                       60,  40,  L1;...
%                       70,   0,  L1;...
%                       60,  -40, L1];

% J=zeros(6,16);
J2=zeros(12,16);

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


c=1;
c2=1;
for i=1:4:16,
J=R.jacob0(theta_in(i:i+3));
J2(c:c+2,c2:c2+3)=J(1:3,:);
c=c+3;
c2=c2+4;
end

JH=J2;