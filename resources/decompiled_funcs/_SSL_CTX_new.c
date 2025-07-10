ssl_ctx_st *__cdecl SSL_CTX_new(const ssl_method_st *meth)
{
  ssl_ctx_st *v1; // esi
  ssl_ctx_st *v3; // eax
  cert_st *v4; // eax
  lhash_st *v5; // eax
  x509_store_st *v6; // eax
  const char *v7; // eax
  const stack_st *p_stack; // ebx
  X509_VERIFY_PARAM_st *v9; // eax
  const env_md_st *digestbyname; // eax
  const env_md_st *v11; // eax
  const env_md_st *v12; // eax
  stack_st *v13; // eax
  ssl3_buf_freelist_st *v14; // eax
  ssl3_buf_freelist_st *v15; // eax

  v1 = 0;
  if ( !meth )
  {
    ERR_put_error(0x14u, 169, 196, ".\\ssl\\ssl_lib.c", 1525);
    return 0;
  }
  if ( SSL_get_ex_data_X509_STORE_CTX_idx() >= 0 )
  {
    v3 = (ssl_ctx_st *)CRYPTO_malloc(356, ".\\ssl\\ssl_lib.c", 1534);
    v1 = v3;
    if ( v3 )
    {
      memset((int)v3, 0, sizeof(ssl_ctx_st));
      v1->method = meth;
      v1->cert_store = 0;
      v1->session_cache_mode = 2;
      v1->session_cache_size = 20480;
      v1->session_cache_head = 0;
      v1->session_cache_tail = 0;
      v1->session_timeout = meth->get_timeout();
      v1->new_session_cb = 0;
      v1->remove_session_cb = 0;
      v1->get_session_cb = 0;
      v1->generate_session_id = 0;
      memset((int)&v1->stats, 0, sizeof(v1->stats));
      v1->references = 1;
      v1->quiet_shutdown = 0;
      v1->info_callback = 0;
      v1->app_verify_callback = 0;
      v1->app_verify_arg = 0;
      v1->max_cert_list = (int)&loc_19000;
      v1->read_ahead = 0;
      v1->msg_callback = 0;
      v1->msg_callback_arg = 0;
      v1->verify_mode = 0;
      v1->sid_ctx_length = 0;
      v1->default_verify_callback = 0;
      v4 = ssl_cert_new();
      v1->cert = v4;
      if ( v4 )
      {
        v1->default_passwd_callback = 0;
        v1->default_passwd_callback_userdata = 0;
        v1->client_cert_cb = 0;
        v1->app_gen_cookie_cb = 0;
        v1->app_verify_cookie_cb = 0;
        v5 = lh_new(
               (int (__cdecl *)(const char *))ssl_session_LHASH_HASH,
               (void (__cdecl *)(unsigned __int8 *, unsigned __int8 *))ssl_session_LHASH_COMP);
        v1->sessions = (lhash_st_SSL_SESSION *)v5;
        if ( v5 )
        {
          v6 = X509_STORE_new();
          v1->cert_store = v6;
          if ( v6 )
          {
            v7 = "SSLv2";
            if ( meth->version != 2 )
              v7 = "ALL:!aNULL:!eNULL:!SSLv2";
            ssl_create_cipher_list(v1->method, &v1->cipher_list, &v1->cipher_list_by_id, v7);
            p_stack = &v1->cipher_list->stack;
            if ( !p_stack || sk_num(p_stack) <= 0 )
            {
              ERR_put_error(0x14u, 169, 161, ".\\ssl\\ssl_lib.c", 1602);
              goto LABEL_31;
            }
            v9 = X509_VERIFY_PARAM_new();
            v1->param = v9;
            if ( v9 )
            {
              digestbyname = EVP_get_digestbyname("ssl2-md5");
              v1->rsa_md5 = digestbyname;
              if ( !digestbyname )
              {
                ERR_put_error(0x14u, 169, 241, ".\\ssl\\ssl_lib.c", 1612);
                goto LABEL_31;
              }
              v11 = EVP_get_digestbyname("ssl3-md5");
              v1->md5 = v11;
              if ( !v11 )
              {
                ERR_put_error(0x14u, 169, 242, ".\\ssl\\ssl_lib.c", 1617);
                goto LABEL_31;
              }
              v12 = EVP_get_digestbyname("ssl3-sha1");
              v1->sha1 = v12;
              if ( !v12 )
              {
                ERR_put_error(0x14u, 169, 243, ".\\ssl\\ssl_lib.c", 1622);
                goto LABEL_31;
              }
              v13 = sk_new_null();
              v1->client_CA = (stack_st_X509_NAME *)v13;
              if ( v13 )
              {
                CRYPTO_new_ex_data(0);
                v1->extra_certs = 0;
                v1->comp_methods = SSL_COMP_get_compression_methods();
                v1->max_send_fragment = 0x4000;
                v1->tlsext_servername_callback = 0;
                v1->tlsext_servername_arg = 0;
                if ( RAND_pseudo_bytes() <= 0 || RAND_bytes() <= 0 || RAND_bytes() <= 0 )
                  v1->options |= 0x4000u;
                v1->tlsext_status_cb = 0;
                v1->tlsext_status_arg = 0;
                v1->psk_identity_hint = 0;
                v1->psk_client_callback = 0;
                v1->psk_server_callback = 0;
                v1->freelist_max_len = 32;
                v14 = (ssl3_buf_freelist_st *)CRYPTO_malloc(12, ".\\ssl\\ssl_lib.c", 1656);
                v1->rbuf_freelist = v14;
                if ( v14 )
                {
                  v14->chunklen = 0;
                  v1->rbuf_freelist->len = 0;
                  v1->rbuf_freelist->head = 0;
                  v15 = (ssl3_buf_freelist_st *)CRYPTO_malloc(12, ".\\ssl\\ssl_lib.c", 1662);
                  v1->wbuf_freelist = v15;
                  if ( v15 )
                  {
                    v15->chunklen = 0;
                    v1->wbuf_freelist->len = 0;
                    v1->wbuf_freelist->head = 0;
                    v1->options |= 4u;
                    v1->client_cert_engine = 0;
                    return v1;
                  }
                  CRYPTO_free(v1->rbuf_freelist);
                }
              }
            }
          }
        }
      }
    }
    ERR_put_error(0x14u, 169, 65, ".\\ssl\\ssl_lib.c", 1699);
    goto LABEL_31;
  }
  ERR_put_error(0x14u, 169, 269, ".\\ssl\\ssl_lib.c", 1531);
  ERR_put_error(0x14u, 169, 65, ".\\ssl\\ssl_lib.c", 1699);
LABEL_31:
  if ( v1 )
    SSL_CTX_free(0, v1);
  return 0;
}
