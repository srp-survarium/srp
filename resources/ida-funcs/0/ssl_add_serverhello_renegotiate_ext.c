int __usercall ssl_add_serverhello_renegotiate_ext@<eax>(
        int a1@<ebx>,
        ssl_st *s,
        unsigned __int8 *p,
        int *len,
        int maxlen)
{
  if ( p )
  {
    if ( s->s3->previous_server_finished_len + s->s3->previous_client_finished_len + 1 > maxlen )
    {
      ERR_put_error(a1, 0x14u, 299, 335, ".\\ssl\\t1_reneg.c", 204);
      return 0;
    }
    *p = s->s3->previous_client_finished_len + s->s3->previous_server_finished_len;
    memcpy((int)(p + 1), (const __m128i *)s->s3->previous_client_finished, s->s3->previous_client_finished_len);
    memcpy(
      (int)&p[s->s3->previous_client_finished_len + 1],
      (const __m128i *)s->s3->previous_server_finished,
      s->s3->previous_server_finished_len);
  }
  *len = s->s3->previous_server_finished_len + s->s3->previous_client_finished_len + 1;
  return 1;
}
