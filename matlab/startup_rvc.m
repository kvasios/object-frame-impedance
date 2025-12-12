% Startup script for Object-Frame Impedance Control project
% Updated paths for reorganized folder structure

disp('Object-Frame Impedance Control - MATLAB Environment Setup')
disp('Based on: Robotics, Vision & Control (c) Peter Corke 1992-2011')

basepath = fileparts(mfilename('fullpath'));

% Add project folders
addpath(fullfile(basepath, 'dynamics'));
addpath(fullfile(basepath, 'kinematics'));
addpath(fullfile(basepath, 'control'));
addpath(fullfile(basepath, 'geometry'));
addpath(fullfile(basepath, 'utils'));
addpath(fullfile(basepath, 'simulink'));

% Add 3rd party libraries
addpath(fullfile(basepath, '3rdparty', 'peter-corke-robotics-toolbox'));
addpath(fullfile(basepath, '3rdparty', 'peter-corke-common'));

% Initialize Peter Corke's Robotics Toolbox if startup exists
rtb_startup = fullfile(basepath, '3rdparty', 'peter-corke-robotics-toolbox', 'startup_rtb.m');
if exist(rtb_startup, 'file')
    run(rtb_startup);
end

clear basepath rtb_startup
disp('Environment ready.')
