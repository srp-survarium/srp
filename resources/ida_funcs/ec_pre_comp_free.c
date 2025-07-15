void __cdecl ec_pre_comp_free(void *pre_)
{
  ec_point_st **v1; // esi
  ec_point_st *i; // eax

  if ( pre_ && CRYPTO_add_lock((int *)pre_ + 6, -1, 36, ".\\crypto\\ec\\ec_mult.c", 140) <= 0 )
  {
    v1 = (ec_point_st **)*((_DWORD *)pre_ + 4);
    if ( v1 )
    {
      for ( i = *v1; i; ++v1 )
      {
        EC_POINT_free(i);
        i = v1[1];
      }
      CRYPTO_free(*((void **)pre_ + 4));
    }
    CRYPTO_free(pre_);
  }
}
