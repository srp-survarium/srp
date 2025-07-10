int __usercall ssl23_get_server_hello@<eax>(ssl_st *s@<esi>)
{
  int result; // eax
  unsigned __int8 *packet; // edi
  int v3; // ebx
  __int16 v4; // bp
  unsigned int v5; // eax
  bool v6; // zf
  ssl2_state_st *s2; // edx
  unsigned __int8 *rbuf; // eax
  const ssl_method_st *v9; // eax
  unsigned __int8 v10; // cl
  const ssl_method_st *v11; // eax
  unsigned __int8 v12; // cl
  void (__cdecl *info_callback)(const ssl_st *, int, int); // eax
  void (__cdecl *msg_callback)(int, int, int, const void *, unsigned int, ssl_st *, void *); // eax
  ssl3_state_st *s3; // ecx
  unsigned __int8 *buf; // eax
  unsigned __int8 v17; // [esp+6h] [ebp-6h]

  result = ssl23_read_bytes(s, 7);
  if ( result == 7 )
  {
    packet = s->packet;
    v3 = *(_DWORD *)packet;
    v4 = *((_WORD *)packet + 2);
    v17 = packet[6];
    if ( (*(_DWORD *)packet & 0x80u) != 0 && packet[2] == 4 && !packet[5] && packet[6] == 2 )
    {
      if ( ((unsigned int)&vostok::memory::s_CRT_arena[5574200] & s->options) != 0 )
      {
        ERR_put_error(0x14u, 119, 258, ".\\ssl\\s23_clnt.c", 553);
        return -1;
      }
      if ( s->s2 )
      {
        ssl2_clear(s);
      }
      else if ( !ssl2_new(s) )
      {
        return -1;
      }
      v5 = (s->options & 2) != 0 ? 16 : 32;
      s->s2->challenge_length = v5;
      memcpy(s->s2->challenge, &s->s3->client_random[-v5 + 32], v5);
      if ( s->s3 )
        ssl3_free(s);
      if ( !BUF_MEM_grow_clean(s->init_buf, 0x3FFFu) )
      {
        ERR_put_error(0x14u, 119, 7, ".\\ssl\\s23_clnt.c", 585);
        return -1;
      }
      v6 = s->client_version == 2;
      s->state = 4128;
      if ( !v6 )
        s->s2->ssl2_rollback = 1;
      s2 = s->s2;
      s->rstate = 240;
      s->packet_length = 7;
      rbuf = s2->rbuf;
      s->packet = rbuf;
      *(_DWORD *)rbuf = v3;
      *((_WORD *)rbuf + 2) = v4;
      rbuf[6] = v17;
      s->s2->rbuf_left = 7;
      s->s2->rbuf_offs = 0;
      s->s2->write_sequence = 1;
      v9 = SSLv2_client_method();
      s->method = v9;
      s->handshake_func = v9->ssl_connect;
    }
    else
    {
      if ( packet[1] != 3
        || (v10 = packet[2], v10 > 1u)
        || ((_BYTE)v3 != 22 || packet[5] != 2) && ((_BYTE)v3 != 21 || packet[3] || packet[4] != 2) )
      {
        ERR_put_error(0x14u, 119, 252, ".\\ssl\\s23_clnt.c", 683);
        return -1;
      }
      if ( v10 || ((unsigned int)&vostok::memory::s_CRT_arena[22351416] & s->options) != 0 )
      {
        if ( v10 != 1 || ((unsigned int)&vostok::memory::s_CRT_arena[55905848] & s->options) != 0 )
        {
          ERR_put_error(0x14u, 119, 258, ".\\ssl\\s23_clnt.c", 631);
          return -1;
        }
        s->version = 769;
        v11 = TLSv1_client_method();
      }
      else
      {
        s->version = 768;
        v11 = SSLv3_client_method();
      }
      s->method = v11;
      if ( *packet == 21 )
      {
        v12 = packet[5];
        if ( v12 != 1 )
        {
          info_callback = s->info_callback;
          if ( info_callback || (info_callback = s->ctx->info_callback) != 0 )
            info_callback(s, 16388, packet[6] | (v12 << 8));
          msg_callback = s->msg_callback;
          if ( msg_callback )
            msg_callback(0, s->version, 21, packet + 5, 2u, s, s->msg_callback_arg);
          s->rwstate = 1;
          ERR_put_error(0x14u, 119, packet[6] + 1000, ".\\ssl\\s23_clnt.c", 658);
          return -1;
        }
      }
      if ( !ssl_init_wbio_buffer(s, 1) )
        return -1;
      s3 = s->s3;
      s->state = 4384;
      s->rstate = 240;
      s->packet_length = 7;
      if ( !s3->rbuf.buf && !ssl3_setup_read_buffer(s) )
        return -1;
      buf = s->s3->rbuf.buf;
      s->packet = buf;
      *(_DWORD *)buf = v3;
      *((_WORD *)buf + 2) = v4;
      buf[6] = v17;
      s->s3->rbuf.left = 7;
      s->s3->rbuf.offset = 0;
      s->handshake_func = s->method->ssl_connect;
    }
    s->init_num = 0;
    if ( ssl_get_new_session(s, 0) )
      return SSL_connect(s);
    return -1;
  }
  return result;
}
