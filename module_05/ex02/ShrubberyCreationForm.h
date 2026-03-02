#pragma once

#include "AForm.h"

class ShrubberyCreationForm : public AForm {
	private:
		std::string target;

	public:
		ShrubberyCreationForm();
		ShrubberyCreationForm(const std::string& target);
		~ShrubberyCreationForm();

		ShrubberyCreationForm(const ShrubberyCreationForm& obj);
		ShrubberyCreationForm& operator=(const ShrubberyCreationForm& obj);

		std::string getTarget() const;
		void execute(Bureaucrat const & executor) const;
};

std::ostream& operator<<(std::ostream& os, const ShrubberyCreationForm& obj);
