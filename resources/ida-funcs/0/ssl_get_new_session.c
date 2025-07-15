int __usercall ssl_get_new_session@<eax>(int a1@<ebx>, ssl_st *s, int session)
{
  int (__cdecl *v3)(const ssl_st *, const __m128i *, unsigned int *); // ebp
  ssl_session_st *v4; // esi
  int session_id; // ebx
  int session_timeout; // eax
  int version; // eax
  int (__cdecl *generate_session_id)(const ssl_st *, unsigned __int8 *, unsigned int *); // eax
  unsigned int session_id_length; // eax
  char *v11; // eax
  unsigned __int8 *v12; // eax
  unsigned __int8 *v13; // eax
  int v14; // edx
  int v15; // [esp-8h] [ebp-18h]
  unsigned int id_len; // [esp+Ch] [ebp-4h] BYREF

  v3 = def_generate_session_id;
  v4 = SSL_SESSION_new(a1);
  session_id = 0;
  if ( !v4 )
    return 0;
  session_timeout = s->initial_ctx->session_timeout;
  if ( !session_timeout )
    session_timeout = SSL_get_default_timeout(s);
  v4->timeout = session_timeout;
  if ( s->session )
  {
    SSL_SESSION_free((int)s, 0, s->session);
    s->session = 0;
  }
  if ( !session )
  {
    v4->session_id_length = 0;
    goto LABEL_53;
  }
  version = s->version;
  if ( s->version == 2 )
  {
    v4->ssl_version = 2;
    v4->session_id_length = 16;
  }
  else
  {
    switch ( version )
    {
      case 768:
        v4->ssl_version = 768;
        break;
      case 769:
        v4->ssl_version = 769;
        break;
      case 256:
        v4->ssl_version = 256;
        break;
      case 65279:
        v4->ssl_version = 65279;
        break;
      default:
        ERR_put_error(0, 0x14u, 181, 259, ".\\ssl\\ssl_sess.c", 315);
        goto LABEL_56;
    }
    v4->session_id_length = 32;
  }
  if ( s->tlsext_ticket_expected )
  {
    v4->session_id_length = 0;
    goto sess_id_done;
  }
  CRYPTO_lock((int)s, 0, 5, 12, ".\\ssl\\ssl_sess.c", 328);
  generate_session_id = s->generate_session_id;
  if ( generate_session_id || (generate_session_id = s->initial_ctx->generate_session_id) != 0 )
    v3 = (int (__cdecl *)(const ssl_st *, const __m128i *, unsigned int *))generate_session_id;
  CRYPTO_lock((int)s, 0, 6, 12, ".\\ssl\\ssl_sess.c", 333);
  session_id = (int)v4->session_id;
  id_len = v4->session_id_length;
  if ( !v3(s, (const __m128i *)v4->session_id, &id_len) )
  {
    ERR_put_error(session_id, 0x14u, 181, 301, ".\\ssl\\ssl_sess.c", 340);
LABEL_56:
    SSL_SESSION_free((int)s, session_id, v4);
    return 0;
  }
  if ( !id_len || (session_id_length = v4->session_id_length, id_len > session_id_length) )
  {
    ERR_put_error(session_id, 0x14u, 181, 303, ".\\ssl\\ssl_sess.c", 350);
    goto LABEL_56;
  }
  if ( id_len < session_id_length && s->version == 2 )
    memset((int)&v4->session_id[id_len], 0, session_id_length - id_len);
  else
    v4->session_id_length = id_len;
  if ( SSL_has_matching_session_id(session_id, s, (const __m128i *)v4->session_id, v4->session_id_length) )
  {
    ERR_put_error(session_id, 0x14u, 181, 302, ".\\ssl\\ssl_sess.c", 364);
    goto LABEL_56;
  }
  session_id = 0;
sess_id_done:
  if ( s->tlsext_hostname )
  {
    v11 = BUF_strdup(s->tlsext_hostname);
    v4->tlsext_hostname = v11;
    if ( !v11 )
    {
      v15 = 373;
LABEL_55:
      ERR_put_error(0, 0x14u, 181, 68, ".\\ssl\\ssl_sess.c", v15);
      goto LABEL_56;
    }
  }
  if ( s->tlsext_ecpointformatlist )
  {
    if ( v4->tlsext_ecpointformatlist )
      CRYPTO_free(v4->tlsext_ecpointformatlist);
    v12 = (unsigned __int8 *)CRYPTO_malloc(s->tlsext_ecpointformatlist_length, ".\\ssl\\ssl_sess.c", 382);
    v4->tlsext_ecpointformatlist = v12;
    if ( !v12 )
    {
      ERR_put_error(0, 0x14u, 181, 65, ".\\ssl\\ssl_sess.c", 384);
      goto LABEL_56;
    }
    v4->tlsext_ecpointformatlist_length = s->tlsext_ecpointformatlist_length;
    memcpy((int)v12, (const __m128i *)s->tlsext_ecpointformatlist, s->tlsext_ecpointformatlist_length);
  }
  if ( s->tlsext_ellipticcurvelist )
  {
    if ( v4->tlsext_ellipticcurvelist )
      CRYPTO_free(v4->tlsext_ellipticcurvelist);
    v13 = (unsigned __int8 *)CRYPTO_malloc(s->tlsext_ellipticcurvelist_length, ".\\ssl\\ssl_sess.c", 394);
    v4->tlsext_ellipticcurvelist = v13;
    if ( !v13 )
    {
      ERR_put_error(0, 0x14u, 181, 65, ".\\ssl\\ssl_sess.c", 396);
      goto LABEL_56;
    }
    v4->tlsext_ellipticcurvelist_length = s->tlsext_ellipticcurvelist_length;
    memcpy((int)v13, (const __m128i *)s->tlsext_ellipticcurvelist, s->tlsext_ellipticcurvelist_length);
  }
LABEL_53:
  if ( s->sid_ctx_length > 0x20 )
  {
    v15 = 413;
    goto LABEL_55;
  }
  memcpy((int)v4->sid_ctx, (const __m128i *)s->sid_ctx, s->sid_ctx_length);
  v4->sid_ctx_length = s->sid_ctx_length;
  v14 = s->version;
  s->session = v4;
  v4->verify_result = 0;
  v4->ssl_version = v14;
  return 1;
}
