int __cdecl ec_pkey_ctrl(ssl_st *pkey, X509_algor_st *op, int arg1, pkcs7_signer_info_st *arg2)
{
  int v5; // esi
  int v6; // eax
  asn1_object_st *v7; // eax
  int v8; // esi
  int v9; // eax
  asn1_object_st *v10; // eax
  int psignid; // [esp+4h] [ebp-8h] BYREF
  X509_algor_st *psig; // [esp+8h] [ebp-4h] BYREF

  if ( op == (X509_algor_st *)1 )
  {
    if ( arg1 )
      return 1;
    PKCS7_SIGNER_INFO_get0_algs(arg2, 0, &op, (X509_algor_st **)&psignid);
    if ( op )
    {
      if ( op->algorithm )
      {
        v8 = OBJ_obj2nid(op->algorithm);
        if ( v8 )
        {
          v9 = EVP_CIPHER_CTX_cipher(pkey);
          if ( OBJ_find_sigid_by_algs((int *)&psig, v8, v9) )
          {
            v10 = OBJ_nid2obj((unsigned int)psig);
            X509_ALGOR_set0((X509_algor_st *)psignid, v10, -1, 0);
            return 1;
          }
        }
      }
    }
  }
  else
  {
    if ( op == (X509_algor_st *)3 )
    {
      arg2->version = (asn1_string_st *)64;
      return 2;
    }
    if ( op != (X509_algor_st *)5 )
      return -2;
    if ( arg1 )
      return 1;
    CMS_SignerInfo_get0_algs((CMS_SignerInfo_st *)arg2, 0, 0, &op, &psig);
    if ( op )
    {
      if ( op->algorithm )
      {
        v5 = OBJ_obj2nid(op->algorithm);
        if ( v5 )
        {
          v6 = EVP_CIPHER_CTX_cipher(pkey);
          if ( OBJ_find_sigid_by_algs(&psignid, v5, v6) )
          {
            v7 = OBJ_nid2obj(psignid);
            X509_ALGOR_set0(psig, v7, -1, 0);
            return 1;
          }
        }
      }
    }
  }
  return -1;
}
