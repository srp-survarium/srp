int __cdecl ssl3_shutdown(ssl_st *s)
{
  int shutdown; // eax
  int result; // eax

  if ( s->quiet_shutdown || s->state == 0x4000 )
  {
    s->shutdown = 3;
    return 1;
  }
  shutdown = s->shutdown;
  if ( (shutdown & 1) == 0 )
  {
    s->shutdown = shutdown | 1;
    ssl3_send_alert(s, 1, 0);
    if ( s->s3->alert_dispatch )
      return -1;
    return s->shutdown == 3 && !s->s3->alert_dispatch;
  }
  if ( !s->s3->alert_dispatch )
  {
    if ( (shutdown & 2) == 0 )
    {
      s->method->ssl_read_bytes(s, 0, 0, 0, 0);
      if ( (s->shutdown & 2) == 0 )
        return -1;
    }
    return s->shutdown == 3 && !s->s3->alert_dispatch;
  }
  result = s->method->ssl_dispatch_alert(s);
  if ( result != -1 )
    return s->shutdown == 3 && !s->s3->alert_dispatch;
  return result;
}
