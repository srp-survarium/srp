int __usercall server_verify@<eax>(ssl_st *s@<esi>)
{
  char *data; // eax
  ssl2_state_st *s2; // ecx
  ssl2_state_st *v4; // ecx

  if ( s->state == 8256 )
  {
    data = s->init_buf->data;
    *data = 5;
    s2 = s->s2;
    if ( s2->challenge_length > 0x20 )
    {
      ERR_put_error(0x14u, 240, 68, ".\\ssl\\s2_srvr.c", 880);
      return -1;
    }
    memcpy((unsigned __int8 *)data + 1, s2->challenge, s2->challenge_length);
    v4 = s->s2;
    s->state = 8257;
    s->init_num = v4->challenge_length + 1;
    s->init_off = 0;
  }
  return ssl2_do_write(s);
}
