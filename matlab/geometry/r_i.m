function out=r_i(xi)

xo=(1/4)*(xi(1,:)+xi(2,:)+xi(3,:)+xi(4,:));

r_1=-(xo-xi(1,:))/norm(xo-xi(1,:));
r_2=-(xo-xi(2,:))/norm(xo-xi(2,:));
r_3=-(xo-xi(3,:))/norm(xo-xi(3,:));
r_4=-(xo-xi(4,:))/norm(xo-xi(4,:));

out=[r_1 r_2 r_3 r_4];