int __usercall PKCS7_bio_add_digest@<eax>(bio_st **pbio@<edi>, X509_algor_st *alg)
{
  bio_method_st *v2; // eax
  bio_st *v3; // esi
  unsigned int v5; // eax
  const char *v6; // eax
  const env_md_st *digestbyname; // eax

  v2 = BIO_f_md();
  v3 = BIO_new(v2);
  if ( !v3 )
  {
    ERR_put_error(0x21u, 125, 32, ".\\crypto\\pkcs7\\pk7_doit.c", 111);
    return 0;
  }
  v5 = OBJ_obj2nid(alg->algorithm);
  v6 = OBJ_nid2sn(v5);
  digestbyname = EVP_get_digestbyname(v6);
  if ( digestbyname )
  {
    BIO_ctrl(v3, 111, 0, (void *)digestbyname);
    if ( *pbio )
    {
      if ( !BIO_push(*pbio, v3) )
      {
        ERR_put_error(0x21u, 125, 32, ".\\crypto\\pkcs7\\pk7_doit.c", 127);
        goto LABEL_10;
      }
    }
    else
    {
      *pbio = v3;
    }
    return 1;
  }
  ERR_put_error(0x21u, 125, 109, ".\\crypto\\pkcs7\\pk7_doit.c", 118);
LABEL_10:
  BIO_free((unsigned int)pbio, v3);
  return 0;
}
