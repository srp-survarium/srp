rsa_st *__cdecl RSA_new_method(engine_st *engine)
{
  _DWORD *v1; // esi
  const rsa_meth_st *v3; // eax
  const rsa_meth_st *v4; // eax
  int v5; // ecx
  int (__cdecl *v6)(_DWORD *); // eax

  v1 = CRYPTO_malloc(88, ".\\crypto\\rsa\\rsa_lib.c", 132);
  if ( !v1 )
  {
    ERR_put_error(4u, 106, 65, ".\\crypto\\rsa\\rsa_lib.c", 135);
    return 0;
  }
  v3 = default_RSA_meth;
  if ( !default_RSA_meth )
  {
    v3 = RSA_PKCS1_SSLeay();
    default_RSA_meth = v3;
  }
  v1[2] = v3;
  if ( engine )
  {
    if ( !ENGINE_init(0, engine) )
    {
      ERR_put_error(4u, 106, 38, ".\\crypto\\rsa\\rsa_lib.c", 145);
      CRYPTO_free(v1);
      return 0;
    }
    v1[3] = engine;
  }
  else
  {
    v1[3] = ENGINE_get_default_RSA();
  }
  if ( !v1[3] || (v4 = EC_KEY_get0_public_key((const engine_st *)v1[3]), (v1[2] = v4) != 0) )
  {
    v5 = v1[2];
    *v1 = 0;
    v1[1] = 0;
    v1[4] = 0;
    v1[5] = 0;
    v1[6] = 0;
    v1[7] = 0;
    v1[8] = 0;
    v1[9] = 0;
    v1[10] = 0;
    v1[11] = 0;
    v1[14] = 1;
    v1[16] = 0;
    v1[17] = 0;
    v1[18] = 0;
    v1[20] = 0;
    v1[21] = 0;
    v1[19] = 0;
    v1[15] = *(_DWORD *)(v5 + 36);
    if ( CRYPTO_new_ex_data(0) )
    {
      v6 = *(int (__cdecl **)(_DWORD *))(v1[2] + 28);
      if ( v6 && !v6(v1) )
      {
        if ( v1[3] )
          ENGINE_finish(0, (engine_st *)v1[3]);
        CRYPTO_free_ex_data(0);
        CRYPTO_free(v1);
        return 0;
      }
      return (rsa_st *)v1;
    }
    else
    {
      if ( v1[3] )
        ENGINE_finish(0, (engine_st *)v1[3]);
      CRYPTO_free(v1);
      return 0;
    }
  }
  else
  {
    ERR_put_error(4u, 106, 38, ".\\crypto\\rsa\\rsa_lib.c", 159);
    ENGINE_finish(0, (engine_st *)v1[3]);
    CRYPTO_free(v1);
    return 0;
  }
}
