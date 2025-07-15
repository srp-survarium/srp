int __usercall i2r_crldp@<eax>(char *a1@<ebx>, const v3_ext_method *method, stack_st *pcrldp, bio_st *out, int indent)
{
  int i; // ebp
  asn1_string_st *v6; // eax

  for ( i = 0; i < sk_num(pcrldp); ++i )
  {
    BIO_puts((int)a1, out, "\n");
    a1 = sk_value(pcrldp, i);
    if ( *(_DWORD *)a1 )
      print_distpoint(out, *(DIST_POINT_NAME_st **)a1, indent);
    v6 = (asn1_string_st *)*((_DWORD *)a1 + 1);
    if ( v6 )
      print_reasons(out, "Reasons", v6, indent);
    if ( *((_DWORD *)a1 + 2) )
    {
      BIO_printf(out, "%*sCRL Issuer:\n", indent, uri);
      a1 = (char *)*((_DWORD *)a1 + 2);
      print_gens(out, (stack_st_GENERAL_NAME *)a1, indent);
    }
  }
  return 1;
}
