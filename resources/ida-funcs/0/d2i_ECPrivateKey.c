ec_key_st *__cdecl d2i_ECPrivateKey(ec_key_st **a, unsigned __int8 **in, unsigned __int8 *len)
{
  ec_key_st *v4; // esi
  ec_key_st *v5; // eax
  bignum_st *v6; // eax
  ec_point_st *v7; // eax
  unsigned int *v8; // ecx
  const ec_group_st *group; // [esp-1Ch] [ebp-20h]
  const unsigned __int8 *v10; // [esp-14h] [ebp-18h]
  unsigned int v11; // [esp-10h] [ebp-14h]
  struct ASN1_VALUE_st *pval; // [esp+0h] [ebp-4h] BYREF

  pval = ASN1_item_new(&stru_83DF50);
  if ( !pval )
  {
    ERR_put_error(0x10u, 146, 65, ".\\crypto\\ec\\ec_asn1.c", 1110);
    return 0;
  }
  pval = ASN1_item_d2i(&pval, in, len, &stru_83DF50);
  if ( !pval )
  {
    ERR_put_error(0x10u, 146, 16, ".\\crypto\\ec\\ec_asn1.c", 1116);
    ASN1_item_free(pval, &stru_83DF50);
    return 0;
  }
  if ( !a || (v4 = *a) == 0 )
  {
    v5 = EC_KEY_new();
    v4 = v5;
    if ( !v5 )
    {
      ERR_put_error(0x10u, 146, 65, ".\\crypto\\ec\\ec_asn1.c", 1126);
LABEL_29:
      v4 = 0;
      goto LABEL_30;
    }
    if ( a )
      *a = v5;
  }
  if ( *((_DWORD *)pval + 2) )
  {
    if ( v4->group )
      EC_GROUP_clear_free(v4->group);
    v4->group = ec_asn1_pkparameters2group(*((const ecpk_parameters_st **)pval + 2));
  }
  if ( !v4->group )
  {
    ERR_put_error(0x10u, 146, 16, ".\\crypto\\ec\\ec_asn1.c", 1144);
LABEL_28:
    EC_KEY_free(v4);
    goto LABEL_29;
  }
  v4->version = *(_DWORD *)pval;
  if ( !*((_DWORD *)pval + 1) )
  {
    ERR_put_error(0x10u, 146, 125, ".\\crypto\\ec\\ec_asn1.c", 1166);
    goto LABEL_28;
  }
  v6 = BN_bin2bn(*(const unsigned __int8 **)(*((_DWORD *)pval + 1) + 8), **((_DWORD **)pval + 1), v4->priv_key);
  v4->priv_key = v6;
  if ( !v6 )
  {
    ERR_put_error(0x10u, 146, 3, ".\\crypto\\ec\\ec_asn1.c", 1159);
    goto LABEL_28;
  }
  if ( *((_DWORD *)pval + 3) )
  {
    if ( v4->pub_key )
      EC_POINT_clear_free(v4->pub_key);
    v7 = EC_POINT_new(v4->group);
    v4->pub_key = v7;
    if ( !v7 )
    {
      ERR_put_error(0x10u, 146, 16, ".\\crypto\\ec\\ec_asn1.c", 1180);
      goto LABEL_28;
    }
    v8 = (unsigned int *)*((_DWORD *)pval + 3);
    v11 = *v8;
    v10 = (const unsigned __int8 *)v8[2];
    group = v4->group;
    v4->conv_form = *v10 & 0xFE;
    if ( !EC_POINT_oct2point(group, v7, v10, v11, 0) )
    {
      ERR_put_error(0x10u, 146, 16, ".\\crypto\\ec\\ec_asn1.c", 1190);
      goto LABEL_28;
    }
  }
LABEL_30:
  if ( pval )
    ASN1_item_free(pval, &stru_83DF50);
  return v4;
}
