int __usercall server_finish@<eax>(ssl_st *s@<esi>, int a2@<ebx>)
{
  char *data; // eax
  ssl_session_st *session; // ecx
  ssl_session_st *v5; // ecx

  if ( s->state == 8288 )
  {
    data = s->init_buf->data;
    *data = 6;
    session = s->session;
    if ( session->session_id_length > 0x20 )
    {
      ERR_put_error(a2, 0x14u, 239, 68, ".\\ssl\\s2_srvr.c", 904);
      return -1;
    }
    memcpy((int)(data + 1), (const __m128i *)session->session_id, session->session_id_length);
    v5 = s->session;
    s->state = 8289;
    s->init_num = v5->session_id_length + 1;
    s->init_off = 0;
  }
  return ssl2_do_write(s);
}
