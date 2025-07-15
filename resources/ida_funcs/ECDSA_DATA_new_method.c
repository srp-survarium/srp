ecdsa_data_st *__usercall ECDSA_DATA_new_method@<eax>(engine_st *engine@<edi>)
{
  void *v1; // esi
  const ecdsa_method *v3; // eax
  const ecdsa_method *ECDSA; // eax

  v1 = CRYPTO_malloc(24, ".\\crypto\\ecdsa\\ecs_lib.c", 109);
  if ( v1 )
  {
    v3 = default_ECDSA_method;
    *(_DWORD *)v1 = 0;
    if ( !v3 )
    {
      v3 = ECDSA_OpenSSL();
      default_ECDSA_method = v3;
    }
    *((_DWORD *)v1 + 3) = v3;
    *((_DWORD *)v1 + 1) = engine;
    if ( !engine )
      *((_DWORD *)v1 + 1) = ENGINE_get_default_ECDSA();
    if ( !*((_DWORD *)v1 + 1)
      || (ECDSA = ENGINE_get_ECDSA(*((const engine_st **)v1 + 1)), (*((_DWORD *)v1 + 3) = ECDSA) != 0) )
    {
      *((_DWORD *)v1 + 2) = *(_DWORD *)(*((_DWORD *)v1 + 3) + 16);
      CRYPTO_new_ex_data((unsigned int)engine);
      return (ecdsa_data_st *)v1;
    }
    else
    {
      ERR_put_error(0x2Au, 100, 38, ".\\crypto\\ecdsa\\ecs_lib.c", 128);
      ENGINE_finish((unsigned int)engine, *((engine_st **)v1 + 1));
      CRYPTO_free(v1);
      return 0;
    }
  }
  else
  {
    ERR_put_error(0x2Au, 100, 65, ".\\crypto\\ecdsa\\ecs_lib.c", 112);
    return 0;
  }
}
