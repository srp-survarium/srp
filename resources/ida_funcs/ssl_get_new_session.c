int __cdecl ssl_get_new_session(ssl_st *s, int session)
{
  int (__cdecl *v2)(const ssl_st *, unsigned __int8 *, unsigned int *); // ebp
  ssl_session_st *v3; // esi
  int session_timeout; // eax
  int version; // eax
  int (__cdecl *generate_session_id)(const ssl_st *, unsigned __int8 *, unsigned int *); // eax
  unsigned int session_id_length; // eax
  char *v9; // eax
  unsigned __int8 *v10; // eax
  unsigned __int8 *v11; // eax
  int v12; // edx
  unsigned int id_len; // [esp+Ch] [ebp-4h] BYREF

  v2 = def_generate_session_id;
  v3 = SSL_SESSION_new();
  if ( !v3 )
    return 0;
  session_timeout = s->initial_ctx->session_timeout;
  if ( !session_timeout )
    session_timeout = SSL_get_default_timeout(s);
  v3->timeout = session_timeout;
  if ( s->session )
  {
    SSL_SESSION_free((unsigned int)s, s->session);
    s->session = 0;
  }
  if ( !session )
  {
    v3->session_id_length = 0;
    goto LABEL_52;
  }
  version = s->version;
  if ( s->version == 2 )
  {
    v3->ssl_version = 2;
    v3->session_id_length = 16;
  }
  else
  {
    switch ( version )
    {
      case 768:
        v3->ssl_version = 768;
        break;
      case 769:
        v3->ssl_version = 769;
        break;
      case 256:
        v3->ssl_version = 256;
        break;
      case 65279:
        v3->ssl_version = 65279;
        break;
      default:
        ERR_put_error(0x14u, 181, 259, ".\\ssl\\ssl_sess.c", 315);
        goto LABEL_54;
    }
    v3->session_id_length = 32;
  }
  if ( !s->tlsext_ticket_expected )
  {
    CRYPTO_lock((unsigned int)s, 5, 12, ".\\ssl\\ssl_sess.c", 328);
    generate_session_id = s->generate_session_id;
    if ( generate_session_id || (generate_session_id = s->initial_ctx->generate_session_id) != 0 )
      v2 = generate_session_id;
    CRYPTO_lock((unsigned int)s, 6, 12, ".\\ssl\\ssl_sess.c", 333);
    id_len = v3->session_id_length;
    if ( v2(s, v3->session_id, &id_len) )
    {
      if ( !id_len || (session_id_length = v3->session_id_length, id_len > session_id_length) )
      {
        ERR_put_error(0x14u, 181, 303, ".\\ssl\\ssl_sess.c", 350);
        goto LABEL_54;
      }
      if ( id_len < session_id_length && s->version == 2 )
        memset((int)&v3->session_id[id_len], 0, session_id_length - id_len);
      else
        v3->session_id_length = id_len;
      if ( !SSL_has_matching_session_id(s, v3->session_id, v3->session_id_length) )
        goto sess_id_done;
      ERR_put_error(0x14u, 181, 302, ".\\ssl\\ssl_sess.c", 364);
    }
    else
    {
      ERR_put_error(0x14u, 181, 301, ".\\ssl\\ssl_sess.c", 340);
    }
LABEL_54:
    SSL_SESSION_free((unsigned int)s, v3);
    return 0;
  }
  v3->session_id_length = 0;
sess_id_done:
  if ( s->tlsext_hostname )
  {
    v9 = BUF_strdup(s->tlsext_hostname);
    v3->tlsext_hostname = v9;
    if ( !v9 )
    {
      ERR_put_error(0x14u, 181, 68, ".\\ssl\\ssl_sess.c", 373);
      goto LABEL_54;
    }
  }
  if ( s->tlsext_ecpointformatlist )
  {
    if ( v3->tlsext_ecpointformatlist )
      CRYPTO_free(v3->tlsext_ecpointformatlist);
    v10 = (unsigned __int8 *)CRYPTO_malloc(s->tlsext_ecpointformatlist_length, ".\\ssl\\ssl_sess.c", 382);
    v3->tlsext_ecpointformatlist = v10;
    if ( !v10 )
    {
      ERR_put_error(0x14u, 181, 65, ".\\ssl\\ssl_sess.c", 384);
      goto LABEL_54;
    }
    v3->tlsext_ecpointformatlist_length = s->tlsext_ecpointformatlist_length;
    memcpy(v10, s->tlsext_ecpointformatlist, s->tlsext_ecpointformatlist_length);
  }
  if ( s->tlsext_ellipticcurvelist )
  {
    if ( v3->tlsext_ellipticcurvelist )
      CRYPTO_free(v3->tlsext_ellipticcurvelist);
    v11 = (unsigned __int8 *)CRYPTO_malloc(s->tlsext_ellipticcurvelist_length, ".\\ssl\\ssl_sess.c", 394);
    v3->tlsext_ellipticcurvelist = v11;
    if ( !v11 )
    {
      ERR_put_error(0x14u, 181, 65, ".\\ssl\\ssl_sess.c", 396);
      goto LABEL_54;
    }
    v3->tlsext_ellipticcurvelist_length = s->tlsext_ellipticcurvelist_length;
    memcpy(v11, s->tlsext_ellipticcurvelist, s->tlsext_ellipticcurvelist_length);
  }
LABEL_52:
  if ( s->sid_ctx_length > 0x20 )
  {
    ERR_put_error(0x14u, 181, 68, ".\\ssl\\ssl_sess.c", 413);
    goto LABEL_54;
  }
  memcpy(v3->sid_ctx, s->sid_ctx, s->sid_ctx_length);
  v3->sid_ctx_length = s->sid_ctx_length;
  v12 = s->version;
  s->session = v3;
  v3->verify_result = 0;
  v3->ssl_version = v12;
  return 1;
}
