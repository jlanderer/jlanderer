function [wnet,etaR] = group123_rankine(Pmin,Pmax,qin,etaP,etaT)
    % This function analyzes an overall ideal Rankine cycle
    % Using the functions for parts of the cycle.

    [work_in, T2] = group123_pump(etaP, Pmin, Pmax); % Get work consumed by pump and T2 by sending pressures & efficiency
    [T3] = group123_boiler(Pmax, T2, qin);    % Get T3 (max temp) by sending max pressure, Tin, and heat in          
    [work_out, T4] = group123_turbine(etaT, Pmax, T3, Pmin);   % Find work produced by turbine and min temp T4 = T1
    wnet = work_out - work_in; % net = in - out
    etaR = wnet/qin;  % Overall thermal efficiency eta = net work divided by heat in
end