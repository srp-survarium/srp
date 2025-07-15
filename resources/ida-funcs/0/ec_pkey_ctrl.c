int __usercall ec_pkey_ctrl@<eax>(
        int a1@<ebx>,
        int a2@<edi>,
        ssl_st *pkey,
        X509_algor_st *op,
        int arg1,
        pkcs7_signer_info_st *arg2)
{
  void *v7; // esi
  int v8; // eax
  asn1_object_st *v9; // eax
  void *v10; // esi
  int v11; // eax
  asn1_object_st *v12; // eax
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
        v10 = OBJ_obj2nid(op->algorithm);
        if ( v10 )
        {
          v11 = EVP_CIPHER_CTX_cipher(pkey);
          if ( OBJ_find_sigid_by_algs(a2, (int *)&psig, (int)v10, v11) )
          {
            v12 = OBJ_nid2obj(a1, (unsigned int)psig);
            X509_ALGOR_set0((X509_algor_st *)psignid, v12, -1, 0);
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
        v7 = OBJ_obj2nid(op->algorithm);
        if ( v7 )
        {
          v8 = EVP_CIPHER_CTX_cipher(pkey);
          if ( OBJ_find_sigid_by_algs(a2, &psignid, (int)v7, v8) )
          {
            v9 = OBJ_nid2obj(a1, psignid);
            X509_ALGOR_set0(psig, v9, -1, 0);
            return 1;
          }
        }
      }
    }
  }
  return -1;
}
