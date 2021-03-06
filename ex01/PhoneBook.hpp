/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tayamamo <tayamamo@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/09 05:17:37 by tayamamo          #+#    #+#             */
/*   Updated: 2021/11/12 10:54:49 by tayamamo         ###   ########.fr       */
/*   Copyright 2021                                                           */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP_
#define PHONEBOOK_HPP_

#include <iomanip>
#include <string>

#include "Contact.hpp"

class PhoneBook {
 public:
    PhoneBook();
    ~PhoneBook();

    void AddContact();
    void SearchContact() const;

 private:
    static int const PHONEBOOK_MAX_SIZE = 8;
    int contact_size_;
    Contact contact_[PHONEBOOK_MAX_SIZE];
    void FormatedCoutCenter_(std::string const str) const;
    void FormatedCoutRight_(std::string const str) const;
    void PutList_() const;
    void PutContact_(const int index) const;
    bool PhoneBookIsEmpty_() const;
    bool PhoneBookIsFull_() const;
};

#endif  // PHONEBOOK_HPP_
