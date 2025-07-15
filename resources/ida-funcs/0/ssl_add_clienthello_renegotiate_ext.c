int __cdecl ssl_add_clienthello_renegotiate_ext(ssl_st *s, unsigned __int8 *p, int *len, int maxlen)
{
  ssl3_state_st *s3; // eax

  if ( p )
  {
    s3 = s->s3;
    if ( s3->previous_client_finished_len + 1 > maxlen )
    {
      ERR_put_error(0x14u, 298, 335, ".\\ssl\\t1_reneg.c", 123);
      return 0;
    }
    *p = s3->previous_client_finished_len;
    memcpy(p + 1, s->s3->previous_client_finished, s->s3->previous_client_finished_len);
  }
  *len = s->s3->previous_client_finished_len + 1;
  return 1;
}
