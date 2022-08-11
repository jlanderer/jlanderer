function [work, Tout] = group123_pump(eta, Pin, Pout)
    % This function analyzes a pump in an ideal Rankine Cycle.
    % It is passed some characteristic data points and returns the real work out and temperature at
    % the exit of the pump in celsius
    
    % The reduced energy formula for the isentropic pump is win = hout-hin
    % The isentropic efficiency formula is eta = (houtisen-hin)/(hout-hin)
    % They are both reworked to find all necessary missing data points

    hin = WaterProps('h', 'p', Pin, 'x', 0);  % Inlet is saturated liquid, so hin is h @ pin
                                                % and a quality of 0.                           
    sin = WaterProps('s', 'x', 0, 'p', Pin);  % Need sin to equate it to sout and fix state 2s
    houtisen = WaterProps('h', 'p', Pout,'s', sin); % enthalpy at exit assuming isentropic process
    work_isen = houtisen - hin;
    work = work_isen/eta;
    hout = hin + work;
    Tout = WaterProps('T', 'h', hout,'p', Pout);    % Temperature can now be gathered bc state is fixed
end