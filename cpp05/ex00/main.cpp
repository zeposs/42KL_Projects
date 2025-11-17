#include "Bureaucrat.hpp"

# define RESET   "\033[0m"
# define RED     "\033[31m"
# define GREEN   "\033[32m"
# define YELLOW  "\033[33m"
# define BLUE    "\033[34m"

int main() {
    try {
        std::cout << YELLOW << "\n== OCF TEST===\n" << RESET;

        Bureaucrat mc;
        Bureaucrat tara(mc);
        mc = tara;
    }
    catch (std::exception &e) {
        std::cout << RED << e.what() << '\n' << RESET;
    }

    try {
        std::cout << YELLOW << "\n== NORMAL TEST===\n" << RESET;

        Bureaucrat Panzer_IV("Panzer_IV", 1);
        std::cout << GREEN << Panzer_IV << '\n' << RESET;

        Bureaucrat Tiger_II("Tiger_II", 150);
        std::cout << GREEN << Tiger_II << '\n' << RESET;
    }
    catch (std::exception &e) {
        std::cout << RED << e.what() << '\n' << RESET;
    }

    try {
        std::cout << YELLOW << "\n=== GRADE TOO LOW TEST ===\n" << RESET;
        Bureaucrat xavier("Xavier", 151);
        std::cout << GREEN << xavier << '\n' << RESET; // This line will be skipped when there is an exception
    } catch (std::exception &e) {
        std::cout << RED << e.what() << '\n' << RESET;
    }

    try {
        std::cout << YELLOW << "\n=== GRADE TOO HIGH TEST ===\n" << RESET;
        Bureaucrat rafayel("Rafayel", 0);
        std::cout << GREEN << rafayel << '\n' << RESET;
    } catch (std::exception &e) {
        std::cout << RED << e.what() << '\n' << RESET;
    }

    try {
        std::cout << YELLOW << "\n=== INCREMENT TEST ===\n" << RESET;
        Bureaucrat zayne("Zayne", 2);
        std::cout << GREEN << zayne << '\n' << RESET;
        for (int i = 0; i < 5; i++) {
            zayne.incrementGrade();
            std::cout << GREEN << zayne << '\n' << RESET;
        }
    } catch (std::exception &e) {
        std::cout << RED << e.what() << '\n' << RESET;
    }

    try {
        std::cout << YELLOW << "\n=== DECREMENT TEST ===\n" << RESET;
        Bureaucrat Panther_D("Panther_D", 149);
        std::cout << GREEN << Panther_D << '\n' << RESET;
        for (int i = 0; i < 5; i++) {
            Panther_D.decrementGrade();
            std::cout << GREEN << Panther_D << '\n' << RESET;
        }
    } catch (std::exception &e) {
        std::cout << RED << e.what() << std::endl << RESET;
    }

    return (0);
}