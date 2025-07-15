int __cdecl def_crl_verify(X509_crl_st *crl, evp_pkey_st *r)
{
  return ASN1_item_verify(&local_it_6, crl->sig_alg, crl->signature, (struct ASN1_VALUE_st *)crl->crl, r);
}
