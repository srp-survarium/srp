int __cdecl ssl23_get_client_hello(ssl_st *s)
{
  int result; // eax
  unsigned __int8 *packet; // esi
  unsigned __int8 v3; // al
  unsigned int options; // eax
  unsigned __int8 v5; // al
  unsigned int v6; // eax
  unsigned int v7; // eax
  unsigned __int8 *v8; // ecx
  int v9; // eax
  void (__cdecl *msg_callback)(int, int, int, const void *, unsigned int, ssl_st *, void *); // eax
  unsigned __int8 *v11; // ebp
  int v12; // edx
  int v13; // ebx
  int v14; // ecx
  int v15; // eax
  int v16; // ecx
  int v17; // ebx
  unsigned int v18; // eax
  char *data; // esi
  unsigned __int8 *v20; // ebp
  unsigned __int8 *v21; // esi
  _DWORD *v22; // esi
  unsigned int v23; // edx
  _BYTE *v24; // esi
  _BYTE *v25; // edx
  __int16 v26; // cx
  _BYTE *v27; // esi
  unsigned int i; // eax
  _BYTE *v29; // esi
  unsigned int v30; // eax
  unsigned int v31; // eax
  ssl2_state_st *s2; // edx
  const ssl_method_st *v33; // eax
  ssl3_state_st *s3; // edx
  ssl3_state_st *v35; // ecx
  const ssl_method_st *v36; // eax
  unsigned __int8 *rbuf; // [esp-Ch] [ebp-40h]
  unsigned __int8 *buf; // [esp-Ch] [ebp-40h]
  int v39; // [esp+10h] [ebp-24h]
  int count; // [esp+14h] [ebp-20h]
  unsigned __int8 v41; // [esp+1Ch] [ebp-18h]
  _BYTE *v42; // [esp+20h] [ebp-14h]
  __m128i src; // [esp+24h] [ebp-10h] BYREF

  count = 0;
  v39 = 0;
  if ( s->state != 8720 )
    goto LABEL_35;
  if ( !ssl3_setup_buffers(s) )
    return -1;
  result = ssl23_read_bytes(s, 0xBu);
  count = result;
  if ( result != 11 )
    return result;
  packet = s->packet;
  src.m128i_i64[0] = *(_QWORD *)packet;
  src.m128i_i16[4] = *((_WORD *)packet + 4);
  src.m128i_i8[10] = packet[10];
  if ( (*packet & 0x80u) != 0 && packet[2] == 1 )
  {
    v3 = packet[3];
    if ( v3 || packet[4] != 2 )
    {
      if ( v3 == 3 )
      {
        options = s->options;
        if ( !packet[4] || (options & 0x4000000) != 0 )
        {
          if ( (options & 0x2000000) != 0 )
          {
            if ( (options & 0x1000000) == 0 )
              v39 = 1;
          }
          else
          {
            s->version = 768;
            s->state = 8721;
          }
        }
        else
        {
          s->version = 769;
          s->state = 8721;
        }
      }
    }
    else
    {
      v39 = (s->options & 0x1000000) == 0;
    }
    goto LABEL_35;
  }
  if ( *packet == 22 && packet[1] == 3 && packet[5] == 1 && ((v5 = packet[3]) == 0 && packet[4] < 5u || packet[9] >= 3u) )
  {
    if ( (v5 || packet[4] >= 6u) && packet[9] <= 3u && !packet[10] )
    {
      v7 = s->options;
      if ( (v7 & 0x2000000) == 0 )
      {
        s->version = 768;
LABEL_34:
        v39 = 3;
        goto LABEL_35;
      }
      if ( (v7 & 0x4000000) != 0 )
        goto LABEL_35;
    }
    else
    {
      v6 = s->options;
      if ( (v6 & 0x4000000) != 0 )
      {
        if ( (v6 & 0x2000000) != 0 )
          goto LABEL_35;
        s->version = 768;
        goto LABEL_34;
      }
    }
    s->version = 769;
    goto LABEL_34;
  }
  if ( !strncmp("GET ", (const char *)packet, 4u)
    || !strncmp("POST ", (const char *)packet, 5u)
    || !strncmp("HEAD ", (const char *)packet, 5u)
    || !strncmp("PUT ", (const char *)packet, 4u) )
  {
    ERR_put_error(8721, 0x14u, 118, 156, ".\\ssl\\s23_srvr.c", 386);
    return -1;
  }
  if ( !strncmp("CONNECT", (const char *)packet, 7u) )
  {
    ERR_put_error(8721, 0x14u, 118, 155, ".\\ssl\\s23_srvr.c", 391);
    return -1;
  }
LABEL_35:
  if ( s->state == 8721 )
  {
    v8 = s->packet;
    v9 = v8[1] | ((*v8 & 0x7F) << 8);
    v39 = 2;
    v41 = v8[4];
    count = v9;
    if ( v9 > 4096 )
    {
      ERR_put_error(8721, 0x14u, 118, 214, ".\\ssl\\s23_srvr.c", 409);
      return -1;
    }
    result = ssl23_read_bytes(s, v9 + 2);
    if ( result <= 0 )
      return result;
    ssl3_finish_mac(s, (const char *)s->packet + 2, s->packet_length - 2);
    msg_callback = s->msg_callback;
    if ( msg_callback )
      msg_callback(0, 2, 0, s->packet + 2, s->packet_length - 2, s, s->msg_callback_arg);
    v11 = s->packet;
    v12 = v11[6];
    v13 = v11[5];
    v11 += 5;
    v14 = v11[2];
    v15 = v11[3];
    v11 += 4;
    v16 = v15 | (v14 << 8);
    v17 = v12 | (v13 << 8);
    v18 = v11[1] | (*v11 << 8);
    data = s->init_buf->data;
    v20 = v11 + 2;
    if ( v18 + v16 + v17 + 11 != s->packet_length )
    {
      ERR_put_error(v17, 0x14u, 118, 213, ".\\ssl\\s23_srvr.c", 430);
      return -1;
    }
    *data = 1;
    v42 = data + 1;
    v21 = (unsigned __int8 *)(data + 4);
    *v21++ = 3;
    *v21 = v41;
    v22 = v21 + 1;
    v23 = 32;
    if ( v18 <= 0x20 )
      v23 = v18;
    *v22 = 0;
    v22[1] = 0;
    v22[2] = 0;
    v22[3] = 0;
    v22[4] = 0;
    v22[5] = 0;
    v22[6] = 0;
    v22[7] = 0;
    memcpy((int)v22 - v23 + 32, (const __m128i *)&v20[v17 + v16], v23);
    v24 = v22 + 8;
    *v24 = 0;
    v25 = v24 + 1;
    v26 = 0;
    v27 = v24 + 3;
    for ( i = 0; i < v17; i += 3 )
    {
      if ( !v20[i] )
      {
        *v27 = v20[i + 1];
        v29 = v27 + 1;
        *v29 = v20[i + 2];
        v27 = v29 + 1;
        v26 += 2;
      }
    }
    v25[1] = v26;
    *v25 = HIBYTE(v26);
    *v27 = 1;
    v27[1] = 0;
    v30 = v27 + 1 - s->init_buf->data - 3;
    *v42 = BYTE2(v30);
    v42[2] = v30;
    v42[1] = BYTE1(v30);
    s->s3->tmp.reuse_message = 1;
    s->s3->tmp.message_type = 1;
    s->s3->tmp.message_size = v30;
LABEL_71:
    if ( !ssl_init_wbio_buffer(v17, s, 1) )
      return -1;
    v17 = v39;
    s->state = 8464;
    if ( v39 == 3 )
    {
      s3 = s->s3;
      s->rstate = 240;
      s->packet_length = count;
      if ( !s3->rbuf.buf && !ssl3_setup_read_buffer(s) )
        return -1;
      buf = s->s3->rbuf.buf;
      s->packet = buf;
      memcpy((int)buf, &src, count);
      s->s3->rbuf.left = count;
      s->s3->rbuf.offset = 0;
    }
    else
    {
      v35 = s->s3;
      s->packet_length = 0;
      v35->rbuf.left = 0;
      s->s3->rbuf.offset = 0;
    }
    if ( s->version == 769 )
      v36 = TLSv1_server_method();
    else
      v36 = SSLv3_server_method();
    s->method = v36;
    s->handshake_func = v36->ssl_accept;
LABEL_81:
    if ( v17 >= 1 )
    {
      s->init_num = 0;
      return SSL_accept(v17, s);
    }
    ERR_put_error(v17, 0x14u, 118, 252, ".\\ssl\\s23_srvr.c", 584);
    return -1;
  }
  v17 = v39;
  if ( v39 != 1 )
  {
    if ( v39 != 3 )
      goto LABEL_81;
    goto LABEL_71;
  }
  if ( s->s2 )
  {
    ssl2_clear(s);
  }
  else if ( !ssl2_new(s) )
  {
    return -1;
  }
  if ( s->s3 )
    ssl3_free((int)s, s);
  if ( !BUF_MEM_grow_clean(s->init_buf, 0x3FFFu) )
    return -1;
  v31 = s->options;
  s->state = 8208;
  s->s2->ssl2_rollback = (v31 & 0x4000000) == 0 || (v31 & 0x2000000) == 0;
  s2 = s->s2;
  s->rstate = 240;
  s->packet_length = count;
  rbuf = s2->rbuf;
  s->packet = rbuf;
  memcpy((int)rbuf, &src, count);
  s->s2->rbuf_left = count;
  s->s2->rbuf_offs = 0;
  v33 = SSLv2_server_method();
  s->method = v33;
  s->handshake_func = v33->ssl_accept;
  s->init_num = 0;
  return SSL_accept(1, s);
}
