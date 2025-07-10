ec_key_st *__cdecl eckey_type2param(const unsigned __int8 *ptype)
{
  const asn1_object_st *pval; // ecx
  const asn1_object_st *v2; // edi
  ec_key_st *v3; // esi
  int v5; // eax
  ec_group_st *v6; // eax
  ec_group_st *v7; // edi
  unsigned __int8 *sn; // [esp-4h] [ebp-Ch]

  v2 = pval;
  if ( ptype == (const unsigned __int8 *)16 )
  {
    sn = (unsigned __int8 *)pval->sn;
    ptype = (const unsigned __int8 *)pval->nid;
    v3 = d2i_ECParameters(0, (unsigned __int8 **)&ptype, sn);
    if ( !v3 )
    {
      ERR_put_error(0x10u, 220, 142, ".\\crypto\\ec\\ec_ameth.c", 151);
      goto ecerr;
    }
    return v3;
  }
  if ( ptype != (const unsigned __int8 *)6 )
  {
    ERR_put_error(0x10u, 220, 142, ".\\crypto\\ec\\ec_ameth.c", 178);
    return 0;
  }
  v3 = EC_KEY_new();
  if ( !v3 )
  {
    ERR_put_error(0x10u, 220, 65, ".\\crypto\\ec\\ec_ameth.c", 165);
    goto ecerr;
  }
  v5 = OBJ_obj2nid(v2);
  v6 = EC_GROUP_new_by_curve_name(v5);
  v7 = v6;
  if ( v6 )
  {
    EC_GROUP_set_asn1_flag(v6, 1);
    if ( EC_KEY_set_group(v3, v7) )
    {
      EC_GROUP_free(v7);
      return v3;
    }
  }
ecerr:
  if ( v3 )
    EC_KEY_free(v3);
  return 0;
}
