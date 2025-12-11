clear all;
close all;
%Connect to the INEMO device
[handle_dev pFD]=INEMO_Connection();
%End connection
acqSize=1000;

%Gyroscope statistics
Offset=[-3.6982,-3.3570,-2.5909]';
var=[(0.5647/180*pi)^2 (0.5674/180*pi)^2 (0.1/180*pi)^2]';
%var=[(0.7698/180*pi)^2 (0.4925/180*pi)^2 (0.5144/180*pi)^2]';

%Acquisition variables
GyroRate=zeros(3,acqSize);
Acc=zeros(3,acqSize);
Magn=zeros(3,acqSize);
Angles=zeros(3,acqSize);
AnglesGyroFiltered=zeros(3,acqSize);
AnglesGyro=zeros(3,acqSize);
AccF=zeros(3,acqSize);
MagnF=zeros(3,acqSize);
mu=zeros(1,acqSize);
dqnorm=zeros(1,acqSize);
dq=zeros(4,acqSize);
err=zeros(4,acqSize);

qUpdate=zeros(4,acqSize);
%Initial quaternion values
%qUpdate(:,1)=[0.5 0.5 0.5 0.5]';
qUpdate(:,1)=[1 0 0 0]';

%Observation vector
qOsserv=zeros(4,acqSize);
%qOsserv(:,1)=[0.5 0.5 0.5 0.5]';
qOsserv(:,1)=[1 0 0 0]';
qOsservBis(:,1)=[1 0 0 0]';

%----KALMAN MATRIXES
Qmatrix=[eye(3,3)*0.05 zeros(3,4);zeros(4,3) [0.001 0 0 0; 0 0.0001 0 0; 0 0 0.0001 0; 0 0 0 0.001]];

H=eye(7,7);

sigmaR=[0.01 0.01 0.01 0.03 0.003 0.003 0.03]';
R=[sigmaR(1,1) 0 0 0 0 0 0;0 sigmaR(2,1) 0 0 0 0 0;0 0 sigmaR(3,1) 0 0 0 0;0 0 0 sigmaR(4,1) 0 0 0;0 0 0 0 sigmaR(5,1) 0 0;0 0 0 0 0 sigmaR(6,1) 0;0 0 0 0 0 0 sigmaR(7,1)];

qPredicted=zeros(4,acqSize);
%qPredicted(:,1)=[0.5 0.5 0.5 0.5]';
qPredicted(:,1)=[1 0 0 0]';
P_Update=eye(7,7)*2;
%----------
t=[0];

i=1;
dt=0;

[bAcc,aAcc] = butter(3,0.0075,'low');
[bMagn,aMagn] = butter(2,0.06,'low');

magnF_Length=13;
accF_Length=13;

xPredicted=zeros(7,acqSize);
xUpdate=zeros(7,acqSize);
xOsserv=zeros(7,acqSize);

%Bring up the filters
while(i<=accF_Length+4)
    if(i>1)
        dt = toc(t0);
        t=[t t(length(t))+dt];
    end
    
    [errre pFD]=calllib('iNEMO2_SDK','INEMO2_GetDataSample',handle_dev,pFD);
    t0 = tic;

        %----------
        pause(0.01)
        %---------
        
    Acc(1,i)=pFD.Accelerometer.X;
    Acc(2,i)=pFD.Accelerometer.Y;
    Acc(3,i)=pFD.Accelerometer.Z;
    Magn(1,i)=pFD.Magnetometer.X;
    Magn(2,i)=pFD.Magnetometer.Y;
    Magn(3,i)=pFD.Magnetometer.Z;
    GyroRate(1,i)=((pFD.Gyroscope.X-Offset(1,1))/180)*pi;
    GyroRate(2,i)=((-pFD.Gyroscope.Y+Offset(2,1))/180)*pi;
    GyroRate(3,i)=((pFD.Gyroscope.Z-Offset(3,1))/180)*pi;
    
    Acc(:,i)=Acc(:,i)/norm(Acc(:,i));
    Magn(:,i)=Magn(:,i)/norm(Magn(:,i));
    if(i<=accF_Length)
        AccF(:,i)=MyFilter(bAcc,aAcc,Acc(:,:));
    else
        AccF(:,i)=MyFilter(bAcc,aAcc,Acc(:,i-accF_Length:i));
    end
    if(i<=magnF_Length)
        MagnF(:,i)=MyFilter(bMagn,aMagn,Magn(:,:));
    else
        MagnF(:,i)=MyFilter(bMagn,aMagn,Magn(:,i-magnF_Length:i));
    end
    MagnF(:,i)=MagnF(:,i)/norm(MagnF(:,i));
    AccF(:,i)=AccF(:,i)/norm(AccF(:,i));
    i=i+1;
    qPredicted(:,i)=[0.5 0.5 0.5 0.5]';
    qUpdate(:,i)=qPredicted(:,i);
    qOsserv(:,i)=qPredicted(:,i);
    xUpdate(:,i)=[zeros(3,1);qUpdate(:,i)];
    xOsserv(:,i)=[zeros(3,1);qUpdate(:,i)];
end



while(i<=acqSize)
    if(i>2)
        dt = toc(t0);
        t=[t t(length(t))+dt];
    end
    %dt=0.015;
    %----Acquisition
        [errre pFD]=calllib('iNEMO2_SDK','INEMO2_GetDataSample',handle_dev,pFD);
        t0 = tic;

        %----------
        pause(0.01)
        %---------
        
    Acc(1,i)=pFD.Accelerometer.X;
    Acc(2,i)=pFD.Accelerometer.Y;
    Acc(3,i)=pFD.Accelerometer.Z;
    Magn(1,i)=pFD.Magnetometer.X;
    Magn(2,i)=pFD.Magnetometer.Y;
    Magn(3,i)=pFD.Magnetometer.Z;
    GyroRate(1,i)=((pFD.Gyroscope.X-Offset(1,1))/180)*pi;
    GyroRate(2,i)=((-pFD.Gyroscope.Y+Offset(2,1))/180)*pi;
    GyroRate(3,i)=((pFD.Gyroscope.Z-Offset(3,1))/180)*pi;
    
    GyroRate(1,i)=(GyroRate(1,i)+GyroRate(1,i-1))/2;
    GyroRate(2,i)=(GyroRate(2,i)+GyroRate(2,i-1))/2;
    GyroRate(3,i)=(GyroRate(3,i)+GyroRate(3,i-1))/2;
    %Normalization and filtering
    Acc(:,i)=Acc(:,i)/norm(Acc(:,i));
    Magn(:,i)=Magn(:,i)/norm(Magn(:,i));
    
    AccF(:,i)=MyFilter(bAcc,aAcc,Acc(:,i-accF_Length:i));
    MagnF(:,i)=MyFilter(bMagn,aMagn,Magn(:,i-magnF_Length:i));
    
    MagnF(:,i)=MagnF(:,i)/norm(MagnF(:,i));
    AccF(:,i)=AccF(:,i)/norm(AccF(:,i));
    %----End Acquisition
    
    %OBSERVATION COMPUTING
    %Gauss Newton step 
    %qOss=GaussNewtonMethod(qUpdate(2,i-1),qUpdate(3,i-1),qUpdate(4,i-1),qUpdate(1,i-1),AccF(:,i),MagnF(:,i),MagnF(:,17));
    %qOsserv(:,i)=[qOss(4,1); qOss(2:4,1)];
    
    %Gradient Descent
    dq(:,i)=0.5*(QuaternionProduct(qUpdate(:,i-1),[0 GyroRate(1,i) GyroRate(2,i) GyroRate(3,i)]'));
    dqnorm(1,i)=norm(dq(:,i));
    %mu(1,i)=norm(dq(:,i))*0.6*(1/(norm(dq(:,i))^(71/100)));
    %mu(1,i)=norm(dq(:,i))*dt*100;
    mu(1,i)=10*dqnorm(1,i)*dt;
    
    xOsserv(4:7,i)=GradientDescent(AccF(:,i),MagnF(:,i),xOsserv(4:7,i-1),mu(1,i));
    
    xOsserv(4:7,i)=xOsserv(4:7,i)/norm(xOsserv(4:7,i));
    qOsserv(:,i)=xOsserv(4:7,i);
    
    xOsserv(:,i)=[GyroRate(:,i);xOsserv(4:7,i)];
    %END OSSERVATION COMPUTING
    
    %KALMAN FILTERING
    const=dt/2;
    %F matrix computing
    F123=[eye(3,3)+eye(3,3)*exp(dt/0.1) zeros(3,4)];
    F4=[-const*qUpdate(2,i-1) -const*qUpdate(3,i-1) -const*qUpdate(4,i-1) 1 0 0 0];
    F5=[const*qUpdate(1,i-1) -const*qUpdate(4,i-1) const*qUpdate(3,i-1) 0 1 0 0];
    F6=[const*qUpdate(4,i-1) const*qUpdate(1,i-1) -const*qUpdate(2,i-1) 0 0 1 0];
    F7=[-const*qUpdate(3,i-1) const*qUpdate(2,i-1) -const*qUpdate(1,i-1) 0 0 0 1];

    
    F=[F123;F4;F5;F6;F7];
    xPredicted(:,i)=F*xUpdate(:,i-1);
    
    %Q=(dt/2)^2*Qmatrix;
    Q=Qmatrix;
    
    P_Predicted=F*P_Update*F'+Q;
    
    K=P_Predicted*H'*(H*P_Predicted*H'+R)^-1;
    xUpdate(:,i)=xPredicted(:,i)+K*(xOsserv(:,i)-H*xPredicted(:,i));
    %qUpdate(:,i)=qPredicted(:,i)+K*(H*qPredicted(:,i)-qOsserv(:,i));
    qUpdate(:,i)=xUpdate(4:7,i);
    qUpdate(:,i)=qUpdate(:,i)/norm(qUpdate(:,i));
    xUpdate(4:7,i)=qUpdate(:,i);
    P_Update=(eye(7,7)-K*H)*P_Predicted;
    Angles(:,i)=GetAnglesFromQuaternion(qUpdate(:,i));
    AnglesGyro(:,i)=GyroRate(:,i)*dt+AnglesGyro(:,i-1);
    AnglesGyroFiltered(:,i)=xUpdate(1:3,i)*dt+AnglesGyroFiltered(:,i-1);
    
    %END KALMAN FILTERING
    i=i+1;
end
figure;
    subplot(3,1,1);plot(t,Acc(1,:),'b',t,AccF(1,:),'r',t,Magn(1,:),'g',t,MagnF(1,:),'c');legend('AccX','AccFX','MagnX','MagnFX');grid;
    subplot(3,1,2);plot(t,Acc(2,:),'b',t,AccF(2,:),'r',t,Magn(2,:),'g',t,MagnF(2,:),'c');legend('AcY','AccFY','MagnY','MagnFY');grid;
    subplot(3,1,3);plot(t,Acc(3,:),'b',t,AccF(3,:),'r',t,Magn(3,:),'g',t,MagnF(3,:),'c');legend('AccZ','AccFZ','MagnZ','MagnFZ');grid;

figure;
    subplot(7,1,1);plot(t,xUpdate(1,1:acqSize));hold on;plot(t,xOsserv(1,1:acqSize),'r');hold on;grid;legend('wx Estimated','wx observed');
    subplot(7,1,2);plot(t,xUpdate(2,1:acqSize));hold on;plot(t,xOsserv(2,1:acqSize),'r');hold on;grid;legend('wy Estimated','wy observed');
    subplot(7,1,3);plot(t,xUpdate(3,1:acqSize));hold on;plot(t,xOsserv(3,1:acqSize),'r');hold on;grid;legend('wz Estimated','wz observed');
    subplot(7,1,4);plot(t,xUpdate(4,1:acqSize));hold on;plot(t,xOsserv(4,1:acqSize),'r');hold on;grid;legend('q0 Estimated','q0 observed');
	subplot(7,1,5);plot(t,xUpdate(5,1:acqSize));hold on;plot(t,xOsserv(5,1:acqSize),'r');hold on;grid;legend('q1 Estimated','q1 observed');
    subplot(7,1,6);plot(t,xUpdate(6,1:acqSize));hold on;plot(t,xOsserv(6,1:acqSize),'r');hold on;grid;legend('q2 Estimated','q2 observed');
    subplot(7,1,7);plot(t,xUpdate(7,1:acqSize));hold on;plot(t,xOsserv(7,1:acqSize),'r');hold on;grid;legend('q3 Estimated','q3 observed');
    	                                                                                                                                    
figure;
    subplot(3,1,1);plot(t,Angles(1,1:acqSize));grid;legend('Roll');
    subplot(3,1,2);plot(t,Angles(2,1:acqSize));grid;legend('Pitch');
   subplot(3,1,3);plot(t,Angles(3,1:acqSize));grid;legend('Yaw');

figure;
    subplot(3,1,1);plot(t,AnglesGyro(1,1:acqSize)*180/pi);hold on;plot(t,AnglesGyroFiltered(1,1:acqSize)*180/pi,'r');grid;legend('Roll');
    subplot(3,1,2);plot(t,AnglesGyro(2,1:acqSize)*180/pi);hold on;plot(t,AnglesGyroFiltered(2,1:acqSize)*180/pi,'r');grid;legend('Pitch');
   subplot(3,1,3);plot(t,AnglesGyro(3,1:acqSize)*180/pi);hold on;plot(t,AnglesGyroFiltered(3,1:acqSize)*180/pi,'r');grid;legend('Yaw');


INEMO_Disconnection(handle_dev);
