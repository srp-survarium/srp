evp_pkey_st *__cdecl X509_get_pubkey(x509_st *x)
{
  if ( x && x->cert_info )
    return X509_PUBKEY_get(x->cert_info->key);
  else
    return 0;
}
