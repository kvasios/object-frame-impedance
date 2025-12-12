function qdes=q_d(key)

% torque_signal_out=zeros(1,16);
qd=zeros(1,16);

q_incr=0.005;
% q_incr = pi/8;
current_key=key;

switch current_key
   case uint8('1')
      qd(1)=q_incr;
   case uint8('q')
      qd(2)=q_incr;
   case uint8('a')
      qd(3)=q_incr;
   case uint8('z')
      qd(4)=q_incr;   
   case uint8('2')
      qd(1)=-q_incr;
   case uint8('w')
      qd(2)=-q_incr;
   case uint8('s')
      qd(3)=-q_incr;
   case uint8('x')
      qd(4)=-q_incr;
   otherwise
      qd=zeros(1,16);
end

qdes=qd';

