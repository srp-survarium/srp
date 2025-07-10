__int64 OPENSSL_instrument_halt()
{
  __int16 v0; // kr00_2

  if ( _bittest((const signed __int32 *)&OPENSSL_ia32cap_P, 4u) )
  {
    if ( (__CS__ & 3) == 0 )
    {
      v0 = __readeflags();
      if ( (v0 & 0x200) != 0 )
      {
        __rdtsc();
        __halt();
      }
    }
  }
  return 0;
}
