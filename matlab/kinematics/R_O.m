function RO=R_O(xi)

x1 = xi(1,:);
x2 = xi(2,:);
x3 = xi(3,:);
x4 = xi(4,:);

% r1=( xi(1,:)-xi(3,:) )/norm( xi(1,:)-xi(3,:) ) + ...
%     ( xi(2,:)-xi(4,:) )/norm( xi(2,:)-xi(4,:) );

r1=( x1-x3 )/norm( x1-x3 ) + ...
    ( x2-x4 )/norm( x2-x4 );


r1_unit=r1/norm(r1);

% r3= cross( (x1-x3),( x2-x4 ))';

r3= skew( x1-x3 ) * ( x2-x4 )';
r3_unit=r3/norm(r3);

r2_unit = skew(r3_unit)*r1_unit';

RO=[r1_unit' r2_unit r3_unit];

