int __cdecl client_master_key(ssl_st *s)
{
  bool v2; // zf
  char *data; // esi
  ssl_session_st *session; // edi
  char *v6; // esi
  int v7; // eax
  int v8; // eax
  int v9; // ebx
  const ssl_cipher_st *cipher; // eax
  unsigned int v11; // ebx
  _BYTE *v12; // esi
  unsigned __int8 *v13; // ebx
  int v14; // eax
  signed int key_arg_length; // ebx
  unsigned __int8 *v16; // ecx
  _BYTE *v17; // esi
  int v18; // ebx
  int v19; // [esp-Ch] [ebp-2Ch]
  int len; // [esp+10h] [ebp-10h]
  const evp_cipher_st *enc; // [esp+14h] [ebp-Ch] BYREF
  char *v22; // [esp+18h] [ebp-8h]
  const env_md_st *md; // [esp+1Ch] [ebp-4h] BYREF
  unsigned __int8 *sa; // [esp+24h] [ebp+4h]
  unsigned __int8 *sb; // [esp+24h] [ebp+4h]
  ssl_st *sc; // [esp+24h] [ebp+4h]

  v2 = s->state == 4144;
  data = s->init_buf->data;
  v22 = data;
  if ( v2 )
  {
    if ( !ssl_cipher_get_evp(s->session, &enc, &md, 0, 0, 0) )
    {
      ssl2_return_error(s, 1);
      ERR_put_error(0x14u, 102, 206, ".\\ssl\\s2_clnt.c", 627);
      return -1;
    }
    session = s->session;
    *data = 2;
    sa = (unsigned __int8 *)(data + 10);
    v6 = &data[s->method->put_cipher_by_char(session->cipher, (unsigned __int8 *)(data + 1)) + 1];
    v7 = (int)EC_KEY_get0_private_key((const ssl_st *)enc);
    session->key_arg_length = v7;
    if ( v7 > 8 )
    {
      ssl2_return_error(s, 0);
      v19 = 644;
LABEL_7:
      ERR_put_error(0x14u, 102, 68, ".\\ssl\\s2_clnt.c", v19);
      return -1;
    }
    if ( v7 > 0 && RAND_pseudo_bytes() <= 0 )
      return -1;
    v8 = (int)EC_KEY_get0_public_key((const engine_st *)enc);
    v9 = v8;
    session->master_key_length = v8;
    if ( v8 > 0 )
    {
      if ( v8 > 48 )
      {
        ssl2_return_error(s, 0);
        v19 = 659;
        goto LABEL_7;
      }
      if ( RAND_bytes() <= 0 )
      {
        ssl2_return_error(s, 0);
        return -1;
      }
    }
    cipher = session->cipher;
    if ( (cipher->algorithm2 & 2) != 0 )
    {
      len = 8;
    }
    else
    {
      if ( (cipher->algo_strength & 2) == 0 )
      {
        len = v9;
LABEL_23:
        v11 = v9 - len;
        *v6 = BYTE1(v11);
        v6[1] = v11;
        v12 = v6 + 2;
        memcpy(sa, session->master_key, v11);
        sb = &sa[v11];
        v13 = &session->master_key[v11];
        v14 = ssl_rsa_public_encrypt(session->sess_cert, len, v13, sb);
        if ( v14 <= 0 )
        {
          ssl2_return_error(s, 0);
          ERR_put_error(0x14u, 102, 208, ".\\ssl\\s2_clnt.c", 693);
          return -1;
        }
        if ( (s->options & 0x8000000) != 0 )
          ++sb[1];
        if ( (s->options & 0x10000000) != 0 )
          ++*v13;
        v12[1] = v14;
        *v12 = BYTE1(v14);
        key_arg_length = session->key_arg_length;
        v16 = &sb[v14];
        v17 = v12 + 2;
        sc = (ssl_st *)&sb[v14];
        *v17 = BYTE1(key_arg_length);
        v17[1] = key_arg_length;
        if ( key_arg_length > 8 )
        {
          ssl2_return_error(s, 0);
          v19 = 708;
          goto LABEL_7;
        }
        memcpy(v16, session->key_arg, key_arg_length);
        v18 = key_arg_length - (_DWORD)v22;
        s->state = 4145;
        s->init_num = (int)sc + v18;
        s->init_off = 0;
        return ssl2_do_write(s);
      }
      len = 5;
    }
    if ( v9 < len )
    {
      ssl2_return_error(s, 0);
      ERR_put_error(0x14u, 102, 139, ".\\ssl\\s2_clnt.c", 679);
      return -1;
    }
    goto LABEL_23;
  }
  return ssl2_do_write(s);
}
