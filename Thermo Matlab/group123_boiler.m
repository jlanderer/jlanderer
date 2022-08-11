function [Tout] = group123_boiler(P,Tin,qin)
    % This function analyzes a boiler in an ideal Rankine Cycle.
    % It is passed some characteristic data points and returns the temperature at
    % the exit of the turbine in celsius

    % The reduced energy formula for the isobaric boiler is q_in = h_out-h_in

hin = WaterProps ('h', 'p', P, 't', Tin); % Find h_in for subsequent energy balance eq
hout = qin + hin; % Rearrange the energy eq to find h_out
Tout = WaterProps ('t', 'h', hout, 'p', P); % h_out and P = p_out allows us to fix state 2 and find t_out
end