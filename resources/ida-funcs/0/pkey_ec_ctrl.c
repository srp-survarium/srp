int __usercall pkey_ec_ctrl@<eax>(int a1@<ebx>, evp_pkey_ctx_st *ctx, int type, int p1, ssl_st *p2)
{
  ec_group_st **data; // edi
  int result; // eax
  ec_group_st *v7; // esi

  data = (ec_group_st **)ctx->data;
  if ( type > 11 )
  {
    if ( type != 4097 )
      return -2;
    v7 = EC_GROUP_new_by_curve_name(p1);
    if ( !v7 )
    {
      ERR_put_error(a1, 0x10u, 197, 141, ".\\crypto\\ec\\ec_pmeth.c", 214);
      return 0;
    }
    if ( *data )
      EC_GROUP_free(*data);
    *data = v7;
    return 1;
  }
  if ( type == 11 )
    return 1;
  switch ( type )
  {
    case 1:
      if ( EVP_CIPHER_CTX_cipher(p2) != 64
        && EVP_CIPHER_CTX_cipher(p2) != 675
        && EVP_CIPHER_CTX_cipher(p2) != 672
        && EVP_CIPHER_CTX_cipher(p2) != 673
        && EVP_CIPHER_CTX_cipher(p2) != 674 )
      {
        ERR_put_error(a1, 0x10u, 197, 138, ".\\crypto\\ec\\ec_pmeth.c", 229);
        return 0;
      }
      data[1] = (ec_group_st *)p2;
      result = 1;
      break;
    case 2:
    case 5:
    case 7:
      return 1;
    default:
      return -2;
  }
  return result;
}
