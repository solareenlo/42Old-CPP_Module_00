/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tayamamo <tayamamo@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/09 05:35:24 by tayamamo          #+#    #+#             */
/*   Updated: 2021/11/09 06:24:57 by tayamamo         ###   ########.fr       */
/*   Copyright 2021                                                           */
/* ************************************************************************** */
#include "Contact.hpp"

Contact::Contact() {
    for (int i = 0; i < CONTACT_SIZE; i++) {
        this->contact_data_[i] = "";
    }
}

Contact::~Contact() {}

std::string Contact::GetFirstName() const {
    return (contact_data_[nFirstName]);
}

std::string Contact::GetLastName() const { return (contact_data_[nLastName]); }

std::string Contact::GetNickname() const { return (contact_data_[nNickname]); }

std::string Contact::GetLogin() const { return (contact_data_[nLogin]); }

std::string Contact::GetPostalAddres() const {
    return (contact_data_[nPostalAddress]);
}

std::string Contact::GetEmailAddress() const {
    return (contact_data_[nEmailAddress]);
}

std::string Contact::GetPhoneNumber() const {
    return (contact_data_[nPhoneNumber]);
}

std::string Contact::GetBirthdayDate() const {
    return (contact_data_[nBirthdayDate]);
}

std::string Contact::GetFavariteMeal() const {
    return (contact_data_[nFavariteMeal]);
}

std::string Contact::GetUnderwearColor() const {
    return (contact_data_[nUnderwearColor]);
}

std::string Contact::GetDarkestSecret() const {
    return (contact_data_[nDarkestSecret]);
}

void Contact::GetLine_(const std::string field, std::string &str) {
    std::cout << field;
    std::cout << "> ";
    getline(std::cin, str);
    if (std::cin.bad() || std::cin.eof()) {
        std::cout << std::endl;
        std::cout << "EXIT" << std::endl;
        exit(0);
    }
}

void Contact::SetFirstName_() {
    Contact::GetLine_("first name ", contact_data_[nFirstName]);
}

void Contact::SetLastName_() {
    Contact::GetLine_("last name ", contact_data_[nLastName]);
}

void Contact::SetNickname_() {
    Contact::GetLine_("nickname ", contact_data_[nNickname]);
}

void Contact::SetLogin_() {
    Contact::GetLine_("login ", contact_data_[nLogin]);
}

void Contact::SetPostalAddress_() {
    std::string postal_address = "";

    for (;;) {
        bool ok = true;
        Contact::GetLine_("postal address (***-****) ", postal_address);
        if (!postal_address.empty()) {
            if (postal_address.size() != 8) ok = false;
            for (int i = 0; i < 3; i++) {
                if (isdigit(postal_address[i]) == 0) {
                    ok = false;
                    break;
                }
            }
            if (postal_address[3] != '-') ok = false;
            for (int i = 4; i < 8; i++) {
                if (isdigit(postal_address[i]) == 0) {
                    ok = false;
                    break;
                }
            }
        }
        if (ok == true) break;
    }

    this->contact_data_[nPostalAddress] = postal_address;
}

bool Contact::IsEmailAddress_(const std::string &email_address) {
    std::string::size_type at = email_address.find("@");
    std::string::size_type dot = email_address.find(".", at);

    return (at != std::string::npos && dot != std::string::npos &&
            dot - at > 1 &&
            email_address[dot] != email_address[email_address.size() - 1]);
}

void Contact::SetEmailAddress_() {
    std::string email_address = "";

    for (;;) {
        bool ok = true;
        Contact::GetLine_("email address ", email_address);
        if (!email_address.empty()) {
            if (!IsEmailAddress_(email_address)) ok = false;
        }
        if (ok) break;
    }

    this->contact_data_[nEmailAddress] = email_address;
}

void Contact::SetPhoneNumber_() {
    std::string phone_number = "";

    for (;;) {
        Contact::GetLine_("Phone Number (10- or 11- digit number) ",
                          phone_number);
        bool ok = true;
        if (!phone_number.empty()) {
            if (!(phone_number.size() == 10 || phone_number.size() == 11))
                ok = false;
            for (int i = 0; i < static_cast<int>(phone_number.size()); i++) {
                if (isdigit(phone_number[i]) == 0) {
                    ok = false;
                    break;
                }
            }
        }
        if (ok) break;
    }

    this->contact_data_[nPhoneNumber] = phone_number;
}

void Contact::SetBirthdayDate_() {
    int days[] = {31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    std::string birthday_date = "";

    for (;;) {
        Contact::GetLine_("birthday date (mm-dd) ", birthday_date);
        bool ok = true;
        if (!birthday_date.empty()) {
            if (birthday_date.size() != 5) {
                ok = false;
            } else {
                if (!isdigit(birthday_date[0]) || !isdigit(birthday_date[1]) ||
                    birthday_date[2] != '-' || !isdigit(birthday_date[3]) ||
                    !isdigit(birthday_date[4])) {
                    ok = false;
                } else {
                    int month =
                        (birthday_date[0] - '0') * 10 + birthday_date[1] - '0';
                    if (month < 1 || 12 < month) {
                        ok = false;
                    } else {
                        int day = (birthday_date[3] - '0') * 10 +
                                  birthday_date[4] - '0';
                        if (day < 1 || days[month - 1] < day) ok = false;
                    }
                }
            }
        }
        if (ok) break;
    }

    this->contact_data_[nBirthdayDate] = birthday_date;
}

void Contact::SetFavariteMeal_() {
    Contact::GetLine_("favarite meal ", contact_data_[nFavariteMeal]);
}

void Contact::SetUnderwearColor_() {
    Contact::GetLine_("underwear color ", contact_data_[nUnderwearColor]);
}

void Contact::SetDarkestSecret_() {
    Contact::GetLine_("darkest secret ", contact_data_[nDarkestSecret]);
}

void Contact::SetContact() {
    SetFirstName_();
    SetLastName_();
    SetNickname_();
    SetLogin_();
    SetPostalAddress_();
    SetEmailAddress_();
    SetPhoneNumber_();
    SetBirthdayDate_();
    SetFavariteMeal_();
    SetUnderwearColor_();
    SetDarkestSecret_();
}
