int __cdecl i2d_ECPKParameters(const ssl_st *a, unsigned __int8 **out)
{
  struct ASN1_VALUE_st *v2; // esi
  int v4; // edi

  v2 = (struct ASN1_VALUE_st *)ec_asn1_group2pkparameters(a, 0);
  if ( v2 )
  {
    v4 = ASN1_item_i2d(v2, out, &local_it_64);
    if ( v4 )
    {
      ASN1_item_free(v2, &local_it_64);
      return v4;
    }
    else
    {
      ERR_put_error(0x10u, 191, 121, ".\\crypto\\ec\\ec_asn1.c", 1092);
      ASN1_item_free(v2, &local_it_64);
      return 0;
    }
  }
  else
  {
    ERR_put_error(0x10u, 191, 120, ".\\crypto\\ec\\ec_asn1.c", 1087);
    return 0;
  }
}
