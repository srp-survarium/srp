int __cdecl ssl3_enc(ssl_st *s, int send)
{
  evp_cipher_ctx_st *enc_write_ctx; // ebx
  ssl3_record_st *p_wrec; // esi
  evp_cipher_ctx_st *enc_read_ctx; // eax
  unsigned int length; // edi
  int v6; // ebp
  unsigned int v7; // ebx
  int v9; // eax
  evp_cipher_ctx_st *v10; // [esp+10h] [ebp-4h]

  if ( send )
  {
    enc_write_ctx = s->enc_write_ctx;
    p_wrec = &s->s3->wrec;
    v10 = enc_write_ctx;
    if ( enc_write_ctx )
      enc_read_ctx = (evp_cipher_ctx_st *)EVP_CIPHER_CTX_cipher((const ssl_st *)enc_write_ctx);
    else
      enc_read_ctx = 0;
  }
  else
  {
    enc_read_ctx = s->enc_read_ctx;
    p_wrec = &s->s3->rrec;
    v10 = enc_read_ctx;
    if ( enc_read_ctx )
    {
      enc_read_ctx = (evp_cipher_ctx_st *)EVP_CIPHER_CTX_cipher((const ssl_st *)enc_read_ctx);
      enc_write_ctx = v10;
    }
    else
    {
      enc_write_ctx = 0;
    }
  }
  if ( !s->session || !enc_write_ctx || !enc_read_ctx )
  {
    memmove(p_wrec->data, p_wrec->input, p_wrec->length);
    p_wrec->input = p_wrec->data;
    return 1;
  }
  length = p_wrec->length;
  v6 = EVP_CIPHER_block_size((const env_md_st *)enc_write_ctx->cipher);
  if ( v6 == 1 )
  {
LABEL_14:
    if ( send )
      goto LABEL_18;
    goto LABEL_15;
  }
  if ( send )
  {
    v7 = v6 - (int)length % v6;
    length += v7;
    memset((int)&p_wrec->input[p_wrec->length], 0, v7);
    p_wrec->length += v7;
    p_wrec->input[length - 1] = v7 - 1;
    enc_write_ctx = v10;
    goto LABEL_14;
  }
LABEL_15:
  if ( !length || length % v6 )
  {
    ERR_put_error(0x14u, 134, 129, ".\\ssl\\s3_enc.c", 525);
    ssl3_send_alert(s, 2, 21);
    return 0;
  }
LABEL_18:
  EVP_Cipher(enc_write_ctx);
  if ( v6 == 1 || send )
    return 1;
  v9 = p_wrec->data[length - 1] + 1;
  if ( v9 > v6 )
    return -1;
  p_wrec->length -= v9;
  return 1;
}
