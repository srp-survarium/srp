void __cdecl RAND_add(const void *buf, int num, long double entropy)
{
  rand_meth_st *RAND; // eax
  const engine_st *default_RAND; // eax
  engine_st *v5; // esi
  void (__cdecl *add)(const void *, int, long double); // ecx
  void *v7; // esp

  RAND = default_RAND_meth;
  if ( !default_RAND_meth )
  {
    default_RAND = ENGINE_get_default_RAND();
    v5 = (engine_st *)default_RAND;
    if ( default_RAND )
    {
      RAND = ENGINE_get_RAND(default_RAND);
      default_RAND_meth = RAND;
      if ( RAND )
      {
        funct_ref = v5;
LABEL_6:
        if ( !RAND )
          return;
        goto LABEL_7;
      }
      ENGINE_finish(v5);
    }
    RAND = RAND_SSLeay();
    default_RAND_meth = RAND;
    goto LABEL_6;
  }
LABEL_7:
  add = RAND->add;
  if ( add )
  {
    v7 = alloca(8);
    ((void (__cdecl *)(const void *, int, _DWORD, _DWORD))add)(buf, num, LODWORD(entropy), HIDWORD(entropy));
  }
}
