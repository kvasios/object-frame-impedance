function n=n(ni)

n1=ni(1:3);
n2=ni(4:6);
n3=ni(7:9);
n4=ni(10:12);

% n=[n1' zeros(3,3);zeros(3,1) n2' zeros(3,2);zeros(3,2) n3' ...
% zeros(3,1);zeros(3,3) n4'];

n=diagmx(diagmx(diagmx(n1,n2),n3),n4);

% n=diag(ni);

% n=eye(12,4);