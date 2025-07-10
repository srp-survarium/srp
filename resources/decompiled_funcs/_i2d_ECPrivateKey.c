int __cdecl i2d_ECPrivateKey(ec_key_st *a, unsigned __int8 **out)
{
  ec_privatekey_st *v3; // ebp
  unsigned int v4; // ebx
  unsigned __int8 *v5; // eax
  char *v6; // edi
  ecpk_parameters_st *v7; // eax
  asn1_string_st *v8; // eax
  unsigned int v9; // eax
  char *v10; // eax
  int v12; // [esp-Ch] [ebp-20h]
  int v13; // [esp+8h] [ebp-Ch]
  int v14; // [esp+Ch] [ebp-8h]
  unsigned int v15; // [esp+10h] [ebp-4h]
  unsigned __int8 *str; // [esp+18h] [ebp+4h]

  v14 = 0;
  v13 = 0;
  if ( !a || !a->group || !a->priv_key )
  {
    ERR_put_error(0x10u, 192, 67, ".\\crypto\\ec\\ec_asn1.c", 1220);
    return 0;
  }
  v3 = (ec_privatekey_st *)ASN1_item_new(&stru_83DF50);
  if ( v3 )
  {
    v3->version = a->version;
    v4 = (BN_num_bits(a->priv_key) + 7) / 8;
    v5 = (unsigned __int8 *)CRYPTO_malloc(v4, ".\\crypto\\ec\\ec_asn1.c", 1234);
    v6 = (char *)v5;
    str = v5;
    if ( !v5 )
    {
      ERR_put_error(0x10u, 192, 65, ".\\crypto\\ec\\ec_asn1.c", 1238);
      goto err_58;
    }
    if ( !BN_bn2bin(a->priv_key, v5) )
    {
      ERR_put_error(0x10u, 192, 3, ".\\crypto\\ec\\ec_asn1.c", 1244);
      goto err_58;
    }
    if ( !ASN1_STRING_set(v3->privateKey, v6, v4) )
    {
      ERR_put_error(0x10u, 192, 13, ".\\crypto\\ec\\ec_asn1.c", 1250);
      goto err_58;
    }
    if ( (a->enc_flag & 1) == 0 )
    {
      v7 = ec_asn1_group2pkparameters((const ssl_st *)a->group, v3->parameters);
      v3->parameters = v7;
      if ( !v7 )
      {
        ERR_put_error(0x10u, 192, 16, ".\\crypto\\ec\\ec_asn1.c", 1259);
        v6 = (char *)str;
        goto err_58;
      }
      v6 = (char *)str;
    }
    if ( (a->enc_flag & 2) != 0 )
      goto LABEL_33;
    v8 = ASN1_STRING_type_new(3);
    v3->publicKey = v8;
    if ( !v8 )
    {
      ERR_put_error(0x10u, 192, 65, ".\\crypto\\ec\\ec_asn1.c", 1270);
      goto err_58;
    }
    v9 = EC_POINT_point2oct(a->group, a->pub_key, a->conv_form, 0, 0, 0);
    v15 = v9;
    if ( v9 > v4 )
    {
      v10 = (char *)CRYPTO_realloc(v6, v9, ".\\crypto\\ec\\ec_asn1.c", 1279);
      if ( !v10 )
      {
        ERR_put_error(0x10u, 192, 65, ".\\crypto\\ec\\ec_asn1.c", 1282);
        goto err_58;
      }
      v4 = v15;
      v6 = v10;
    }
    if ( !EC_POINT_point2oct(a->group, a->pub_key, a->conv_form, (unsigned __int8 *)v6, v4, 0) )
    {
      v12 = 1292;
LABEL_25:
      ERR_put_error(0x10u, 192, 16, ".\\crypto\\ec\\ec_asn1.c", v12);
      goto err_58;
    }
    v3->publicKey->flags &= 0xFFFFFFF0;
    v3->publicKey->flags |= 8u;
    if ( ASN1_STRING_set(v3->publicKey, v6, v4) )
    {
LABEL_33:
      v14 = i2d_EC_PRIVATEKEY(v3, out);
      if ( !v14 )
      {
        v12 = 1308;
        goto LABEL_25;
      }
      v13 = 1;
    }
    else
    {
      ERR_put_error(0x10u, 192, 13, ".\\crypto\\ec\\ec_asn1.c", 1301);
    }
err_58:
    if ( v6 )
      CRYPTO_free(v6);
    goto LABEL_28;
  }
  ERR_put_error(0x10u, 192, 65, ".\\crypto\\ec\\ec_asn1.c", 1227);
LABEL_28:
  if ( v3 )
    ASN1_item_free((struct ASN1_VALUE_st *)v3, &stru_83DF50);
  return v13 != 0 ? v14 : 0;
}
