#ifndef _MCAL_IRQ_2010_04_10_H_
  #define _MCAL_IRQ_2010_04_10_H_

  namespace mcal
  {
    namespace irq
    {
      typedef void config_type;
      void init(const config_type*);

      inline void enable_all () { asm volatile ("cpsie i"); }
      inline void disable_all() { asm volatile ("cpsid i"); }
    }
  }

#endif // _MCAL_IRQ_2010_04_10_H_