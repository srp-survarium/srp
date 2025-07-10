int __cdecl ssl_add_serverhello_renegotiate_ext(ssl_st *s, unsigned __int8 *p, int *len, int maxlen)
{
  if ( p )
  {
    if ( s->s3->previous_server_finished_len + s->s3->previous_client_finished_len + 1 > maxlen )
    {
      ERR_put_error(0x14u, 299, 335, ".\\ssl\\t1_reneg.c", 204);
      return 0;
    }
    *p = s->s3->previous_client_finished_len + s->s3->previous_server_finished_len;
    memcpy(p + 1, s->s3->previous_client_finished, s->s3->previous_client_finished_len);
    memcpy(
      &p[s->s3->previous_client_finished_len + 1],
      s->s3->previous_server_finished,
      s->s3->previous_server_finished_len);
  }
  *len = s->s3->previous_server_finished_len + s->s3->previous_client_finished_len + 1;
  return 1;
}
