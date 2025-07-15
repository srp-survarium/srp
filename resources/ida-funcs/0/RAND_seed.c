void __usercall RAND_seed(int a1@<edi>)
{
  const rand_meth_st *RAND; // eax
  const engine_st *default_RAND; // eax
  engine_st *v3; // esi
  void (*seed)(void); // eax

  RAND = default_RAND_meth;
  if ( !default_RAND_meth )
  {
    default_RAND = ENGINE_get_default_RAND();
    v3 = (engine_st *)default_RAND;
    if ( default_RAND )
    {
      RAND = ENGINE_get_RAND(default_RAND);
      default_RAND_meth = RAND;
      if ( RAND )
      {
        funct_ref = v3;
LABEL_6:
        if ( !RAND )
          return;
        goto LABEL_7;
      }
      ENGINE_finish(a1, v3);
    }
    RAND = RAND_SSLeay();
    default_RAND_meth = RAND;
    goto LABEL_6;
  }
LABEL_7:
  seed = (void (*)(void))RAND->seed;
  if ( seed )
    seed();
}
