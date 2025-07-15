int __usercall read_n@<eax>(ssl_st *s@<ecx>, signed int n@<ebx>, unsigned int max, unsigned int extend)
{
  ssl2_state_st *s2; // eax
  signed int rbuf_left; // edi
  int result; // eax
  unsigned __int8 *v8; // ecx
  unsigned int packet_length; // ebp
  unsigned __int8 *packet; // ecx
  unsigned __int8 *rbuf; // eax
  int rbuf_offs; // ecx
  bool v13; // cc
  bio_st *rbio; // eax
  ssl2_state_st *v15; // edx

  s2 = s->s2;
  rbuf_left = s2->rbuf_left;
  if ( rbuf_left >= n )
  {
    if ( extend )
    {
      s->packet_length += n;
    }
    else
    {
      v8 = &s2->rbuf[s2->rbuf_offs];
      s->packet_length = n;
      s->packet = v8;
    }
    s2->rbuf_left -= n;
    s->s2->rbuf_offs += n;
    return n;
  }
  if ( !s->read_ahead )
    max = n;
  if ( max > 0x8001 )
    max = 32769;
  packet_length = 0;
  if ( rbuf_left )
  {
    if ( !extend )
    {
      rbuf_offs = s2->rbuf_offs;
      if ( rbuf_offs )
      {
        memcpy(s2->rbuf, &s2->rbuf[rbuf_offs], rbuf_left);
        s->s2->rbuf_offs = 0;
      }
      goto LABEL_19;
    }
  }
  else if ( !s->packet_length || !extend )
  {
    rbuf_left = 0;
    goto LABEL_20;
  }
  packet = s->packet;
  rbuf = s2->rbuf;
  packet_length = s->packet_length;
  if ( packet != rbuf )
    memcpy(rbuf, packet, rbuf_left + packet_length);
LABEL_19:
  s->s2->rbuf_left = 0;
LABEL_20:
  v13 = rbuf_left <= n;
  s->packet = s->s2->rbuf;
  if ( rbuf_left >= n )
  {
LABEL_25:
    if ( v13 )
    {
      s->s2->rbuf_offs = 0;
      s->s2->rbuf_left = 0;
    }
    else
    {
      s->s2->rbuf_offs = n + packet_length;
      s->s2->rbuf_left = rbuf_left - n;
    }
    if ( extend )
      s->packet_length += n;
    else
      s->packet_length = n;
    s->rwstate = 1;
    return n;
  }
  else
  {
    while ( 1 )
    {
      SetLastError(0);
      rbio = s->rbio;
      if ( !rbio )
        break;
      v15 = s->s2;
      s->rwstate = 3;
      result = BIO_read(rbio, (char *)&v15->rbuf[rbuf_left + packet_length], max - rbuf_left);
      if ( result <= 0 )
        goto LABEL_28;
      rbuf_left += result;
      if ( rbuf_left >= n )
      {
        v13 = rbuf_left <= n;
        goto LABEL_25;
      }
    }
    ERR_put_error(0x14u, 112, 211, ".\\ssl\\s2_pkt.c", 385);
    result = -1;
LABEL_28:
    s->s2->rbuf_left += rbuf_left;
  }
  return result;
}
