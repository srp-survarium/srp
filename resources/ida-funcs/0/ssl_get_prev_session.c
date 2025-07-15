int __cdecl ssl_get_prev_session(ssl_st *s, __m128i *session_id, int len, unsigned __int8 *limit)
{
  int v4; // ebx
  int v5; // edi
  int v6; // eax
  ssl_session_st *v7; // ebp
  ssl_session_st *v9; // eax
  ssl_ctx_st *initial_ctx; // eax
  ssl_ctx_st *v11; // edx
  ssl_session_st *(__cdecl *get_session_cb)(ssl_st *, unsigned __int8 *, int, int *); // eax
  ssl_ctx_st *v13; // eax
  unsigned int sid_ctx_length; // eax
  unsigned __int8 *sid_ctx; // ecx
  unsigned int cipher_id; // eax
  const ssl_cipher_st *v17; // eax
  __int64 v18; // rax
  bool v19; // cc
  ssl_ctx_st *v20; // eax
  ssl_session_st *v21; // eax
  ssl_session_st *ret; // [esp+10h] [ebp-104h] BYREF
  int v23; // [esp+14h] [ebp-100h]
  _DWORD v24[18]; // [esp+18h] [ebp-FCh] BYREF
  unsigned __int8 dst[168]; // [esp+60h] [ebp-B4h] BYREF
  _DWORD v26[2]; // [esp+108h] [ebp-Ch] BYREF

  v4 = (int)session_id;
  v5 = len;
  ret = 0;
  v23 = 0;
  if ( len > 32 )
    return 0;
  v6 = tls1_process_ticket(s, (unsigned __int8 *)session_id, len, limit, &ret);
  if ( v6 == -1 )
  {
    v23 = 1;
LABEL_4:
    v7 = ret;
    goto err_233;
  }
  if ( !v6 )
    goto LABEL_4;
  v7 = ret;
  if ( !ret )
  {
    if ( !len )
      return 0;
    if ( (s->initial_ctx->session_cache_mode & 0x100) != 0 )
      goto LABEL_51;
    v24[0] = s->version;
    v24[17] = len;
    memcpy((int)dst, session_id, len);
    CRYPTO_lock(len, (int)session_id, 5, 12, ".\\ssl\\ssl_sess.c", 461);
    v9 = (ssl_session_st *)lh_retrieve((lhash_st *)s->initial_ctx->sessions, v24);
    ret = v9;
    if ( v9 )
      CRYPTO_add_lock(&v9->references, 1, 14, ".\\ssl\\ssl_sess.c", 465);
    CRYPTO_lock(len, (int)session_id, 6, 12, ".\\ssl\\ssl_sess.c", 466);
    v7 = ret;
    if ( !ret )
    {
LABEL_51:
      initial_ctx = s->initial_ctx;
      v26[0] = 1;
      ++initial_ctx->stats.sess_miss;
      v11 = s->initial_ctx;
      ret = 0;
      get_session_cb = v11->get_session_cb;
      if ( !get_session_cb )
        return 0;
      ret = get_session_cb(s, (unsigned __int8 *)session_id, len, v26);
      if ( !ret )
        return 0;
      ++s->initial_ctx->stats.sess_cb_hit;
      if ( v26[0] )
        CRYPTO_add_lock(&ret->references, 1, 14, ".\\ssl\\ssl_sess.c", 487);
      v13 = s->initial_ctx;
      if ( (v13->session_cache_mode & 0x200) == 0 )
        SSL_CTX_add_session(len, (int)session_id, v13, (lhash_node_st *)ret);
      v7 = ret;
      if ( !ret )
        return 0;
    }
  }
  sid_ctx_length = v7->sid_ctx_length;
  if ( sid_ctx_length != s->sid_ctx_length )
    goto err_233;
  sid_ctx = s->sid_ctx;
  v5 = (int)v7->sid_ctx;
  if ( sid_ctx_length >= 4 )
  {
    while ( *(_DWORD *)v5 == *(_DWORD *)sid_ctx )
    {
      sid_ctx_length -= 4;
      sid_ctx += 4;
      v5 += 4;
      if ( sid_ctx_length < 4 )
        goto LABEL_27;
    }
    goto err_233;
  }
LABEL_27:
  if ( sid_ctx_length )
  {
    if ( *sid_ctx != *(_BYTE *)v5 )
      goto err_233;
    v4 = 1;
    if ( sid_ctx_length > 1
      && (sid_ctx[1] != *(_BYTE *)(v5 + 1) || sid_ctx_length > 2 && sid_ctx[2] != *(_BYTE *)(v5 + 2)) )
    {
      goto err_233;
    }
  }
  else
  {
    v4 = 1;
  }
  if ( (s->verify_mode & 1) != 0 && !s->sid_ctx_length )
  {
    ERR_put_error(1, 0x14u, 217, 277, ".\\ssl\\ssl_sess.c", 528);
    v23 = 1;
    goto LABEL_4;
  }
  if ( !v7->cipher )
  {
    cipher_id = v7->cipher_id;
    LOBYTE(v26[0]) = HIBYTE(cipher_id);
    BYTE1(v26[0]) = BYTE2(cipher_id);
    BYTE2(v26[0]) = BYTE1(cipher_id);
    HIBYTE(v26[0]) = cipher_id;
    v17 = (int)(v7->ssl_version & 0xFFFFFF00) < 768
        ? s->method->get_cipher_by_char((char *)v26 + 1)
        : s->method->get_cipher_by_char((char *)v26 + 2);
    ret->cipher = v17;
    v7 = ret;
    if ( !ret->cipher )
    {
err_233:
      if ( v7 )
        SSL_SESSION_free(v5, v4, v7);
      if ( v23 )
        return -1;
      return 0;
    }
  }
  v18 = _time64(0);
  v19 = ret->timeout < (int)v18 - ret->time;
  v20 = s->initial_ctx;
  v26[1] = HIDWORD(v18);
  if ( v19 )
  {
    ++v20->stats.sess_timeout;
    SSL_CTX_remove_session(1, s->initial_ctx, ret);
    goto LABEL_4;
  }
  ++v20->stats.sess_hit;
  if ( s->session )
    SSL_SESSION_free(v5, 1, s->session);
  v21 = ret;
  s->session = ret;
  s->verify_result = v21->verify_result;
  return 1;
}
