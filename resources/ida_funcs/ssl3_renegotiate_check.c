int __cdecl ssl3_renegotiate_check(ssl_st *s)
{
  ssl3_state_st *s3; // eax
  ssl3_state_st *v2; // eax

  s3 = s->s3;
  if ( !s3->renegotiate || s3->rbuf.left || s3->wbuf.left || (SSL_state(s) & 0x3000) != 0 )
    return 0;
  v2 = s->s3;
  s->state = 12292;
  v2->renegotiate = 0;
  ++s->s3->num_renegotiations;
  ++s->s3->total_renegotiations;
  return 1;
}
