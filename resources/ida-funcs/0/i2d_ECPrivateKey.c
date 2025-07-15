int __usercall i2d_ECPrivateKey@<eax>(int a1@<ebx>, ec_key_st *a, unsigned __int8 **out)
{
  ec_privatekey_st *v4; // ebp
  unsigned int v5; // ebx
  unsigned __int8 *v6; // eax
  __m128i *v7; // edi
  ecpk_parameters_st *v8; // eax
  asn1_string_st *v9; // eax
  unsigned int v10; // eax
  __m128i *v11; // eax
  int v13; // [esp-Ch] [ebp-20h]
  int v14; // [esp+8h] [ebp-Ch]
  int v15; // [esp+Ch] [ebp-8h]
  unsigned int v16; // [esp+10h] [ebp-4h]
  __m128i *str; // [esp+18h] [ebp+4h]

  v15 = 0;
  v14 = 0;
  if ( !a || !a->group || !a->priv_key )
  {
    ERR_put_error(a1, 0x10u, 192, 67, ".\\crypto\\ec\\ec_asn1.c", 1220);
    return 0;
  }
  v4 = (ec_privatekey_st *)ASN1_item_new(&stru_6CFBF8);
  if ( v4 )
  {
    v4->version = a->version;
    v5 = (BN_num_bits(a->priv_key) + 7) / 8;
    v6 = (unsigned __int8 *)CRYPTO_malloc(v5, ".\\crypto\\ec\\ec_asn1.c", 1234);
    v7 = (__m128i *)v6;
    str = (__m128i *)v6;
    if ( !v6 )
    {
      ERR_put_error(v5, 0x10u, 192, 65, ".\\crypto\\ec\\ec_asn1.c", 1238);
      goto err_60;
    }
    if ( !BN_bn2bin(a->priv_key, v6) )
    {
      ERR_put_error(v5, 0x10u, 192, 3, ".\\crypto\\ec\\ec_asn1.c", 1244);
      goto err_60;
    }
    if ( !ASN1_STRING_set(v4->privateKey, v7, v5) )
    {
      ERR_put_error(v5, 0x10u, 192, 13, ".\\crypto\\ec\\ec_asn1.c", 1250);
      goto err_60;
    }
    if ( (a->enc_flag & 1) == 0 )
    {
      v8 = ec_asn1_group2pkparameters((const ssl_st *)a->group, v4->parameters, v5);
      v4->parameters = v8;
      if ( !v8 )
      {
        ERR_put_error(v5, 0x10u, 192, 16, ".\\crypto\\ec\\ec_asn1.c", 1259);
        v7 = str;
        goto err_60;
      }
      v7 = str;
    }
    if ( (a->enc_flag & 2) != 0 )
      goto LABEL_33;
    v9 = ASN1_STRING_type_new(v5, 3);
    v4->publicKey = v9;
    if ( !v9 )
    {
      ERR_put_error(v5, 0x10u, 192, 65, ".\\crypto\\ec\\ec_asn1.c", 1270);
      goto err_60;
    }
    v10 = EC_POINT_point2oct(a->group, a->pub_key, a->conv_form, 0, 0, 0);
    v16 = v10;
    if ( v10 > v5 )
    {
      v11 = (__m128i *)CRYPTO_realloc(v7, v10, ".\\crypto\\ec\\ec_asn1.c", 1279);
      if ( !v11 )
      {
        ERR_put_error(v5, 0x10u, 192, 65, ".\\crypto\\ec\\ec_asn1.c", 1282);
        goto err_60;
      }
      v5 = v16;
      v7 = v11;
    }
    if ( !EC_POINT_point2oct(a->group, a->pub_key, a->conv_form, (unsigned __int8 *)v7, v5, 0) )
    {
      v13 = 1292;
LABEL_25:
      ERR_put_error(v5, 0x10u, 192, 16, ".\\crypto\\ec\\ec_asn1.c", v13);
      goto err_60;
    }
    v4->publicKey->flags &= 0xFFFFFFF0;
    v4->publicKey->flags |= 8u;
    if ( ASN1_STRING_set(v4->publicKey, v7, v5) )
    {
LABEL_33:
      v15 = i2d_EC_PRIVATEKEY(v4, out);
      if ( !v15 )
      {
        v13 = 1308;
        goto LABEL_25;
      }
      v14 = 1;
    }
    else
    {
      ERR_put_error(v5, 0x10u, 192, 13, ".\\crypto\\ec\\ec_asn1.c", 1301);
    }
err_60:
    if ( v7 )
      CRYPTO_free(v7);
    goto LABEL_28;
  }
  ERR_put_error(a1, 0x10u, 192, 65, ".\\crypto\\ec\\ec_asn1.c", 1227);
LABEL_28:
  if ( v4 )
    ASN1_item_free((struct ASN1_VALUE_st *)v4, &stru_6CFBF8);
  return v14 != 0 ? v15 : 0;
}
