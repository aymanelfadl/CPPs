#include "ShrubberyCreationForm.h"

ShrubberyCreationForm::ShrubberyCreationForm() : Form(), target("Default Target") {}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string& target)
	: Form("ShrubberyCreationForm", 145, 137), target(target) {}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& obj)
	: Form(obj), target(obj.target) {}

ShrubberyCreationForm::~ShrubberyCreationForm() {}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& obj)
{
	if (this == &obj)
		return *this;
	this->target = obj.target;
	return *this;
}

std::string ShrubberyCreationForm::getTarget() const
{
	return this->target;
}

void ShrubberyCreationForm::execute(Bureaucrat const & executor) const
{
	(void)executor;
	std::cout << target << " has been shrubberized.\n";
}

std::ostream& operator<<(std::ostream& os, const ShrubberyCreationForm& obj)
{
	char isSigned = obj.getIsSigned() ? 'y' : 'n';

	os << "Form: " << obj.getFormName()
	   << ", target: " << obj.getTarget()
	   << ", Signed: " << isSigned
	   << ", Grade to sign: " << obj.getGradeToSign()
	   << ", Grade to execute: " << obj.getGradeToExecute();
	return os;
}
