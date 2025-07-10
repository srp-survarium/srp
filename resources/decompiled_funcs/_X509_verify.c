int __cdecl X509_verify(x509_st *a, evp_pkey_st *r)
{
  const ASN1_ITEM_st *v2; // eax
  X509_algor_st *sig_alg; // [esp-10h] [ebp-10h]
  asn1_string_st *signature; // [esp-Ch] [ebp-Ch]
  x509_cinf_st *cert_info; // [esp-8h] [ebp-8h]

  cert_info = a->cert_info;
  signature = a->signature;
  sig_alg = a->sig_alg;
  v2 = X509_CINF_it();
  return ASN1_item_verify(v2, sig_alg, signature, cert_info, r);
}
