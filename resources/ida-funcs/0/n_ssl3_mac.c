unsigned int __usercall n_ssl3_mac@<eax>(int a1@<ebx>, ssl_st *ssl, unsigned __int8 *md, int send)
{
  ssl3_state_st *s3; // eax
  env_md_ctx_st *write_hash; // ebp
  ssl3_record_st *p_wrec; // esi
  unsigned int write_mac_secret; // edx
  unsigned __int8 *write_sequence; // eax
  ui_string_st *object; // eax
  int v10; // eax
  int v12; // ebx
  int i; // eax
  unsigned int v16[2]; // [esp+8h] [ebp-24h] BYREF
  unsigned __int8 *v17; // [esp+10h] [ebp-1Ch]
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
  v17 = write_sequence;
  v16[1] = write_mac_secret;
  object = X509_EXTENSION_get_object((ui_string_st *)write_hash);
  v10 = EVP_MD_size(a1, (const env_md_st *)object);
  if ( v10 < 0 )
    return -1;
  v16[0] = v10;
  v12 = v10 * (0x30u / v10);
  EVP_MD_CTX_init(&ctx);
  EVP_MD_CTX_copy_ex(v12, &ctx, write_hash);
  EVP_DigestUpdate(&ctx);
  EVP_DigestUpdate(&ctx);
  EVP_DigestUpdate(&ctx);
  EVP_DigestUpdate(&ctx);
  *md = BYTE1(p_wrec->length);
  md[1] = p_wrec->length;
  EVP_DigestUpdate(&ctx);
  EVP_DigestUpdate(&ctx);
  EVP_DigestFinal_ex((int)md, v12, &ctx, md, 0);
  EVP_MD_CTX_copy_ex(v12, &ctx, write_hash);
  EVP_DigestUpdate(&ctx);
  EVP_DigestUpdate(&ctx);
  EVP_DigestUpdate(&ctx);
  EVP_DigestFinal_ex((int)md, v12, &ctx, md, v16);
  EVP_MD_CTX_cleanup((int)md, v12, &ctx);
  for ( i = 7; i >= 0; --i )
  {
    if ( v17[i]++ != 0xFF )
      break;
  }
  return v16[0];
}
