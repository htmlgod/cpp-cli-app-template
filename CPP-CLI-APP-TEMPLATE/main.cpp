#include <iostream>

#include <boost/program_options.hpp>

#include <CPP-CLI-APP-TEMPLATE/CPP-CLI-APP-TEMPLATE.hpp>

#define APP_NAME "CPP-CLI-APP-TEMPLATE"

namespace po = boost::program_options;

int main(int argc, char** argv) {
    try {
        po::options_description desc("Allowed options");
        desc.add_options()
            ("help", "produce help message")
            ("print-test", "")
        ;
        po::variables_map vm;        
        po::store(po::parse_command_line(argc, argv, desc), vm);
        po::notify(vm);    

        if (vm.count("help") or argc == 1) {
            std::cout << "Usage: " << APP_NAME << " [OPTIONS]" << std::endl;
            std::cout << desc << "\n";
            return 0;
        }

        if (vm.count("print-test")) {
            std::cout << test() << std::endl;
            return 0;
        }
    }
    catch(po::error& e) {
        std::cerr << "error: " << e.what() << "\n";
        return 1;
    }

    return 0;
}
