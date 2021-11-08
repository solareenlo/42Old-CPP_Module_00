/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tayamamo <tayamamo@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/09 05:32:05 by tayamamo          #+#    #+#             */
/*   Updated: 2021/11/09 06:48:49 by tayamamo         ###   ########.fr       */
/*   Copyright 2021                                                           */
/* ************************************************************************** */

#ifndef CONTACT_HPP_
#define CONTACT_HPP_

#define CONTACT_SIZE 11

#include <cstdlib>
#include <iostream>
#include <string>

#define nFirstName 0
#define nLastName 1
#define nNickname 2
#define nLogin 3
#define nPostalAddress 4
#define nEmailAddress 5
#define nPhoneNumber 6
#define nBirthdayDate 7
#define nFavariteMeal 8
#define nUnderwearColor 9
#define nDarkestSecret 10

class Contact {
 public:
    Contact();
    ~Contact();

    std::string GetFirstName() const;
    std::string GetLastName() const;
    std::string GetNickname() const;
    std::string GetLogin() const;
    std::string GetPostalAddres() const;
    std::string GetEmailAddress() const;
    std::string GetPhoneNumber() const;
    std::string GetBirthdayDate() const;
    std::string GetFavariteMeal() const;
    std::string GetUnderwearColor() const;
    std::string GetDarkestSecret() const;

    void SetContact();

 private:
    std::string contact_data_[CONTACT_SIZE];
    void GetLine_(std::string a, std::string &str);
    bool IsEmailAddress_(const std::string &str);
    void SetFirstName_();
    void SetLastName_();
    void SetNickname_();
    void SetLogin_();
    void SetPostalAddress_();
    void SetEmailAddress_();
    void SetPhoneNumber_();
    void SetBirthdayDate_();
    void SetFavariteMeal_();
    void SetUnderwearColor_();
    void SetDarkestSecret_();
};

#endif  // CONTACT_HPP_
