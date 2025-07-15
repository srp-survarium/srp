dh_st *__cdecl DH_new_method(engine_st *engine)
{
  _DWORD *v1; // esi
  const dh_method *v3; // eax
  const dh_method *DH; // eax
  int v5; // ecx
  int (__cdecl *v6)(_DWORD *); // eax

  v1 = CRYPTO_malloc(76, ".\\crypto\\dh\\dh_lib.c", 111);
  if ( !v1 )
  {
    ERR_put_error(5u, 105, 65, ".\\crypto\\dh\\dh_lib.c", 114);
    return 0;
  }
  v3 = default_DH_method;
  if ( !default_DH_method )
  {
    v3 = DH_OpenSSL();
    default_DH_method = v3;
  }
  v1[17] = v3;
  if ( engine )
  {
    if ( !ENGINE_init(0, engine) )
    {
      ERR_put_error(5u, 105, 38, ".\\crypto\\dh\\dh_lib.c", 124);
      CRYPTO_free(v1);
      return 0;
    }
    v1[18] = engine;
  }
  else
  {
    v1[18] = ENGINE_get_default_DH();
  }
  if ( !v1[18] || (DH = ENGINE_get_DH((const engine_st *)v1[18]), (v1[17] = DH) != 0) )
  {
    v5 = v1[17];
    *v1 = 0;
    v1[1] = 0;
    v1[2] = 0;
    v1[3] = 0;
    v1[4] = 0;
    v1[5] = 0;
    v1[6] = 0;
    v1[9] = 0;
    v1[10] = 0;
    v1[11] = 0;
    v1[12] = 0;
    v1[13] = 0;
    v1[8] = 0;
    v1[14] = 1;
    v1[7] = *(_DWORD *)(v5 + 24);
    CRYPTO_new_ex_data(0);
    v6 = *(int (__cdecl **)(_DWORD *))(v1[17] + 16);
    if ( v6 && !v6(v1) )
    {
      if ( v1[18] )
        ENGINE_finish(0, (engine_st *)v1[18]);
      CRYPTO_free_ex_data(0);
      CRYPTO_free(v1);
      return 0;
    }
    return (dh_st *)v1;
  }
  else
  {
    ERR_put_error(5u, 105, 38, ".\\crypto\\dh\\dh_lib.c", 137);
    ENGINE_finish(0, (engine_st *)v1[18]);
    CRYPTO_free(v1);
    return 0;
  }
}
