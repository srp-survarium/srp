ec_key_st *__usercall d2i_ECPrivateKey@<eax>(
        int a1@<ebx>,
        ec_key_st **a,
        unsigned __int8 **in,
        const unsigned __int8 **len)
{
  ec_key_st *v5; // esi
  ec_key_st *v6; // eax
  bignum_st *v7; // eax
  ec_point_st *v8; // eax
  unsigned int *v9; // ecx
  const ec_group_st *group; // [esp-1Ch] [ebp-20h]
  const unsigned __int8 *v11; // [esp-14h] [ebp-18h]
  unsigned int v12; // [esp-10h] [ebp-14h]
  struct ASN1_VALUE_st *val; // [esp+0h] [ebp-4h] BYREF

  val = ASN1_item_new(&stru_6CFBF8);
  if ( !val )
  {
    ERR_put_error(a1, 0x10u, 146, 65, ".\\crypto\\ec\\ec_asn1.c", 1110);
    return 0;
  }
  val = ASN1_item_d2i(&val, in, len, &stru_6CFBF8);
  if ( !val )
  {
    ERR_put_error(a1, 0x10u, 146, 16, ".\\crypto\\ec\\ec_asn1.c", 1116);
    ASN1_item_free(val, &stru_6CFBF8);
    return 0;
  }
  if ( !a || (v5 = *a) == 0 )
  {
    v6 = EC_KEY_new(a1);
    v5 = v6;
    if ( !v6 )
    {
      ERR_put_error(a1, 0x10u, 146, 65, ".\\crypto\\ec\\ec_asn1.c", 1126);
LABEL_29:
      v5 = 0;
      goto LABEL_30;
    }
    if ( a )
      *a = v6;
  }
  if ( *((_DWORD *)val + 2) )
  {
    if ( v5->group )
      EC_GROUP_clear_free(v5->group);
    v5->group = ec_asn1_pkparameters2group(a1, *((const ecpk_parameters_st **)val + 2));
  }
  if ( !v5->group )
  {
    ERR_put_error(a1, 0x10u, 146, 16, ".\\crypto\\ec\\ec_asn1.c", 1144);
LABEL_28:
    EC_KEY_free(v5);
    goto LABEL_29;
  }
  v5->version = *(_DWORD *)val;
  if ( !*((_DWORD *)val + 1) )
  {
    ERR_put_error(a1, 0x10u, 146, 125, ".\\crypto\\ec\\ec_asn1.c", 1166);
    goto LABEL_28;
  }
  v7 = BN_bin2bn(*(const unsigned __int8 **)(*((_DWORD *)val + 1) + 8), **((_DWORD **)val + 1), v5->priv_key);
  v5->priv_key = v7;
  if ( !v7 )
  {
    ERR_put_error(a1, 0x10u, 146, 3, ".\\crypto\\ec\\ec_asn1.c", 1159);
    goto LABEL_28;
  }
  if ( *((_DWORD *)val + 3) )
  {
    if ( v5->pub_key )
      EC_POINT_clear_free(v5->pub_key);
    v8 = EC_POINT_new(v5->group);
    v5->pub_key = v8;
    if ( !v8 )
    {
      ERR_put_error(a1, 0x10u, 146, 16, ".\\crypto\\ec\\ec_asn1.c", 1180);
      goto LABEL_28;
    }
    v9 = (unsigned int *)*((_DWORD *)val + 3);
    v12 = *v9;
    v11 = (const unsigned __int8 *)v9[2];
    group = v5->group;
    v5->conv_form = *v11 & 0xFE;
    if ( !EC_POINT_oct2point(group, v8, v11, v12, 0) )
    {
      ERR_put_error(a1, 0x10u, 146, 16, ".\\crypto\\ec\\ec_asn1.c", 1190);
      goto LABEL_28;
    }
  }
LABEL_30:
  if ( val )
    ASN1_item_free(val, &stru_6CFBF8);
  return v5;
}
