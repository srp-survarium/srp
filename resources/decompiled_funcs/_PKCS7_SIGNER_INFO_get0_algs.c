void __cdecl PKCS7_SIGNER_INFO_get0_algs(
        pkcs7_signer_info_st *si,
        evp_pkey_st **pk,
        X509_algor_st **pdig,
        X509_algor_st **psig)
{
  if ( pk )
    *pk = si->pkey;
  if ( pdig )
    *pdig = si->digest_alg;
  if ( psig )
    *psig = si->digest_enc_alg;
}
