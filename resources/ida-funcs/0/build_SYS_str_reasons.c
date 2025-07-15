void __usercall build_SYS_str_reasons(int a1@<edi>, int a2@<ebx>)
{
  int v2; // ebp
  unsigned __int8 *v3; // edi
  const char **p_string; // esi
  bool v5; // zf
  unsigned __int8 *v6; // eax

  CRYPTO_lock(a1, a2, 5, 1, ".\\crypto\\err\\err.c", 580);
  if ( init_3 )
  {
    CRYPTO_lock(a1, a2, 6, 1, ".\\crypto\\err\\err.c", 587);
    CRYPTO_lock(a1, a2, 9, 1, ".\\crypto\\err\\err.c", 588);
    if ( init_3 )
    {
      v2 = 1;
      v3 = (unsigned __int8 *)strerror_tab;
      p_string = &SYS_str_reasons[0].string;
      do
      {
        v5 = *p_string == 0;
        *(p_string - 1) = (const char *)v2;
        if ( v5 )
        {
          v6 = (unsigned __int8 *)strerror(v2);
          if ( v6 )
          {
            strncpy(v3, v6, 0x20u);
            v3[31] = 0;
            *p_string = (const char *)v3;
          }
          if ( !*p_string )
            *p_string = "unknown";
        }
        p_string += 2;
        ++v2;
        v3 += 32;
      }
      while ( (int)p_string <= (int)&SYS_str_reasons[126].string );
      init_3 = 0;
      CRYPTO_lock((int)v3, a2, 10, 1, ".\\crypto\\err\\err.c", 620);
    }
    else
    {
      CRYPTO_lock(a1, a2, 10, 1, ".\\crypto\\err\\err.c", 591);
    }
  }
  else
  {
    CRYPTO_lock(a1, a2, 6, 1, ".\\crypto\\err\\err.c", 583);
  }
}
