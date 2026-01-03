#include "perfect6502.h"
#include "perfect6502/emulator.hpp"

namespace p6502
{
   Emulator::Emulator(std::optional<Memory> const& initial_memory, std::optional<ProgramCounter> const program_start)
   {
      reset(initial_memory, program_start);
   }

   Emulator::~Emulator()
   {
      if (state_)
         destroyChip(state_);
   }

   void Emulator::reset(std::optional<Memory> const& initial_memory, std::optional<ProgramCounter> const program_start)
   {
      if (initial_memory)
         memory() = std::move(*initial_memory);

      Data const reset_vector_low = memory()[0xFFFC];
      Data const reset_vector_high = memory()[0xFFFD];
      if (program_start)
      {
         memory()[0xFFFC] = *program_start & 0xFF;
         memory()[0xFFFD] = *program_start >> 8;
      }

      if (state_)
         destroyChip(state_);

      state_ = initAndResetChip();
      memory()[0xFFFC] = reset_vector_low;
      memory()[0xFFFD] = reset_vector_high;
   }

   void Emulator::half_step()
   {
      ::step(state_);
   }

   void Emulator::step()
   {
      half_step();
      half_step();
   }

   Cycle Emulator::cycle() const
   {
      // NOTE: perfect6502's `cycle` variable is actually a half-cycle
      return (::cycle + 1) >> 1;
   }

   ProgramCounter Emulator::program_counter() const
   {
      return readPC(state_);
   }

   Accumulator Emulator::accumulator() const
   {
      return readA(state_);
   }

   Index Emulator::x() const
   {
      return readX(state_);
   }

   Index Emulator::y() const
   {
      return readY(state_);
   }

   StackPointer Emulator::stack_pointer() const
   {
      return readSP(state_);
   }

   ProcessorStatus Emulator::processor_status() const
   {
      return readP(state_);
   }

   Memory const& Emulator::memory() const
   {
      return reinterpret_cast<Memory const&>(::memory);
   }

   Memory& Emulator::memory()
   {
      return reinterpret_cast<Memory&>(::memory);
   }
}