int __usercall ssl3_write@<eax>(unsigned int a1@<edi>, ssl_st *s, void *buf, int len)
{
  ssl3_state_st *s3; // eax
  int result; // eax
  ssl3_state_st *v6; // esi
  bio_st *wbio; // [esp-10h] [ebp-14h]

  SetLastError(0);
  if ( s->s3->renegotiate )
    ssl3_renegotiate_check(s);
  s3 = s->s3;
  if ( (s3->flags & 4) == 0 || s->wbio != s->bbio )
    return s->method->ssl_write_bytes(s, 23, buf, len);
  if ( !s3->delay_buf_pop_ret )
  {
    result = ssl3_write_bytes(s, 23, (char *)buf, len);
    if ( result <= 0 )
      return result;
    s->s3->delay_buf_pop_ret = result;
  }
  wbio = s->wbio;
  s->rwstate = 2;
  result = BIO_ctrl(wbio, 11, 0, 0);
  if ( result > 0 )
  {
    s->rwstate = 1;
    ssl_free_wbio_buffer(a1, s);
    s->s3->flags &= ~4u;
    v6 = s->s3;
    result = v6->delay_buf_pop_ret;
    v6->delay_buf_pop_ret = 0;
  }
  return result;
}
