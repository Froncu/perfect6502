#ifndef EMULATOR_HPP
#define EMULATOR_HPP

#include "types.hpp"

namespace p6502
{
   class Emulator final
   {
      public:
         Emulator();
         Emulator(Emulator const&) = delete;
         Emulator(Emulator&&) = delete;

         ~Emulator();

         Emulator& operator=(Emulator const&) = delete;
         Emulator& operator=(Emulator&&) = delete;

         void reset();
         void step();

         [[nodiscard]] Cycle cycle() const;
         [[nodiscard]] ProgramCounter program_counter() const;
         [[nodiscard]] Accumulator accumulator() const;
         [[nodiscard]] Index x() const;
         [[nodiscard]] Index y() const;
         [[nodiscard]] StackPointer stack_pointer() const;
         [[nodiscard]] ProcessorStatus processor_status() const;

         [[nodiscard]] Memory const& memory() const;
         [[nodiscard]] Memory& memory();

      private:
         void* state_;
   };
}

#endif