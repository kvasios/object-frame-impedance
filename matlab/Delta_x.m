function Deltax=Delta_x(xi)

dx = zeros(1,4);

x1 = xi(1,:);
x2 = xi(2,:);
x3 = xi(3,:);
x4 = xi(4,:);


xO = (1/4)*(x1+x2+x3+x4);
% xO =[0.2000         0    2.0900];


% 
dx(1)=norm((x1-xO));
dx(2)=norm((x2-xO));
dx(3)=norm((x3-xO));
dx(4)=norm((x4-xO));

Deltax=dx';