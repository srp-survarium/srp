int __cdecl ssl2_write(ssl_st *s, unsigned __int8 *_buf, int len)
{
  int result; // eax
  ssl2_state_st *s2; // ecx
  unsigned int wnum; // edi
  signed int v6; // ebp

  if ( (SSL_state(s) & 0x3000) != 0 && !s->in_handshake )
  {
    result = s->handshake_func(s);
    if ( result < 0 )
      return result;
    if ( !result )
    {
      ERR_put_error(0x14u, 127, 229, ".\\ssl\\s2_pkt.c", 430);
      return -1;
    }
  }
  if ( s->error )
  {
    ssl2_write_error(s);
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
    v6 = len - wnum;
    result = n_do_ssl_write(len - wnum, s, &_buf[wnum]);
    if ( result <= 0 )
    {
LABEL_14:
      s->s2->wnum = wnum;
    }
    else
    {
      while ( result != v6 && (s->mode & 1) == 0 )
      {
        wnum += result;
        v6 -= result;
        result = n_do_ssl_write(v6, s, &_buf[wnum]);
        if ( result <= 0 )
          goto LABEL_14;
      }
      result += wnum;
    }
  }
  return result;
}
