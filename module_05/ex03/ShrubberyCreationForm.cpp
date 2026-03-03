#include "ShrubberyCreationForm.h"

ShrubberyCreationForm::ShrubberyCreationForm() : AForm(), target("Default Target") {}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string &target)
	: AForm("ShrubberyCreationForm", 145, 137), target(target) {}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &obj)
	: AForm(obj), target(obj.target) {}

ShrubberyCreationForm::~ShrubberyCreationForm() {}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &obj)
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

void ShrubberyCreationForm::execute(Bureaucrat const &executor) const
{
	if (!this->getIsSigned())
		throw AForm::FromNotSigned();
	else if (executor.getGrade() > this->getGradeToExecute())
		throw AForm::GradeTooLowException();
	else
	{
		const std::string fileName = this->target + "__shrubbery";
		std::ofstream file(fileName.c_str());
		file << "    *\n"
			 << "   ***\n"
			 << "  *****\n"
			 << " *******\n"
			 << "   |||\n";
		file.close();
	}
}

std::ostream &operator<<(std::ostream &os, const ShrubberyCreationForm &obj)
{
	const char isSigned = obj.getIsSigned() ? 'y' : 'n';

	os << "Form: " << obj.getFormName()
	   << ", target: " << obj.getTarget()
	   << ", Signed: " << isSigned
	   << ", Grade to sign: " << obj.getGradeToSign()
	   << ", Grade to execute: " << obj.getGradeToExecute();
	return os;
}
