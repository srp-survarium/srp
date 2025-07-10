dsa_st *__cdecl DSA_new_method(engine_st *engine)
{
  _DWORD *v1; // esi
  const dsa_method *v3; // eax
  bio_st *v4; // eax
  int v5; // ecx
  int (__cdecl *v6)(_DWORD *); // eax

  v1 = CRYPTO_malloc(68, ".\\crypto\\dsa\\dsa_lib.c", 117);
  if ( !v1 )
  {
    ERR_put_error(0xAu, 103, 65, ".\\crypto\\dsa\\dsa_lib.c", 120);
    return 0;
  }
  v3 = default_DSA_method;
  if ( !default_DSA_method )
  {
    v3 = DSA_OpenSSL();
    default_DSA_method = v3;
  }
  v1[15] = v3;
  if ( engine )
  {
    if ( !ENGINE_init(0, engine) )
    {
      ERR_put_error(0xAu, 103, 38, ".\\crypto\\dsa\\dsa_lib.c", 129);
      CRYPTO_free(v1);
      return 0;
    }
    v1[16] = engine;
  }
  else
  {
    v1[16] = ENGINE_get_default_DSA();
  }
  if ( !v1[16] || (v4 = EC_KEY_get0_private_key((const ssl_st *)v1[16]), (v1[15] = v4) != 0) )
  {
    v5 = v1[15];
    *v1 = 0;
    v1[1] = 0;
    v1[2] = 1;
    v1[3] = 0;
    v1[4] = 0;
    v1[5] = 0;
    v1[6] = 0;
    v1[7] = 0;
    v1[8] = 0;
    v1[9] = 0;
    v1[11] = 0;
    v1[12] = 1;
    v1[10] = *(_DWORD *)(v5 + 32);
    CRYPTO_new_ex_data(0);
    v6 = *(int (__cdecl **)(_DWORD *))(v1[15] + 24);
    if ( v6 && !v6(v1) )
    {
      if ( v1[16] )
        ENGINE_finish(0, (engine_st *)v1[16]);
      CRYPTO_free_ex_data(0);
      CRYPTO_free(v1);
      return 0;
    }
    return (dsa_st *)v1;
  }
  else
  {
    ERR_put_error(0xAu, 103, 38, ".\\crypto\\dsa\\dsa_lib.c", 143);
    ENGINE_finish(0, (engine_st *)v1[16]);
    CRYPTO_free(v1);
    return 0;
  }
}
