#include "perfect6502.h"
#include "perfect6502/emulator.hpp"

namespace p6502
{
   Emulator::Emulator()
      : state_{ initAndResetChip() }
   {
   }

   Emulator::~Emulator()
   {
      destroyChip(state_);
   }

   void Emulator::reset()
   {
      destroyChip(state_);
      state_ = initAndResetChip();
   }

   void Emulator::step()
   {
      ::step(state_);
   }

   Cycle Emulator::cycle() const
   {
      return ::cycle;
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