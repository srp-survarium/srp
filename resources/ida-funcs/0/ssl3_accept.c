// positive sp value has been detected, the output may be wrong!
int __cdecl ssl3_accept(ssl_st *s)
{
  int v1; // ebx
  void (__cdecl *info_callback)(const ssl_st *, int, int); // edi
  void *v3; // esp
  ssl_ctx_st *ctx; // ecx
  int state; // eax
  int v8; // eax
  int v9; // eax
  bool v10; // zf
  bio_st *wbio; // edx
  ssl3_state_st *v12; // eax
  int client_hello; // edi
  const ssl_cipher_st *new_cipher; // eax
  ssl3_state_st *v15; // eax
  unsigned int algorithm_mkey; // ecx
  ssl3_state_st *v17; // edx
  cert_st *cert; // ecx
  int verify_mode; // edx
  ssl3_state_st *v20; // eax
  const ssl_cipher_st *v21; // edi
  unsigned int algorithm_auth; // ecx
  ssl3_state_st *v23; // ecx
  int v24; // eax
  int client_key_exchange; // eax
  ssl3_state_st *v26; // edx
  int v27; // ebp
  ssl3_state_st *v28; // eax
  ui_string_st **v29; // ecx
  int (__cdecl **p_cert_verify_mac)(ssl_st *, int, unsigned __int8 *); // edi
  ui_string_st *object; // eax
  int v32; // eax
  ui_string_st *v33; // eax
  int v34; // eax
  const ssl_method_st *method; // ecx
  buf_mem_st *v36; // eax
  ssl3_state_st *s3; // eax
  ssl_ctx_st *v38; // eax
  int v39; // edi
  int v40; // [esp-4h] [ebp-20h]
  void (__cdecl *v41)(const ssl_st *, int, int); // [esp+10h] [ebp-Ch]
  int v42; // [esp+14h] [ebp-8h]
  int v43; // [esp+18h] [ebp-4h] BYREF
  int buf; // [esp+20h] [ebp+4h]

  v1 = 0;
  v41 = (void (__cdecl *)(const ssl_st *, int, int))_time64(0);
  info_callback = 0;
  v3 = alloca(8);
  RAND_add(0, &v43, 4, 0.0);
  ERR_clear_error(0);
  SetLastError(0);
  if ( s->info_callback )
  {
    info_callback = s->info_callback;
    v41 = info_callback;
  }
  else
  {
    ctx = s->ctx;
    if ( ctx->info_callback )
    {
      info_callback = ctx->info_callback;
      v41 = info_callback;
    }
  }
  ++s->in_handshake;
  if ( (SSL_state(s) & 0x3000) == 0 || (SSL_state(s) & 0x4000) != 0 )
    SSL_clear(0, s);
  if ( !s->cert )
  {
    ERR_put_error(0, 0x14u, 128, 179, ".\\ssl\\s3_srvr.c", 210);
    return -1;
  }
  while ( 1 )
  {
    state = s->state;
    buf = state;
    if ( state > 8448 )
      break;
    if ( state != 8448 )
    {
      v8 = state - 3;
      if ( !v8 )
      {
        ssl3_cleanup_key_block(s);
        BUF_MEM_free(s->init_buf);
        s->init_buf = 0;
        ssl_free_wbio_buffer((int)info_callback, 0, s);
        v10 = s->new_session == 2;
        s->init_num = 0;
        if ( v10 )
        {
          s->new_session = 0;
          ssl_update_cache(s, 2);
          ++s->ctx->stats.sess_accept_good;
          s->handshake_func = ssl3_accept;
          if ( info_callback )
            info_callback(s, 32, 1);
        }
        client_hello = 1;
        goto end_19;
      }
      v9 = v8 - 8189;
      if ( !v9 )
        goto LABEL_100;
      v10 = v9 == 3;
LABEL_99:
      if ( !v10 )
      {
LABEL_127:
        ERR_put_error(0, 0x14u, 128, 255, ".\\ssl\\s3_srvr.c", 698);
        goto LABEL_130;
      }
LABEL_100:
      s->server = 1;
      if ( info_callback )
        info_callback(s, 16, 1);
      if ( (s->version & 0xFFFFFF00) != 0x300 )
      {
        ERR_put_error(0, 0x14u, 128, 68, ".\\ssl\\s3_srvr.c", 234);
        return -1;
      }
      s->type = 0x2000;
      if ( s->init_buf )
        goto LABEL_107;
      v36 = BUF_MEM_new(0);
      info_callback = (void (__cdecl *)(const ssl_st *, int, int))v36;
      if ( v36 && BUF_MEM_grow(v36, 0x4000u) )
      {
        s->init_buf = (buf_mem_st *)info_callback;
LABEL_107:
        if ( ssl3_setup_buffers(s) )
        {
          s3 = s->s3;
          s->init_num = 0;
          s3->flags &= ~0x40u;
          if ( s->state == 12292 )
          {
            if ( s->s3->send_connection_binding || (s->options & 0x40000) != 0 )
            {
              ++s->ctx->stats.sess_accept_renegotiate;
              s->state = 8480;
              goto LABEL_114;
            }
            ERR_put_error(0, 0x14u, 128, 338, ".\\ssl\\s3_srvr.c", 281);
            ssl3_send_alert(s, 2, 40);
          }
          else if ( ssl_init_wbio_buffer(0, s, 1) )
          {
            ssl3_init_finished_mac((int)info_callback, s);
            v38 = s->ctx;
            s->state = 8464;
            ++v38->stats.sess_accept;
            goto LABEL_114;
          }
        }
      }
LABEL_130:
      client_hello = -1;
end_19:
      --s->in_handshake;
      if ( v41 )
        v41(s, 8194, client_hello);
      return client_hello;
    }
    wbio = s->wbio;
    s->rwstate = 2;
    if ( BIO_ctrl(0, wbio, 11, 0, 0) <= 0 )
      goto LABEL_130;
    v12 = s->s3;
    s->rwstate = 1;
    s->state = v12->tmp.next_state;
LABEL_114:
    if ( !s->s3->tmp.reuse_message && !v42 )
    {
      if ( s->debug )
      {
        client_hello = BIO_ctrl(0, s->wbio, 11, 0, 0);
        if ( client_hello <= 0 )
          goto end_19;
      }
      if ( v41 )
      {
        v39 = s->state;
        if ( v39 != buf )
        {
          s->state = buf;
          v41(s, 8193, 1);
          s->state = v39;
        }
      }
    }
    info_callback = v41;
    v42 = 0;
  }
  if ( state > 12292 )
  {
    if ( state == 0x4000 )
      goto LABEL_100;
    v10 = state == 24576;
    goto LABEL_99;
  }
  if ( state == 12292 )
  {
    s->new_session = 1;
    goto LABEL_100;
  }
  switch ( state )
  {
    case 8464:
    case 8465:
    case 8466:
      s->shutdown = 0;
      client_hello = ssl3_get_client_hello(s);
      if ( client_hello <= 0 )
        goto end_19;
      s->new_session = 2;
      s->state = 8496;
      s->init_num = 0;
      goto LABEL_114;
    case 8480:
    case 8481:
      s->shutdown = 0;
      client_hello = ssl3_send_hello_request(s);
      if ( client_hello <= 0 )
        goto end_19;
      s->s3->tmp.next_state = 8482;
      s->state = 8448;
      s->init_num = 0;
      ssl3_init_finished_mac(client_hello, s);
      goto LABEL_114;
    case 8482:
      s->state = 3;
      goto LABEL_114;
    case 8496:
    case 8497:
      client_hello = ssl3_send_server_hello(s);
      if ( client_hello <= 0 )
        goto end_19;
      if ( s->hit )
        s->state = s->tlsext_ticket_expected != 0 ? 8688 : 8656;
      else
        s->state = 8512;
      s->init_num = 0;
      goto LABEL_114;
    case 8512:
    case 8513:
      new_cipher = s->s3->tmp.new_cipher;
      if ( (new_cipher->algorithm_auth & 0x24) != 0 || (new_cipher->algorithm_mkey & 0x100) != 0 )
      {
        v42 = 1;
        s->state = 8528;
        s->init_num = 0;
      }
      else
      {
        client_hello = ssl3_send_server_certificate(0, s);
        if ( client_hello <= 0 )
          goto end_19;
        s->state = s->tlsext_status_expected != 0 ? 8704 : 8528;
        s->init_num = 0;
      }
      goto LABEL_114;
    case 8528:
    case 8529:
      v15 = s->s3;
      algorithm_mkey = v15->tmp.new_cipher->algorithm_mkey;
      v15->tmp.use_rsa_tmp = (s->options >> 21) & 1;
      v17 = s->s3;
      if ( v17->tmp.use_rsa_tmp
        || (algorithm_mkey & 0x100) != 0 && s->ctx->psk_identity_hint
        || (algorithm_mkey & 0x8E) != 0
        || (algorithm_mkey & 1) != 0
        && ((cert = s->cert, !cert->pkeys[0].privatekey)
         || (v17->tmp.new_cipher->algo_strength & 2) != 0
         && 8 * EVP_PKEY_size(cert->pkeys[0].privatekey) > ((s->s3->tmp.new_cipher->algo_strength & 8) != 0 ? 512 : 1024)) )
      {
        client_hello = ssl3_send_server_key_exchange(s);
        if ( client_hello <= 0 )
          goto end_19;
        s->state = 8544;
        s->init_num = 0;
      }
      else
      {
        v42 = 1;
        s->state = 8544;
        s->init_num = 0;
      }
      goto LABEL_114;
    case 8544:
    case 8545:
      verify_mode = s->verify_mode;
      if ( (verify_mode & 1) == 0
        || s->session->peer && (verify_mode & 4) != 0
        || (v20 = s->s3, v21 = v20->tmp.new_cipher, algorithm_auth = v21->algorithm_auth, (algorithm_auth & 4) != 0)
        && (verify_mode & 2) == 0
        || (algorithm_auth & 0x20) != 0
        || (v21->algorithm_mkey & 0x100) != 0 )
      {
        s->s3->tmp.cert_request = 0;
        v42 = 1;
        s->state = 8560;
      }
      else
      {
        v20->tmp.cert_request = 1;
        client_hello = ssl3_send_certificate_request(s);
        if ( client_hello <= 0 )
          goto end_19;
        v23 = s->s3;
        s->state = 8448;
        v23->tmp.next_state = 8576;
        s->init_num = 0;
      }
      goto LABEL_114;
    case 8560:
    case 8561:
      client_hello = ssl3_send_server_done(s);
      if ( client_hello <= 0 )
        goto end_19;
      s->s3->tmp.next_state = 8576;
      s->state = 8448;
      s->init_num = 0;
      goto LABEL_114;
    case 8576:
    case 8577:
      v24 = ssl3_check_client_hello((int)info_callback, 0, s);
      client_hello = v24;
      if ( v24 <= 0 )
        goto end_19;
      if ( v24 == 2 )
      {
        s->state = 8466;
      }
      else
      {
        if ( s->s3->tmp.cert_request )
        {
          client_hello = ssl3_get_client_certificate(s);
          if ( client_hello <= 0 )
            goto end_19;
        }
        s->init_num = 0;
        s->state = 8592;
      }
      goto LABEL_114;
    case 8592:
    case 8593:
      client_key_exchange = ssl3_get_client_key_exchange(s);
      client_hello = client_key_exchange;
      if ( client_key_exchange <= 0 )
        goto end_19;
      s->init_num = 0;
      if ( client_key_exchange == 2 )
      {
        s->state = 8640;
        goto LABEL_114;
      }
      v26 = s->s3;
      s->state = 8608;
      if ( !v26->handshake_buffer || ssl3_digest_cached_records(s) )
      {
        v27 = 0;
        while ( 1 )
        {
          v28 = s->s3;
          v29 = (ui_string_st **)&v28->handshake_dgst[v27];
          if ( *v29 )
          {
            v40 = (int)&v28->tmp.cert_verify_md[v1];
            p_cert_verify_mac = &s->method->ssl3_enc->cert_verify_mac;
            object = X509_EXTENSION_get_object(*v29);
            v32 = EVP_CIPHER_CTX_cipher((const ssl_st *)object);
            (*p_cert_verify_mac)(s, v32, (unsigned __int8 *)v40);
            v33 = X509_EXTENSION_get_object((ui_string_st *)s->s3->handshake_dgst[v27]);
            v34 = EVP_MD_size(v1, (const env_md_st *)v33);
            if ( v34 < 0 )
            {
              client_hello = -1;
              goto end_19;
            }
            v1 += v34;
          }
          if ( ++v27 >= 4 )
          {
            v1 = 0;
            goto LABEL_114;
          }
        }
      }
      return -1;
    case 8608:
    case 8609:
      client_hello = ssl3_get_cert_verify(s);
      if ( client_hello <= 0 )
        goto end_19;
      s->state = 8640;
      s->init_num = 0;
      goto LABEL_114;
    case 8640:
    case 8641:
      client_hello = ssl3_get_finished(s, 8640, 8641);
      if ( client_hello <= 0 )
        goto end_19;
      if ( s->tlsext_ticket_expected )
        s->state = 8688;
      else
        s->state = s->hit != 0 ? 3 : 8656;
      s->init_num = 0;
      goto LABEL_114;
    case 8656:
    case 8657:
      s->session->cipher = s->s3->tmp.new_cipher;
      if ( !s->method->ssl3_enc->setup_key_block(s) )
        goto LABEL_130;
      client_hello = ssl3_send_change_cipher_spec(s, 8656, 8657);
      if ( client_hello <= 0 )
        goto end_19;
      method = s->method;
      s->state = 8672;
      s->init_num = 0;
      if ( method->ssl3_enc->change_cipher_state(s, 34) )
        goto LABEL_114;
      goto LABEL_130;
    case 8672:
    case 8673:
      client_hello = ssl3_send_finished(
                       s,
                       8672,
                       8673,
                       s->method->ssl3_enc->server_finished_label,
                       s->method->ssl3_enc->server_finished_label_len);
      if ( client_hello <= 0 )
        goto end_19;
      s->state = 8448;
      if ( s->hit )
        s->s3->tmp.next_state = 8640;
      else
        s->s3->tmp.next_state = 3;
      s->init_num = 0;
      goto LABEL_114;
    case 8688:
    case 8689:
      client_hello = ssl3_send_newsession_ticket(s);
      if ( client_hello <= 0 )
        goto end_19;
      s->state = 8656;
      s->init_num = 0;
      goto LABEL_114;
    case 8704:
    case 8705:
      client_hello = ssl3_send_cert_status(s);
      if ( client_hello <= 0 )
        goto end_19;
      s->state = 8528;
      s->init_num = 0;
      goto LABEL_114;
    default:
      goto LABEL_127;
  }
}
