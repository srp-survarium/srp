void __cdecl CMS_SignerInfo_get0_algs(
        CMS_SignerInfo_st *si,
        evp_pkey_st **pk,
        x509_st **signer,
        X509_algor_st **pdig,
        X509_algor_st **psig)
{
  if ( pk )
    *pk = si->pkey;
  if ( signer )
    *signer = si->signer;
  if ( pdig )
    *pdig = si->digestAlgorithm;
  if ( psig )
    *psig = si->signatureAlgorithm;
}
