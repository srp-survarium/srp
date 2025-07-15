ecdsa_data_st *__usercall ECDSA_DATA_new_method@<eax>(engine_st *engine@<edi>, int a2@<ebx>)
{
  void *v2; // esi
  const ecdsa_method *v4; // eax
  const ecdsa_method *ECDSA; // eax

  v2 = CRYPTO_malloc(24, ".\\crypto\\ecdsa\\ecs_lib.c", 109);
  if ( v2 )
  {
    v4 = default_ECDSA_method;
    *(_DWORD *)v2 = 0;
    if ( !v4 )
    {
      v4 = ECDSA_OpenSSL();
      default_ECDSA_method = v4;
    }
    *((_DWORD *)v2 + 3) = v4;
    *((_DWORD *)v2 + 1) = engine;
    if ( !engine )
      *((_DWORD *)v2 + 1) = ENGINE_get_default_ECDSA();
    if ( !*((_DWORD *)v2 + 1)
      || (ECDSA = ENGINE_get_ECDSA(*((const engine_st **)v2 + 1)), (*((_DWORD *)v2 + 3) = ECDSA) != 0) )
    {
      *((_DWORD *)v2 + 2) = *(_DWORD *)(*((_DWORD *)v2 + 3) + 16);
      CRYPTO_new_ex_data((int)engine, a2);
      return (ecdsa_data_st *)v2;
    }
    else
    {
      ERR_put_error(a2, 0x2Au, 100, 38, ".\\crypto\\ecdsa\\ecs_lib.c", 128);
      ENGINE_finish((int)engine, a2, *((engine_st **)v2 + 1));
      CRYPTO_free(v2);
      return 0;
    }
  }
  else
  {
    ERR_put_error(a2, 0x2Au, 100, 65, ".\\crypto\\ecdsa\\ecs_lib.c", 112);
    return 0;
  }
}
