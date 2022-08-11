function [work, Tout] = group123_turbine(eta,Pin,Tin,Pout)
    % This function analyzes a turbine in an ideal Rankine Cycle.
    % It is passed some characteristic data points and returns the real work out
    % and temperature at the exit of the turbine in celsius
    
    % The reduced energy formula for the isentropic turbine is wout = hin-hout
    % The isentropic efficiency formula is eta = (hin - hout) / (hin-houtisen)
    % They are both reworkd to find all necessary missing data points

    hin = WaterProps ('h', 'p', Pin, 't', Tin);
    sin = WaterProps('s', 'p', Pin, 't', Tin);   % Gather points from state 1
    houtisen = WaterProps('h', 's', sin, 'p', Pout); % Use sin and outlet pressure to find houtisen
    work = eta*(hin-houtisen);   % rearranged isentropic efficiency eq to find real work
    hout = hin - work; % rearranged work eq
    Tout = WaterProps('t', 'h', hout,'p', Pout);   % state 2 can be fixed to find tout
end