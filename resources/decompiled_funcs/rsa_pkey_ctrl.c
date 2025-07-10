int __cdecl rsa_pkey_ctrl(evp_pkey_st *pkey, int op, int arg1, pkcs7_signer_info_st *arg2)
{
  asn1_object_st *v4; // eax
  X509_algor_st *psig; // [esp+0h] [ebp-4h] BYREF

  psig = 0;
  switch ( op )
  {
    case 1:
      if ( arg1 )
        return 1;
      PKCS7_SIGNER_INFO_get0_algs(arg2, 0, 0, &psig);
      break;
    case 2:
      if ( arg1 )
        return 1;
      PKCS7_RECIP_INFO_get0_alg((pkcs7_recip_info_st *)arg2, &psig);
      break;
    case 3:
      arg2->version = (asn1_string_st *)64;
      return 1;
    case 5:
      if ( arg1 )
        return 1;
      CMS_SignerInfo_get0_algs((CMS_SignerInfo_st *)arg2, 0, 0, 0, &psig);
      break;
    case 7:
      if ( arg1 )
        return 1;
      CMS_RecipientInfo_ktri_get0_algs((CMS_RecipientInfo_st *)arg2, 0, 0, &psig);
      break;
    default:
      return -2;
  }
  if ( psig )
  {
    v4 = OBJ_nid2obj(6u);
    X509_ALGOR_set0(psig, v4, 5, 0);
  }
  return 1;
}
