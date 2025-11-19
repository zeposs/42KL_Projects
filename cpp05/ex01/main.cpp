#include "Bureaucrat.hpp"

# define RESET   "\033[0m"
# define RED     "\033[31m"
# define GREEN   "\033[32m"
# define YELLOW  "\033[33m"
# define BLUE    "\033[34m"

#include "Form.hpp"

int main() {
    try {
        std::cout << YELLOW << "\n== OCF TEST ===\n" << RESET;

        Bureaucrat mc;
        Bureaucrat tara(mc);
        mc = tara;

        std::cout << '\n';

        Form tax;
        Form evasion(tax);
        tax = evasion;

        std::cout << '\n'; 
    }
    catch (std::exception &e) {
        std::cout << RED << e.what() << '\n' << RESET;
    }

    try {
        std::cout << YELLOW << "\n== GRADE TO SIGN TEST===\n" << RESET;
        Form fraud("FraudForm", 0, 1);
        std::cout << fraud << '\n';
    }
    catch (std::exception &e) {
        std::cout << RED << e.what() << '\n' << RESET;
    }

    try {
        Form fraud("FraudForm", 151, 1);
        std::cout << fraud << '\n';
    }
    catch (std::exception &e) {
        std::cout << RED << e.what() << '\n' << RESET;
    }

    try {
        std::cout << YELLOW << "\n== GRADE TO EXECUTE TEST===\n" << RESET;
        Form evasion("EvasionForm", 1, 0);
        std::cout << evasion << '\n';
    }
    catch (std::exception &e) {
        std::cout << RED << e.what() << '\n' << RESET;
    }

    try {
        Form evasion("EvasionForm", 1, 151);
        std::cout << evasion << '\n';
    }
    catch (std::exception &e) {
        std::cout << RED << e.what() << '\n' << RESET;
    }

    try {
        std::cout << YELLOW << "\n== SIGN TEST ===\n" << RESET;

        Bureaucrat caleb("Caleb", 1);
        std::cout << GREEN << caleb << '\n' << RESET;

        Bureaucrat sylus("Sylus", 150);
        std::cout << GREEN << sylus << '\n' << RESET;

        Form tax("TaxForm", 75, 65);
        std::cout << tax << '\n';

        caleb.signForm(tax);
        std::cout << '\n';

        sylus.signForm(tax);
        std::cout <<'\n';
    }
    catch (std::exception &e) {
        std::cout << RED << e.what() << '\n' << RESET;
    }

    return (0);
}