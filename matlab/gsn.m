function gsn=gsn(ri)
% xo=(1/4)*(xi(1,:)+xi(2,:)+xi(3,:)+xi(4,:));

r_1=ri(1:3);
r_2=ri(4:6);
r_3=ri(7:9);
r_4=ri(10:12);
% r1=( x1-x3 )/norm( x1-x3 ) + ...
%     ( x2-x4 )/norm( x2-x4 );
% 
% 
% r1_unit=r1/norm(r1);
% 
% % r3= cross( (x1-x3),( x2-x4 ))';
% 
% r3= skew( x1-x3 ) * ( x2-x4 )';
% r3_unit=r3/norm(r3);
% 
% r2_unit = skew(r3_unit)*r1_unit';
% 
% RO=[r1_unit' r2_unit r3_unit];
% n=[n1' zeros(3,3);zeros(3,1) n2' zeros(3,2);zeros(3,2) n3' ...
% zeros(3,1);zeros(3,3) n4'];

% n=diagmx(n1,n2,n3,n4)';

G=[eye(3) eye(3) eye(3) eye(3) ;skew(r_1) skew(r_2) skew(r_3) skew(r_4)];

% G_pinv=pinv(G);

% gsn=(eye(12)-G_pinv*G);
% gsn=eye(12);
gsn=G;
% gsn=eye(12);