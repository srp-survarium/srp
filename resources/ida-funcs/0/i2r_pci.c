int __cdecl i2r_pci(v3_ext_method *method, PROXY_CERT_INFO_EXTENSION_st *pci, bio_st *out, int indent)
{
  asn1_string_st *policy; // eax
  const char *data; // eax

  BIO_printf(out, "%*sPath Length Constraint: ", indent, uri);
  if ( pci->pcPathLengthConstraint )
    i2a_ASN1_INTEGER(out, pci->pcPathLengthConstraint);
  else
    BIO_printf(out, "infinite");
  BIO_puts(indent, out, "\n");
  BIO_printf(out, "%*sPolicy Language: ", indent, uri);
  i2a_ASN1_OBJECT(indent, out, pci->proxyPolicy->policyLanguage);
  BIO_puts(indent, out, "\n");
  policy = pci->proxyPolicy->policy;
  if ( policy )
  {
    data = (const char *)policy->data;
    if ( data )
      BIO_printf(out, "%*sPolicy Text: %s\n", indent, uri, data);
  }
  return 1;
}
