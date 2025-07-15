ec_key_st *__usercall eckey_type2param@<eax>(const asn1_object_st *a1@<ecx>, int a2@<ebx>, int ptype)
{
  ec_key_st *v4; // esi
  void *v6; // eax
  ec_group_st *v7; // eax
  ec_group_st *v8; // edi
  const unsigned __int8 **sn; // [esp-4h] [ebp-Ch]

  if ( ptype == 16 )
  {
    sn = (const unsigned __int8 **)a1->sn;
    ptype = a1->nid;
    v4 = d2i_ECParameters(0, (unsigned __int8 **)&ptype, sn);
    if ( !v4 )
    {
      ERR_put_error(a2, 0x10u, 220, 142, ".\\crypto\\ec\\ec_ameth.c", 151);
      goto ecerr;
    }
    return v4;
  }
  if ( ptype != 6 )
  {
    ERR_put_error(a2, 0x10u, 220, 142, ".\\crypto\\ec\\ec_ameth.c", 178);
    return 0;
  }
  v4 = EC_KEY_new(a2);
  if ( !v4 )
  {
    ERR_put_error(a2, 0x10u, 220, 65, ".\\crypto\\ec\\ec_ameth.c", 165);
    goto ecerr;
  }
  v6 = OBJ_obj2nid(a1);
  v7 = EC_GROUP_new_by_curve_name((int)v6);
  v8 = v7;
  if ( v7 )
  {
    EC_GROUP_set_asn1_flag(v7, 1);
    if ( EC_KEY_set_group(v4, v8) )
    {
      EC_GROUP_free(v8);
      return v4;
    }
  }
ecerr:
  if ( v4 )
    EC_KEY_free(v4);
  return 0;
}
