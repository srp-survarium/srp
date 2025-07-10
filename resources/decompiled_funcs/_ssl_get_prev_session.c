int __cdecl ssl_get_prev_session(ssl_st *s, unsigned __int8 *session_id, int len, unsigned __int8 *limit)
{
  unsigned int v4; // edi
  int v5; // eax
  ssl_session_st *v6; // ebp
  ssl_session_st *v8; // eax
  ssl_ctx_st *initial_ctx; // eax
  ssl_ctx_st *v10; // edx
  ssl_session_st *(__cdecl *get_session_cb)(ssl_st *, unsigned __int8 *, int, int *); // eax
  ssl_ctx_st *v12; // eax
  unsigned int sid_ctx_length; // eax
  unsigned __int8 *sid_ctx; // ecx
  unsigned int cipher_id; // eax
  const ssl_cipher_st *v16; // eax
  __int64 v17; // rax
  bool v18; // cc
  ssl_ctx_st *v19; // eax
  ssl_session_st *v20; // eax
  ssl_session_st *ret; // [esp+10h] [ebp-104h] BYREF
  int v22; // [esp+14h] [ebp-100h]
  _DWORD data[18]; // [esp+18h] [ebp-FCh] BYREF
  unsigned __int8 dst[168]; // [esp+60h] [ebp-B4h] BYREF
  _DWORD v25[2]; // [esp+108h] [ebp-Ch] BYREF

  v4 = len;
  ret = 0;
  v22 = 0;
  if ( len > 32 )
    return 0;
  v5 = tls1_process_ticket(s, session_id, len, limit, &ret);
  if ( v5 == -1 )
  {
    v22 = 1;
LABEL_4:
    v6 = ret;
    goto err_231;
  }
  if ( !v5 )
    goto LABEL_4;
  v6 = ret;
  if ( !ret )
  {
    if ( !len )
      return 0;
    if ( (s->initial_ctx->session_cache_mode & 0x100) != 0 )
      goto LABEL_49;
    data[0] = s->version;
    data[17] = len;
    memcpy(dst, session_id, len);
    CRYPTO_lock(len, 5, 12, ".\\ssl\\ssl_sess.c", 461);
    v8 = (ssl_session_st *)lh_retrieve((lhash_st *)s->initial_ctx->sessions, data);
    ret = v8;
    if ( v8 )
      CRYPTO_add_lock(&v8->references, 1, 14, ".\\ssl\\ssl_sess.c", 465);
    CRYPTO_lock(len, 6, 12, ".\\ssl\\ssl_sess.c", 466);
    v6 = ret;
    if ( !ret )
    {
LABEL_49:
      initial_ctx = s->initial_ctx;
      v25[0] = 1;
      ++initial_ctx->stats.sess_miss;
      v10 = s->initial_ctx;
      ret = 0;
      get_session_cb = v10->get_session_cb;
      if ( !get_session_cb )
        return 0;
      ret = get_session_cb(s, session_id, len, v25);
      if ( !ret )
        return 0;
      ++s->initial_ctx->stats.sess_cb_hit;
      if ( v25[0] )
        CRYPTO_add_lock(&ret->references, 1, 14, ".\\ssl\\ssl_sess.c", 487);
      v12 = s->initial_ctx;
      if ( (v12->session_cache_mode & 0x200) == 0 )
        SSL_CTX_add_session(len, v12, ret);
      v6 = ret;
      if ( !ret )
        return 0;
    }
  }
  sid_ctx_length = v6->sid_ctx_length;
  if ( sid_ctx_length != s->sid_ctx_length )
    goto err_231;
  sid_ctx = s->sid_ctx;
  v4 = (unsigned int)v6->sid_ctx;
  if ( sid_ctx_length >= 4 )
  {
    while ( *(_DWORD *)v4 == *(_DWORD *)sid_ctx )
    {
      sid_ctx_length -= 4;
      sid_ctx += 4;
      v4 += 4;
      if ( sid_ctx_length < 4 )
        goto LABEL_27;
    }
    goto err_231;
  }
LABEL_27:
  if ( sid_ctx_length
    && (*sid_ctx != *(_BYTE *)v4
     || sid_ctx_length > 1
     && (sid_ctx[1] != *(_BYTE *)(v4 + 1) || sid_ctx_length > 2 && sid_ctx[2] != *(_BYTE *)(v4 + 2))) )
  {
    goto err_231;
  }
  if ( (s->verify_mode & 1) != 0 && !s->sid_ctx_length )
  {
    ERR_put_error(0x14u, 217, 277, ".\\ssl\\ssl_sess.c", 528);
    v22 = 1;
    goto LABEL_4;
  }
  if ( !v6->cipher )
  {
    cipher_id = v6->cipher_id;
    LOBYTE(v25[0]) = HIBYTE(cipher_id);
    BYTE1(v25[0]) = BYTE2(cipher_id);
    BYTE2(v25[0]) = BYTE1(cipher_id);
    HIBYTE(v25[0]) = cipher_id;
    v16 = (int)(v6->ssl_version & 0xFFFFFF00) < 768
        ? s->method->get_cipher_by_char((char *)v25 + 1)
        : s->method->get_cipher_by_char((char *)v25 + 2);
    ret->cipher = v16;
    v6 = ret;
    if ( !ret->cipher )
    {
err_231:
      if ( v6 )
        SSL_SESSION_free(v4, v6);
      if ( v22 )
        return -1;
      return 0;
    }
  }
  v17 = _time64(0);
  v18 = ret->timeout < (int)v17 - ret->time;
  v19 = s->initial_ctx;
  v25[1] = HIDWORD(v17);
  if ( v18 )
  {
    ++v19->stats.sess_timeout;
    SSL_CTX_remove_session(s->initial_ctx, ret);
    goto LABEL_4;
  }
  ++v19->stats.sess_hit;
  if ( s->session )
    SSL_SESSION_free(v4, s->session);
  v20 = ret;
  s->session = ret;
  s->verify_result = v20->verify_result;
  return 1;
}
