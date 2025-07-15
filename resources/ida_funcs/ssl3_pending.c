unsigned int __cdecl ssl3_pending(const ssl_st *s)
{
  ssl3_state_st *s3; // eax

  if ( s->rstate == 241 )
    return 0;
  s3 = s->s3;
  if ( s3->rrec.type != 23 )
    return 0;
  else
    return s3->rrec.length;
}
