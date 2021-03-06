/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tayamamo <tayamamo@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/09 05:25:48 by tayamamo          #+#    #+#             */
/*   Updated: 2021/11/09 07:15:14 by tayamamo         ###   ########.fr       */
/*   Copyright 2021                                                           */
/* ************************************************************************** */

#include "PhoneBook.hpp"

PhoneBook::PhoneBook() : contact_size_(0) {}
PhoneBook::~PhoneBook() {}

void PhoneBook::AddContact() {
    if (contact_size_ == PHONEBOOK_MAX_SIZE) {
        std::cout << "Phonebook is full." << std::endl;
        return;
    }
    contact_[contact_size_].SetContact();
    std::cout << "Input completed!" << std::endl;
    contact_size_++;
}

void PhoneBook::FormatedCoutCenter_(std::string const str) const {
    std::cout << '|';
    std::cout << std::left << std::setw(10) << str;
}

void PhoneBook::FormatedCoutRight_(std::string const str) const {
    std::cout << '|';
    if (str.size() > 9)
        std::cout << std::setw(9) << str.substr(0, 9) << ".";
    else
        std::cout << std::right << std::setw(10) << str;
}

void PhoneBook::PutList_() const {
    PhoneBook::FormatedCoutCenter_("Index");
    PhoneBook::FormatedCoutCenter_("First Name");
    PhoneBook::FormatedCoutCenter_("Last Name");
    PhoneBook::FormatedCoutCenter_("Nickname");
    std::cout << '|' << std::endl;
    PhoneBook::FormatedCoutCenter_("----------");
    PhoneBook::FormatedCoutCenter_("----------");
    PhoneBook::FormatedCoutCenter_("----------");
    PhoneBook::FormatedCoutCenter_("----------");
    std::cout << '|' << std::endl;
    for (int i = 0; i < contact_size_; i++) {
        std::cout << '|';
        std::cout << std::right << std::setw(10) << i;
        PhoneBook::FormatedCoutRight_(contact_[i].GetFirstName());
        PhoneBook::FormatedCoutRight_(contact_[i].GetLastName());
        PhoneBook::FormatedCoutRight_(contact_[i].GetNickname());
        std::cout << '|' << std::endl;
    }
    std::cout << std::endl;
}

void PhoneBook::PutContact_(const int index) const {
    if (index < 0 || contact_size_ - 1 < index) return;
    std::cout << "first name\t: " << contact_[index].GetFirstName()
              << std::endl;
    std::cout << "last name\t: " << contact_[index].GetLastName() << std::endl;
    std::cout << "nickname\t: " << contact_[index].GetNickname() << std::endl;
    std::cout << "login\t\t: " << contact_[index].GetLogin() << std::endl;
    std::cout << "postal address\t: ";
    std::cout << contact_[index].GetPostalAddres() << std::endl;
    std::cout << "email address\t: ";
    std::cout << contact_[index].GetEmailAddress() << std::endl;
    std::cout << "phone number\t: ";
    std::cout << contact_[index].GetPhoneNumber() << std::endl;
    std::cout << "birthday date\t: ";
    std::cout << contact_[index].GetBirthdayDate() << std::endl;
    std::cout << "favorite meal\t: ";
    std::cout << contact_[index].GetFavariteMeal() << std::endl;
    std::cout << "underwear color\t: ";
    std::cout << contact_[index].GetUnderwearColor() << std::endl;
    std::cout << "darkest secret\t: ";
    std::cout << contact_[index].GetDarkestSecret() << std::endl;
}

void PhoneBook::SearchContact() const {
    if (PhoneBookIsEmpty_()) {
        std::cout << "Phone Book is empty. Please \"ADD\" contact first.";
        std::cout << std::endl;
        return;
    }

    PhoneBook::PutList_();
    std::string index;
    bool put_content = true;

    for (;;) {
        std::cout << "Index > ";
        bool ok = true;
        std::getline(std::cin, index);
        if (std::cin.bad() || std::cin.eof()) {
            std::cout << std::endl;
            std::cout << "EXIT" << std::endl;
            std::exit(0);
        }
        if (!index.compare("EXIT")) {
            std::cout << "SEARCH EXIT" << std::endl;
            put_content = false;
            break;
        }
        if (index.empty() || isdigit(index[0]) == 0) {
            ok = false;
        } else {
            int i = atoi(index.c_str());
            if (i < 0 || contact_size_ - 1 < i) {
                ok = false;
            }
        }
        if (ok)
            break;
        else
            std::cout << "Invalid index." << std::endl;
    }

    if (put_content) {
        int i = atoi(index.c_str());
        if (0 <= i && i < contact_size_) PhoneBook::PutContact_(i);
    }
}

bool PhoneBook::PhoneBookIsEmpty_() const { return (contact_size_ == 0); }

bool PhoneBook::PhoneBookIsFull_() const {
    return (contact_size_ == PHONEBOOK_MAX_SIZE);
}
