ecdh_data_st *__usercall ECDH_DATA_new_method@<eax>(engine_st *engine@<edi>)
{
  void *v1; // esi
  const ecdh_method *v3; // eax
  const ecdh_method *conv_form; // eax

  v1 = CRYPTO_malloc(24, ".\\crypto\\ecdh\\ech_lib.c", 130);
  if ( v1 )
  {
    v3 = default_ECDH_method;
    *(_DWORD *)v1 = 0;
    if ( !v3 )
    {
      v3 = ECDH_OpenSSL();
      default_ECDH_method = v3;
    }
    *((_DWORD *)v1 + 3) = v3;
    *((_DWORD *)v1 + 1) = engine;
    if ( !engine )
      *((_DWORD *)v1 + 1) = ENGINE_get_default_ECDH();
    if ( !*((_DWORD *)v1 + 1)
      || (conv_form = EC_KEY_get_conv_form(*((const engine_st **)v1 + 1)), (*((_DWORD *)v1 + 3) = conv_form) != 0) )
    {
      *((_DWORD *)v1 + 2) = *(_DWORD *)(*((_DWORD *)v1 + 3) + 8);
      CRYPTO_new_ex_data((unsigned int)engine);
      return (ecdh_data_st *)v1;
    }
    else
    {
      ERR_put_error(0x2Bu, 101, 38, ".\\crypto\\ecdh\\ech_lib.c", 149);
      ENGINE_finish((unsigned int)engine, *((engine_st **)v1 + 1));
      CRYPTO_free(v1);
      return 0;
    }
  }
  else
  {
    ERR_put_error(0x2Bu, 101, 65, ".\\crypto\\ecdh\\ech_lib.c", 133);
    return 0;
  }
}
