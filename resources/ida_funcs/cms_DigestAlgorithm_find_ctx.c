int __cdecl cms_DigestAlgorithm_find_ctx(env_md_ctx_st *mctx, bio_st *chain, X509_algor_st *mdalg)
{
  int v3; // edi
  bio_st *type; // esi
  ui_string_st *object; // eax
  ui_string_st *v6; // eax
  bio_st *v7; // eax
  asn1_object_st *paobj; // [esp+8h] [ebp-4h] BYREF

  X509_ALGOR_get0(&paobj, 0, 0, mdalg);
  v3 = OBJ_obj2nid(paobj);
  type = BIO_find_type(chain, 520);
  if ( type )
  {
    while ( 1 )
    {
      BIO_ctrl(type, 120, 0, &chain);
      object = X509_EXTENSION_get_object((ui_string_st *)chain);
      if ( EVP_CIPHER_CTX_cipher((const ssl_st *)object) == v3 )
        break;
      v6 = X509_EXTENSION_get_object((ui_string_st *)chain);
      if ( EVP_CIPHER_block_size((const env_md_st *)v6) == v3 )
        break;
      v7 = BIO_next(type);
      type = BIO_find_type(v7, 520);
      if ( !type )
        goto LABEL_5;
    }
    EVP_MD_CTX_copy_ex(mctx, (const env_md_ctx_st *)chain);
    return 1;
  }
  else
  {
LABEL_5:
    ERR_put_error(0x2Eu, 115, 131, ".\\crypto\\cms\\cms_lib.c", 405);
    return 0;
  }
}
