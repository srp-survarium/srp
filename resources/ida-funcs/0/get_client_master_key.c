int __usercall get_client_master_key@<eax>(ssl_st *s@<esi>, int a2@<ebx>)
{
  char *data; // edi
  int v3; // eax
  char v5; // al
  char *v6; // edi
  const ssl_cipher_st *cipher_by_char; // eax
  int v8; // eax
  int v9; // edx
  unsigned __int8 *v10; // edi
  signed int v11; // eax
  buf_mem_st *init_buf; // eax
  char *v13; // ebp
  unsigned int v14; // ebx
  int init_num; // eax
  unsigned int v16; // edi
  int v17; // eax
  void (__cdecl *msg_callback)(int, int, int, const void *, unsigned int, ssl_st *, void *); // eax
  const __m128i *v19; // ebp
  cert_st *cert; // edi
  int v21; // ebx
  unsigned int v22; // edi
  unsigned int count; // [esp+4h] [ebp-Ch]
  unsigned int counta; // [esp+4h] [ebp-Ch]
  const evp_cipher_st *enc; // [esp+8h] [ebp-8h] BYREF
  const env_md_st *md; // [esp+Ch] [ebp-4h] BYREF

  data = s->init_buf->data;
  if ( s->state != 8240 )
    goto LABEL_14;
  v3 = ssl2_read(s, (unsigned __int8 *)&data[s->init_num], 10 - s->init_num);
  if ( v3 < 10 - s->init_num )
    return ssl2_part_read(s, 107, v3);
  s->init_num = 10;
  v5 = *data;
  v6 = data + 1;
  if ( v5 == 2 )
  {
    cipher_by_char = ssl2_get_cipher_by_char((const unsigned __int8 *)v6);
    if ( !cipher_by_char )
    {
      ssl2_return_error(s, 1);
      ERR_put_error(a2, 0x14u, 107, 185, ".\\ssl\\s2_srvr.c", 398);
      return -1;
    }
    s->session->cipher = cipher_by_char;
    v8 = (unsigned __int8)v6[3];
    v9 = (unsigned __int8)v6[4];
    v10 = (unsigned __int8 *)(v6 + 3);
    s->s2->tmp.clear = v9 | (v8 << 8);
    s->s2->tmp.enc = v10[3] | (v10[2] << 8);
    v11 = v10[5] | (v10[4] << 8);
    if ( v11 > 8 )
    {
      ssl2_return_error(s, 0);
      ERR_put_error(a2, 0x14u, 107, 284, ".\\ssl\\s2_srvr.c", 410);
      return -1;
    }
    s->session->key_arg_length = v11;
    s->state = 8241;
LABEL_14:
    init_buf = s->init_buf;
    v13 = init_buf->data;
    if ( init_buf->length < 0x3FFF )
    {
      ssl2_return_error(s, 0);
      ERR_put_error(a2, 0x14u, 107, 68, ".\\ssl\\s2_srvr.c", 422);
      return -1;
    }
    v14 = s->s2->tmp.clear + s->s2->tmp.enc + s->session->key_arg_length + 10;
    count = s->session->key_arg_length;
    if ( v14 > 0x3FFF )
    {
      ssl2_return_error(s, 0);
      ERR_put_error(v14, 0x14u, 107, 296, ".\\ssl\\s2_srvr.c", 430);
      return -1;
    }
    init_num = s->init_num;
    v16 = v14 - init_num;
    v17 = ssl2_read(s, (unsigned __int8 *)&v13[init_num], v14 - init_num);
    if ( v17 != v16 )
      return ssl2_part_read(s, 107, v17);
    msg_callback = s->msg_callback;
    if ( msg_callback )
      msg_callback(0, s->version, 0, v13, v14, s, s->msg_callback_arg);
    v19 = (const __m128i *)(v13 + 10);
    memcpy((int)s->session->key_arg, (const __m128i *)((char *)v19 + s->s2->tmp.clear + s->s2->tmp.enc), count);
    cert = s->cert;
    if ( !cert->pkeys[0].privatekey )
    {
      ssl2_return_error(s, 0);
      ERR_put_error(v14, 0x14u, 107, 189, ".\\ssl\\s2_srvr.c", 446);
      return -1;
    }
    v21 = ssl_rsa_private_decrypt(
            v14,
            cert,
            s->s2->tmp.enc,
            &v19->m128i_u8[s->s2->tmp.clear],
            &v19->m128i_u8[s->s2->tmp.clear]);
    v22 = s->session->cipher->algo_strength & 2;
    if ( !ssl_cipher_get_evp(s->session, &enc, &md, 0, 0, 0) )
    {
      ssl2_return_error(s, 1);
      ERR_put_error(v21, 0x14u, 107, 206, ".\\ssl\\s2_srvr.c", 458);
      return 0;
    }
    if ( (s->session->cipher->algorithm2 & 2) != 0 )
    {
      v22 = 1;
      counta = 8;
    }
    else
    {
      counta = 5;
    }
    if ( v21 >= 0 )
    {
      if ( v22 )
      {
        if ( v21 == counta
          && (const rsa_meth_st *)(v21 + s->s2->tmp.clear) == EC_KEY_get0_public_key((const engine_st *)enc) )
        {
LABEL_40:
          if ( v22 )
            v21 += s->s2->tmp.clear;
          goto LABEL_42;
        }
      }
      else if ( (const rsa_meth_st *)v21 == EC_KEY_get0_public_key((const engine_st *)enc) )
      {
LABEL_42:
        if ( v21 <= 48 )
        {
          s->session->master_key_length = v21;
          memcpy((int)s->session->master_key, v19, v21);
          return 1;
        }
        else
        {
          ssl2_return_error(s, 0);
          ERR_put_error(v21, 0x14u, 107, 68, ".\\ssl\\s2_srvr.c", 513);
          return -1;
        }
      }
    }
    ERR_clear_error(v21);
    if ( v22 )
      v21 = counta;
    else
      v21 = (int)EC_KEY_get0_public_key((const engine_st *)enc);
    if ( RAND_pseudo_bytes(v22) <= 0 )
      return 0;
    goto LABEL_40;
  }
  if ( *(v6 - 1) )
  {
    ssl2_return_error(s, 0);
    ERR_put_error(a2, 0x14u, 107, 212, ".\\ssl\\s2_srvr.c", 387);
  }
  else
  {
    ERR_put_error(a2, 0x14u, 107, 200, ".\\ssl\\s2_srvr.c", 390);
  }
  return -1;
}
