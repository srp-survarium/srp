void __usercall build_SYS_str_reasons(unsigned int a1@<edi>)
{
  int v1; // ebp
  unsigned __int8 *v2; // edi
  const char **p_string; // esi
  bool v4; // zf
  unsigned __int8 *v5; // eax

  CRYPTO_lock(a1, 5, 1, ".\\crypto\\err\\err.c", 580);
  if ( init_3 )
  {
    CRYPTO_lock(a1, 6, 1, ".\\crypto\\err\\err.c", 587);
    CRYPTO_lock(a1, 9, 1, ".\\crypto\\err\\err.c", 588);
    if ( init_3 )
    {
      v1 = 1;
      v2 = (unsigned __int8 *)strerror_tab;
      p_string = &SYS_str_reasons[0].string;
      do
      {
        v4 = *p_string == 0;
        *(p_string - 1) = (const char *)v1;
        if ( v4 )
        {
          v5 = (unsigned __int8 *)strerror(v1);
          if ( v5 )
          {
            strncpy(v2, v5, 0x20u);
            v2[31] = 0;
            *p_string = (const char *)v2;
          }
          if ( !*p_string )
            *p_string = "unknown";
        }
        p_string += 2;
        ++v1;
        v2 += 32;
      }
      while ( (int)p_string <= (int)&SYS_str_reasons[126].string );
      init_3 = 0;
      CRYPTO_lock((unsigned int)v2, 10, 1, ".\\crypto\\err\\err.c", 620);
    }
    else
    {
      CRYPTO_lock(a1, 10, 1, ".\\crypto\\err\\err.c", 591);
    }
  }
  else
  {
    CRYPTO_lock(a1, 6, 1, ".\\crypto\\err\\err.c", 583);
  }
}
