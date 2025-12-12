function x=x_i_v02(q)

x_=zeros(4,3);

rot_base=[0.0000         0   -1.0000;
         0    1.0000         0;
    1.0000         0    0.0000];

L1 = 0.10;
L2 = 1.10;
L3 = 0.60;
L4 = 0.55;

fingers_positions = [-0.70,   0,  L1;...
                      0.60,  0.40,  L1;...
                      0.70,   0,  L1;...
                      0.60,  -0.40, L1];

c=1;
                  
for i=1:4:16,

q1 = q(i);
q2 = q(i+1);
q3 = q(i+2);
q4 = q(i+3);

x_(c,1)=cos(q1) .* (L2 .* cos(q2) + L3 .* cos(q2 + q3) + L4 .*  cos(q2 + q3 + q4));
x_(c,2)=(L2 .* cos(q2) + L3 .* cos(q2 + q3) + L4 .* cos(q2 + q3 + q4)) .* sin(q1);
x_(c,3)= L2 .* sin(q2) + L3 .* sin(q2 + q3) + L4 .* sin(q2 + q3 + q4);

x_(c,:)=rot_base*x_(c,:)'+fingers_positions(c,:)';
c=c+1;
end

x=x_;