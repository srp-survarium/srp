int __cdecl dtls1_enc(ssl_st *s, int send)
{
  ssl_st *v2; // ebp
  ui_string_st *object; // eax
  const env_md_st **enc_write_ctx; // ebx
  ssl3_record_st *p_wrec; // esi
  int v6; // edi
  _iobuf *v7; // eax
  ui_string_st *v9; // eax
  signed int length; // edi
  int v11; // ebp
  int v12; // ecx
  unsigned __int8 v13; // dl
  signed int i; // eax
  int v15; // ebx
  signed int v16; // ebp
  unsigned int v17; // ecx
  _DWORD *v18; // eax
  signed int v19; // ecx
  int v20; // eax
  int v21; // [esp+10h] [ebp-4h]

  if ( send )
  {
    v2 = s;
    if ( X509_EXTENSION_get_object((ui_string_st *)s->write_hash) )
    {
      object = X509_EXTENSION_get_object((ui_string_st *)s->write_hash);
      if ( EVP_MD_size((const env_md_st *)object) < 0 )
        return -1;
    }
    enc_write_ctx = (const env_md_st **)s->enc_write_ctx;
    p_wrec = &s->s3->wrec;
    if ( enc_write_ctx )
    {
      v6 = EVP_CIPHER_CTX_cipher((const ssl_st *)s->enc_write_ctx);
      if ( p_wrec->data == p_wrec->input )
      {
        if ( EVP_CIPHER_block_size(*enc_write_ctx) > 1 )
        {
          EVP_CIPHER_block_size(*enc_write_ctx);
          if ( RAND_bytes() <= 0 )
            return -1;
        }
      }
      else
      {
        v7 = __iob_func();
        fprintf(v7 + 2, "%s:%d: rec->data != rec->input\n", ".\\ssl\\d1_enc.c", 155);
      }
    }
    else
    {
      v6 = 0;
    }
  }
  else
  {
    if ( X509_EXTENSION_get_object((ui_string_st *)s->read_hash) )
    {
      v9 = X509_EXTENSION_get_object((ui_string_st *)s->read_hash);
      if ( EVP_MD_size((const env_md_st *)v9) < 0 )
        return -1;
    }
    enc_write_ctx = (const env_md_st **)s->enc_read_ctx;
    p_wrec = &s->s3->rrec;
    if ( enc_write_ctx )
      v6 = EVP_CIPHER_CTX_cipher((const ssl_st *)enc_write_ctx);
    else
      v6 = 0;
    v2 = s;
  }
  if ( !v2->session || !enc_write_ctx || !v6 )
  {
    memmove(p_wrec->data, p_wrec->input, p_wrec->length);
    p_wrec->input = p_wrec->data;
    return 1;
  }
  length = p_wrec->length;
  v11 = EVP_CIPHER_block_size(*enc_write_ctx);
  v21 = v11;
  if ( v11 != 1 )
  {
    if ( !send )
      goto LABEL_29;
    v12 = v11 - length % v11;
    v13 = v12 - 1;
    if ( (s->options & 0x200) != 0 && (s->s3->flags & 8) != 0 )
      v13 = v11 - length % v11;
    for ( i = length; i < v12 + length; ++i )
      p_wrec->input[i] = v13;
    p_wrec->length += v12;
    length += v12;
  }
  if ( send )
    goto LABEL_31;
LABEL_29:
  if ( !length || length % (unsigned int)v11 )
    return -1;
LABEL_31:
  EVP_Cipher((evp_cipher_ctx_st *)enc_write_ctx);
  if ( v11 == 1 || send )
    return 1;
  v15 = p_wrec->data[length - 1];
  v16 = v15 + 1;
  if ( (s->options & 0x200) != 0 )
  {
    v17 = 8;
    v18 = &unk_853388;
    do
    {
      if ( *(_DWORD *)((char *)v18 + s->s3->read_sequence - (unsigned __int8 *)&unk_853388) != *v18 )
      {
        v15 = p_wrec->data[length - 1];
        goto LABEL_40;
      }
      v17 -= 4;
      ++v18;
    }
    while ( v17 >= 4 );
    v15 = p_wrec->data[length - 1];
    if ( (p_wrec->data[length - 1] & 1) == 0 )
      s->s3->flags |= 8u;
LABEL_40:
    if ( (s->s3->flags & 8) != 0 )
      --v16;
  }
  v19 = p_wrec->length;
  if ( v16 > v19 )
    return -1;
  v20 = length - v16;
  if ( length - v16 < length )
  {
    while ( p_wrec->data[v20] == v15 )
    {
      if ( ++v20 >= length )
        goto LABEL_46;
    }
    return -1;
  }
LABEL_46:
  p_wrec->data += v21;
  p_wrec->input += v21;
  p_wrec->length = v19 - v16 - v21;
  return 1;
}
