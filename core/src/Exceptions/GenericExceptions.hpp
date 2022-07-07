/*
** EPITECH PROJECT, 2021
** B-OOP-400-NAN-4-1-arcade-victor.harri-chal
** File description:
** GenericExceptions.hpp
*/

#ifndef _GENERIC_EXCEPTIONS_HPP_
    #define _GENERIC_EXCEPTIONS_HPP_

    #include <iostream>
    #include <exception>

    class GenericExceptions : public std::exception {
        public:
            // Ctor & Dtor
            GenericExceptions(const std::string &message) noexcept;
            ~GenericExceptions() = default;

            // Member Functions
            const char *what() const noexcept override ;
            void dispErrorMessage() noexcept;

        protected:
            std::string _message;
    };

#endif