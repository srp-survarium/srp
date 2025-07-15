int __usercall pkey_dsa_ctrl@<eax>(int a1@<ebx>, evp_pkey_ctx_st *ctx, int type, int p1, ssl_st *p2)
{
  _DWORD *data; // edi
  ssl_st *v6; // esi

  data = ctx->data;
  if ( type <= 11 )
  {
    if ( type != 11 )
    {
      switch ( type )
      {
        case 1:
          v6 = p2;
          if ( EVP_CIPHER_CTX_cipher(p2) == 64
            || EVP_CIPHER_CTX_cipher(p2) == 116
            || EVP_CIPHER_CTX_cipher(p2) == 66
            || EVP_CIPHER_CTX_cipher(p2) == 675
            || EVP_CIPHER_CTX_cipher(p2) == 672 )
          {
            goto LABEL_10;
          }
          ERR_put_error(a1, 0xAu, 120, 106, ".\\crypto\\dsa\\dsa_pmeth.c", 194);
          break;
        case 2:
          ERR_put_error(a1, 0xAu, 120, 150, ".\\crypto\\dsa\\dsa_pmeth.c", 207);
          return -2;
        case 5:
        case 7:
          return 1;
        default:
          return -2;
      }
      return 0;
    }
    return 1;
  }
  if ( type != 4097 )
  {
    if ( type == 4098 )
    {
      if ( p1 == 160 || p1 == 224 || !p1 || p1 == 256 )
      {
        data[1] = p1;
        return 1;
      }
    }
    else if ( type == 4099 )
    {
      v6 = p2;
      if ( EVP_CIPHER_CTX_cipher(p2) == 64 || EVP_CIPHER_CTX_cipher(p2) == 675 || EVP_CIPHER_CTX_cipher(p2) == 672 )
      {
LABEL_10:
        data[5] = v6;
        return 1;
      }
      ERR_put_error(a1, 0xAu, 120, 106, ".\\crypto\\dsa\\dsa_pmeth.c", 181);
      return 0;
    }
    return -2;
  }
  if ( p1 < 256 )
    return -2;
  *data = p1;
  return 1;
}
