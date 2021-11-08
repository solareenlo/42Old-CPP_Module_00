/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tayamamo <tayamamo@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/09 04:55:09 by tayamamo          #+#    #+#             */
/*   Updated: 2021/11/09 07:07:31 by tayamamo         ###   ########.fr       */
/*   Copyright 2021                                                           */
/* ************************************************************************** */

#include <iostream>

#include "PhoneBook.hpp"

int main(int argc, char *argv[]) {
    (void)argv;
    if (argc != 1) {
        std::cout << "Usage:\n./phonebook" << std::endl;
        return 1;
    }

    PhoneBook phone_book;
    std::string cmd;

    for (;;) {
        std::cout << "> ";
        std::getline(std::cin, cmd);
        if (std::cin.bad() || std::cin.eof()) {
            std::cout << std::endl;
            std::cout << "EXIT" << std::endl;
            break;
        }
        if (!cmd.compare("EXIT")) {
            std::cout << "EXIT" << std::endl;
            break;
        } else if (!cmd.compare("ADD")) {
            phone_book.AddContact();
        } else if (!cmd.compare("SEARCH")) {
            phone_book.SearchContact();
        }
    }
    return 0;
}
