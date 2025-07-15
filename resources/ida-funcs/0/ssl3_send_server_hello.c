int __cdecl ssl3_send_server_hello(ssl_st *s)
{
  char *v3; // ebp
  const ssl_comp_st *new_compression; // eax
  unsigned __int8 *v5; // ebp
  unsigned __int8 *v6; // eax
  int v7; // [esp-4h] [ebp-1Ch]
  char *data; // [esp+10h] [ebp-8h]
  char *v9; // [esp+14h] [ebp-4h]
  int sa; // [esp+1Ch] [ebp+4h]

  if ( s->state == 8496 )
  {
    data = s->init_buf->data;
    data[4] = BYTE1(s->version);
    v9 = data + 4;
    data[5] = s->version;
    qmemcpy(data + 6, s->s3->server_random, 0x20u);
    if ( (s->ctx->session_cache_mode & 2) == 0 && !s->hit )
      s->session->session_id_length = 0;
    sa = s->session->session_id_length;
    if ( sa > 32 )
    {
      v7 = 1350;
LABEL_7:
      ERR_put_error(0x14u, 242, 68, ".\\ssl\\s3_srvr.c", v7);
      return -1;
    }
    data[38] = sa;
    memcpy((unsigned __int8 *)data + 39, s->session->session_id, sa);
    v3 = &data[sa + 39 + ssl3_put_cipher_by_char(s->s3->tmp.new_cipher, (unsigned __int8 *)&data[sa + 39])];
    new_compression = s->s3->tmp.new_compression;
    if ( new_compression )
      *v3 = new_compression->id;
    else
      *v3 = 0;
    v5 = (unsigned __int8 *)(v3 + 1);
    if ( ssl_prepare_serverhello_tlsext(s) <= 0 )
    {
      ERR_put_error(0x14u, 242, 275, ".\\ssl\\s3_srvr.c", 1373);
      return -1;
    }
    v6 = ssl_add_serverhello_tlsext(s, v5, (unsigned __int8 *)data + 0x4000);
    if ( !v6 )
    {
      v7 = 1378;
      goto LABEL_7;
    }
    *data = 2;
    data[1] = (unsigned int)(v6 - (unsigned __int8 *)v9) >> 16;
    data[2] = (unsigned __int16)((_WORD)v6 - (_WORD)v9) >> 8;
    data[3] = (_BYTE)v6 - (_BYTE)v9;
    s->state = 8497;
    s->init_num = v6 - (unsigned __int8 *)data;
    s->init_off = 0;
  }
  return ssl3_do_write(s, 22);
}
