int __cdecl ssl3_send_alert(ssl_st *s, int level, int desc)
{
  int v3; // eax
  unsigned __int8 v4; // bl

  v3 = s->method->ssl3_enc->alert_value(desc);
  v4 = v3;
  if ( s->version == 768 && v3 == 70 )
  {
    v4 = 40;
  }
  else if ( v3 < 0 )
  {
    return -1;
  }
  if ( level == 2 )
  {
    if ( s->session )
      SSL_CTX_remove_session(s->ctx, s->session);
  }
  s->s3->alert_dispatch = 1;
  s->s3->send_alert[0] = level;
  s->s3->send_alert[1] = v4;
  if ( !s->s3->wbuf.left )
    return s->method->ssl_dispatch_alert(s);
  return -1;
}
