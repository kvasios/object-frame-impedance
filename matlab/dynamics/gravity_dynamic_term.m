function gravity_dynamic_term = gravity_dynamic_term(theta_in)

c= zeros(1,16);
g= 9.81;

gain=1.1;

DOFs = 16;

L1 = 0.10;
L2 = 1.10;
L3 = 0.60;
L4 = 0.55;


caspule1mass = 2.00;
caspule2mass = 1.00;
caspule3mass = 1.00;


for i=1:4:DOFs,
q1=theta_in(i);
q2=theta_in(i+1);
q3=theta_in(i+2);
q4=theta_in(i+3);

c(i:i+3)=gain*[(-1 / 2) .* g .* ((caspule1mass .* L2 + 2 .* caspule2mass .* L2 + ...
   2 .* caspule3mass .* L2) .* cos(q2) + (caspule2mass .* L3 + 2 .*  ...
  caspule3mass .* L3) .* cos(q2 + q3) + caspule3mass .* L4 .* cos( ...
  q2 + q3 + q4)) .* sin(q1),(-1 / 2) .* g .* cos(q1) .* (( ...
  caspule1mass .* L2 + 2 .* caspule2mass .* L2 + 2 .* caspule3mass  ...
  .* L2) .* sin(q2) + (caspule2mass .* L3 + 2 .* caspule3mass .* L3) ...
   .* sin(q2 + q3) + caspule3mass .* L4 .* sin(q2 + q3 + q4)),(-1 /  ...
  2) .* g .* cos(q1) .* ((caspule2mass .* L3 + 2 .* caspule3mass .*  ...
  L3) .* sin(q2 + q3) + caspule3mass .* L4 .* sin(q2 + q3 + q4)),( ...
  -1 / 2) .* caspule3mass .* g .* L4 .* cos(q1) .* sin(q2 + q3 + q4) ...
  ];
end

gravity_dynamic_term=c;