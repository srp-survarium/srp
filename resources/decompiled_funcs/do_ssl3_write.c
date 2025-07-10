int __cdecl do_ssl3_write(
        ssl_st *s,
        int type,
        unsigned __int8 *buf,
        unsigned int len,
        unsigned int create_empty_fragment)
{
  ssl3_buffer_st *p_wbuf; // ebx
  int result; // eax
  ssl3_record_st *p_wrec; // ebp
  char v9; // al
  ui_string_st *object; // eax
  ssl3_state_st *s3; // eax
  int v12; // eax
  unsigned __int8 *v13; // esi
  unsigned __int8 *v14; // esi
  int v15; // eax
  _BYTE *v16; // esi
  _BYTE *v17; // ebx
  unsigned __int8 *v18; // esi
  unsigned int length; // ebp
  int v20; // [esp+8h] [ebp-8h]
  ssl3_buffer_st *v21; // [esp+Ch] [ebp-4h]
  int sa; // [esp+14h] [ebp+4h]

  p_wbuf = &s->s3->wbuf;
  v20 = 0;
  v21 = p_wbuf;
  if ( !p_wbuf->buf && !ssl3_setup_write_buffer(s) )
    return -1;
  if ( p_wbuf->left )
    return ssl3_write_pending(s, type, buf, len);
  if ( s->s3->alert_dispatch )
  {
    result = s->method->ssl_dispatch_alert(s);
    if ( result <= 0 )
      return result;
  }
  if ( !len && !create_empty_fragment )
    return 0;
  p_wrec = &s->s3->wrec;
  if ( !s->session || !s->enc_write_ctx || !X509_EXTENSION_get_object((ui_string_st *)s->write_hash) )
  {
    sa = 0;
    if ( create_empty_fragment )
    {
LABEL_15:
      v9 = -2;
LABEL_27:
      v14 = p_wbuf->buf;
      v15 = (v9 - (unsigned __int8)p_wbuf->buf) & 7;
      p_wbuf->offset = v15;
      v13 = &v14[v15];
      goto LABEL_28;
    }
    goto LABEL_26;
  }
  object = X509_EXTENSION_get_object((ui_string_st *)s->write_hash);
  sa = EVP_MD_size((const env_md_st *)object);
  if ( sa < 0 )
    return -1;
  if ( create_empty_fragment )
    goto LABEL_15;
  s3 = s->s3;
  if ( s3->empty_fragment_done )
  {
LABEL_26:
    v9 = 3;
    goto LABEL_27;
  }
  if ( s3->need_empty_fragments && type == 23 )
  {
    v12 = do_ssl3_write(s, 23, buf, 0, 1);
    v20 = v12;
    if ( v12 > 0 )
    {
      if ( v12 > 85 )
      {
        ERR_put_error(0x14u, 104, 68, ".\\ssl\\s3_pkt.c", 696);
        return -1;
      }
      goto LABEL_24;
    }
    return -1;
  }
LABEL_24:
  s->s3->empty_fragment_done = 1;
  if ( !v20 )
    goto LABEL_26;
  v13 = &p_wbuf->buf[p_wbuf->offset + v20];
LABEL_28:
  *v13 = type;
  p_wrec->type = type;
  v16 = v13 + 1;
  *v16++ = BYTE1(s->version);
  *v16 = s->version;
  v17 = v16 + 1;
  v18 = v16 + 3;
  p_wrec->data = v18;
  p_wrec->length = len;
  p_wrec->input = buf;
  if ( s->compress )
  {
    if ( !ssl3_do_compress(s) )
    {
      ERR_put_error(0x14u, 104, 141, ".\\ssl\\s3_pkt.c", 756);
      return -1;
    }
  }
  else
  {
    memcpy(v18, buf, len);
    p_wrec->input = p_wrec->data;
  }
  if ( sa )
  {
    if ( s->method->ssl3_enc->mac(s, &v18[p_wrec->length], 1) < 0 )
      return -1;
    p_wrec->length += sa;
    p_wrec->input = v18;
    p_wrec->data = v18;
  }
  s->method->ssl3_enc->enc(s, 1);
  *v17 = BYTE1(p_wrec->length);
  v17[1] = p_wrec->length;
  p_wrec->length += 5;
  p_wrec->type = type;
  length = p_wrec->length;
  if ( create_empty_fragment )
    return length;
  v21->left = v20 + length;
  s->s3->wpend_tot = len;
  s->s3->wpend_buf = buf;
  s->s3->wpend_type = type;
  s->s3->wpend_ret = len;
  return ssl3_write_pending(s, type, buf, len);
}
