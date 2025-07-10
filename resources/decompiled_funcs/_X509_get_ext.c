X509_extension_st *__cdecl X509_get_ext(x509_st *x, int loc)
{
  return X509v3_get_ext(x->cert_info->extensions, loc);
}
