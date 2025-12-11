function eb = epsilon_b(R)

e=zeros(1,4);

q=Quaternion(R);
e(1)=q.s;
e(2:4)=q.v;

% q.dot([0.4 0.35 0.7])
eb=e;
