#pragma once

#include <cmath>

class Infectious {
public:
    Infectious(uint64_t number_of_sites, uint64_t number_of_susceptible_groups);
    ~Infectious();
    void Debug();
    void Update();

    void set_susceptibility_group(uint64_t group, uint64_t haplotype);
    PyObject* get_susceptibility_group();
    void set_transmission_rate(double rate, uint64_t haplotype);
    PyObject* get_transmission_rate();
    void set_recovery_rate(double rate, uint64_t haplotype);
    PyObject* get_recovery_rate();
    void set_sampling_rate(double rate, uint64_t haplotype);
    PyObject* get_sampling_rate();
    void set_mutation_rate(double rate, uint64_t haplotype, uint64_t mutation);
    PyObject* get_mutation_rate();
    void set_mutation_probabilities(double rate, uint64_t haplotype, uint64_t mutation, uint64_t index);
    PyObject* get_mutation_probabilities();
    void set_susceptibility(double rate, uint64_t haplotype, uint64_t group);
    PyObject* get_susceptibility();

    inline double GetMaxEffectiveTransmission() const;
    inline double GetTransmissionSusceptibility(uint64_t haplotype, uint64_t group) const;

    // void SetSusceptibilityTypes(uint64_t type, uint64_t haplotype);
    inline uint64_t GetSusceptibilityTypes(uint64_t haplotype) const;
    // void SetTransmissionRate(double rate, uint64_t haplotype);
    // inline double GetTransmissionRate(uint64_t haplotype) const;
    inline double* GetTransmissionRateBegin() const;
    // void SetRecoveryRate(double rate, uint64_t haplotype);
    // inline double GetRecoveryRate(uint64_t haplotype) const;
    inline double* GetRecoveryRateBegin() const;
    // void SetSamplingRate(double rate, uint64_t haplotype);
    // inline double GetSamplingRate(uint64_t haplotype) const;
    inline double* GetSamplingRateBegin() const;
    // void SetMutationRate(double rate, uint64_t haplotype, uint64_t site);
    // inline double GetMutationRate(uint64_t haplotype, uint64_t site) const;
    inline double* GetMutationRateHapBegin(uint64_t haplotype) const;
    inline double* GetMutationRateBegin() const;
    inline double GetTotalMutationRateHap(uint64_t haplotype) const;
    inline double* GetTotalMutationRateBegin() const;
    // void SetSitesRateHapSite(double rate, uint64_t haplotype, uint64_t site, uint64_t index);
    inline double GetSitesRateHapSiteProbability(uint64_t haplotype, uint64_t site, uint64_t index) const;
    // inline double GetSitesRateHapSite(uint64_t haplotype, uint64_t site, uint64_t index) const;
    inline double* GetSitesRateHapSiteBegin(uint64_t haplotype, uint64_t site) const;
    inline double GetTotalSitesRateHapSite(uint64_t haplotype, uint64_t site) const;
    // void SetSusceptibility(double rate, uint64_t haplotype, uint64_t group);
    inline double GetSusceptibility(uint64_t haplotype, uint64_t group) const;

private:
    inline uint64_t getNumberSites() const;
    inline uint64_t getNumberHaplotypes() const;
    inline uint64_t getNumberSusceptibleGroups() const;
    inline uint64_t getIndexSite(uint64_t first, uint64_t second) const;
    inline uint64_t getIndexSus(uint64_t first, uint64_t second) const;
    inline uint64_t getIndexSite3(uint64_t first, uint64_t second, uint64_t third) const;

    uint64_t number_of_sites_;
    uint64_t number_of_haplotypes_;
    uint64_t number_of_susceptible_groups_;

    uint64_t* susceptibility_groups_;
    double max_effective_transmission_;
    double* transmission_rates_;
    double* recovery_rates_;
    double* sampling_rates_;
    double* total_mutation_rates_;
    double* mutation_rates_;
    double* total_sites_rates_;
    double* susceptibility_;
    double* sites_rates_;
};
