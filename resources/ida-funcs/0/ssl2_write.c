int __usercall ssl2_write@<eax>(int a1@<ebx>, ssl_st *s, unsigned __int8 *_buf, int len)
{
  int result; // eax
  ssl2_state_st *s2; // ecx
  unsigned int wnum; // edi
  unsigned int v7; // ebp

  if ( (SSL_state(s) & 0x3000) != 0 && !s->in_handshake )
  {
    result = s->handshake_func(s);
    if ( result < 0 )
      return result;
    if ( !result )
    {
      ERR_put_error(a1, 0x14u, 127, 229, ".\\ssl\\s2_pkt.c", 430);
      return -1;
    }
  }
  if ( s->error )
  {
    ssl2_write_error(a1, s);
    if ( s->error )
      return -1;
  }
  SetLastError(0);
  result = len;
  s->rwstate = 1;
  if ( len > 0 )
  {
    s2 = s->s2;
    wnum = s2->wnum;
    s2->wnum = 0;
    v7 = len - wnum;
    result = n_do_ssl_write(len - wnum, s, (const __m128i *)&_buf[wnum]);
    if ( result <= 0 )
    {
LABEL_14:
      s->s2->wnum = wnum;
    }
    else
    {
      while ( result != v7 && (s->mode & 1) == 0 )
      {
        wnum += result;
        v7 -= result;
        result = n_do_ssl_write(v7, s, (const __m128i *)&_buf[wnum]);
        if ( result <= 0 )
          goto LABEL_14;
      }
      result += wnum;
    }
  }
  return result;
}
