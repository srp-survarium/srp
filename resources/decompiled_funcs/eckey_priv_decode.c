int __cdecl eckey_priv_decode(evp_pkey_st *pkey, pkcs8_priv_key_info_st *p8)
{
  int result; // eax
  const ec_group_st *v3; // edi
  ec_point_st *v4; // esi
  const ec_point_st *v5; // eax
  const bignum_st *v6; // eax
  ec_key_st *a; // [esp+0h] [ebp-18h] BYREF
  unsigned __int8 *pk; // [esp+4h] [ebp-14h] BYREF
  X509_algor_st *pa; // [esp+8h] [ebp-10h] BYREF
  int pptype; // [esp+Ch] [ebp-Ch] BYREF
  void *ppval; // [esp+10h] [ebp-8h] BYREF
  int ppklen; // [esp+14h] [ebp-4h] BYREF

  pk = 0;
  a = 0;
  result = PKCS8_pkey_get0(0, (const unsigned __int8 **)&pk, &ppklen, &pa, p8);
  if ( !result )
    return result;
  X509_ALGOR_get0(0, &pptype, &ppval, pa);
  a = eckey_type2param((const unsigned __int8 *)pptype);
  if ( !a )
    goto ecliberr;
  if ( d2i_ECPrivateKey(&a, &pk, (unsigned __int8 *)ppklen) )
  {
    if ( !EC_KEY_get0_public_key((const engine_st *)a) )
    {
      v3 = (const ec_group_st *)EVP_CIPHER_block_size((const env_md_st *)a);
      v4 = EC_POINT_new(v3);
      if ( !v4 )
      {
        ERR_put_error(0x10u, 213, 16, ".\\crypto\\ec\\ec_ameth.c", 276);
ecliberr:
        ERR_put_error(0x10u, 213, 16, ".\\crypto\\ec\\ec_ameth.c", 305);
        goto LABEL_15;
      }
      v5 = (const ec_point_st *)EVP_CIPHER_block_size((const env_md_st *)v3);
      if ( !EC_POINT_copy(v4, v5) )
      {
        EC_POINT_free(v4);
        ERR_put_error(0x10u, 213, 16, ".\\crypto\\ec\\ec_ameth.c", 282);
        goto ecliberr;
      }
      v6 = (const bignum_st *)EC_KEY_get0_private_key((const ssl_st *)a);
      if ( !EC_POINT_mul(v3, v4, v6, 0, 0, 0) )
      {
        EC_POINT_free(v4);
        ERR_put_error(0x10u, 213, 16, ".\\crypto\\ec\\ec_ameth.c", 289);
        goto ecliberr;
      }
      if ( !EC_KEY_set_public_key(a, v4) )
      {
        EC_POINT_free(v4);
        ERR_put_error(0x10u, 213, 16, ".\\crypto\\ec\\ec_ameth.c", 295);
        goto ecliberr;
      }
      EC_POINT_free(v4);
    }
    EVP_PKEY_assign(pkey, 408, (char *)a);
    return 1;
  }
  ERR_put_error(0x10u, 213, 142, ".\\crypto\\ec\\ec_ameth.c", 260);
LABEL_15:
  if ( a )
    EC_KEY_free(a);
  return 0;
}
