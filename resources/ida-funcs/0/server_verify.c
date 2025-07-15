int __usercall server_verify@<eax>(ssl_st *s@<esi>, int a2@<ebx>)
{
  char *data; // eax
  ssl2_state_st *s2; // ecx
  ssl2_state_st *v5; // ecx

  if ( s->state == 8256 )
  {
    data = s->init_buf->data;
    *data = 5;
    s2 = s->s2;
    if ( s2->challenge_length > 0x20 )
    {
      ERR_put_error(a2, 0x14u, 240, 68, ".\\ssl\\s2_srvr.c", 880);
      return -1;
    }
    memcpy((int)(data + 1), (const __m128i *)s2->challenge, s2->challenge_length);
    v5 = s->s2;
    s->state = 8257;
    s->init_num = v5->challenge_length + 1;
    s->init_off = 0;
  }
  return ssl2_do_write(s);
}
