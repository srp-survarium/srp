int __cdecl ssl3_dispatch_alert(ssl_st *s)
{
  ssl3_state_st *s3; // ebx
  int result; // eax
  ssl3_record_st *p_wrec; // ebp
  ui_string_st *object; // eax
  ssl3_state_st *v6; // eax
  unsigned __int8 *buf; // ecx
  int v8; // eax
  unsigned __int8 *v9; // edi
  int v10; // edi
  void (__cdecl *msg_callback)(int, int, int, const void *, unsigned int, ssl_st *, void *); // eax
  void (__cdecl *info_callback)(const ssl_st *, int, int); // ecx
  const unsigned __int8 *send_alert; // [esp+10h] [ebp-8h]
  unsigned __int8 *v14; // [esp+14h] [ebp-4h]
  int sa; // [esp+1Ch] [ebp+4h]

  s->s3->alert_dispatch = 0;
  s3 = s->s3;
  send_alert = s3->send_alert;
  if ( !s3->wbuf.buf && !ssl3_setup_write_buffer(s) )
    goto LABEL_3;
  if ( s3->wbuf.left )
  {
    result = ssl3_write_pending((int)s3, s, 21, s3->send_alert, 2);
    goto LABEL_23;
  }
  if ( !s->s3->alert_dispatch || (result = s->method->ssl_dispatch_alert(s), result > 0) )
  {
    p_wrec = &s->s3->wrec;
    if ( s->session && s->enc_write_ctx && X509_EXTENSION_get_object((ui_string_st *)s->write_hash) )
    {
      object = X509_EXTENSION_get_object((ui_string_st *)s->write_hash);
      sa = EVP_MD_size((int)s3, (const env_md_st *)object);
      if ( sa < 0 )
      {
LABEL_3:
        s->s3->alert_dispatch = 1;
        return -1;
      }
      v6 = s->s3;
      if ( !v6->empty_fragment_done )
        v6->empty_fragment_done = 1;
    }
    else
    {
      sa = 0;
    }
    buf = s3->wbuf.buf;
    v8 = (3 - (_BYTE)buf) & 7;
    s3->wbuf.offset = v8;
    buf[v8] = 21;
    p_wrec->type = 21;
    buf[v8 + 1] = BYTE1(s->version);
    buf[v8 + 2] = s->version;
    v14 = &buf[v8 + 3];
    v9 = &buf[v8 + 5];
    p_wrec->data = v9;
    p_wrec->length = 2;
    p_wrec->input = (unsigned __int8 *)send_alert;
    if ( s->compress )
    {
      if ( !ssl3_do_compress(s) )
      {
        ERR_put_error((int)s3, 0x14u, 104, 141, ".\\ssl\\s3_pkt.c", 756);
        goto LABEL_3;
      }
    }
    else
    {
      *(_WORD *)v9 = *(_WORD *)send_alert;
      p_wrec->input = p_wrec->data;
    }
    if ( sa )
    {
      if ( s->method->ssl3_enc->mac(s, &v9[p_wrec->length], 1) < 0 )
        goto LABEL_3;
      p_wrec->length += sa;
      p_wrec->input = v9;
      p_wrec->data = v9;
    }
    s->method->ssl3_enc->enc(s, 1);
    *v14 = BYTE1(p_wrec->length);
    v14[1] = p_wrec->length;
    p_wrec->length += 5;
    p_wrec->type = 21;
    s3->wbuf.left = p_wrec->length;
    s->s3->wpend_tot = 2;
    s->s3->wpend_buf = send_alert;
    s->s3->wpend_type = 21;
    s->s3->wpend_ret = 2;
    result = ssl3_write_pending((int)s3, s, 21, send_alert, 2);
  }
LABEL_23:
  v10 = result;
  if ( result > 0 )
  {
    if ( s->s3->send_alert[0] == 2 )
      BIO_ctrl((int)s3, s->wbio, 11, 0, 0);
    msg_callback = s->msg_callback;
    if ( msg_callback )
      msg_callback(1, s->version, 21, s->s3->send_alert, 2u, s, s->msg_callback_arg);
    info_callback = s->info_callback;
    if ( info_callback || (info_callback = s->ctx->info_callback) != 0 )
      info_callback(s, 16392, s->s3->send_alert[1] | (s->s3->send_alert[0] << 8));
    return v10;
  }
  else
  {
    s->s3->alert_dispatch = 1;
  }
  return result;
}
