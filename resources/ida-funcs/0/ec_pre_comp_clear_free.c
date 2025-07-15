void __cdecl ec_pre_comp_clear_free(void *pre_)
{
  ec_point_st **v1; // esi
  ec_point_st *i; // eax

  if ( pre_ && CRYPTO_add_lock((int *)pre_ + 6, -1, 36, ".\\crypto\\ec\\ec_mult.c", 163) <= 0 )
  {
    v1 = (ec_point_st **)*((_DWORD *)pre_ + 4);
    if ( v1 )
    {
      for ( i = *v1; i; ++v1 )
      {
        EC_POINT_clear_free(i);
        OPENSSL_cleanse(v1, 4);
        i = v1[1];
      }
      CRYPTO_free(*((void **)pre_ + 4));
    }
    OPENSSL_cleanse(pre_, 28);
    CRYPTO_free(pre_);
  }
}
