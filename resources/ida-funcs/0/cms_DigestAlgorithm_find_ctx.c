int __usercall cms_DigestAlgorithm_find_ctx@<eax>(
        int a1@<ebx>,
        env_md_ctx_st *mctx,
        bio_st *chain,
        X509_algor_st *mdalg)
{
  void *v4; // edi
  bio_st *type; // esi
  ui_string_st *object; // eax
  ui_string_st *v7; // eax
  bio_st *v8; // eax
  asn1_object_st *a; // [esp+8h] [ebp-4h] BYREF

  X509_ALGOR_get0(&a, 0, 0, mdalg);
  v4 = OBJ_obj2nid(a);
  type = BIO_find_type(chain, 520);
  if ( type )
  {
    while ( 1 )
    {
      BIO_ctrl(a1, type, 120, 0, &chain);
      object = X509_EXTENSION_get_object((ui_string_st *)chain);
      if ( (void *)EVP_CIPHER_CTX_cipher((const ssl_st *)object) == v4 )
        break;
      v7 = X509_EXTENSION_get_object((ui_string_st *)chain);
      if ( (void *)EVP_CIPHER_block_size((const env_md_st *)v7) == v4 )
        break;
      v8 = BIO_next(type);
      type = BIO_find_type(v8, 520);
      if ( !type )
        goto LABEL_5;
    }
    EVP_MD_CTX_copy_ex(a1, mctx, (const env_md_ctx_st *)chain);
    return 1;
  }
  else
  {
LABEL_5:
    ERR_put_error(a1, 0x2Eu, 115, 131, ".\\crypto\\cms\\cms_lib.c", 405);
    return 0;
  }
}
