function n_i=Sphere_n_i(input_vector)

sphere_position=input_vector(1:3);
x_1=input_vector(4:6);
x_2=input_vector(7:9);
x_3=input_vector(10:12);
x_4=input_vector(13:15);

n_1=(x_1-sphere_position)/norm(x_1-sphere_position);
n_2=(x_2-sphere_position)/norm(x_2-sphere_position);
n_3=(x_3-sphere_position)/norm(x_3-sphere_position);
n_4=(x_4-sphere_position)/norm(x_4-sphere_position);

n_i=[n_1; n_2; n_3; n_4];