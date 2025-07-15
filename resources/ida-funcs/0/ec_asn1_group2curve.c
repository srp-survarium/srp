int __usercall ec_asn1_group2curve@<eax>(int a1@<ebx>, ssl_st *group, x9_62_curve_st *curve)
{
  bignum_st *v3; // ebx
  const ssl_st *v4; // eax
  int v5; // kr00_4
  int v6; // edi
  int v7; // ebx
  __m128i *v8; // eax
  const __m128i *v9; // esi
  const __m128i *v11; // edi
  int v12; // esi
  asn1_string_st *v13; // eax
  __m128i *v14; // eax
  int v15; // [esp-8h] [ebp-30h]
  char v16; // [esp+Fh] [ebp-19h] BYREF
  bignum_st *b; // [esp+10h] [ebp-18h]
  const __m128i *v18; // [esp+14h] [ebp-14h]
  void *str; // [esp+18h] [ebp-10h]
  void *v20; // [esp+1Ch] [ebp-Ch]
  bignum_st *v21; // [esp+20h] [ebp-8h]
  int v22; // [esp+24h] [ebp-4h]

  v22 = 0;
  b = 0;
  str = 0;
  v20 = 0;
  v16 = 0;
  if ( !group || !curve || !curve->a || !curve->b )
    return 0;
  v3 = BN_new(a1);
  v21 = v3;
  if ( v3 && (b = BN_new((int)v3)) != 0 )
  {
    v4 = (const ssl_st *)EVP_CIPHER_CTX_cipher(group);
    if ( EVP_CIPHER_CTX_cipher(v4) == 406 )
    {
      if ( !EC_GROUP_get_curve_GFp((const ec_group_st *)group) )
      {
        ERR_put_error((int)v3, 0x10u, 153, 16, ".\\crypto\\ec\\ec_asn1.c", 455);
        goto LABEL_25;
      }
LABEL_13:
      v5 = BN_num_bits(v3) + 7;
      v6 = (BN_num_bits(b) + 7) / 8;
      if ( v5 / 8 )
      {
        v8 = (__m128i *)CRYPTO_malloc(v5 / 8, ".\\crypto\\ec\\ec_asn1.c", 479);
        v9 = v8;
        str = v8;
        if ( !v8 )
        {
          ERR_put_error((int)v3, 0x10u, 153, 65, ".\\crypto\\ec\\ec_asn1.c", 482);
err_59:
          if ( str )
            CRYPTO_free(str);
          if ( v20 )
            CRYPTO_free(v20);
          v3 = v21;
          goto LABEL_25;
        }
        v7 = BN_bn2bin(v3, (unsigned __int8 *)v8);
        if ( !v7 )
        {
          v15 = 487;
LABEL_19:
          ERR_put_error(v7, 0x10u, 153, 3, ".\\crypto\\ec\\ec_asn1.c", v15);
          goto err_59;
        }
        v18 = v9;
      }
      else
      {
        v18 = (const __m128i *)&v16;
        v7 = 1;
      }
      if ( !v6 )
      {
        v11 = (const __m128i *)&v16;
        v12 = 1;
        goto LABEL_33;
      }
      v14 = (__m128i *)CRYPTO_malloc(v6, ".\\crypto\\ec\\ec_asn1.c", 501);
      v11 = v14;
      v20 = v14;
      if ( !v14 )
      {
        ERR_put_error(v7, 0x10u, 153, 65, ".\\crypto\\ec\\ec_asn1.c", 504);
        goto err_59;
      }
      v12 = BN_bn2bin(b, (unsigned __int8 *)v14);
      if ( v12 )
      {
LABEL_33:
        if ( !ASN1_STRING_set(curve->a, v18, v7) || !ASN1_STRING_set(curve->b, v11, v12) )
        {
          ERR_put_error(v7, 0x10u, 153, 13, ".\\crypto\\ec\\ec_asn1.c", 519);
          goto err_59;
        }
        if ( group->init_buf )
        {
          if ( !curve->seed )
          {
            v13 = ASN1_BIT_STRING_new();
            curve->seed = v13;
            if ( !v13 )
            {
              ERR_put_error(v7, 0x10u, 153, 65, ".\\crypto\\ec\\ec_asn1.c", 529);
              goto err_59;
            }
          }
          curve->seed->flags &= 0xFFFFFFF0;
          curve->seed->flags |= 8u;
          if ( !ASN1_OCTET_STRING_set(curve->seed, (unsigned __int8 *)group->init_buf, (int)group->init_msg) )
          {
            ERR_put_error(v7, 0x10u, 153, 13, ".\\crypto\\ec\\ec_asn1.c", 537);
            goto err_59;
          }
        }
        else if ( curve->seed )
        {
          ASN1_BIT_STRING_free(curve->seed);
          curve->seed = 0;
        }
        v22 = 1;
        goto err_59;
      }
      v15 = 509;
      goto LABEL_19;
    }
    if ( EC_GROUP_get_curve_GF2m((const ec_group_st *)group) )
      goto LABEL_13;
    ERR_put_error((int)v3, 0x10u, 153, 16, ".\\crypto\\ec\\ec_asn1.c", 463);
  }
  else
  {
    ERR_put_error((int)v3, 0x10u, 153, 65, ".\\crypto\\ec\\ec_asn1.c", 444);
  }
LABEL_25:
  if ( v3 )
    BN_free(v3);
  if ( b )
    BN_free(b);
  return v22;
}
