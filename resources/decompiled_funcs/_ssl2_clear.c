void __cdecl ssl2_clear(ssl_st *s)
{
  ssl2_state_st *s2; // esi
  unsigned __int8 *rbuf; // ebx
  unsigned __int8 *wbuf; // ebp

  s2 = s->s2;
  rbuf = s2->rbuf;
  wbuf = s2->wbuf;
  memset((int)s2, 0, sizeof(ssl2_state_st));
  s2->rbuf = rbuf;
  s2->wbuf = wbuf;
  s2->clear_text = 1;
  s->packet = rbuf;
  s->version = 2;
  s->packet_length = 0;
}
