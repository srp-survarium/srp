X509_extension_st *__cdecl X509_CRL_get_ext(X509_crl_st *x, int loc)
{
  return X509v3_get_ext(x->crl->extensions, loc);
}
