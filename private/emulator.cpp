#include <perfect6502.h>

#include "perfect6502/emulator.hpp"

namespace p6502
{
    Emulator::Emulator()
        : state{ initAndResetChip() }
    {
    }

    Emulator::~Emulator()
    {
        destroyChip(state);
    }

    void Emulator::step()
    {
        ::step(state);
    }

    std::uint16_t Emulator::program_counter() const
    {
        return readPC(state);
    }

    std::uint8_t Emulator::accumulator() const
    {
        return readA(state);
    }

    std::uint8_t Emulator::x() const
    {
        return readX(state);
    }

    std::uint8_t Emulator::y() const
    {
        return readY(state);
    }

    std::uint8_t Emulator::stack_pointer() const
    {
        return readSP(state);
    }

    std::uint8_t Emulator::processor_status() const
    {
        return readP(state);
    }

    std::array<std::uint8_t, 65536>& Emulator::memory()
    {
        return reinterpret_cast<std::array<std::uint8_t, 65536>&>(::memory);
    }
}