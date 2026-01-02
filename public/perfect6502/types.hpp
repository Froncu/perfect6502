#ifndef TYPES_HPP
#define TYPES_HPP

#include "pch.hpp"

namespace p6502
{
   using Cycle = std::uint64_t;
   using Address = std::uint16_t;
   using ProgramCounter = std::uint16_t;
   using Accumulator = std::uint8_t;
   using Index = std::uint8_t;
   using StackPointer = std::uint8_t;
   using ProcessorStatus = std::uint8_t;

   using Data = std::uint8_t;
   using Memory = std::array<std::uint8_t, std::numeric_limits<ProgramCounter>::max() + 1>;

   enum class ProcessorStatusFlag : ProcessorStatus
   {
      C = 0b00000001,
      Z = 0b00000010,
      I = 0b00000100,
      D = 0b00001000,
      B = 0b00010000,
      _ = 0b00100000,
      V = 0b01000000,
      N = 0b10000000
   };
}

#endif