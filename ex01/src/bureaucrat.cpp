/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afavre <afavre@student.42lausanne>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 13:39:27 by afavre            #+#    #+#             */
/*   Updated: 2023/10/11 13:39:29 by afavre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bureaucrat.hpp"

bureaucrat::bureaucrat()
{
	this->rank = 150;
}

bureaucrat::bureaucrat(std::string const &name, int rank): name(name), rank(rank)
{
	if (rank < 1)
		throw bureaucrat::GradeTooHighException();
	if (rank > 150)
		throw GradeTooLowException();
	std::cout << this->name << " a rejoint notre entreprise ! souhaitez lui la bienvenue !" << std::endl;
}

bureaucrat::~bureaucrat()
{
	std::cout << this->name << " a posé sa démission." << std::endl;
}

std::string bureaucrat::getName() const
{
	return (this->name);
}

int  bureaucrat::getRank() const
{
	return (this->rank);
}

void bureaucrat::signForm(form &form) {
	try {
		form.beSigned(*this);
		std::cout << this->getName() << " a signer " << form.getName() << "." << std::endl;
	}
	catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}
}

void bureaucrat::incrementGrade() {
	if (rank > 1) {
		std::cout << this->name << " est monte en grade ! bravo a lui !" << std::endl;
		this->rank--;
	}
	else
		throw bureaucrat::GradeTooHighException();
}

void bureaucrat::decrementGrade() {
	if (rank < 149) {
		std::cout << this->name << " est tombe en grade ! aller le lyncher ! mouhahaha !" << std::endl;
		this->rank++;
	}
	else
		throw bureaucrat::GradeTooLowException();
}

//COPLIEN FORM
bureaucrat &bureaucrat::operator=(bureaucrat const &copy)
{
	if (this != &copy)
		this->rank = copy.rank;
	return (*this);
}

bureaucrat::bureaucrat(bureaucrat &src) : rank()
{
	*this = src;
}

std::ostream& operator<<(std::ostream& os, const bureaucrat& obj)
{
	os << "Nom : " << obj.getName() << ", Rang : " << obj.getRank();
	return os;
}

