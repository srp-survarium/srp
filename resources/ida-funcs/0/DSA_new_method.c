dsa_st *__usercall DSA_new_method@<eax>(int a1@<ebx>, engine_st *engine)
{
  _DWORD *v2; // esi
  const dsa_method *v4; // eax
  bio_st *v5; // eax
  int v6; // ecx
  int v7; // ebx
  int (__cdecl *v8)(_DWORD *); // eax

  v2 = CRYPTO_malloc(68, ".\\crypto\\dsa\\dsa_lib.c", 117);
  if ( !v2 )
  {
    ERR_put_error(a1, 0xAu, 103, 65, ".\\crypto\\dsa\\dsa_lib.c", 120);
    return 0;
  }
  v4 = default_DSA_method;
  if ( !default_DSA_method )
  {
    v4 = DSA_OpenSSL();
    default_DSA_method = v4;
  }
  v2[15] = v4;
  if ( engine )
  {
    if ( !ENGINE_init(0, (int)engine, engine) )
    {
      ERR_put_error((int)engine, 0xAu, 103, 38, ".\\crypto\\dsa\\dsa_lib.c", 129);
      CRYPTO_free(v2);
      return 0;
    }
    v2[16] = engine;
  }
  else
  {
    v2[16] = ENGINE_get_default_DSA();
  }
  if ( !v2[16] || (v5 = EC_KEY_get0_private_key((const ssl_st *)v2[16]), (v2[15] = v5) != 0) )
  {
    v6 = v2[15];
    v7 = (int)(v2 + 13);
    *v2 = 0;
    v2[1] = 0;
    v2[2] = 1;
    v2[3] = 0;
    v2[4] = 0;
    v2[5] = 0;
    v2[6] = 0;
    v2[7] = 0;
    v2[8] = 0;
    v2[9] = 0;
    v2[11] = 0;
    v2[12] = 1;
    v2[10] = *(_DWORD *)(v6 + 32);
    CRYPTO_new_ex_data(0, (int)(v2 + 13));
    v8 = *(int (__cdecl **)(_DWORD *))(v2[15] + 24);
    if ( v8 && !v8(v2) )
    {
      if ( v2[16] )
        ENGINE_finish(0, v7, (engine_st *)v2[16]);
      CRYPTO_free_ex_data(0, v7);
      CRYPTO_free(v2);
      return 0;
    }
    return (dsa_st *)v2;
  }
  else
  {
    ERR_put_error((int)engine, 0xAu, 103, 38, ".\\crypto\\dsa\\dsa_lib.c", 143);
    ENGINE_finish(0, (int)engine, (engine_st *)v2[16]);
    CRYPTO_free(v2);
    return 0;
  }
}
