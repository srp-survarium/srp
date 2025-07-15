int __cdecl i2r_idp(const v3_ext_method *method, DIST_POINT_NAME_st **pidp, bio_st *out, int indent)
{
  asn1_string_st *v4; // eax

  if ( *pidp )
    print_distpoint(out, *pidp, indent);
  if ( (int)pidp[1] > 0 )
    BIO_printf(out, "%*sOnly User Certificates\n", indent, uri);
  if ( (int)pidp[2] > 0 )
    BIO_printf(out, "%*sOnly CA Certificates\n", indent, uri);
  if ( (int)pidp[4] > 0 )
    BIO_printf(out, "%*sIndirect CRL\n", indent, uri);
  v4 = (asn1_string_st *)pidp[3];
  if ( v4 )
    print_reasons(out, "Only Some Reasons", v4, indent);
  if ( (int)pidp[5] > 0 )
    BIO_printf(out, "%*sOnly Attribute Certificates\n", indent, uri);
  if ( !*pidp && (int)pidp[1] <= 0 && (int)pidp[2] <= 0 && (int)pidp[4] <= 0 && !pidp[3] && (int)pidp[5] <= 0 )
    BIO_printf(out, "%*s<EMPTY>\n", indent, uri);
  return 1;
}
