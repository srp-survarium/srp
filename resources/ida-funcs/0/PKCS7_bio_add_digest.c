int __usercall PKCS7_bio_add_digest@<eax>(bio_st **pbio@<edi>, int a2@<ebx>, X509_algor_st *alg)
{
  bio_method_st *v3; // eax
  bio_st *v4; // esi
  void *v6; // eax
  char *v7; // eax
  const env_md_st *digestbyname; // eax

  v3 = BIO_f_md();
  v4 = BIO_new(a2, v3);
  if ( !v4 )
  {
    ERR_put_error(a2, 0x21u, 125, 32, ".\\crypto\\pkcs7\\pk7_doit.c", 111);
    return 0;
  }
  v6 = OBJ_obj2nid(alg->algorithm);
  v7 = (char *)OBJ_nid2sn(a2, (unsigned int)v6);
  digestbyname = EVP_get_digestbyname(v7);
  if ( digestbyname )
  {
    BIO_ctrl(a2, v4, 111, 0, (void *)digestbyname);
    if ( *pbio )
    {
      if ( !BIO_push(a2, *pbio, v4) )
      {
        ERR_put_error(a2, 0x21u, 125, 32, ".\\crypto\\pkcs7\\pk7_doit.c", 127);
        goto LABEL_10;
      }
    }
    else
    {
      *pbio = v4;
    }
    return 1;
  }
  ERR_put_error(a2, 0x21u, 125, 109, ".\\crypto\\pkcs7\\pk7_doit.c", 118);
LABEL_10:
  BIO_free((int)pbio, a2, v4);
  return 0;
}
