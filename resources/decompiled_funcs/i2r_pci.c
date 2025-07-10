int __cdecl i2r_pci(v3_ext_method *method, PROXY_CERT_INFO_EXTENSION_st *pci, bio_st *out, int indent)
{
  asn1_string_st *policy; // eax
  const char *data; // eax

  BIO_printf(out, "%*sPath Length Constraint: ", indent, (const char *)&buf);
  if ( pci->pcPathLengthConstraint )
    i2a_ASN1_INTEGER(out, pci->pcPathLengthConstraint);
  else
    BIO_printf(out, "infinite");
  BIO_puts(out, "\n");
  BIO_printf(out, "%*sPolicy Language: ", indent, (const char *)&buf);
  i2a_ASN1_OBJECT(out, pci->proxyPolicy->policyLanguage);
  BIO_puts(out, "\n");
  policy = pci->proxyPolicy->policy;
  if ( policy )
  {
    data = (const char *)policy->data;
    if ( data )
      BIO_printf(out, "%*sPolicy Text: %s\n", indent, (const char *)&buf, data);
  }
  return 1;
}
