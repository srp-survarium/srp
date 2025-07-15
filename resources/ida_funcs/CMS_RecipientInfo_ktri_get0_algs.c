int __cdecl CMS_RecipientInfo_ktri_get0_algs(
        CMS_RecipientInfo_st *ri,
        evp_pkey_st **pk,
        x509_st **recip,
        X509_algor_st **palg)
{
  CMS_KeyTransRecipientInfo_st *ktri; // eax

  if ( ri->type )
  {
    ERR_put_error(0x2Eu, 142, 124, ".\\crypto\\cms\\cms_env.c", 244);
    return 0;
  }
  else
  {
    ktri = ri->d.ktri;
    if ( pk )
      *pk = ktri->pkey;
    if ( recip )
      *recip = ktri->recip;
    if ( palg )
      *palg = ktri->keyEncryptionAlgorithm;
    return 1;
  }
}
