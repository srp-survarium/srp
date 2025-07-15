bio_st *__usercall PKCS7_find_digest@<eax>(ui_string_st **pmd@<edi>, int nid@<ebx>, bio_st *bio)
{
  bio_st *type; // esi
  ui_string_st *object; // eax
  bio_st *v5; // eax

  type = BIO_find_type(bio, 520);
  if ( type )
  {
    while ( 1 )
    {
      BIO_ctrl(type, 120, 0, pmd);
      if ( !*pmd )
      {
        ERR_put_error(0x21u, 127, 68, ".\\crypto\\pkcs7\\pk7_doit.c", 652);
        return 0;
      }
      object = X509_EXTENSION_get_object(*pmd);
      if ( EVP_CIPHER_CTX_cipher((const ssl_st *)object) == nid )
        return type;
      v5 = BIO_next(type);
      type = BIO_find_type(v5, 520);
      if ( !type )
        goto LABEL_5;
    }
  }
  else
  {
LABEL_5:
    ERR_put_error(0x21u, 127, 108, ".\\crypto\\pkcs7\\pk7_doit.c", 646);
    return 0;
  }
}
