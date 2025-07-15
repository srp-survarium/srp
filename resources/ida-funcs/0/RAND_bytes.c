int __usercall RAND_bytes@<eax>(int a1@<edi>)
{
  rand_meth_st *RAND; // eax
  const engine_st *default_RAND; // eax
  engine_st *v3; // esi
  int (*bytes)(void); // eax

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
          return -1;
        goto LABEL_7;
      }
      ENGINE_finish(a1, v3);
    }
    RAND = RAND_SSLeay();
    default_RAND_meth = RAND;
    goto LABEL_6;
  }
LABEL_7:
  bytes = (int (*)(void))RAND->bytes;
  if ( bytes )
    return bytes();
  return -1;
}
