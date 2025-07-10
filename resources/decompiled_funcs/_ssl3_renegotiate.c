int __cdecl ssl3_renegotiate(ssl_st *s)
{
  ssl3_state_st *s3; // eax

  if ( s->handshake_func )
  {
    s3 = s->s3;
    if ( (s3->flags & 1) != 0 )
      return 0;
    s3->renegotiate = 1;
  }
  return 1;
}
