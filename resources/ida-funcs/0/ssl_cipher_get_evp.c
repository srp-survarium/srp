BOOL __cdecl ssl_cipher_get_evp(
        const ssl_session_st *s,
        const evp_cipher_st **enc,
        const env_md_st **md,
        int *mac_pkey_type,
        int *mac_secret_size,
        ssl_comp_st **comp)
{
  const ssl_cipher_st *cipher; // ebx
  int v8; // eax
  unsigned int algorithm_enc; // eax
  int v10; // eax
  int *v11; // ecx
  unsigned int v12[3]; // [esp+8h] [ebp-Ch] BYREF

  cipher = s->cipher;
  if ( !cipher )
    return 0;
  if ( comp )
  {
    load_builtin_compressions((int)s, (int)cipher);
    *comp = 0;
    v12[0] = s->compress_meth;
    if ( ssl_comp_methods )
    {
      v8 = sk_find((int)s, &ssl_comp_methods->stack, (char *)v12);
      if ( v8 < 0 )
        *comp = 0;
      else
        *comp = (ssl_comp_st *)sk_value(&ssl_comp_methods->stack, v8);
    }
  }
  if ( !enc || !md )
    return 0;
  algorithm_enc = cipher->algorithm_enc;
  if ( algorithm_enc > 0x40 )
  {
    if ( algorithm_enc > 0x200 )
    {
      if ( algorithm_enc == 1024 )
      {
        *enc = ssl_cipher_methods[10];
        goto LABEL_32;
      }
      if ( algorithm_enc == 2048 )
      {
        *enc = ssl_cipher_methods[11];
        goto LABEL_32;
      }
    }
    else
    {
      switch ( algorithm_enc )
      {
        case 0x200u:
          *enc = ssl_cipher_methods[9];
          goto LABEL_32;
        case 0x80u:
          *enc = ssl_cipher_methods[7];
          goto LABEL_32;
        case 0x100u:
          *enc = ssl_cipher_methods[8];
          goto LABEL_32;
      }
    }
LABEL_31:
    *enc = 0;
  }
  else if ( algorithm_enc == 64 )
  {
    *enc = ssl_cipher_methods[6];
  }
  else
  {
    switch ( algorithm_enc )
    {
      case 1u:
        *enc = ssl_cipher_methods[0];
        break;
      case 2u:
        *enc = ssl_cipher_methods[1];
        break;
      case 4u:
        *enc = ssl_cipher_methods[2];
        break;
      case 8u:
        *enc = ssl_cipher_methods[3];
        break;
      case 0x10u:
        *enc = ssl_cipher_methods[4];
        break;
      case 0x20u:
        *enc = EVP_enc_null();
        break;
      default:
        goto LABEL_31;
    }
  }
LABEL_32:
  switch ( cipher->algorithm_mac )
  {
    case 1u:
      v10 = 0;
      goto LABEL_37;
    case 2u:
      v10 = 1;
      goto LABEL_37;
    case 4u:
      v10 = 2;
      goto LABEL_37;
    case 8u:
      v10 = 3;
LABEL_37:
      v11 = mac_pkey_type;
      *md = ssl_digest_methods[v10];
      if ( mac_pkey_type )
        *mac_pkey_type = ssl_mac_pkey_id[v10];
      if ( mac_secret_size )
        *mac_secret_size = ssl_mac_secret_size[v10];
      break;
    default:
      v11 = mac_pkey_type;
      *md = 0;
      if ( mac_pkey_type )
        *mac_pkey_type = 0;
      if ( mac_secret_size )
        *mac_secret_size = 0;
      break;
  }
  return *enc && *md && (!v11 || *v11);
}
