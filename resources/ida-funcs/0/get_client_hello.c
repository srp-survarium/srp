int __usercall get_client_hello@<eax>(ssl_st *s@<esi>, int a2@<ebx>)
{
  char *data; // edi
  int v3; // eax
  char v5; // dl
  unsigned __int8 *v6; // edi
  int v7; // eax
  unsigned __int8 *v8; // edi
  unsigned int v9; // eax
  char *v10; // ebx
  unsigned int v11; // ebp
  int init_num; // eax
  unsigned int v13; // edi
  int v14; // eax
  void (__cdecl *msg_callback)(int, int, int, const void *, unsigned int, ssl_st *, void *); // eax
  ssl2_state_st *s2; // ecx
  unsigned int session_id_length; // eax
  unsigned __int8 *v18; // ebx
  int prev_session; // eax
  stack_st_SSL_CIPHER *v20; // edi
  stack_st_SSL_CIPHER *ciphers; // eax
  stack_st_SSL_CIPHER *v22; // ebp
  int i; // edi
  char *v24; // eax
  ssl2_state_st *v25; // eax
  const __m128i *v26; // ebx
  stack_st *p_stack; // [esp+0h] [ebp-4h]

  if ( s->state == 8208 )
  {
    s->first_packet = 1;
    s->state = 8209;
  }
  data = s->init_buf->data;
  if ( s->state != 8209 )
    goto LABEL_15;
  v3 = ssl2_read(s, (unsigned __int8 *)&data[s->init_num], 9 - s->init_num);
  if ( v3 < 9 - s->init_num )
    return ssl2_part_read(s, 106, v3);
  s->init_num = 9;
  v5 = *data;
  v6 = (unsigned __int8 *)(data + 1);
  if ( v5 == 1 )
  {
    v7 = v6[1] | (*v6 << 8);
    v8 = v6 + 2;
    if ( v7 < s->version )
      s->version = v7;
    s->s2->tmp.cipher_spec_length = v8[1] | (*v8 << 8);
    s->s2->tmp.session_id_length = v8[3] | (v8[2] << 8);
    v9 = v8[5] | (v8[4] << 8);
    s->s2->challenge_length = v9;
    if ( v9 - 16 > 0x10 )
    {
      ssl2_return_error(s, 0);
      ERR_put_error(a2, 0x14u, 106, 158, ".\\ssl\\s2_srvr.c", 567);
      return -1;
    }
    s->state = 8210;
LABEL_15:
    v10 = s->init_buf->data;
    v11 = s->s2->tmp.cipher_spec_length + s->s2->tmp.session_id_length + s->s2->challenge_length + 9;
    if ( v11 > 0x3FFF )
    {
      ssl2_return_error(s, 0);
      ERR_put_error((int)v10, 0x14u, 106, 296, ".\\ssl\\s2_srvr.c", 579);
      return -1;
    }
    init_num = s->init_num;
    v13 = v11 - init_num;
    v14 = ssl2_read(s, (unsigned __int8 *)&v10[init_num], v11 - init_num);
    if ( v14 != v13 )
      return ssl2_part_read(s, 106, v14);
    msg_callback = s->msg_callback;
    if ( msg_callback )
      msg_callback(0, s->version, 0, v10, v11, s, s->msg_callback_arg);
    s2 = s->s2;
    session_id_length = s2->tmp.session_id_length;
    v18 = (unsigned __int8 *)(v10 + 9);
    if ( session_id_length )
    {
      if ( session_id_length != 16 )
      {
        ssl2_return_error(s, 0);
        ERR_put_error((int)v18, 0x14u, 106, 125, ".\\ssl\\s2_srvr.c", 596);
        return -1;
      }
      prev_session = ssl_get_prev_session(s, &v18[s2->tmp.cipher_spec_length], 16, 0);
      if ( prev_session == 1 )
      {
        s->hit = 1;
        goto LABEL_27;
      }
      if ( prev_session == -1 )
      {
LABEL_36:
        ssl2_return_error(s, 0);
        return -1;
      }
      if ( !s->cert )
      {
        ssl2_return_error(s, 2);
        ERR_put_error((int)v18, 0x14u, 106, 179, ".\\ssl\\s2_srvr.c", 626);
        return -1;
      }
    }
    if ( ssl_get_new_session(s, 1) )
    {
LABEL_27:
      if ( !s->hit )
      {
        v20 = ssl_bytes_to_cipher_list(s, v18, s->s2->tmp.cipher_spec_length, (stack_st **)&s->session->ciphers);
        if ( !v20 )
        {
mem_err:
          ERR_put_error((int)v18, 0x14u, 106, 65, ".\\ssl\\s2_srvr.c", 693);
          return 0;
        }
        ciphers = SSL_get_ciphers(s);
        if ( ((unsigned int)&loc_400000 & s->options) != 0 )
        {
          v22 = (stack_st_SSL_CIPHER *)sk_dup(&ciphers->stack);
          if ( !v22 )
            goto mem_err;
          p_stack = &v20->stack;
        }
        else
        {
          v22 = v20;
          p_stack = &ciphers->stack;
        }
        for ( i = 0; i < sk_num(&v22->stack); ++i )
        {
          v24 = sk_value(&v22->stack, i);
          if ( sk_find(i, p_stack, v24) < 0 )
            sk_delete(&v22->stack, i--);
        }
        if ( ((unsigned int)&loc_400000 & s->options) != 0 )
        {
          sk_free(&s->session->ciphers->stack);
          s->session->ciphers = v22;
        }
      }
      v25 = s->s2;
      v26 = (const __m128i *)&v18[v25->tmp.cipher_spec_length + v25->tmp.session_id_length];
      if ( v25->challenge_length <= 0x20 )
      {
        memcpy((int)v25->challenge, v26, v25->challenge_length);
        return 1;
      }
      else
      {
        ssl2_return_error(s, 0);
        ERR_put_error((int)v26, 0x14u, 106, 68, ".\\ssl\\s2_srvr.c", 687);
        return -1;
      }
    }
    goto LABEL_36;
  }
  if ( *(v6 - 1) )
  {
    ssl2_return_error(s, 0);
    ERR_put_error(a2, 0x14u, 106, 212, ".\\ssl\\s2_srvr.c", 552);
  }
  else
  {
    ERR_put_error(a2, 0x14u, 106, 200, ".\\ssl\\s2_srvr.c", 555);
  }
  return -1;
}
