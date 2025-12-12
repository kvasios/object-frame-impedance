function y=path_planning(clock)
set_IPC=0;
out=[R_O_Desired x_O_desired set_IPC];
%%% Wait for the initial grasp posture ... ends at about 1 sec
while (clock <1.1)
    for i=1:1000 end
end
%%% Set the IPC Controller
set_IPC=1;
y=out;


%%%% Apply the desired object posture