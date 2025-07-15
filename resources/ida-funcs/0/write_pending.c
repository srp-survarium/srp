int __usercall write_pending@<eax>(ssl_st *s@<esi>, int a2@<ebx>, const unsigned __int8 *buf, signed int len)
{
  ssl2_state_st *s2; // eax
  bio_st *wbio; // ecx
  ssl2_state_st *v6; // eax
  int result; // eax
  ssl2_state_st *v8; // ecx
  ssl2_state_st *v9; // ecx

  s2 = s->s2;
  if ( s2->wpend_tot <= len && (s2->wpend_buf == buf || (s->mode & 2) != 0) )
  {
    while ( 1 )
    {
      SetLastError(0);
      wbio = s->wbio;
      if ( wbio )
      {
        v6 = s->s2;
        s->rwstate = 2;
        result = BIO_write(a2, wbio, (const char *)&v6->write_ptr[v6->wpend_off], v6->wpend_len);
      }
      else
      {
        ERR_put_error(a2, 0x14u, 212, 260, ".\\ssl\\s2_pkt.c", 497);
        result = -1;
      }
      v8 = s->s2;
      if ( result == v8->wpend_len )
        break;
      if ( result <= 0 )
        return result;
      v8->wpend_off += result;
      s->s2->wpend_len -= result;
    }
    v8->wpend_len = 0;
    v9 = s->s2;
    s->rwstate = 1;
    return v9->wpend_ret;
  }
  else
  {
    ERR_put_error(a2, 0x14u, 212, 127, ".\\ssl\\s2_pkt.c", 481);
    return -1;
  }
}
