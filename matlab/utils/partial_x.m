function Jc=partial_x(xi)

dx =zeros(4,3);
norm_dx=zeros(1,4);


b=(1-(1/4));
a=-1/4;
% a=0;


x1 = xi(1,:);
x2 = xi(2,:);
x3 = xi(3,:);
x4 = xi(4,:);


xO = (1/4)*(x1+x2+x3+x4);
% xO = [0.2000         0    2.09];

% 
dx(1,:)=((x1-xO));
dx(2,:)=((x2-xO));
dx(3,:)=((x3-xO));
dx(4,:)=((x4-xO));

norm_dx(1) = norm(dx(1,:));
norm_dx(2) = norm(dx(2,:));
norm_dx(3) = norm(dx(3,:));
norm_dx(4) = norm(dx(4,:));

partial_delta_x1 = [b*eye(3); a*eye(3); a*eye(3); a*eye(3)];

partial_delta_x2 = [a*eye(3); b*eye(3); a*eye(3); a*eye(3)];

partial_delta_x3 = [a*eye(3); a*eye(3); b*eye(3); a*eye(3)];

partial_delta_x4 = [a*eye(3); a*eye(3); a*eye(3); b*eye(3)];


% size(partial_delta_x1)
% size(dx(1,:))
% size(norm_dx(1))

Jc=[partial_delta_x1*(dx(1,:)'/norm_dx(1)), partial_delta_x2*(dx(2,:)'/norm_dx(2)), ...
    partial_delta_x3*(dx(3,:)'/norm_dx(3)), partial_delta_x4*(dx(4,:)'/norm_dx(4))];




