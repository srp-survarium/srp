int __usercall ssl3_write_bytes@<eax>(int a1@<ebx>, ssl_st *s, int type, char *buf_, int len)
{
  ssl3_state_st *s3; // eax
  unsigned int wnum; // ebp
  int result; // eax
  unsigned int v9; // ecx
  unsigned int max_send_fragment; // edi
  __m128i *v11; // ebp
  ssl3_buffer_st *p_wbuf; // ebx
  ssl3_record_st *p_wrec; // edi
  int v14; // eax
  unsigned __int8 *v15; // ebp
  _BYTE *v16; // ebp
  int v17; // ebp
  ui_string_st *object; // eax
  ssl3_state_st *v19; // eax
  int v20; // eax
  int v22; // [esp+8h] [ebp-18h]
  unsigned int count; // [esp+Ch] [ebp-14h]
  unsigned int i; // [esp+10h] [ebp-10h]
  int v25; // [esp+14h] [ebp-Ch]
  const __m128i *src; // [esp+18h] [ebp-8h]
  _BYTE *v27; // [esp+1Ch] [ebp-4h]
  unsigned int ssl; // [esp+24h] [ebp+4h]

  s3 = s->s3;
  s->rwstate = 1;
  wnum = s3->wnum;
  ssl = wnum;
  s3->wnum = 0;
  if ( (SSL_state(s) & 0x3000) != 0 && !s->in_handshake )
  {
    result = s->handshake_func(s);
    if ( result < 0 )
      return result;
    if ( !result )
    {
      ERR_put_error(a1, 0x14u, 158, 229, ".\\ssl\\s3_pkt.c", 591);
      return -1;
    }
  }
  v9 = len - wnum;
  for ( i = len - wnum; ; v9 = i )
  {
    if ( v9 <= s->max_send_fragment )
    {
      count = v9;
      max_send_fragment = v9;
    }
    else
    {
      max_send_fragment = s->max_send_fragment;
      count = max_send_fragment;
    }
    v11 = (__m128i *)&buf_[wnum];
    p_wbuf = &s->s3->wbuf;
    src = v11;
    v22 = 0;
    if ( !p_wbuf->buf && !ssl3_setup_write_buffer(s) )
      goto LABEL_25;
    if ( p_wbuf->left )
    {
      result = ssl3_write_pending((int)p_wbuf, s, type, (const unsigned __int8 *)v11, max_send_fragment);
      goto LABEL_40;
    }
    if ( s->s3->alert_dispatch )
    {
      result = s->method->ssl_dispatch_alert(s);
      if ( result <= 0 )
        goto LABEL_26;
    }
    if ( !max_send_fragment )
    {
      result = 0;
      s->s3->wnum = ssl;
      return result;
    }
    p_wrec = &s->s3->wrec;
    if ( !s->session || !s->enc_write_ctx || !X509_EXTENSION_get_object((ui_string_st *)s->write_hash) )
    {
      v25 = 0;
LABEL_21:
      v14 = (3 - (unsigned __int8)p_wbuf->buf) & 7;
      v15 = &p_wbuf->buf[v14];
      p_wbuf->offset = v14;
      goto LABEL_22;
    }
    object = X509_EXTENSION_get_object((ui_string_st *)s->write_hash);
    v25 = EVP_MD_size((int)p_wbuf, (const env_md_st *)object);
    if ( v25 < 0 )
      goto LABEL_25;
    v19 = s->s3;
    if ( v19->empty_fragment_done )
      goto LABEL_21;
    if ( v19->need_empty_fragments && type == 23 )
    {
      v20 = do_ssl3_write(s, 23, v11, 0, 1u);
      v22 = v20;
      if ( v20 <= 0 )
        goto LABEL_25;
      if ( v20 > 85 )
      {
        ERR_put_error((int)p_wbuf, 0x14u, 104, 68, ".\\ssl\\s3_pkt.c", 696);
        goto LABEL_25;
      }
    }
    s->s3->empty_fragment_done = 1;
    if ( !v22 )
      goto LABEL_21;
    v15 = &p_wbuf->buf[p_wbuf->offset + v22];
LABEL_22:
    *v15 = type;
    p_wrec->type = type;
    v16 = v15 + 1;
    *v16 = BYTE1(s->version);
    v16[1] = s->version;
    v27 = v16 + 2;
    v17 = (int)(v16 + 4);
    p_wrec->data = (unsigned __int8 *)v17;
    p_wrec->length = count;
    p_wrec->input = (unsigned __int8 *)src;
    if ( s->compress )
    {
      if ( !ssl3_do_compress(s) )
      {
        ERR_put_error((int)p_wbuf, 0x14u, 104, 141, ".\\ssl\\s3_pkt.c", 756);
LABEL_25:
        result = -1;
LABEL_26:
        s->s3->wnum = ssl;
        return result;
      }
    }
    else
    {
      memcpy(v17, src, count);
      p_wrec->input = p_wrec->data;
    }
    if ( v25 )
    {
      if ( s->method->ssl3_enc->mac(s, (unsigned __int8 *)(v17 + p_wrec->length), 1) < 0 )
        goto LABEL_25;
      p_wrec->length += v25;
      p_wrec->input = (unsigned __int8 *)v17;
      p_wrec->data = (unsigned __int8 *)v17;
    }
    s->method->ssl3_enc->enc(s, 1);
    *v27 = BYTE1(p_wrec->length);
    v27[1] = p_wrec->length;
    p_wrec->length += 5;
    p_wrec->type = type;
    p_wbuf->left = v22 + p_wrec->length;
    s->s3->wpend_tot = count;
    s->s3->wpend_buf = (const unsigned __int8 *)src;
    s->s3->wpend_type = type;
    s->s3->wpend_ret = count;
    result = ssl3_write_pending((int)p_wbuf, s, type, (const unsigned __int8 *)src, count);
LABEL_40:
    if ( result <= 0 )
      goto LABEL_26;
    if ( result == i || type == 23 && (s->mode & 1) != 0 )
      break;
    i -= result;
    ssl += result;
    wnum = ssl;
  }
  s->s3->empty_fragment_done = 0;
  result += ssl;
  return result;
}
