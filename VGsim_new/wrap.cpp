#include <boost/python.hpp>

#include "simulator.cpp"

using namespace boost::python;

BOOST_PYTHON_MODULE( source_VGsim ) {
    class_<Simulator>( "Simulator" )
        .def( init<uint64_t,uint64_t,uint64_t,uint64_t>( args( "number_of_sites", "number_of_populations", "number_of_susceptible_groups", "seed" ) ) )
        .def( "simulate", static_cast< void (Simulator::*)(uint64_t, uint64_t, double, std::string, uint64_t) >( &Simulator::simulate ), args("iterations", "sampling", "epidemic_time", "type", "number_attempts"))
        .def( "Genealogy", static_cast< void (Simulator::*)() > ( &Simulator::Genealogy ))
        .def( "Debug", static_cast< void (Simulator::*)() > ( &Simulator::Debug ))

        .def( "get_flat_chain", static_cast< PyObject* (Simulator::*)() > ( &Simulator::get_flat_chain ))
        .def( "export_chain_events", static_cast< PyObject* (Simulator::*)() >( &Simulator::export_chain_events ))

        // Infectious
        .def( "set_susceptibility_group", static_cast< void (Simulator::*)(uint64_t, uint64_t) > ( &Simulator::set_susceptibility_group ), args("group", "haplotype"))
        .def( "get_susceptibility_group", static_cast< PyObject* (Simulator::*)() > ( &Simulator::get_susceptibility_group ))
        .def( "set_transmission_rate", static_cast< void (Simulator::*)(double, uint64_t) > ( &Simulator::set_transmission_rate ), args("rate", "haplotype"))
        .def( "get_transmission_rate", static_cast< PyObject* (Simulator::*)() > ( &Simulator::get_transmission_rate ))
        .def( "set_recovery_rate", static_cast< void (Simulator::*)(double, uint64_t) > ( &Simulator::set_recovery_rate ), args("rate", "haplotype"))
        .def( "get_recovery_rate", static_cast< PyObject* (Simulator::*)() > ( &Simulator::get_recovery_rate ))
        .def( "set_sampling_rate", static_cast< void (Simulator::*)(double, uint64_t) > ( &Simulator::set_sampling_rate ), args("rate", "haplotype"))
        .def( "get_sampling_rate", static_cast< PyObject* (Simulator::*)() > ( &Simulator::get_sampling_rate ))
        .def( "set_mutation_rate", static_cast< void (Simulator::*)(double, uint64_t, uint64_t) > ( &Simulator::set_mutation_rate ), args("rate", "haplotype", "mutation"))
        .def( "get_mutation_rate", static_cast< PyObject* (Simulator::*)() > ( &Simulator::get_mutation_rate ))
        .def( "set_mutation_probabilities", static_cast< void (Simulator::*)(double, uint64_t, uint64_t, uint64_t) > ( &Simulator::set_mutation_probabilities ), args("rate", "haplotype", "mutation", "index"))
        .def( "get_mutation_probabilities", static_cast< PyObject* (Simulator::*)() > ( &Simulator::get_mutation_probabilities ))
        .def( "set_susceptibility", static_cast< void (Simulator::*)(double, uint64_t, uint64_t) > ( &Simulator::set_susceptibility ), args("rate", "haplotype", "group"))
        .def( "get_susceptibility", static_cast< PyObject* (Simulator::*)() > ( &Simulator::get_susceptibility ))

        // Susceptibles
        .def( "set_immunity_transition", static_cast< void (Simulator::*)(double, uint64_t, uint64_t) > ( &Simulator::set_immunity_transition ), args("rate", "source_group", "target_group"))
        .def( "get_immunity_transition", static_cast< PyObject* (Simulator::*)() > ( &Simulator::get_immunity_transition ))

        // Population pool
        .def( "set_population_size", static_cast< void (Simulator::*)(uint64_t, uint64_t) > ( &Simulator::set_population_size ), args("size", "population"))
        .def( "get_population_size", static_cast< PyObject* (Simulator::*)() > ( &Simulator::get_population_size ))
        .def( "set_contact_density", static_cast< void (Simulator::*)(double, uint64_t) > ( &Simulator::set_contact_density ), args("value", "population"))
        .def( "get_contact_density", static_cast< PyObject* (Simulator::*)() > ( &Simulator::get_contact_density ))
        .def( "set_npi", static_cast< void (Simulator::*)(double, double, double, uint64_t) > ( &Simulator::set_npi ), args("after", "start", "end", "population"))
        .def( "get_npi", static_cast< PyObject* (Simulator::*)() > ( &Simulator::get_npi ))
        .def( "set_sampling_multiplier", static_cast< void (Simulator::*)(double, uint64_t) > ( &Simulator::set_sampling_multiplier ), args("multiplier", "source_group"))
        .def( "get_sampling_multiplier", static_cast< PyObject* (Simulator::*)() > ( &Simulator::get_sampling_multiplier ))
        .def( "set_migration_probability", static_cast< void (Simulator::*)(double, uint64_t, uint64_t) > ( &Simulator::set_migration_probability ), args("probability", "source_population", "target_population"))
        .def( "get_migration_probability", static_cast< PyObject* (Simulator::*)() > ( &Simulator::get_migration_probability ))
        .def( "check_migration_probability", static_cast< uint64_t (Simulator::*)() > ( &Simulator::check_migration_probability ))
    ;
}