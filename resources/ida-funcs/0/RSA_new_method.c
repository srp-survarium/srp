rsa_st *__usercall RSA_new_method@<eax>(int a1@<ebx>, engine_st *engine)
{
  _DWORD *v2; // esi
  const rsa_meth_st *v4; // eax
  const rsa_meth_st *v5; // eax
  int v6; // ecx
  int v7; // ebx
  int (__cdecl *v8)(_DWORD *); // eax

  v2 = CRYPTO_malloc(88, ".\\crypto\\rsa\\rsa_lib.c", 132);
  if ( !v2 )
  {
    ERR_put_error(a1, 4u, 106, 65, ".\\crypto\\rsa\\rsa_lib.c", 135);
    return 0;
  }
  v4 = default_RSA_meth;
  if ( !default_RSA_meth )
  {
    v4 = RSA_PKCS1_SSLeay();
    default_RSA_meth = v4;
  }
  v2[2] = v4;
  if ( engine )
  {
    if ( !ENGINE_init(0, (int)engine, engine) )
    {
      ERR_put_error((int)engine, 4u, 106, 38, ".\\crypto\\rsa\\rsa_lib.c", 145);
      CRYPTO_free(v2);
      return 0;
    }
    v2[3] = engine;
  }
  else
  {
    v2[3] = ENGINE_get_default_RSA();
  }
  if ( !v2[3] || (v5 = EC_KEY_get0_public_key((const engine_st *)v2[3]), (v2[2] = v5) != 0) )
  {
    v6 = v2[2];
    v7 = (int)(v2 + 12);
    *v2 = 0;
    v2[1] = 0;
    v2[4] = 0;
    v2[5] = 0;
    v2[6] = 0;
    v2[7] = 0;
    v2[8] = 0;
    v2[9] = 0;
    v2[10] = 0;
    v2[11] = 0;
    v2[14] = 1;
    v2[16] = 0;
    v2[17] = 0;
    v2[18] = 0;
    v2[20] = 0;
    v2[21] = 0;
    v2[19] = 0;
    v2[15] = *(_DWORD *)(v6 + 36);
    if ( CRYPTO_new_ex_data(0, (int)(v2 + 12)) )
    {
      v8 = *(int (__cdecl **)(_DWORD *))(v2[2] + 28);
      if ( v8 && !v8(v2) )
      {
        if ( v2[3] )
          ENGINE_finish(0, v7, (engine_st *)v2[3]);
        CRYPTO_free_ex_data(0, v7);
        CRYPTO_free(v2);
        return 0;
      }
      return (rsa_st *)v2;
    }
    else
    {
      if ( v2[3] )
        ENGINE_finish(0, v7, (engine_st *)v2[3]);
      CRYPTO_free(v2);
      return 0;
    }
  }
  else
  {
    ERR_put_error((int)engine, 4u, 106, 38, ".\\crypto\\rsa\\rsa_lib.c", 159);
    ENGINE_finish(0, (int)engine, (engine_st *)v2[3]);
    CRYPTO_free(v2);
    return 0;
  }
}
