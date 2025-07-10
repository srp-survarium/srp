int __cdecl ssl23_client_hello(ssl_st *s)
{
  bool v2; // zf
  BOOL v3; // ebx
  unsigned int options; // eax
  char *data; // edi
  unsigned __int8 *client_random; // esi
  int v7; // eax
  char *v8; // esi
  unsigned __int8 *v9; // edi
  _BYTE *v10; // esi
  stack_st_SSL_CIPHER *v11; // eax
  int v12; // eax
  char v14; // dl
  unsigned __int8 *v15; // edi
  _BYTE *v16; // esi
  unsigned int v17; // ebx
  unsigned __int8 *v18; // eax
  int v19; // ebx
  _BYTE *v20; // edi
  _BYTE *v21; // ebx
  stack_st_SSL_CIPHER *ciphers; // eax
  int v23; // eax
  _BYTE *v24; // esi
  ssl_ctx_st *ctx; // edx
  int v26; // ebx
  char *v27; // esi
  int i; // edi
  unsigned __int8 *v29; // eax
  unsigned int v30; // edx
  int v31; // esi
  void (__cdecl *msg_callback)(int, int, int, const void *, unsigned int, ssl_st *, void *); // eax
  buf_mem_st *init_buf; // ecx
  int v34; // [esp-4h] [ebp-28h]
  void *msg_callback_arg; // [esp-4h] [ebp-28h]
  char v36; // [esp+10h] [ebp-14h]
  char v37; // [esp+14h] [ebp-10h]
  int v38; // [esp+18h] [ebp-Ch]
  char *v39; // [esp+1Ch] [ebp-8h]
  unsigned __int8 *buf; // [esp+20h] [ebp-4h]
  unsigned __int8 *bufa; // [esp+20h] [ebp-4h]
  ssl_st *sa; // [esp+28h] [ebp+4h]

  v3 = (s->options & 0x1000000) == 0;
  v2 = (s->options & 0x1000000) != 0;
  v38 = 0;
  sa = (ssl_st *)v3;
  if ( !v2 && ssl23_no_ssl2_ciphers(s) )
  {
    sa = 0;
    v3 = 0;
  }
  options = s->options;
  if ( ((unsigned int)&vostok::memory::s_CRT_arena[55905848] & options) == 0 )
  {
    v38 = 769;
LABEL_6:
    if ( s->tlsext_hostname )
    {
      sa = 0;
      v3 = 0;
    }
    if ( s->tlsext_status_type != -1 )
    {
      sa = 0;
      v3 = 0;
    }
    goto LABEL_10;
  }
  if ( ((unsigned int)&vostok::memory::s_CRT_arena[22351416] & options) == 0 )
  {
    v38 = 768;
    goto LABEL_6;
  }
  if ( ((unsigned int)&vostok::memory::s_CRT_arena[5574200] & options) != 0 )
    goto LABEL_6;
  v38 = 2;
LABEL_10:
  data = s->init_buf->data;
  v39 = data;
  if ( s->state != 4624 )
    goto LABEL_45;
  client_random = s->s3->client_random;
  v7 = _time64(0);
  *client_random++ = HIBYTE(v7);
  *client_random++ = BYTE2(v7);
  *client_random = BYTE1(v7);
  client_random[1] = v7;
  if ( RAND_pseudo_bytes() <= 0 )
    return -1;
  switch ( v38 )
  {
    case 769:
      v36 = 3;
      v37 = 1;
      break;
    case 768:
      v36 = 3;
      v37 = 0;
      break;
    case 2:
      v36 = 0;
      v37 = 2;
      break;
    default:
      ERR_put_error(0x14u, 116, 191, ".\\ssl\\s23_clnt.c", 349);
      return -1;
  }
  s->client_version = v38;
  if ( !v3 )
  {
    data[9] = v36;
    bufa = (unsigned __int8 *)(data + 9);
    data[10] = v37;
    v20 = data + 11;
    qmemcpy(v20, s->s3->client_random, 0x20u);
    v20[32] = 0;
    v21 = v20 + 33;
    ciphers = SSL_get_ciphers(s);
    v23 = ssl_cipher_list_to_bytes(s, ciphers, v20 + 35, ssl3_put_cipher_by_char);
    if ( !v23 )
    {
      v34 = 437;
      goto LABEL_25;
    }
    *v21 = BYTE1(v23);
    v20[34] = v23;
    v24 = &v21[v23 + 2];
    if ( ((unsigned int)&loc_20000 & s->options) != 0 || (ctx = s->ctx, !ctx->comp_methods) )
      v26 = 0;
    else
      v26 = sk_num(&ctx->comp_methods->stack);
    *v24 = v26 + 1;
    v27 = v24 + 1;
    for ( i = 0; i < v26; ++v27 )
      *v27 = *sk_value(&s->ctx->comp_methods->stack, i++);
    *v27 = 0;
    if ( ssl_prepare_clienthello_tlsext(s) <= 0 )
    {
      ERR_put_error(0x14u, 116, 226, ".\\ssl\\s23_clnt.c", 465);
      return -1;
    }
    v29 = ssl_add_clienthello_tlsext(s, (unsigned __int8 *)v27 + 1, (unsigned __int8 *)v39 + 0x4000);
    if ( !v29 )
    {
      ERR_put_error(0x14u, 116, 68, ".\\ssl\\s23_clnt.c", 470);
      return -1;
    }
    v39[5] = 1;
    v39[6] = (unsigned int)(v29 - bufa) >> 16;
    v39[8] = (_BYTE)v29 - (_BYTE)bufa;
    v30 = v29 - bufa + 4;
    v39[7] = (unsigned __int16)((_WORD)v29 - (_WORD)bufa) >> 8;
    if ( v30 > 0x4000 )
    {
      ERR_put_error(0x14u, 116, 68, ".\\ssl\\s23_clnt.c", 486);
      return -1;
    }
    *v39 = 22;
    v39[1] = v36;
    v39[2] = v37;
    v39[3] = BYTE1(v30);
    v39[4] = v30;
    s->init_num = v29 - (unsigned __int8 *)v39;
    s->init_off = 0;
    ssl3_finish_mac(s, (const unsigned __int8 *)v39 + 5, v29 - (unsigned __int8 *)v39 - 5);
    goto LABEL_44;
  }
  v8 = data + 2;
  data[2] = 1;
  v9 = (unsigned __int8 *)(data + 11);
  buf = (unsigned __int8 *)v8++;
  *v8++ = v36;
  *v8 = v37;
  v10 = v8 + 1;
  v11 = SSL_get_ciphers(s);
  v12 = ssl_cipher_list_to_bytes(s, v11, v9, 0);
  if ( !v12 )
  {
    v34 = 372;
LABEL_25:
    ERR_put_error(0x14u, 116, 181, ".\\ssl\\s23_clnt.c", v34);
    return -1;
  }
  v10[1] = v12;
  *v10 = BYTE1(v12);
  v10[2] = 0;
  v10[3] = 0;
  v14 = s->options & 2;
  v15 = &v9[v12];
  v16 = v10 + 4;
  v17 = v14 != 0 ? 16 : 32;
  v16[1] = v17;
  *v16 = (unsigned __int16)(v14 != 0 ? 16 : 32) >> 8;
  v18 = s->s3->client_random;
  *(_DWORD *)v18 = 0;
  *((_DWORD *)v18 + 1) = 0;
  *((_DWORD *)v18 + 2) = 0;
  *((_DWORD *)v18 + 3) = 0;
  *((_DWORD *)v18 + 4) = 0;
  *((_DWORD *)v18 + 5) = 0;
  *((_DWORD *)v18 + 6) = 0;
  *((_DWORD *)v18 + 7) = 0;
  if ( RAND_pseudo_bytes() <= 0 )
    return -1;
  memcpy(v15, &s->s3->client_random[-v17 + 32], v17);
  v19 = (int)&v15[v17 - (_DWORD)v39 - 2];
  *v39 = BYTE1(v19) | 0x80;
  v39[1] = v19;
  s->init_num = v19 + 2;
  s->init_off = 0;
  ssl3_finish_mac(s, buf, v19);
LABEL_44:
  v3 = (BOOL)sa;
  s->state = 4625;
  s->init_off = 0;
LABEL_45:
  v31 = ssl23_write_bytes(s);
  if ( v31 >= 2 )
  {
    msg_callback = s->msg_callback;
    if ( msg_callback )
    {
      msg_callback_arg = s->msg_callback_arg;
      init_buf = s->init_buf;
      if ( v3 )
      {
        msg_callback(1, 2, 0, init_buf->data + 2, v31 - 2, s, msg_callback_arg);
        return v31;
      }
      msg_callback(1, v38, 22, init_buf->data + 5, v31 - 5, s, msg_callback_arg);
    }
  }
  return v31;
}
