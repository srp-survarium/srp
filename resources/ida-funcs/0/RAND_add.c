void __usercall RAND_add(int a1@<edi>, const void *buf, int num, long double entropy)
{
  rand_meth_st *RAND; // eax
  const engine_st *default_RAND; // eax
  engine_st *v6; // esi
  void (__cdecl *add)(const void *, int, long double); // ecx
  void *v8; // esp

  RAND = default_RAND_meth;
  if ( !default_RAND_meth )
  {
    default_RAND = ENGINE_get_default_RAND();
    v6 = (engine_st *)default_RAND;
    if ( default_RAND )
    {
      RAND = ENGINE_get_RAND(default_RAND);
      default_RAND_meth = RAND;
      if ( RAND )
      {
        funct_ref = v6;
LABEL_6:
        if ( !RAND )
          return;
        goto LABEL_7;
      }
      ENGINE_finish(a1, v6);
    }
    RAND = RAND_SSLeay();
    default_RAND_meth = RAND;
    goto LABEL_6;
  }
LABEL_7:
  add = RAND->add;
  if ( add )
  {
    v8 = alloca(8);
    ((void (__cdecl *)(const void *, int, _DWORD, _DWORD))add)(buf, num, LODWORD(entropy), HIDWORD(entropy));
  }
}
