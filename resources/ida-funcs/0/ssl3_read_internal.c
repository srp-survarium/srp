int __usercall ssl3_read_internal@<eax>(ssl_st *s@<esi>, int len@<ebx>, int peek@<edi>, unsigned __int8 *buf)
{
  int result; // eax
  const ssl_method_st *method; // edx

  SetLastError(0);
  if ( s->s3->renegotiate )
    ssl3_renegotiate_check(s);
  s->s3->in_read_app_data = 1;
  result = s->method->ssl_read_bytes(s, 23, buf, len, peek);
  if ( result == -1 && s->s3->in_read_app_data == 2 )
  {
    method = s->method;
    ++s->in_handshake;
    result = method->ssl_read_bytes(s, 23, buf, len, peek);
    --s->in_handshake;
  }
  else
  {
    s->s3->in_read_app_data = 0;
  }
  return result;
}
