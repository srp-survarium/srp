int __usercall eckey_priv_decode@<eax>(int a1@<ebx>, evp_pkey_st *pkey, pkcs8_priv_key_info_st *p8)
{
  int result; // eax
  const ec_group_st *v4; // edi
  ec_point_st *v5; // esi
  const ec_point_st *v6; // eax
  const bignum_st *v7; // eax
  engine_st *e; // [esp+0h] [ebp-18h] BYREF
  unsigned __int8 *pk; // [esp+4h] [ebp-14h] BYREF
  X509_algor_st *pa; // [esp+8h] [ebp-10h] BYREF
  int v11; // [esp+Ch] [ebp-Ch] BYREF
  const asn1_object_st *v12; // [esp+10h] [ebp-8h] BYREF
  int ppklen; // [esp+14h] [ebp-4h] BYREF

  pk = 0;
  e = 0;
  result = PKCS8_pkey_get0(0, (const unsigned __int8 **)&pk, &ppklen, &pa, p8);
  if ( !result )
    return result;
  X509_ALGOR_get0(0, &v11, (char **)&v12, pa);
  e = (engine_st *)eckey_type2param(v12, a1, v11);
  if ( !e )
    goto ecliberr;
  if ( d2i_ECPrivateKey(a1, (ec_key_st **)&e, &pk, (const unsigned __int8 **)ppklen) )
  {
    if ( !EC_KEY_get0_public_key(e) )
    {
      v4 = (const ec_group_st *)EVP_CIPHER_block_size((const env_md_st *)e);
      v5 = EC_POINT_new(v4);
      if ( !v5 )
      {
        ERR_put_error(a1, 0x10u, 213, 16, ".\\crypto\\ec\\ec_ameth.c", 276);
ecliberr:
        ERR_put_error(a1, 0x10u, 213, 16, ".\\crypto\\ec\\ec_ameth.c", 305);
        goto LABEL_15;
      }
      v6 = (const ec_point_st *)EVP_CIPHER_block_size((const env_md_st *)v4);
      if ( !EC_POINT_copy(v5, v6) )
      {
        EC_POINT_free(v5);
        ERR_put_error(a1, 0x10u, 213, 16, ".\\crypto\\ec\\ec_ameth.c", 282);
        goto ecliberr;
      }
      v7 = (const bignum_st *)EC_KEY_get0_private_key((const ssl_st *)e);
      if ( !EC_POINT_mul(v4, v5, v7, 0, 0, 0) )
      {
        EC_POINT_free(v5);
        ERR_put_error(a1, 0x10u, 213, 16, ".\\crypto\\ec\\ec_ameth.c", 289);
        goto ecliberr;
      }
      if ( !EC_KEY_set_public_key((ec_key_st *)e, v5) )
      {
        EC_POINT_free(v5);
        ERR_put_error(a1, 0x10u, 213, 16, ".\\crypto\\ec\\ec_ameth.c", 295);
        goto ecliberr;
      }
      EC_POINT_free(v5);
    }
    EVP_PKEY_assign(pkey, (void *)0x198, (char *)e);
    return 1;
  }
  ERR_put_error(a1, 0x10u, 213, 142, ".\\crypto\\ec\\ec_ameth.c", 260);
LABEL_15:
  if ( e )
    EC_KEY_free((ec_key_st *)e);
  return 0;
}
