int __usercall dtls1_enc@<eax>(int a1@<ebx>, ssl_st *s, int send)
{
  ssl_st *v3; // ebp
  ui_string_st *object; // eax
  const env_md_st **enc_write_ctx; // ebx
  ssl3_record_st *p_wrec; // esi
  int v7; // edi
  _iobuf *v8; // eax
  ui_string_st *v10; // eax
  signed int length; // edi
  int v12; // ebp
  int v13; // ecx
  unsigned __int8 v14; // dl
  signed int i; // eax
  int v16; // ebx
  signed int v17; // ebp
  unsigned int v18; // ecx
  _DWORD *v19; // eax
  signed int v20; // ecx
  int v21; // eax
  int v22; // [esp+10h] [ebp-4h]

  if ( send )
  {
    v3 = s;
    if ( X509_EXTENSION_get_object((ui_string_st *)s->write_hash) )
    {
      object = X509_EXTENSION_get_object((ui_string_st *)s->write_hash);
      if ( EVP_MD_size(a1, (const env_md_st *)object) < 0 )
        return -1;
    }
    enc_write_ctx = (const env_md_st **)s->enc_write_ctx;
    p_wrec = &s->s3->wrec;
    if ( enc_write_ctx )
    {
      v7 = EVP_CIPHER_CTX_cipher((const ssl_st *)s->enc_write_ctx);
      if ( p_wrec->data == p_wrec->input )
      {
        if ( EVP_CIPHER_block_size(*enc_write_ctx) > 1 )
        {
          EVP_CIPHER_block_size(*enc_write_ctx);
          if ( RAND_bytes(v7) <= 0 )
            return -1;
        }
      }
      else
      {
        v8 = __iob_func();
        fprintf(v7, v8 + 2, "%s:%d: rec->data != rec->input\n", ".\\ssl\\d1_enc.c", 155);
      }
    }
    else
    {
      v7 = 0;
    }
  }
  else
  {
    if ( X509_EXTENSION_get_object((ui_string_st *)s->read_hash) )
    {
      v10 = X509_EXTENSION_get_object((ui_string_st *)s->read_hash);
      if ( EVP_MD_size(a1, (const env_md_st *)v10) < 0 )
        return -1;
    }
    enc_write_ctx = (const env_md_st **)s->enc_read_ctx;
    p_wrec = &s->s3->rrec;
    if ( enc_write_ctx )
      v7 = EVP_CIPHER_CTX_cipher((const ssl_st *)enc_write_ctx);
    else
      v7 = 0;
    v3 = s;
  }
  if ( !v3->session || !enc_write_ctx || !v7 )
  {
    memmove((int)p_wrec->data, (const __m128i *)p_wrec->input, p_wrec->length);
    p_wrec->input = p_wrec->data;
    return 1;
  }
  length = p_wrec->length;
  v12 = EVP_CIPHER_block_size(*enc_write_ctx);
  v22 = v12;
  if ( v12 != 1 )
  {
    if ( !send )
      goto LABEL_29;
    v13 = v12 - length % v12;
    v14 = v13 - 1;
    if ( (s->options & 0x200) != 0 && (s->s3->flags & 8) != 0 )
      v14 = v12 - length % v12;
    for ( i = length; i < v13 + length; ++i )
      p_wrec->input[i] = v14;
    p_wrec->length += v13;
    length += v13;
  }
  if ( send )
    goto LABEL_31;
LABEL_29:
  if ( !length || length % (unsigned int)v12 )
    return -1;
LABEL_31:
  EVP_Cipher((evp_cipher_ctx_st *)enc_write_ctx);
  if ( v12 == 1 || send )
    return 1;
  v16 = p_wrec->data[length - 1];
  v17 = v16 + 1;
  if ( (s->options & 0x200) != 0 )
  {
    v18 = 8;
    v19 = &unk_6E5050;
    do
    {
      if ( *(_DWORD *)((char *)v19 + s->s3->read_sequence - (unsigned __int8 *)&unk_6E5050) != *v19 )
      {
        v16 = p_wrec->data[length - 1];
        goto LABEL_40;
      }
      v18 -= 4;
      ++v19;
    }
    while ( v18 >= 4 );
    v16 = p_wrec->data[length - 1];
    if ( (p_wrec->data[length - 1] & 1) == 0 )
      s->s3->flags |= 8u;
LABEL_40:
    if ( (s->s3->flags & 8) != 0 )
      --v17;
  }
  v20 = p_wrec->length;
  if ( v17 > v20 )
    return -1;
  v21 = length - v17;
  if ( length - v17 < length )
  {
    while ( p_wrec->data[v21] == v16 )
    {
      if ( ++v21 >= length )
        goto LABEL_46;
    }
    return -1;
  }
LABEL_46:
  p_wrec->data += v22;
  p_wrec->input += v22;
  p_wrec->length = v20 - v17 - v22;
  return 1;
}
