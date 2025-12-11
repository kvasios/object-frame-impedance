function m=get_stiffness(u)

world_time_step=0.0315/(4*12);
start_experiment_time=round(1.5/world_time_step);
experiment_step=round(0.7/world_time_step);

x=u.signals.values(1,:,:);
y=u.signals.values(2,:,:);
z=u.signals.values(3,:,:);

f(1)=0;
f_step=3;

backstep=5;
sample_point(1)=(start_experiment_time-backstep);
for i=1:7
    x_measurements(i) = x(sample_point(i));
    y_measurements(i) = y(sample_point(i));
    z_measurements(i) = z(sample_point(i));
    sample_point(i+1)=sample_point(i)+experiment_step;
    f(i+1)=f(i)+f_step;
end
f2=f(1:7);

m=[f2 x_measurements y_measurements z_measurements];

% hold on
% createfigure4(y_measurements,f2);
% plot(x_measurements,f2);
% plot(y_measurements,f2);
% plot(z_measurements,f2);
%  y_measurements;
% sample_point

% beta1=(x_measurements*x_measurements')^-1*x_measurements*f2'
% beta2=(y_measurements*y_measurements')^-1*y_measurements*f2'
% beta3=(z_measurements*z_measurements')^-1*z_measurements*f2'

% beta1=pinv(x_measurements')*f2';
% beta2=pinv(y_measurements')*f2';
% beta3=pinv(z_measurements')*f2';
% 
% % fit1 = polyfit(x_measurements,f2,1);
% % fit2 = polyfit(y_measurements,f2,1);
% % fit3 = polyfit(z_measurements,f2,1);
% 
% K=[beta1 beta2 beta3];

% plot(fit1(1)*(1:u.time)+fit1(2));