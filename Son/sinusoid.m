function [ signal ] = sinusoid( freq, amp, phi, Fech, size )
i=1:size;
signal = amp * sin(2 * pi * freq * i/Fech+ phi);
%%return signal
end

