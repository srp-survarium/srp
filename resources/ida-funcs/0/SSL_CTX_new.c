ssl_ctx_st *__cdecl SSL_CTX_new(const ssl_method_st *meth)
{
  int cipher_list; // ebx
  ssl_ctx_st *v2; // esi
  ssl_ctx_st *v4; // eax
  cert_st *v5; // eax
  lhash_st *v6; // eax
  x509_store_st *v7; // eax
  char *v8; // eax
  X509_VERIFY_PARAM_st *v9; // eax
  const env_md_st *digestbyname; // eax
  const env_md_st *v11; // eax
  const env_md_st *v12; // eax
  stack_st *v13; // eax
  ssl3_buf_freelist_st *v14; // eax
  ssl3_buf_freelist_st *v15; // eax

  cipher_list = (int)meth;
  v2 = 0;
  if ( !meth )
  {
    ERR_put_error(0, 0x14u, 169, 196, ".\\ssl\\ssl_lib.c", 1525);
    return 0;
  }
  if ( SSL_get_ex_data_X509_STORE_CTX_idx(0) >= 0 )
  {
    v4 = (ssl_ctx_st *)CRYPTO_malloc(356, ".\\ssl\\ssl_lib.c", 1534);
    v2 = v4;
    if ( v4 )
    {
      memset((int)v4, 0, sizeof(ssl_ctx_st));
      v2->method = meth;
      v2->cert_store = 0;
      v2->session_cache_mode = 2;
      v2->session_cache_size = 20480;
      v2->session_cache_head = 0;
      v2->session_cache_tail = 0;
      v2->session_timeout = meth->get_timeout();
      v2->new_session_cb = 0;
      v2->remove_session_cb = 0;
      v2->get_session_cb = 0;
      v2->generate_session_id = 0;
      memset((int)&v2->stats, 0, sizeof(v2->stats));
      v2->references = 1;
      v2->quiet_shutdown = 0;
      v2->info_callback = 0;
      v2->app_verify_callback = 0;
      v2->app_verify_arg = 0;
      v2->max_cert_list = 102400;
      v2->read_ahead = 0;
      v2->msg_callback = 0;
      v2->msg_callback_arg = 0;
      v2->verify_mode = 0;
      v2->sid_ctx_length = 0;
      v2->default_verify_callback = 0;
      v5 = ssl_cert_new();
      v2->cert = v5;
      if ( v5 )
      {
        v2->default_passwd_callback = 0;
        v2->default_passwd_callback_userdata = 0;
        v2->client_cert_cb = 0;
        v2->app_gen_cookie_cb = 0;
        v2->app_verify_cookie_cb = 0;
        v6 = lh_new(
               (unsigned int (__cdecl *)(const char *))ssl_session_LHASH_HASH,
               (void (__cdecl *)(unsigned __int8 *, unsigned __int8 *))ssl_session_LHASH_COMP);
        v2->sessions = (lhash_st_SSL_SESSION *)v6;
        if ( v6 )
        {
          v7 = X509_STORE_new((int)meth);
          v2->cert_store = v7;
          if ( v7 )
          {
            v8 = "SSLv2";
            if ( meth->version != 2 )
              v8 = "ALL:!aNULL:!eNULL:!SSLv2";
            ssl_create_cipher_list(v2->method, &v2->cipher_list, &v2->cipher_list_by_id, v8);
            cipher_list = (int)v2->cipher_list;
            if ( !cipher_list || sk_num((const stack_st *)cipher_list) <= 0 )
            {
              ERR_put_error(cipher_list, 0x14u, 169, 161, ".\\ssl\\ssl_lib.c", 1602);
              goto LABEL_31;
            }
            v9 = X509_VERIFY_PARAM_new();
            v2->param = v9;
            if ( v9 )
            {
              digestbyname = EVP_get_digestbyname("ssl2-md5");
              v2->rsa_md5 = digestbyname;
              if ( !digestbyname )
              {
                ERR_put_error(cipher_list, 0x14u, 169, 241, ".\\ssl\\ssl_lib.c", 1612);
                goto LABEL_31;
              }
              v11 = EVP_get_digestbyname("ssl3-md5");
              v2->md5 = v11;
              if ( !v11 )
              {
                ERR_put_error(cipher_list, 0x14u, 169, 242, ".\\ssl\\ssl_lib.c", 1617);
                goto LABEL_31;
              }
              v12 = EVP_get_digestbyname("ssl3-sha1");
              v2->sha1 = v12;
              if ( !v12 )
              {
                ERR_put_error(cipher_list, 0x14u, 169, 243, ".\\ssl\\ssl_lib.c", 1622);
                goto LABEL_31;
              }
              v13 = sk_new_null();
              v2->client_CA = (stack_st_X509_NAME *)v13;
              if ( v13 )
              {
                CRYPTO_new_ex_data(0, cipher_list);
                v2->extra_certs = 0;
                cipher_list = 0x4000;
                v2->comp_methods = SSL_COMP_get_compression_methods(0);
                v2->max_send_fragment = 0x4000;
                v2->tlsext_servername_callback = 0;
                v2->tlsext_servername_arg = 0;
                if ( RAND_pseudo_bytes(0) <= 0 || RAND_bytes(0) <= 0 || RAND_bytes(0) <= 0 )
                  v2->options |= 0x4000u;
                v2->tlsext_status_cb = 0;
                v2->tlsext_status_arg = 0;
                v2->psk_identity_hint = 0;
                v2->psk_client_callback = 0;
                v2->psk_server_callback = 0;
                v2->freelist_max_len = 32;
                v14 = (ssl3_buf_freelist_st *)CRYPTO_malloc(12, ".\\ssl\\ssl_lib.c", 1656);
                v2->rbuf_freelist = v14;
                if ( v14 )
                {
                  v14->chunklen = 0;
                  v2->rbuf_freelist->len = 0;
                  v2->rbuf_freelist->head = 0;
                  v15 = (ssl3_buf_freelist_st *)CRYPTO_malloc(12, ".\\ssl\\ssl_lib.c", 1662);
                  v2->wbuf_freelist = v15;
                  if ( v15 )
                  {
                    v15->chunklen = 0;
                    v2->wbuf_freelist->len = 0;
                    v2->wbuf_freelist->head = 0;
                    v2->options |= 4u;
                    v2->client_cert_engine = 0;
                    return v2;
                  }
                  CRYPTO_free(v2->rbuf_freelist);
                }
              }
            }
          }
        }
      }
    }
    ERR_put_error(cipher_list, 0x14u, 169, 65, ".\\ssl\\ssl_lib.c", 1699);
    goto LABEL_31;
  }
  ERR_put_error((int)meth, 0x14u, 169, 269, ".\\ssl\\ssl_lib.c", 1531);
  ERR_put_error((int)meth, 0x14u, 169, 65, ".\\ssl\\ssl_lib.c", 1699);
LABEL_31:
  if ( v2 )
    SSL_CTX_free(0, cipher_list, v2);
  return 0;
}
