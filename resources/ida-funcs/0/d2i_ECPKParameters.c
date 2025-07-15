ec_group_st *__usercall d2i_ECPKParameters@<eax>(
        int a1@<ebx>,
        ec_group_st **a,
        unsigned __int8 **in,
        const unsigned __int8 **len)
{
  struct ASN1_VALUE_st *v4; // eax
  struct ASN1_VALUE_st *v5; // edi
  ec_group_st *v7; // esi

  v4 = ASN1_item_d2i(0, in, len, &local_it_64);
  v5 = v4;
  if ( v4 )
  {
    v7 = ec_asn1_pkparameters2group(a1, (const ecpk_parameters_st *)v4);
    if ( v7 )
    {
      if ( a )
      {
        if ( *a )
          EC_GROUP_clear_free(*a);
        *a = v7;
      }
      ASN1_item_free(v5, &local_it_64);
      return v7;
    }
    else
    {
      ERR_put_error(a1, 0x10u, 145, 127, ".\\crypto\\ec\\ec_asn1.c", 1067);
      return 0;
    }
  }
  else
  {
    ERR_put_error(a1, 0x10u, 145, 117, ".\\crypto\\ec\\ec_asn1.c", 1060);
    ASN1_item_free(0, &local_it_64);
    return 0;
  }
}
