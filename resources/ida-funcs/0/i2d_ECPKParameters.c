int __usercall i2d_ECPKParameters@<eax>(int a1@<ebx>, const ssl_st *a, unsigned __int8 **out)
{
  struct ASN1_VALUE_st *v3; // esi
  int v5; // edi

  v3 = (struct ASN1_VALUE_st *)ec_asn1_group2pkparameters(a, 0, a1);
  if ( v3 )
  {
    v5 = ASN1_item_i2d(v3, out, &local_it_64);
    if ( v5 )
    {
      ASN1_item_free(v3, &local_it_64);
      return v5;
    }
    else
    {
      ERR_put_error(a1, 0x10u, 191, 121, ".\\crypto\\ec\\ec_asn1.c", 1092);
      ASN1_item_free(v3, &local_it_64);
      return 0;
    }
  }
  else
  {
    ERR_put_error(a1, 0x10u, 191, 120, ".\\crypto\\ec\\ec_asn1.c", 1087);
    return 0;
  }
}
