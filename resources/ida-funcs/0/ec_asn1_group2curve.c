int __cdecl ec_asn1_group2curve(ssl_st *group, x9_62_curve_st *curve)
{
  bignum_st *v2; // ebx
  const ssl_st *v3; // eax
  int v4; // kr00_4
  int v5; // edi
  int v6; // ebx
  void *v7; // eax
  void *v8; // esi
  char *v10; // edi
  int v11; // esi
  asn1_string_st *v12; // eax
  char *v13; // eax
  int v14; // [esp-8h] [ebp-30h]
  char v15; // [esp+Fh] [ebp-19h] BYREF
  bignum_st *b; // [esp+10h] [ebp-18h]
  void *_data; // [esp+14h] [ebp-14h]
  void *str; // [esp+18h] [ebp-10h]
  void *v19; // [esp+1Ch] [ebp-Ch]
  bignum_st *v20; // [esp+20h] [ebp-8h]
  int v21; // [esp+24h] [ebp-4h]

  v21 = 0;
  b = 0;
  str = 0;
  v19 = 0;
  v15 = 0;
  if ( !group || !curve || !curve->a || !curve->b )
    return 0;
  v2 = BN_new();
  v20 = v2;
  if ( v2 && (b = BN_new()) != 0 )
  {
    v3 = (const ssl_st *)EVP_CIPHER_CTX_cipher(group);
    if ( EVP_CIPHER_CTX_cipher(v3) == 406 )
    {
      if ( !EC_GROUP_get_curve_GFp((const ec_group_st *)group, 0, v2, b, 0) )
      {
        ERR_put_error(0x10u, 153, 16, ".\\crypto\\ec\\ec_asn1.c", 455);
        goto LABEL_25;
      }
LABEL_13:
      v4 = BN_num_bits(v2) + 7;
      v5 = (BN_num_bits(b) + 7) / 8;
      if ( v4 / 8 )
      {
        v7 = CRYPTO_malloc(v4 / 8, ".\\crypto\\ec\\ec_asn1.c", 479);
        v8 = v7;
        str = v7;
        if ( !v7 )
        {
          ERR_put_error(0x10u, 153, 65, ".\\crypto\\ec\\ec_asn1.c", 482);
err_57:
          if ( str )
            CRYPTO_free(str);
          if ( v19 )
            CRYPTO_free(v19);
          v2 = v20;
          goto LABEL_25;
        }
        v6 = BN_bn2bin(v2, (unsigned __int8 *)v7);
        if ( !v6 )
        {
          v14 = 487;
LABEL_19:
          ERR_put_error(0x10u, 153, 3, ".\\crypto\\ec\\ec_asn1.c", v14);
          goto err_57;
        }
        _data = v8;
      }
      else
      {
        _data = &v15;
        v6 = 1;
      }
      if ( !v5 )
      {
        v10 = &v15;
        v11 = 1;
        goto LABEL_33;
      }
      v13 = (char *)CRYPTO_malloc(v5, ".\\crypto\\ec\\ec_asn1.c", 501);
      v10 = v13;
      v19 = v13;
      if ( !v13 )
      {
        ERR_put_error(0x10u, 153, 65, ".\\crypto\\ec\\ec_asn1.c", 504);
        goto err_57;
      }
      v11 = BN_bn2bin(b, (unsigned __int8 *)v13);
      if ( v11 )
      {
LABEL_33:
        if ( !ASN1_STRING_set(curve->a, (char *)_data, v6) || !ASN1_STRING_set(curve->b, v10, v11) )
        {
          ERR_put_error(0x10u, 153, 13, ".\\crypto\\ec\\ec_asn1.c", 519);
          goto err_57;
        }
        if ( group->init_buf )
        {
          if ( !curve->seed )
          {
            v12 = ASN1_BIT_STRING_new();
            curve->seed = v12;
            if ( !v12 )
            {
              ERR_put_error(0x10u, 153, 65, ".\\crypto\\ec\\ec_asn1.c", 529);
              goto err_57;
            }
          }
          curve->seed->flags &= 0xFFFFFFF0;
          curve->seed->flags |= 8u;
          if ( !ASN1_OCTET_STRING_set(curve->seed, (const unsigned __int8 *)group->init_buf, (int)group->init_msg) )
          {
            ERR_put_error(0x10u, 153, 13, ".\\crypto\\ec\\ec_asn1.c", 537);
            goto err_57;
          }
        }
        else if ( curve->seed )
        {
          ASN1_BIT_STRING_free(curve->seed);
          curve->seed = 0;
        }
        v21 = 1;
        goto err_57;
      }
      v14 = 509;
      goto LABEL_19;
    }
    if ( EC_GROUP_get_curve_GF2m((const ec_group_st *)group, 0, v2, b, 0) )
      goto LABEL_13;
    ERR_put_error(0x10u, 153, 16, ".\\crypto\\ec\\ec_asn1.c", 463);
  }
  else
  {
    ERR_put_error(0x10u, 153, 65, ".\\crypto\\ec\\ec_asn1.c", 444);
  }
LABEL_25:
  if ( v2 )
    BN_free(v2);
  if ( b )
    BN_free(b);
  return v21;
}
