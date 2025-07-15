int __cdecl i2r_crldp(const v3_ext_method *method, const stack_st *pcrldp, bio_st *out, int indent)
{
  int i; // ebp
  char *v5; // ebx
  asn1_string_st *v6; // eax

  for ( i = 0; i < sk_num(pcrldp); ++i )
  {
    BIO_puts(out, "\n");
    v5 = sk_value(pcrldp, i);
    if ( *(_DWORD *)v5 )
      print_distpoint(out, *(DIST_POINT_NAME_st **)v5, indent);
    v6 = (asn1_string_st *)*((_DWORD *)v5 + 1);
    if ( v6 )
      print_reasons(out, "Reasons", v6, indent);
    if ( *((_DWORD *)v5 + 2) )
    {
      BIO_printf(out, "%*sCRL Issuer:\n", indent, (const char *)&buf);
      print_gens(out, *((stack_st_GENERAL_NAME **)v5 + 2), indent);
    }
  }
  return 1;
}
