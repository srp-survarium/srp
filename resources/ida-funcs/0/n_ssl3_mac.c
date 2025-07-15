unsigned int __cdecl n_ssl3_mac(ssl_st *ssl, unsigned __int8 *md, int send)
{
  ssl3_state_st *s3; // eax
  env_md_ctx_st *write_hash; // ebp
  ssl3_record_st *p_wrec; // esi
  unsigned int write_mac_secret; // edx
  unsigned __int8 *write_sequence; // eax
  ui_string_st *object; // eax
  int v9; // eax
  int i; // eax
  unsigned int count[2]; // [esp+8h] [ebp-24h] BYREF
  void *v15; // [esp+10h] [ebp-1Ch]
  env_md_ctx_st ctx; // [esp+14h] [ebp-18h] BYREF

  s3 = ssl->s3;
  if ( send )
  {
    write_hash = ssl->write_hash;
    p_wrec = &s3->wrec;
    write_mac_secret = (unsigned int)s3->write_mac_secret;
    write_sequence = s3->write_sequence;
  }
  else
  {
    write_hash = ssl->read_hash;
    p_wrec = &s3->rrec;
    write_mac_secret = (unsigned int)s3->read_mac_secret;
    write_sequence = s3->read_sequence;
  }
  v15 = write_sequence;
  count[1] = write_mac_secret;
  object = X509_EXTENSION_get_object((ui_string_st *)write_hash);
  v9 = EVP_MD_size((const env_md_st *)object);
  if ( v9 < 0 )
    return -1;
  count[0] = v9;
  EVP_MD_CTX_init(&ctx);
  EVP_MD_CTX_copy_ex(&ctx, write_hash);
  EVP_DigestUpdate(&ctx);
  EVP_DigestUpdate(&ctx);
  EVP_DigestUpdate(&ctx);
  EVP_DigestUpdate(&ctx);
  *md = BYTE1(p_wrec->length);
  md[1] = p_wrec->length;
  EVP_DigestUpdate(&ctx);
  EVP_DigestUpdate(&ctx);
  EVP_DigestFinal_ex((unsigned int)md, &ctx, md, 0);
  EVP_MD_CTX_copy_ex(&ctx, write_hash);
  EVP_DigestUpdate(&ctx);
  EVP_DigestUpdate(&ctx);
  EVP_DigestUpdate(&ctx);
  EVP_DigestFinal_ex((unsigned int)md, &ctx, md, count);
  EVP_MD_CTX_cleanup((unsigned int)md, &ctx);
  for ( i = 7; i >= 0; --i )
  {
    if ( (*((_BYTE *)v15 + i))++ != 0xFF )
      break;
  }
  return count[0];
}
