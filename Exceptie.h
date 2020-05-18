
#include <exception>
#pragma once
class Exceptie : public std :: exception
{
    public:
        Exceptie() noexcept{}
        Exceptie(const Exceptie&) noexcept = default;
        Exceptie& operator = (const Exceptie&) noexcept = default;

        virtual const char* what() const noexcept{ return "Invalid value\n";}

        virtual ~Exceptie() noexcept = default;


};
