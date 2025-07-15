int __cdecl ssl3_write_bytes(ssl_st *s, int type, char *buf_, int len)
{
  ssl3_state_st *s3; // eax
  unsigned int wnum; // ebp
  int result; // eax
  unsigned int v8; // ecx
  unsigned int max_send_fragment; // edi
  unsigned __int8 *v10; // ebp
  ssl3_buffer_st *p_wbuf; // ebx
  ssl3_record_st *p_wrec; // edi
  int v13; // eax
  unsigned __int8 *v14; // ebp
  _BYTE *v15; // ebp
  unsigned __int8 *v16; // ebp
  ui_string_st *object; // eax
  ssl3_state_st *v18; // eax
  int v19; // eax
  int v21; // [esp+8h] [ebp-18h]
  unsigned int count; // [esp+Ch] [ebp-14h]
  unsigned int i; // [esp+10h] [ebp-10h]
  int v24; // [esp+14h] [ebp-Ch]
  unsigned __int8 *src; // [esp+18h] [ebp-8h]
  _BYTE *v26; // [esp+1Ch] [ebp-4h]
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
      ERR_put_error(0x14u, 158, 229, ".\\ssl\\s3_pkt.c", 591);
      return -1;
    }
  }
  v8 = len - wnum;
  for ( i = len - wnum; ; v8 = i )
  {
    if ( v8 <= s->max_send_fragment )
    {
      count = v8;
      max_send_fragment = v8;
    }
    else
    {
      max_send_fragment = s->max_send_fragment;
      count = max_send_fragment;
    }
    v10 = (unsigned __int8 *)&buf_[wnum];
    p_wbuf = &s->s3->wbuf;
    src = v10;
    v21 = 0;
    if ( !p_wbuf->buf && !ssl3_setup_write_buffer(s) )
      goto LABEL_25;
    if ( p_wbuf->left )
    {
      result = ssl3_write_pending(s, type, v10, max_send_fragment);
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
      v24 = 0;
LABEL_21:
      v13 = (3 - (unsigned __int8)p_wbuf->buf) & 7;
      v14 = &p_wbuf->buf[v13];
      p_wbuf->offset = v13;
      goto LABEL_22;
    }
    object = X509_EXTENSION_get_object((ui_string_st *)s->write_hash);
    v24 = EVP_MD_size((const env_md_st *)object);
    if ( v24 < 0 )
      goto LABEL_25;
    v18 = s->s3;
    if ( v18->empty_fragment_done )
      goto LABEL_21;
    if ( v18->need_empty_fragments && type == 23 )
    {
      v19 = do_ssl3_write(s, 23, v10, 0, 1u);
      v21 = v19;
      if ( v19 <= 0 )
        goto LABEL_25;
      if ( v19 > 85 )
      {
        ERR_put_error(0x14u, 104, 68, ".\\ssl\\s3_pkt.c", 696);
        goto LABEL_25;
      }
    }
    s->s3->empty_fragment_done = 1;
    if ( !v21 )
      goto LABEL_21;
    v14 = &p_wbuf->buf[p_wbuf->offset + v21];
LABEL_22:
    *v14 = type;
    p_wrec->type = type;
    v15 = v14 + 1;
    *v15 = BYTE1(s->version);
    v15[1] = s->version;
    v26 = v15 + 2;
    v16 = v15 + 4;
    p_wrec->data = v16;
    p_wrec->length = count;
    p_wrec->input = src;
    if ( s->compress )
    {
      if ( !ssl3_do_compress(s) )
      {
        ERR_put_error(0x14u, 104, 141, ".\\ssl\\s3_pkt.c", 756);
LABEL_25:
        result = -1;
LABEL_26:
        s->s3->wnum = ssl;
        return result;
      }
    }
    else
    {
      memcpy(v16, src, count);
      p_wrec->input = p_wrec->data;
    }
    if ( v24 )
    {
      if ( s->method->ssl3_enc->mac(s, &v16[p_wrec->length], 1) < 0 )
        goto LABEL_25;
      p_wrec->length += v24;
      p_wrec->input = v16;
      p_wrec->data = v16;
    }
    s->method->ssl3_enc->enc(s, 1);
    *v26 = BYTE1(p_wrec->length);
    v26[1] = p_wrec->length;
    p_wrec->length += 5;
    p_wrec->type = type;
    p_wbuf->left = v21 + p_wrec->length;
    s->s3->wpend_tot = count;
    s->s3->wpend_buf = src;
    s->s3->wpend_type = type;
    s->s3->wpend_ret = count;
    result = ssl3_write_pending(s, type, src, count);
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
