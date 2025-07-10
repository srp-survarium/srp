int __usercall server_hello@<eax>(ssl_st *s@<edi>)
{
  char *data; // esi
  int hit; // ebx
  _BYTE *v3; // esi
  _BYTE *v4; // esi
  ssl_session_st *session; // edx
  _BYTE *v7; // esi
  _BYTE *v8; // esi
  _BYTE *v9; // esi
  __int16 v10; // ax
  int v11; // eax
  ssl2_state_st *s2; // eax
  int v13; // edx
  buf_mem_st *init_buf; // ecx
  unsigned __int8 *v15; // eax
  int v16; // eax
  unsigned __int8 *out; // [esp+8h] [ebp-4h] BYREF

  data = s->init_buf->data;
  if ( s->state == 8224 )
  {
    out = (unsigned __int8 *)(data + 11);
    *data = 4;
    hit = s->hit;
    v3 = data + 1;
    *v3 = hit;
    v4 = v3 + 1;
    if ( !hit )
    {
      session = s->session;
      if ( session->sess_cert )
        ssl_sess_cert_free(session->sess_cert);
      s->session->sess_cert = ssl_sess_cert_new();
      if ( !s->session->sess_cert )
      {
        ERR_put_error(0x14u, 114, 65, ".\\ssl\\s2_srvr.c", 720);
        return -1;
      }
    }
    if ( !s->cert )
    {
      ssl2_return_error(s, 2);
      ERR_put_error(0x14u, 114, 180, ".\\ssl\\s2_srvr.c", 757);
      return -1;
    }
    if ( hit )
    {
      *v4 = 0;
      v7 = v4 + 1;
      *v7 = BYTE1(s->version);
      v7[1] = s->version;
      v7 += 2;
      *v7 = 0;
      v7[1] = 0;
      v8 = v7 + 2;
      *v8 = 0;
      v8[1] = 0;
    }
    else
    {
      *v4 = 1;
      v9 = v4 + 1;
      *v9 = BYTE1(s->version);
      v9[1] = s->version;
      v9 += 2;
      v10 = i2d_X509(s->cert->pkeys[0].x509, 0);
      *v9 = HIBYTE(v10);
      v9[1] = v10;
      v8 = v9 + 2;
      i2d_X509(s->cert->pkeys[0].x509, &out);
      v11 = ssl_cipher_list_to_bytes(s, s->session->ciphers, out, 0);
      out += v11;
      *v8 = BYTE1(v11);
      v8[1] = v11;
    }
    v8[2] = 0;
    v8[3] = 16;
    s->s2->conn_id_length = 16;
    if ( RAND_pseudo_bytes() <= 0 )
      return -1;
    s2 = s->s2;
    *(_DWORD *)out = *(_DWORD *)s2->conn_id;
    v13 = *(_DWORD *)&s2->conn_id[4];
    s2 = (ssl2_state_st *)((char *)s2 + 140);
    *((_DWORD *)out + 1) = v13;
    *((_DWORD *)out + 2) = s2->escape;
    *((_DWORD *)out + 3) = s2->ssl2_rollback;
    init_buf = s->init_buf;
    out += 16;
    v15 = out;
    s->state = 8225;
    v16 = v15 - (unsigned __int8 *)init_buf->data;
    s->init_off = 0;
    s->init_num = v16;
  }
  if ( s->hit && !ssl_init_wbio_buffer(s, 1) )
    return -1;
  return ssl2_do_write(s);
}
