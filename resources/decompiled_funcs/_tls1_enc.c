int __usercall tls1_enc@<eax>(unsigned int a1@<edi>, unsigned int a2@<esi>, ssl_st *s, int send)
{
  ui_string_st *object; // eax
  evp_cipher_ctx_st *enc_write_ctx; // ebp
  ssl3_record_st *p_wrec; // esi
  evp_cipher_ctx_st *enc_read_ctx; // eax
  ui_string_st *v9; // eax
  signed int length; // edi
  int v11; // ebp
  int v12; // ecx
  unsigned __int8 v13; // dl
  signed int i; // eax
  ssl_st *v16; // ecx
  _DWORD *v17; // eax
  unsigned int v18; // ecx
  signed int v19; // ebp
  int v20; // eax
  ssl_st *sa; // [esp+18h] [ebp+4h]
  ssl_st *sb; // [esp+18h] [ebp+4h]

  if ( send )
  {
    if ( X509_EXTENSION_get_object((ui_string_st *)s->write_hash) )
    {
      object = X509_EXTENSION_get_object((ui_string_st *)s->write_hash);
      if ( EVP_MD_size((const env_md_st *)object) < 0 )
        OpenSSLDie(a1, a2, ".\\ssl\\t1_enc.c", 651, "n >= 0");
    }
    enc_write_ctx = s->enc_write_ctx;
    p_wrec = &s->s3->wrec;
    sa = (ssl_st *)enc_write_ctx;
    if ( enc_write_ctx )
      enc_read_ctx = (evp_cipher_ctx_st *)EVP_CIPHER_CTX_cipher((const ssl_st *)enc_write_ctx);
    else
      enc_read_ctx = 0;
  }
  else
  {
    if ( X509_EXTENSION_get_object((ui_string_st *)s->read_hash) )
    {
      v9 = X509_EXTENSION_get_object((ui_string_st *)s->read_hash);
      if ( EVP_MD_size((const env_md_st *)v9) < 0 )
        OpenSSLDie(a1, a2, ".\\ssl\\t1_enc.c", 665, "n >= 0");
    }
    enc_read_ctx = s->enc_read_ctx;
    p_wrec = &s->s3->rrec;
    sa = (ssl_st *)enc_read_ctx;
    if ( enc_read_ctx )
    {
      enc_read_ctx = (evp_cipher_ctx_st *)EVP_CIPHER_CTX_cipher((const ssl_st *)enc_read_ctx);
      enc_write_ctx = (evp_cipher_ctx_st *)sa;
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
  v11 = EVP_CIPHER_block_size((const env_md_st *)enc_write_ctx->cipher);
  if ( v11 == 1 )
  {
LABEL_25:
    if ( send )
      goto LABEL_29;
    goto LABEL_26;
  }
  if ( send )
  {
    v12 = v11 - length % v11;
    v13 = v12 - 1;
    if ( (s->options & 0x200) != 0 && (s->s3->flags & 8) != 0 )
      v13 = v11 - length % v11;
    for ( i = length; i < v12 + length; ++i )
      p_wrec->input[i] = v13;
    p_wrec->length += v12;
    length += v12;
    goto LABEL_25;
  }
LABEL_26:
  if ( !length || length % (unsigned int)v11 )
  {
    ERR_put_error(0x14u, 210, 129, ".\\ssl\\t1_enc.c", 731);
    ssl3_send_alert(s, 2, 21);
    return 0;
  }
LABEL_29:
  EVP_Cipher((evp_cipher_ctx_st *)sa);
  if ( v11 == 1 || send )
    return 1;
  sb = (ssl_st *)p_wrec->data[length - 1];
  v16 = (ssl_st *)((char *)&sb->version + 1);
  if ( (s->options & 0x200) != 0 && !s->expand )
  {
    v17 = &unk_853388;
    v18 = 8;
    while ( *(_DWORD *)((char *)v17 + s->s3->read_sequence - (unsigned __int8 *)&unk_853388) == *v17 )
    {
      v18 -= 4;
      ++v17;
      if ( v18 < 4 )
      {
        if ( ((unsigned __int8)sb & 1) == 0 )
          s->s3->flags |= 8u;
        break;
      }
    }
    v16 = (ssl_st *)((char *)&sb->version + 1);
    if ( (s->s3->flags & 8) != 0 )
      v16 = sb;
  }
  v19 = p_wrec->length;
  if ( (int)v16 > v19 )
    return -1;
  v20 = length - (_DWORD)v16;
  if ( length - (int)v16 < length )
  {
    while ( (ssl_st *)p_wrec->data[v20] == sb )
    {
      if ( ++v20 >= length )
        goto LABEL_45;
    }
    return -1;
  }
LABEL_45:
  p_wrec->length = v19 - (_DWORD)v16;
  return 1;
}
