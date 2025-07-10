int __cdecl ssl3_check_finished(ssl_st *s)
{
  ssl_st *v1; // esi
  int result; // eax
  ssl3_state_st *s3; // ecx

  v1 = s;
  if ( !s->session->tlsext_tick )
    return 1;
  result = s->method->ssl_get_message(s, 4400, 4401, -1, s->max_cert_list, (int *)&s);
  if ( s )
  {
    result = 1;
    v1->s3->tmp.reuse_message = 1;
    s3 = v1->s3;
    if ( s3->tmp.message_type == 20 || s3->tmp.message_type == 4 )
      return 2;
  }
  return result;
}
