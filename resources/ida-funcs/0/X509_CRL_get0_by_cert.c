int __cdecl X509_CRL_get0_by_cert(X509_crl_st *crl, x509_revoked_st **ret, x509_st *x)
{
  const x509_crl_method_st *meth; // esi
  asn1_string_st *v4; // eax
  X509_name_st *issuer_name; // [esp-8h] [ebp-10h]

  meth = crl->meth;
  if ( !meth->crl_lookup )
    return 0;
  issuer_name = X509_get_issuer_name(x);
  v4 = EVP_CIPHER_CTX_block_size(x);
  return meth->crl_lookup(crl, ret, v4, issuer_name);
}
