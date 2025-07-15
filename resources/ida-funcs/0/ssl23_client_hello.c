int __cdecl ssl23_client_hello(ssl_st *s)
{
  bool v2; // zf
  int v3; // ebx
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
  int v15; // edi
  _BYTE *v16; // esi
  unsigned int v17; // ebx
  unsigned __int8 *v18; // eax
  int v19; // ebx
  unsigned __int8 *v20; // edi
  stack_st_SSL_CIPHER *ciphers; // eax
  int v22; // eax
  _BYTE *v23; // esi
  ssl_ctx_st *ctx; // edx
  int v25; // ebx
  char *v26; // esi
  int i; // edi
  unsigned __int8 *v28; // eax
  unsigned int v29; // edx
  int v30; // esi
  void (__cdecl *msg_callback)(int, int, int, const void *, unsigned int, ssl_st *, void *); // eax
  buf_mem_st *init_buf; // ecx
  int v33; // [esp-4h] [ebp-28h]
  void *msg_callback_arg; // [esp-4h] [ebp-28h]
  char v35; // [esp+10h] [ebp-14h]
  char v36; // [esp+14h] [ebp-10h]
  int v37; // [esp+18h] [ebp-Ch]
  char *v38; // [esp+1Ch] [ebp-8h]
  unsigned __int8 *buf; // [esp+20h] [ebp-4h]
  unsigned __int8 *bufa; // [esp+20h] [ebp-4h]
  ssl_st *sa; // [esp+28h] [ebp+4h]

  v3 = (s->options & 0x1000000) == 0;
  v2 = (s->options & 0x1000000) != 0;
  v37 = 0;
  sa = (ssl_st *)v3;
  if ( !v2 && ssl23_no_ssl2_ciphers(s) )
  {
    sa = 0;
    v3 = 0;
  }
  options = s->options;
  if ( (options & 0x4000000) == 0 )
  {
    v37 = 769;
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
  if ( (options & 0x2000000) == 0 )
  {
    v37 = 768;
    goto LABEL_6;
  }
  if ( (options & 0x1000000) != 0 )
    goto LABEL_6;
  v37 = 2;
LABEL_10:
  data = s->init_buf->data;
  v38 = data;
  if ( s->state != 4624 )
    goto LABEL_45;
  client_random = s->s3->client_random;
  v7 = _time64(0);
  *client_random++ = HIBYTE(v7);
  *client_random++ = BYTE2(v7);
  *client_random = BYTE1(v7);
  client_random[1] = v7;
  if ( RAND_pseudo_bytes((int)data) <= 0 )
    return -1;
  switch ( v37 )
  {
    case 769:
      v35 = 3;
      v36 = 1;
      break;
    case 768:
      v35 = 3;
      v36 = 0;
      break;
    case 2:
      v35 = 0;
      v36 = 2;
      break;
    default:
      ERR_put_error(v3, 0x14u, 116, 191, ".\\ssl\\s23_clnt.c", 349);
      return -1;
  }
  s->client_version = v37;
  if ( !v3 )
  {
    data[9] = v35;
    bufa = (unsigned __int8 *)(data + 9);
    data[10] = v36;
    v20 = (unsigned __int8 *)(data + 11);
    qmemcpy(v20, s->s3->client_random, 0x20u);
    v20[32] = 0;
    v3 = (int)(v20 + 33);
    ciphers = SSL_get_ciphers(s);
    v22 = ssl_cipher_list_to_bytes(s, ciphers, v20 + 35, ssl3_put_cipher_by_char);
    if ( !v22 )
    {
      v33 = 437;
      goto LABEL_25;
    }
    *(_BYTE *)v3 = BYTE1(v22);
    v20[34] = v22;
    v23 = (_BYTE *)(v3 + v22 + 2);
    if ( ((unsigned int)&loc_20000 & s->options) != 0 || (ctx = s->ctx, !ctx->comp_methods) )
      v25 = 0;
    else
      v25 = sk_num(&ctx->comp_methods->stack);
    *v23 = v25 + 1;
    v26 = v23 + 1;
    for ( i = 0; i < v25; ++v26 )
      *v26 = *sk_value(&s->ctx->comp_methods->stack, i++);
    *v26 = 0;
    if ( ssl_prepare_clienthello_tlsext(s) <= 0 )
    {
      ERR_put_error(v25, 0x14u, 116, 226, ".\\ssl\\s23_clnt.c", 465);
      return -1;
    }
    v28 = ssl_add_clienthello_tlsext(s, (unsigned __int8 *)v26 + 1, (unsigned __int8 *)v38 + 0x4000);
    if ( !v28 )
    {
      ERR_put_error(v25, 0x14u, 116, 68, ".\\ssl\\s23_clnt.c", 470);
      return -1;
    }
    v38[5] = 1;
    v38[6] = (unsigned int)(v28 - bufa) >> 16;
    v38[8] = (_BYTE)v28 - (_BYTE)bufa;
    v29 = v28 - bufa + 4;
    v38[7] = (unsigned __int16)((_WORD)v28 - (_WORD)bufa) >> 8;
    if ( v29 > 0x4000 )
    {
      ERR_put_error((int)(v38 + 5), 0x14u, 116, 68, ".\\ssl\\s23_clnt.c", 486);
      return -1;
    }
    *v38 = 22;
    v38[1] = v35;
    v38[2] = v36;
    v38[3] = BYTE1(v29);
    v38[4] = v29;
    s->init_num = v28 - (unsigned __int8 *)v38;
    s->init_off = 0;
    ssl3_finish_mac(s, v38 + 5, v28 - (unsigned __int8 *)v38 - 5);
    goto LABEL_44;
  }
  v8 = data + 2;
  data[2] = 1;
  v9 = (unsigned __int8 *)(data + 11);
  buf = (unsigned __int8 *)v8++;
  *v8++ = v35;
  *v8 = v36;
  v10 = v8 + 1;
  v11 = SSL_get_ciphers(s);
  v12 = ssl_cipher_list_to_bytes(s, v11, v9, 0);
  if ( !v12 )
  {
    v33 = 372;
LABEL_25:
    ERR_put_error(v3, 0x14u, 116, 181, ".\\ssl\\s23_clnt.c", v33);
    return -1;
  }
  v10[1] = v12;
  *v10 = BYTE1(v12);
  v10[2] = 0;
  v10[3] = 0;
  v14 = s->options & 2;
  v15 = (int)&v9[v12];
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
  if ( RAND_pseudo_bytes(v15) <= 0 )
    return -1;
  memcpy(v15, (const __m128i *)&s->s3->client_random[-v17 + 32], v17);
  v19 = v17 - (_DWORD)v38 + v15 - 2;
  *v38 = BYTE1(v19) | 0x80;
  v38[1] = v19;
  s->init_num = v19 + 2;
  s->init_off = 0;
  ssl3_finish_mac(s, (const char *)buf, v19);
LABEL_44:
  v3 = (int)sa;
  s->state = 4625;
  s->init_off = 0;
LABEL_45:
  v30 = ssl23_write_bytes(s);
  if ( v30 >= 2 )
  {
    msg_callback = s->msg_callback;
    if ( msg_callback )
    {
      msg_callback_arg = s->msg_callback_arg;
      init_buf = s->init_buf;
      if ( v3 )
      {
        msg_callback(1, 2, 0, init_buf->data + 2, v30 - 2, s, msg_callback_arg);
        return v30;
      }
      msg_callback(1, v37, 22, init_buf->data + 5, v30 - 5, s, msg_callback_arg);
    }
  }
  return v30;
}
