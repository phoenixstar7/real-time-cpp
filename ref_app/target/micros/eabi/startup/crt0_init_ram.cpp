#include <algorithm>
#include <cstddef>
#include <cstdint>

extern "C"
{
  extern std::uintptr_t _rom_data_begin; // Start address for the initialization values of the rom-to-ram section.
  extern std::uintptr_t _data_begin;     // Start address for the .data section.
  extern std::uintptr_t _data_end;       // End address for the .data section.
  extern std::uintptr_t _bss_begin;      // Start address for the .bss section.
  extern std::uintptr_t _bss_end;        // End address for the .bss section.
}

namespace crt
{
  void init_ram();
}

void crt::init_ram()
{
  // Copy the data segment initializers from ROM to RAM.
  const std::size_t count =   static_cast<const std::uintptr_t*>(&_data_end)
                            - static_cast<const std::uintptr_t*>(&_data_begin);

  std::copy(static_cast<const std::uintptr_t*>(&_rom_data_begin),
            static_cast<const std::uintptr_t*>(&_rom_data_begin) + count,
            static_cast<      std::uintptr_t*>(&_data_begin));

  // Clear the bss segment.
  std::fill(static_cast<std::uintptr_t*>(&_bss_begin),
            static_cast<std::uintptr_t*>(&_bss_end),
            static_cast<std::uintptr_t>(0uL));
}