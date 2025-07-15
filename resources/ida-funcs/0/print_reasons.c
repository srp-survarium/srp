int __usercall print_reasons@<eax>(bio_st *out@<edi>, const char *rname@<edx>, asn1_string_st *rflags, int indent)
{
  int v4; // ebx
  const char **p_lname; // esi

  v4 = 1;
  BIO_printf(out, "%*s%s:\n%*s", indent, uri, rname, indent + 2, uri);
  if ( !reason_flags[0].lname )
    goto LABEL_10;
  p_lname = &reason_flags[0].lname;
  do
  {
    if ( ASN1_BIT_STRING_get_bit(rflags, (int)*(p_lname - 1)) )
    {
      if ( v4 )
        v4 = 0;
      else
        BIO_puts(0, out, ", ");
      BIO_puts(0, out, *p_lname);
    }
    p_lname += 3;
  }
  while ( *p_lname );
  if ( !v4 )
  {
    BIO_puts(0, out, "\n");
    return 1;
  }
  else
  {
LABEL_10:
    BIO_puts(v4, out, "<EMPTY>\n");
    return 1;
  }
}
