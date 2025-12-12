function M_Null=NullSpaceProjection(M)
s=size(M);
% M_Null=eye(4,4);
M_Null=(eye(s(2))-pinv(M)*M);