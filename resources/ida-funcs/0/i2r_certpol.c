int __cdecl i2r_certpol(v3_ext_method *method, stack_st_POLICYINFO *pol, bio_st *out, int indent)
{
  int i; // ebp
  char *v5; // edi
  stack_st_POLICYQUALINFO *v6; // edi

  for ( i = 0; i < sk_num(&pol->stack); ++i )
  {
    v5 = sk_value(&pol->stack, i);
    BIO_printf(out, "%*sPolicy: ", indent, uri);
    i2a_ASN1_OBJECT(indent, out, *(asn1_object_st **)v5);
    BIO_puts(indent, out, "\n");
    v6 = (stack_st_POLICYQUALINFO *)*((_DWORD *)v5 + 1);
    if ( v6 )
      print_qualifiers(out, indent + 2, v6);
  }
  return 1;
}
