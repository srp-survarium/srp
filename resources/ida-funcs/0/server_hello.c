int __usercall server_hello@<eax>(ssl_st *s@<edi>, int a2@<ebx>)
{
  char *data; // esi
  int hit; // ebx
  _BYTE *v4; // esi
  _BYTE *v5; // esi
  ssl_session_st *session; // edx
  _BYTE *v8; // esi
  _BYTE *v9; // esi
  _BYTE *v10; // esi
  __int16 v11; // ax
  int v12; // eax
  ssl2_state_st *s2; // eax
  int v14; // edx
  buf_mem_st *init_buf; // ecx
  unsigned __int8 *v16; // eax
  int v17; // eax
  unsigned __int8 *out; // [esp+8h] [ebp-4h] BYREF

  data = s->init_buf->data;
  if ( s->state == 8224 )
  {
    out = (unsigned __int8 *)(data + 11);
    *data = 4;
    hit = s->hit;
    v4 = data + 1;
    *v4 = hit;
    v5 = v4 + 1;
    if ( !hit )
    {
      session = s->session;
      if ( session->sess_cert )
        ssl_sess_cert_free(session->sess_cert);
      s->session->sess_cert = ssl_sess_cert_new();
      if ( !s->session->sess_cert )
      {
        ERR_put_error(0, 0x14u, 114, 65, ".\\ssl\\s2_srvr.c", 720);
        return -1;
      }
    }
    if ( !s->cert )
    {
      ssl2_return_error(s, 2);
      ERR_put_error(hit, 0x14u, 114, 180, ".\\ssl\\s2_srvr.c", 757);
      return -1;
    }
    if ( hit )
    {
      *v5 = 0;
      v8 = v5 + 1;
      *v8 = BYTE1(s->version);
      v8[1] = s->version;
      v8 += 2;
      *v8 = 0;
      v8[1] = 0;
      v9 = v8 + 2;
      *v9 = 0;
      v9[1] = 0;
    }
    else
    {
      *v5 = 1;
      v10 = v5 + 1;
      *v10 = BYTE1(s->version);
      v10[1] = s->version;
      v10 += 2;
      v11 = i2d_X509(s->cert->pkeys[0].x509, 0);
      *v10 = HIBYTE(v11);
      v10[1] = v11;
      v9 = v10 + 2;
      i2d_X509(s->cert->pkeys[0].x509, &out);
      v12 = ssl_cipher_list_to_bytes(s, s->session->ciphers, out, 0);
      out += v12;
      *v9 = BYTE1(v12);
      v9[1] = v12;
    }
    v9[2] = 0;
    a2 = 16;
    v9[3] = 16;
    s->s2->conn_id_length = 16;
    if ( RAND_pseudo_bytes((int)s) <= 0 )
      return -1;
    s2 = s->s2;
    *(_DWORD *)out = *(_DWORD *)s2->conn_id;
    v14 = *(_DWORD *)&s2->conn_id[4];
    s2 = (ssl2_state_st *)((char *)s2 + 140);
    *((_DWORD *)out + 1) = v14;
    *((_DWORD *)out + 2) = s2->escape;
    *((_DWORD *)out + 3) = s2->ssl2_rollback;
    init_buf = s->init_buf;
    out += 16;
    v16 = out;
    s->state = 8225;
    v17 = v16 - (unsigned __int8 *)init_buf->data;
    s->init_off = 0;
    s->init_num = v17;
  }
  if ( s->hit && !ssl_init_wbio_buffer(a2, s, 1) )
    return -1;
  return ssl2_do_write(s);
}
