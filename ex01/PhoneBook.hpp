/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tayamamo <tayamamo@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/09 05:17:37 by tayamamo          #+#    #+#             */
/*   Updated: 2021/11/09 06:06:41 by tayamamo         ###   ########.fr       */
/*   Copyright 2021                                                           */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP_
#define PHONEBOOK_HPP_

#include <iomanip>
#include <string>

#include "Contact.hpp"

#define PHONEBOOK_MAX_SIZE 8

class PhoneBook {
 public:
    PhoneBook();
    ~PhoneBook();

    void AddContact();
    void SearchContact();

 private:
    int contact_size_;
    Contact contact_[PHONEBOOK_MAX_SIZE];
    void FormatedCoutCenter_(std::string const str);
    void FormatedCoutRight_(std::string const str);
    void PutList_();
    void PutContact_(const int index);
    bool PhoneBookIsEmpty_() const;
    bool PhoneBookIsFull_() const;
};

#endif  // PHONEBOOK_HPP_
