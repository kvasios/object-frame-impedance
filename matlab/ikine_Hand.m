function ps = ikine_Hand(x_touch)

syms q1 q2 q3
x_translation =[-0.70 0.60 0.70 0.60];


points = zeros(1,16);

L1 = 0.10;
L2 = 1.10;
L3 = 0.60;
L4 = 0.55;

c=1;
for i=1:4:4,
pz = x_touch(c,3);
px = x_touch(c,1);

% eq1 =[num2str(L1),'+',num2str(L2),'*cos(q1)+',num2str(L3),'*cos(q1+q2)+',num2str(L4),'*cos(q1+2*q2)-',num2str(pz)];
% eq2 =[num2str(L2),'*sin(q1)+',num2str(L3),'*sin(q1+q2)+',num2str(L4),'*sin(q1+2*q2)-',num2str(px),'+',num2str(x_translation(c))];

eq1 =[num2str(L1),'+',num2str(L2),'*cos(q1)+',num2str(L3),'*cos(q1+q2)+',num2str(L4),'*cos(q1+q2+q3)-2.14'];
eq2 =[num2str(L2),'*sin(q1)+',num2str(L3),'*sin(q1+q2)+',num2str(L4),'*sin(q1+q2+q3)--0.17'];
eq3=['q2-q3'];

pnts = solve (eq1,eq2,eq3);
theta1 = 0;
theta2 = pnts.q1;
theta3 = pnts.q2;
theta4 = pnts.q2;
points(i:i+3) = [asin(sin(theta1)),asin(sin(theta2)), asin(sin(theta3)), asin(sin(theta4))]; 
% L1+L2*cos(p_touch(2))+L3*cos(p_touch(2)+p_touch(3))+L4*cos(p_touch(2)+p_touch(3)+p_touch(4))
% L2*sin(p_touch(2))+L3*sin(p_touch(2)+p_touch(3))+L4*sin(p_touch(2)+p_touch(3)+p_touch(4))+-0.7

c=c+1;

end
ps=points;

% fingers_positions = [-70,   0,  0;...
%                       60,  40,  0;...
%                       70,   0,  0;...
%                       60,  -40, 0];
% 
% 
% NUM_FINGERS = 4;
% EACH_FINGER_DOFs = 4;
% 
% 
% q=theta;
% x=zeros(3,NUM_FINGERS);
% p=zeros(4);
% l=zeros(3,4);
% 
% L(1) = Link([ 0     0      0         pi/2     0], 'standard');
% L(2) = Link([ 0     0	   L2         0       0], 'standard');
% L(3) = Link([ 0     0      L3         0       0], 'standard');
% L(4) = Link([ 0 	0      L4	      0       0], 'standard');
% 
% 
% R=SerialLink(L);
% R.base=rt2tr(eye(3),[0,0,L1]')*troty(-pi/2)*trotx(-pi);


%  R.plot(q(1:1+3));
% for i=1:4:NUM_FINGERS*EACH_FINGER_DOFs,
%     p=R.fkine(q(i:i+3));
%     p=rt2tr(eye(3),fingers_positions(round((i+1)/4),:)')*p;
%     l=p(1:3,4);
%     x(:,round((i+1)/4))=l;
%     R.plot(q(i:i+3));
% end
% R.plot(q)
% x=x';