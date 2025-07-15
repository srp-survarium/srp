void __cdecl print_notice(bio_st *out, USERNOTICE_st *notice, int indent)
{
  NOTICEREF_st *noticeref; // edi
  bool v4; // cc
  const char *v5; // eax
  int i; // esi
  char *v7; // ebx
  char *v8; // ebx
  asn1_string_st *exptext; // eax

  noticeref = notice->noticeref;
  if ( notice->noticeref )
  {
    BIO_printf(out, "%*sOrganization: %s\n", indent, (const char *)&buf, (const char *)noticeref->organization->data);
    v4 = sk_num(&noticeref->noticenos->stack) <= 1;
    v5 = "s";
    if ( v4 )
      v5 = (const char *)&buf;
    BIO_printf(out, "%*sNumber%s: ", indent, (const char *)&buf, v5);
    for ( i = 0; i < sk_num(&noticeref->noticenos->stack); ++i )
    {
      v7 = sk_value(&noticeref->noticenos->stack, i);
      if ( i )
        BIO_puts(out, (const char *)&stru_95AF78.m_key_bindings[32]);
      v8 = i2s_ASN1_INTEGER(0, (asn1_string_st *)v7);
      BIO_puts(out, v8);
      CRYPTO_free(v8);
    }
    BIO_puts(out, "\n");
  }
  exptext = notice->exptext;
  if ( exptext )
    BIO_printf(out, "%*sExplicit Text: %s\n", indent, (const char *)&buf, (const char *)exptext->data);
}
