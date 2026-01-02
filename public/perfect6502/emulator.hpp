#ifndef EMULATOR_HPP
#define EMULATOR_HPP

#include "pch.hpp"

namespace p6502
{
    class Emulator final
    {
        public:
            Emulator();
            Emulator(const Emulator&) = delete;
            Emulator(Emulator&&) = delete;

            ~Emulator();

            Emulator& operator=(const Emulator&) = delete;
            Emulator& operator=(Emulator&&) = delete;

            void step();
            [[nodiscard]] std::uint16_t program_counter() const;
            [[nodiscard]] std::uint8_t accumulator() const;
            [[nodiscard]] std::uint8_t x() const;
            [[nodiscard]] std::uint8_t y() const;
            [[nodiscard]] std::uint8_t stack_pointer() const;
            [[nodiscard]] std::uint8_t processor_status() const;

            [[nodiscard]] std::array<std::uint8_t, 65536>& memory();

        private:
            void* state;
    };
}

#endif