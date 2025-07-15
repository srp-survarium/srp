bio_st *__cdecl cms_DigestAlgorithm_init_bio(X509_algor_st *digestAlgorithm)
{
  unsigned int v1; // eax
  const char *v2; // eax
  const env_md_st *digestbyname; // edi
  bio_method_st *v5; // eax
  bio_st *v6; // eax
  bio_st *v7; // esi
  asn1_object_st *paobj; // [esp+8h] [ebp-4h] BYREF

  X509_ALGOR_get0(&paobj, 0, 0, digestAlgorithm);
  v1 = OBJ_obj2nid(paobj);
  v2 = OBJ_nid2sn(v1);
  digestbyname = EVP_get_digestbyname(v2);
  if ( digestbyname )
  {
    v5 = BIO_f_md();
    v6 = BIO_new(v5);
    v7 = v6;
    if ( v6 && BIO_ctrl(v6, 111, 0, (void *)digestbyname) )
    {
      return v7;
    }
    else
    {
      ERR_put_error(0x2Eu, 116, 119, ".\\crypto\\cms\\cms_lib.c", 378);
      if ( v7 )
        BIO_free((unsigned int)digestbyname, v7);
      return 0;
    }
  }
  else
  {
    ERR_put_error(0x2Eu, 116, 149, ".\\crypto\\cms\\cms_lib.c", 371);
    return 0;
  }
}
