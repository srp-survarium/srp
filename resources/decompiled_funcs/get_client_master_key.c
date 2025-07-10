int __usercall get_client_master_key@<eax>(ssl_st *s@<esi>)
{
  char *data; // edi
  int v2; // eax
  char v4; // al
  char *v5; // edi
  const ssl_cipher_st *cipher_by_char; // eax
  int v7; // eax
  int v8; // edx
  unsigned __int8 *v9; // edi
  signed int v10; // eax
  buf_mem_st *init_buf; // eax
  unsigned __int8 *v12; // ebp
  unsigned int v13; // ebx
  int init_num; // eax
  unsigned int v15; // edi
  int v16; // eax
  void (__cdecl *msg_callback)(int, int, int, const void *, unsigned int, ssl_st *, void *); // eax
  unsigned __int8 *v18; // ebp
  cert_st *cert; // edi
  int v20; // ebx
  unsigned int v21; // edi
  unsigned int count; // [esp+4h] [ebp-Ch]
  unsigned int counta; // [esp+4h] [ebp-Ch]
  const evp_cipher_st *enc; // [esp+8h] [ebp-8h] BYREF
  const env_md_st *md; // [esp+Ch] [ebp-4h] BYREF

  data = s->init_buf->data;
  if ( s->state != 8240 )
    goto LABEL_14;
  v2 = ssl2_read(s, &data[s->init_num], 10 - s->init_num);
  if ( v2 < 10 - s->init_num )
    return ssl2_part_read(s, 0x6Bu, v2);
  s->init_num = 10;
  v4 = *data;
  v5 = data + 1;
  if ( v4 == 2 )
  {
    cipher_by_char = ssl2_get_cipher_by_char((const unsigned __int8 *)v5);
    if ( !cipher_by_char )
    {
      ssl2_return_error(s, 1);
      ERR_put_error(0x14u, 107, 185, ".\\ssl\\s2_srvr.c", 398);
      return -1;
    }
    s->session->cipher = cipher_by_char;
    v7 = (unsigned __int8)v5[3];
    v8 = (unsigned __int8)v5[4];
    v9 = (unsigned __int8 *)(v5 + 3);
    s->s2->tmp.clear = v8 | (v7 << 8);
    s->s2->tmp.enc = v9[3] | (v9[2] << 8);
    v10 = v9[5] | (v9[4] << 8);
    if ( v10 > 8 )
    {
      ssl2_return_error(s, 0);
      ERR_put_error(0x14u, 107, 284, ".\\ssl\\s2_srvr.c", 410);
      return -1;
    }
    s->session->key_arg_length = v10;
    s->state = 8241;
LABEL_14:
    init_buf = s->init_buf;
    v12 = (unsigned __int8 *)init_buf->data;
    if ( init_buf->length < 0x3FFF )
    {
      ssl2_return_error(s, 0);
      ERR_put_error(0x14u, 107, 68, ".\\ssl\\s2_srvr.c", 422);
      return -1;
    }
    v13 = s->s2->tmp.clear + s->s2->tmp.enc + s->session->key_arg_length + 10;
    count = s->session->key_arg_length;
    if ( v13 > 0x3FFF )
    {
      ssl2_return_error(s, 0);
      ERR_put_error(0x14u, 107, 296, ".\\ssl\\s2_srvr.c", 430);
      return -1;
    }
    init_num = s->init_num;
    v15 = v13 - init_num;
    v16 = ssl2_read(s, &v12[init_num], v13 - init_num);
    if ( v16 != v15 )
      return ssl2_part_read(s, 0x6Bu, v16);
    msg_callback = s->msg_callback;
    if ( msg_callback )
      msg_callback(0, s->version, 0, v12, v13, s, s->msg_callback_arg);
    v18 = v12 + 10;
    memcpy(s->session->key_arg, &v18[s->s2->tmp.clear + s->s2->tmp.enc], count);
    cert = s->cert;
    if ( !cert->pkeys[0].privatekey )
    {
      ssl2_return_error(s, 0);
      ERR_put_error(0x14u, 107, 189, ".\\ssl\\s2_srvr.c", 446);
      return -1;
    }
    v20 = ssl_rsa_private_decrypt(cert, s->s2->tmp.enc, &v18[s->s2->tmp.clear], &v18[s->s2->tmp.clear]);
    v21 = s->session->cipher->algo_strength & 2;
    if ( !ssl_cipher_get_evp(s->session, &enc, &md, 0, 0, 0) )
    {
      ssl2_return_error(s, 1);
      ERR_put_error(0x14u, 107, 206, ".\\ssl\\s2_srvr.c", 458);
      return 0;
    }
    if ( (s->session->cipher->algorithm2 & 2) != 0 )
    {
      v21 = 1;
      counta = 8;
    }
    else
    {
      counta = 5;
    }
    if ( v20 >= 0 )
    {
      if ( v21 )
      {
        if ( v20 == counta
          && (const rsa_meth_st *)(v20 + s->s2->tmp.clear) == EC_KEY_get0_public_key((const engine_st *)enc) )
        {
LABEL_40:
          if ( v21 )
            v20 += s->s2->tmp.clear;
          goto LABEL_42;
        }
      }
      else if ( (const rsa_meth_st *)v20 == EC_KEY_get0_public_key((const engine_st *)enc) )
      {
LABEL_42:
        if ( v20 <= 48 )
        {
          s->session->master_key_length = v20;
          memcpy(s->session->master_key, v18, v20);
          return 1;
        }
        else
        {
          ssl2_return_error(s, 0);
          ERR_put_error(0x14u, 107, 68, ".\\ssl\\s2_srvr.c", 513);
          return -1;
        }
      }
    }
    ERR_clear_error();
    if ( v21 )
      v20 = counta;
    else
      v20 = (int)EC_KEY_get0_public_key((const engine_st *)enc);
    if ( RAND_pseudo_bytes() <= 0 )
      return 0;
    goto LABEL_40;
  }
  if ( *(v5 - 1) )
  {
    ssl2_return_error(s, 0);
    ERR_put_error(0x14u, 107, 212, ".\\ssl\\s2_srvr.c", 387);
  }
  else
  {
    ERR_put_error(0x14u, 107, 200, ".\\ssl\\s2_srvr.c", 390);
  }
  return -1;
}
