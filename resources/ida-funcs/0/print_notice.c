void __usercall print_notice(int a1@<ebx>, bio_st *out, USERNOTICE_st *notice, int indent)
{
  NOTICEREF_st *noticeref; // edi
  bool v5; // cc
  const char *v6; // eax
  int v7; // esi
  char *v8; // ebx
  char *v9; // ebx
  asn1_string_st *exptext; // eax
  int v11; // [esp-8h] [ebp-10h]

  noticeref = notice->noticeref;
  if ( notice->noticeref )
  {
    BIO_printf(out, "%*sOrganization: %s\n", indent, uri, (const char *)noticeref->organization->data);
    v5 = sk_num(&noticeref->noticenos->stack) <= 1;
    v6 = "s";
    if ( v5 )
      v6 = uri;
    BIO_printf(out, "%*sNumber%s: ", indent, uri, v6);
    v7 = 0;
    if ( sk_num(&noticeref->noticenos->stack) > 0 )
    {
      v11 = a1;
      do
      {
        v8 = sk_value(&noticeref->noticenos->stack, v7);
        if ( v7 )
          BIO_puts((int)v8, out, ", ");
        v9 = i2s_ASN1_INTEGER((int)v8, 0, (asn1_string_st *)v8);
        BIO_puts((int)v9, out, v9);
        CRYPTO_free(v9);
        ++v7;
      }
      while ( v7 < sk_num(&noticeref->noticenos->stack) );
      a1 = v11;
    }
    BIO_puts(a1, out, "\n");
  }
  exptext = notice->exptext;
  if ( exptext )
    BIO_printf(out, "%*sExplicit Text: %s\n", indent, uri, (const char *)exptext->data);
}
