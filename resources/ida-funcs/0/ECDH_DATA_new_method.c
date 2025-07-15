ecdh_data_st *__usercall ECDH_DATA_new_method@<eax>(engine_st *engine@<edi>, int a2@<ebx>)
{
  void *v2; // esi
  const ecdh_method *v4; // eax
  const ecdh_method *conv_form; // eax

  v2 = CRYPTO_malloc(24, ".\\crypto\\ecdh\\ech_lib.c", 130);
  if ( v2 )
  {
    v4 = default_ECDH_method;
    *(_DWORD *)v2 = 0;
    if ( !v4 )
    {
      v4 = ECDH_OpenSSL();
      default_ECDH_method = v4;
    }
    *((_DWORD *)v2 + 3) = v4;
    *((_DWORD *)v2 + 1) = engine;
    if ( !engine )
      *((_DWORD *)v2 + 1) = ENGINE_get_default_ECDH();
    if ( !*((_DWORD *)v2 + 1)
      || (conv_form = EC_KEY_get_conv_form(*((const engine_st **)v2 + 1)), (*((_DWORD *)v2 + 3) = conv_form) != 0) )
    {
      *((_DWORD *)v2 + 2) = *(_DWORD *)(*((_DWORD *)v2 + 3) + 8);
      CRYPTO_new_ex_data((int)engine, a2);
      return (ecdh_data_st *)v2;
    }
    else
    {
      ERR_put_error(a2, 0x2Bu, 101, 38, ".\\crypto\\ecdh\\ech_lib.c", 149);
      ENGINE_finish((int)engine, a2, *((engine_st **)v2 + 1));
      CRYPTO_free(v2);
      return 0;
    }
  }
  else
  {
    ERR_put_error(a2, 0x2Bu, 101, 65, ".\\crypto\\ecdh\\ech_lib.c", 133);
    return 0;
  }
}
