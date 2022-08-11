function [] = group123_study(Pmin, Pmax, qin, etaRange)
    % This function prints two graphs: Eta_Th_Cycle V. Eta_isen_pump, and 
    % Eta_Th_Cycle V. Eta_isen_turbine.
    
    for i = 1:length(etaRange) % Keeping pump at 1 and varying turbine
        [~, eta1(i)] = group123_rankine(Pmin, Pmax, qin, 1, etaRange(i));
    end

    for i = 1:length(etaRange) % Keeping turbine at 1 and varying pump
        [~, eta2(i)] = group123_rankine(Pmin, Pmax, qin, etaRange(i),1);
    end
    
    plot(eta1, etaRange)
    xlabel('Pump Isentropic Efficiencies')
    ylabel('Overall Thermal Efficiency')
    
    plot(eta2, etaRange)
    xlabel('Turbine Isentropic Efficiencies')
    ylabel('Overall Thermal Efficiency')
end