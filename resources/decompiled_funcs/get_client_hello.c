int __usercall get_client_hello@<eax>(ssl_st *s@<esi>)
{
  char *data; // edi
  int v2; // eax
  char v4; // dl
  unsigned __int8 *v5; // edi
  int v6; // eax
  unsigned __int8 *v7; // edi
  unsigned int v8; // eax
  char *v9; // ebx
  unsigned int v10; // ebp
  int init_num; // eax
  unsigned int v12; // edi
  int v13; // eax
  void (__cdecl *msg_callback)(int, int, int, const void *, unsigned int, ssl_st *, void *); // eax
  ssl2_state_st *s2; // ecx
  unsigned int session_id_length; // eax
  unsigned __int8 *v17; // ebx
  int prev_session; // eax
  stack_st_SSL_CIPHER *v19; // edi
  stack_st_SSL_CIPHER *ciphers; // eax
  stack_st_SSL_CIPHER *v21; // ebp
  int i; // edi
  char *v23; // eax
  ssl2_state_st *v24; // eax
  unsigned __int8 *v25; // ebx
  stack_st *st; // [esp+0h] [ebp-4h]

  if ( s->state == 8208 )
  {
    s->first_packet = 1;
    s->state = 8209;
  }
  data = s->init_buf->data;
  if ( s->state != 8209 )
    goto LABEL_15;
  v2 = ssl2_read(s, &data[s->init_num], 9 - s->init_num);
  if ( v2 < 9 - s->init_num )
    return ssl2_part_read(s, 0x6Au, v2);
  s->init_num = 9;
  v4 = *data;
  v5 = (unsigned __int8 *)(data + 1);
  if ( v4 == 1 )
  {
    v6 = v5[1] | (*v5 << 8);
    v7 = v5 + 2;
    if ( v6 < s->version )
      s->version = v6;
    s->s2->tmp.cipher_spec_length = v7[1] | (*v7 << 8);
    s->s2->tmp.session_id_length = v7[3] | (v7[2] << 8);
    v8 = v7[5] | (v7[4] << 8);
    s->s2->challenge_length = v8;
    if ( v8 - 16 > 0x10 )
    {
      ssl2_return_error(s, 0);
      ERR_put_error(0x14u, 106, 158, ".\\ssl\\s2_srvr.c", 567);
      return -1;
    }
    s->state = 8210;
LABEL_15:
    v9 = s->init_buf->data;
    v10 = s->s2->tmp.cipher_spec_length + s->s2->tmp.session_id_length + s->s2->challenge_length + 9;
    if ( v10 > 0x3FFF )
    {
      ssl2_return_error(s, 0);
      ERR_put_error(0x14u, 106, 296, ".\\ssl\\s2_srvr.c", 579);
      return -1;
    }
    init_num = s->init_num;
    v12 = v10 - init_num;
    v13 = ssl2_read(s, &v9[init_num], v10 - init_num);
    if ( v13 != v12 )
      return ssl2_part_read(s, 0x6Au, v13);
    msg_callback = s->msg_callback;
    if ( msg_callback )
      msg_callback(0, s->version, 0, v9, v10, s, s->msg_callback_arg);
    s2 = s->s2;
    session_id_length = s2->tmp.session_id_length;
    v17 = (unsigned __int8 *)(v9 + 9);
    if ( session_id_length )
    {
      if ( session_id_length != 16 )
      {
        ssl2_return_error(s, 0);
        ERR_put_error(0x14u, 106, 125, ".\\ssl\\s2_srvr.c", 596);
        return -1;
      }
      prev_session = ssl_get_prev_session(s, &v17[s2->tmp.cipher_spec_length], 16, 0);
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
        ERR_put_error(0x14u, 106, 179, ".\\ssl\\s2_srvr.c", 626);
        return -1;
      }
    }
    if ( ssl_get_new_session(s, 1) )
    {
LABEL_27:
      if ( !s->hit )
      {
        v19 = ssl_bytes_to_cipher_list(s, v17, s->s2->tmp.cipher_spec_length, &s->session->ciphers);
        if ( !v19 )
        {
mem_err:
          ERR_put_error(0x14u, 106, 65, ".\\ssl\\s2_srvr.c", 693);
          return 0;
        }
        ciphers = SSL_get_ciphers(s);
        if ( ((unsigned int)Scaleform::GFx::AS2::CreateShadow & s->options) != 0 )
        {
          v21 = (stack_st_SSL_CIPHER *)sk_dup(&ciphers->stack);
          if ( !v21 )
            goto mem_err;
          st = &v19->stack;
        }
        else
        {
          v21 = v19;
          st = &ciphers->stack;
        }
        for ( i = 0; i < sk_num(&v21->stack); ++i )
        {
          v23 = sk_value(&v21->stack, i);
          if ( sk_find(st, v23) < 0 )
            sk_delete(&v21->stack, i--);
        }
        if ( ((unsigned int)Scaleform::GFx::AS2::CreateShadow & s->options) != 0 )
        {
          sk_free(&s->session->ciphers->stack);
          s->session->ciphers = v21;
        }
      }
      v24 = s->s2;
      v25 = &v17[v24->tmp.cipher_spec_length + v24->tmp.session_id_length];
      if ( v24->challenge_length <= 0x20 )
      {
        memcpy(v24->challenge, v25, v24->challenge_length);
        return 1;
      }
      else
      {
        ssl2_return_error(s, 0);
        ERR_put_error(0x14u, 106, 68, ".\\ssl\\s2_srvr.c", 687);
        return -1;
      }
    }
    goto LABEL_36;
  }
  if ( *(v5 - 1) )
  {
    ssl2_return_error(s, 0);
    ERR_put_error(0x14u, 106, 212, ".\\ssl\\s2_srvr.c", 552);
  }
  else
  {
    ERR_put_error(0x14u, 106, 200, ".\\ssl\\s2_srvr.c", 555);
  }
  return -1;
}
