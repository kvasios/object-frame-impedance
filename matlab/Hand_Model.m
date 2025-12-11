function Hand_Model()

L1 = 0.10;
L2 = 1.10;
L3 = 0.60;
L4 = 0.55;

% fingers_positions = [-70,   0,  L1;...
%                       60,  40,  L1;...
%                       70,   0,  L1;...
%                       60,  -40, L1];



% x=zeros(3,NUM_FINGERS);
p=zeros(4);
l=zeros(3,4);

L(1) = Link([ 0     0      0         pi/2     0], 'standard');
L(2) = Link([ 0     0	   L2         0       0], 'standard');
L(3) = Link([ 0     0      L3         0       0], 'standard');
L(4) = Link([ 0 	0      L4	      0       0], 'standard');


R=SerialLink(L);
R.base=troty(-pi/2);
% R.plot([0,0,0,0]);
R.plot([0 -0.3655    0.5897    0.5897] );
% R.jacobi0(zeros(1,4));


J=R.jacob0([0 -0.3655    0.5897    0.5897]);
% rot=troty(pi/2);
R.fkine([0 -0.3655    0.5897    0.5897])
% rot(1:3,1:3)*J(1:3,1:4)
J(1:3,1:4)


    