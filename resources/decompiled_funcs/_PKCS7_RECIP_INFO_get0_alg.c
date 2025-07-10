void __cdecl PKCS7_RECIP_INFO_get0_alg(pkcs7_recip_info_st *ri, X509_algor_st **penc)
{
  if ( penc )
    *penc = ri->key_enc_algor;
}
