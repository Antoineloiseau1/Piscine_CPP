#include "ShrubberryCreationForm.hpp"
#include <iostream>

ShrubberryCreationForm::ShrubberryCreationForm(std::string target) : AForm("ShrubberryCreationForm", 145, 137), _target(target) {}

ShrubberryCreationForm::ShrubberryCreationForm(const ShrubberryCreationForm & src) : AForm(src), _target(src.getTarget()) {}

ShrubberryCreationForm&	ShrubberryCreationForm::operator=(const ShrubberryCreationForm & rhs) {
	(void)rhs;
	return *this;
}

std::string const	ShrubberryCreationForm::getTarget(void) const { return this->_target; }

void	ShrubberryCreationForm::execute(Bureaucrat const & executor) const {
	this->checkPrerequisites(executor);
	std::ofstream	file((this->_target + "_shrubberry").c_str());
	if (file.is_open()) {
		file << "	                 00000000000000" << std::endl;
		file << "              oooooo  00000000  o88o" << std::endl;
		file << "           ooOOOOOOOoo  ```''  8888888" << std::endl;
		file << "         OOOOOOOOOOOO'.qQQQQq. `8888888'" << std::endl;
		file << "        oOOOOOOOOOO'.QQQQQQQQQQ/.888888'" << std::endl;
		file << "        OOOOOOOOOO'.QQQQQQQQQQ/ /q8888" << std::endl;
		file << "         OOOOOOOOO QQQQQQQQQQ/ /QQ888" << std::endl;
		file << "           OOOOOOOOO `QQQQQQ/ /QQ888'" << std::endl;
		file << "             OO:F_P:O `QQQ/  /Q888'" << std::endl;
		file << "                \\\\. \\ |  // |" << std::endl;
		file << "                d\\ \\\\\\|_////" << std::endl;
		file << "                qP| \\\\ _' `|Ob" << std::endl;
		file << "                   \\  / \\  \\Op" << std::endl;
		file << "                   |  | O| |" << std::endl;
		file << "           _       /\\. \\_/ /\\" << std::endl;
		file << "            `---__/|_\\\\   //|  __" << std::endl;
		file << "                  `-'  `-'`-'-'" << std::endl;
		file.close();
	}
	else
		std::cerr << "failed to create file" << std::endl;
}

ShrubberryCreationForm::~ShrubberryCreationForm(void) {}