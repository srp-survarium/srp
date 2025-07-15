void __cdecl __set_fpsr_sse2(unsigned int newMXCSR)
{
  if ( __sse2_available )
  {
    if ( (newMXCSR & 0x40) != 0 && _DAZ_ENABLED )
      _mm_setcsr(newMXCSR);
    else
      _mm_setcsr(newMXCSR & 0xFFFFFFBF);
  }
}
