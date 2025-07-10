ec_group_st *__cdecl d2i_ECPKParameters(ec_group_st **a, unsigned __int8 **in, unsigned __int8 *len)
{
  struct ASN1_VALUE_st *v3; // eax
  struct ASN1_VALUE_st *v4; // edi
  ec_group_st *v6; // esi

  v3 = ASN1_item_d2i(0, in, len, &local_it_64);
  v4 = v3;
  if ( v3 )
  {
    v6 = ec_asn1_pkparameters2group((const ecpk_parameters_st *)v3);
    if ( v6 )
    {
      if ( a )
      {
        if ( *a )
          EC_GROUP_clear_free(*a);
        *a = v6;
      }
      ASN1_item_free(v4, &local_it_64);
      return v6;
    }
    else
    {
      ERR_put_error(0x10u, 145, 127, ".\\crypto\\ec\\ec_asn1.c", 1067);
      return 0;
    }
  }
  else
  {
    ERR_put_error(0x10u, 145, 117, ".\\crypto\\ec\\ec_asn1.c", 1060);
    ASN1_item_free(0, &local_it_64);
    return 0;
  }
}
