int __usercall client_master_key@<eax>(int key_arg_length@<ebx>, ssl_st *s)
{
  bool v3; // zf
  char *data; // esi
  ssl_session_st *session; // edi
  char *v7; // esi
  int v8; // eax
  int v9; // eax
  const ssl_cipher_st *cipher; // eax
  unsigned int v11; // ebx
  _BYTE *v12; // esi
  unsigned __int8 *v13; // ebx
  int v14; // eax
  int v15; // ecx
  _BYTE *v16; // esi
  int v17; // ebx
  int v18; // [esp-Ch] [ebp-2Ch]
  int v19; // [esp+10h] [ebp-10h]
  const evp_cipher_st *enc; // [esp+14h] [ebp-Ch] BYREF
  char *v21; // [esp+18h] [ebp-8h]
  const env_md_st *md; // [esp+1Ch] [ebp-4h] BYREF
  ssl_st *sa; // [esp+24h] [ebp+4h]
  unsigned __int8 *sb; // [esp+24h] [ebp+4h]
  ssl_st *sc; // [esp+24h] [ebp+4h]

  v3 = s->state == 4144;
  data = s->init_buf->data;
  v21 = data;
  if ( v3 )
  {
    if ( !ssl_cipher_get_evp(s->session, &enc, &md, 0, 0, 0) )
    {
      ssl2_return_error(s, 1);
      ERR_put_error(key_arg_length, 0x14u, 102, 206, ".\\ssl\\s2_clnt.c", 627);
      return -1;
    }
    session = s->session;
    *data = 2;
    sa = (ssl_st *)(data + 10);
    v7 = &data[s->method->put_cipher_by_char(session->cipher, (unsigned __int8 *)(data + 1)) + 1];
    v8 = (int)EC_KEY_get0_private_key((const ssl_st *)enc);
    session->key_arg_length = v8;
    if ( v8 > 8 )
    {
      ssl2_return_error(s, 0);
      v18 = 644;
LABEL_7:
      ERR_put_error(key_arg_length, 0x14u, 102, 68, ".\\ssl\\s2_clnt.c", v18);
      return -1;
    }
    if ( v8 > 0 && RAND_pseudo_bytes((int)session) <= 0 )
      return -1;
    v9 = (int)EC_KEY_get0_public_key((const engine_st *)enc);
    key_arg_length = v9;
    session->master_key_length = v9;
    if ( v9 > 0 )
    {
      if ( v9 > 48 )
      {
        ssl2_return_error(s, 0);
        v18 = 659;
        goto LABEL_7;
      }
      if ( RAND_bytes((int)session) <= 0 )
      {
        ssl2_return_error(s, 0);
        return -1;
      }
    }
    cipher = session->cipher;
    if ( (cipher->algorithm2 & 2) != 0 )
    {
      v19 = 8;
    }
    else
    {
      if ( (cipher->algo_strength & 2) == 0 )
      {
        v19 = key_arg_length;
LABEL_23:
        v11 = key_arg_length - v19;
        *v7 = BYTE1(v11);
        v7[1] = v11;
        v12 = v7 + 2;
        memcpy((int)sa, (const __m128i *)session->master_key, v11);
        sb = (unsigned __int8 *)sa + v11;
        v13 = &session->master_key[v11];
        v14 = ssl_rsa_public_encrypt((int)v13, session->sess_cert, v19, v13, sb);
        if ( v14 <= 0 )
        {
          ssl2_return_error(s, 0);
          ERR_put_error((int)v13, 0x14u, 102, 208, ".\\ssl\\s2_clnt.c", 693);
          return -1;
        }
        if ( (s->options & 0x8000000) != 0 )
          ++sb[1];
        if ( (s->options & 0x10000000) != 0 )
          ++*v13;
        v12[1] = v14;
        *v12 = BYTE1(v14);
        key_arg_length = session->key_arg_length;
        v15 = (int)&sb[v14];
        v16 = v12 + 2;
        sc = (ssl_st *)&sb[v14];
        *v16 = BYTE1(key_arg_length);
        v16[1] = key_arg_length;
        if ( key_arg_length > 8 )
        {
          ssl2_return_error(s, 0);
          v18 = 708;
          goto LABEL_7;
        }
        memcpy(v15, (const __m128i *)session->key_arg, key_arg_length);
        v17 = key_arg_length - (_DWORD)v21;
        s->state = 4145;
        s->init_num = (int)sc + v17;
        s->init_off = 0;
        return ssl2_do_write(s);
      }
      v19 = 5;
    }
    if ( key_arg_length < v19 )
    {
      ssl2_return_error(s, 0);
      ERR_put_error(key_arg_length, 0x14u, 102, 139, ".\\ssl\\s2_clnt.c", 679);
      return -1;
    }
    goto LABEL_23;
  }
  return ssl2_do_write(s);
}
