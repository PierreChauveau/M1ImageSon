close all

freq = 400;
amp = 1;
phi = 0;
Fech = 44000;
size = 128;
signal = sinusoid(freq,amp,phi,Fech, size);
plot(signal);
%{
s1 =  -sin(14 * pi * i/Fech)
figure()
plot(s1)

s2 = -sin(6 * pi * i/Fech);
figure()
plot(s2)

%}

%{
size2 = 128

s3 = sinusoid(100,1,0,256,size2)
figure()
plot(s3)

s4 = sinusoid(156,1,0,256,size2)
figure()
plot(s4)

s5 = s3 + s4
figure()
plot(s5)
%}

%{
size3 = 128;
s5 = sinusoid(356,amp,phi,256,size3);
figure()
plot(s5)

s6 = sinusoid(100,1,0,256,size3)
figure()
plot(s6)

s7 = s5 - s6
figure()
plot(s7)
%}

