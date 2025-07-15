bio_st *__usercall cms_DigestAlgorithm_init_bio@<eax>(int a1@<ebx>, X509_algor_st *digestAlgorithm)
{
  void *v2; // eax
  char *v3; // eax
  const env_md_st *digestbyname; // edi
  bio_method_st *v6; // eax
  bio_st *v7; // eax
  bio_st *v8; // esi
  asn1_object_st *a; // [esp+8h] [ebp-4h] BYREF

  X509_ALGOR_get0(&a, 0, 0, digestAlgorithm);
  v2 = OBJ_obj2nid(a);
  v3 = (char *)OBJ_nid2sn(a1, (unsigned int)v2);
  digestbyname = EVP_get_digestbyname(v3);
  if ( digestbyname )
  {
    v6 = BIO_f_md();
    v7 = BIO_new(a1, v6);
    v8 = v7;
    if ( v7 && BIO_ctrl(a1, v7, 111, 0, (void *)digestbyname) )
    {
      return v8;
    }
    else
    {
      ERR_put_error(a1, 0x2Eu, 116, 119, ".\\crypto\\cms\\cms_lib.c", 378);
      if ( v8 )
        BIO_free((int)digestbyname, a1, v8);
      return 0;
    }
  }
  else
  {
    ERR_put_error(a1, 0x2Eu, 116, 149, ".\\crypto\\cms\\cms_lib.c", 371);
    return 0;
  }
}
