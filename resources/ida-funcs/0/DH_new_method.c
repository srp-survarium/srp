dh_st *__usercall DH_new_method@<eax>(int a1@<ebx>, engine_st *engine)
{
  _DWORD *v2; // esi
  const dh_method *v4; // eax
  const dh_method *DH; // eax
  int v6; // ecx
  int v7; // ebx
  int (__cdecl *v8)(_DWORD *); // eax

  v2 = CRYPTO_malloc(76, ".\\crypto\\dh\\dh_lib.c", 111);
  if ( !v2 )
  {
    ERR_put_error(a1, 5u, 105, 65, ".\\crypto\\dh\\dh_lib.c", 114);
    return 0;
  }
  v4 = default_DH_method;
  if ( !default_DH_method )
  {
    v4 = DH_OpenSSL();
    default_DH_method = v4;
  }
  v2[17] = v4;
  if ( engine )
  {
    if ( !ENGINE_init(0, (int)engine, engine) )
    {
      ERR_put_error((int)engine, 5u, 105, 38, ".\\crypto\\dh\\dh_lib.c", 124);
      CRYPTO_free(v2);
      return 0;
    }
    v2[18] = engine;
  }
  else
  {
    v2[18] = ENGINE_get_default_DH();
  }
  if ( !v2[18] || (DH = ENGINE_get_DH((const engine_st *)v2[18]), (v2[17] = DH) != 0) )
  {
    v6 = v2[17];
    v7 = (int)(v2 + 15);
    *v2 = 0;
    v2[1] = 0;
    v2[2] = 0;
    v2[3] = 0;
    v2[4] = 0;
    v2[5] = 0;
    v2[6] = 0;
    v2[9] = 0;
    v2[10] = 0;
    v2[11] = 0;
    v2[12] = 0;
    v2[13] = 0;
    v2[8] = 0;
    v2[14] = 1;
    v2[7] = *(_DWORD *)(v6 + 24);
    CRYPTO_new_ex_data(0, (int)(v2 + 15));
    v8 = *(int (__cdecl **)(_DWORD *))(v2[17] + 16);
    if ( v8 && !v8(v2) )
    {
      if ( v2[18] )
        ENGINE_finish(0, v7, (engine_st *)v2[18]);
      CRYPTO_free_ex_data(0, v7);
      CRYPTO_free(v2);
      return 0;
    }
    return (dh_st *)v2;
  }
  else
  {
    ERR_put_error((int)engine, 5u, 105, 38, ".\\crypto\\dh\\dh_lib.c", 137);
    ENGINE_finish(0, (int)engine, (engine_st *)v2[18]);
    CRYPTO_free(v2);
    return 0;
  }
}
