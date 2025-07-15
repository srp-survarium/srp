int __cdecl ssl_parse_clienthello_tlsext(
        ssl_st *s,
        unsigned __int16 **p,
        unsigned __int8 *d,
        unsigned __int8 *n,
        int *al)
{
  unsigned __int8 *v5; // edx
  unsigned __int16 *v7; // edi
  unsigned int v8; // ebx
  unsigned int v9; // edi
  __int16 v10; // ax
  unsigned __int16 v11; // cx
  unsigned int v12; // edi
  int v13; // ecx
  int v14; // ebp
  unsigned int v15; // edi
  void (__cdecl *tlsext_debug_cb)(ssl_st *, int, int, unsigned __int8 *, int, void *); // eax
  int v17; // eax
  int v18; // edx
  unsigned __int16 v19; // ax
  unsigned int v20; // ebp
  bool v21; // cc
  char *v22; // eax
  ssl_session_st *v23; // eax
  const char *tlsext_hostname; // edx
  BOOL v25; // eax
  ssl_session_st *session; // edx
  ssl_session_st *v28; // eax
  ssl_session_st *v29; // eax
  ssl_session_st *v30; // eax
  int (__cdecl *tls_session_ticket_ext_cb)(ssl_st *, const unsigned __int8 *, int, void *); // eax
  int v32; // eax
  char *v33; // ebx
  int v34; // ebp
  unsigned __int8 *v35; // edi
  const unsigned __int8 **v36; // eax
  unsigned __int8 *v37; // edi
  stack_st_OCSP_RESPID *v38; // eax
  const unsigned __int8 *v39; // ebp
  stack_st_X509_EXTENSION *tlsext_ocsp_exts; // eax
  stack_st_X509_EXTENSION *v41; // eax
  int *v42; // eax
  unsigned __int8 *v43; // [esp+10h] [ebp-Ch]
  int v44; // [esp+14h] [ebp-8h]
  ssl_st *sa; // [esp+20h] [ebp+4h]
  ocsp_responder_id_st *sb; // [esp+20h] [ebp+4h]
  int v47; // [esp+28h] [ebp+Ch]
  int v48; // [esp+28h] [ebp+Ch]

  v5 = n;
  v7 = *p;
  v44 = 0;
  s->servername_done = 0;
  v8 = (unsigned int)&v5[(_DWORD)d - 2];
  s->tlsext_status_type = -1;
  v43 = &v5[(_DWORD)d];
  if ( (unsigned int)v7 < v8 )
  {
    v8 = _byteswap_ushort(*v7);
    v9 = (unsigned int)(v7 + 1);
    if ( (unsigned __int8 *)v9 <= &d[(int)v5 - (unsigned __int16)v8] )
    {
      if ( (unsigned __int8 *)v9 > &v5[(int)d - 4] )
      {
LABEL_77:
        *p = (unsigned __int16 *)v9;
      }
      else
      {
        while ( 1 )
        {
          v10 = *(unsigned __int8 *)(v9 + 2);
          v11 = _byteswap_ushort(*(_WORD *)v9);
          v12 = v9 + 2;
          v8 = v11;
          v13 = (unsigned __int16)(*(unsigned __int8 *)(v12 + 1) | (unsigned __int16)(v10 << 8));
          v14 = v13;
          v15 = v12 + 2;
          sa = (ssl_st *)v13;
          if ( v15 + v13 > (unsigned int)v43 )
            break;
          tlsext_debug_cb = s->tlsext_debug_cb;
          if ( tlsext_debug_cb )
          {
            tlsext_debug_cb(s, 0, (unsigned __int16)v8, (unsigned __int8 *)v15, v13, s->tlsext_debug_arg);
            LOWORD(v13) = (_WORD)sa;
          }
          if ( (_WORD)v8 )
          {
            switch ( (_WORD)v8 )
            {
              case 0xB:
                if ( s->version != 65279 )
                {
                  v8 = *(unsigned __int8 *)v15;
                  if ( v8 != v14 - 1 )
                    goto LABEL_86;
                  if ( !s->hit )
                  {
                    session = s->session;
                    if ( session->tlsext_ecpointformatlist )
                    {
                      CRYPTO_free(session->tlsext_ecpointformatlist);
                      s->session->tlsext_ecpointformatlist = 0;
                    }
                    s->session->tlsext_ecpointformatlist_length = 0;
                    s->session->tlsext_ecpointformatlist = (unsigned __int8 *)CRYPTO_malloc(v8, ".\\ssl\\t1_lib.c", 786);
                    v28 = s->session;
                    if ( !v28->tlsext_ecpointformatlist )
                      goto LABEL_90;
                    v28->tlsext_ecpointformatlist_length = v8;
                    memcpy((int)s->session->tlsext_ecpointformatlist, (const __m128i *)(v15 + 1), v8);
                  }
                }
                break;
              case 0xA:
                if ( s->version != 65279 )
                {
                  v8 = *(unsigned __int8 *)(v15 + 1) + (*(unsigned __int8 *)v15 << 8);
                  if ( v8 != v14 - 2 )
                    goto LABEL_28;
                  if ( !s->hit )
                  {
                    v29 = s->session;
                    if ( v29->tlsext_ellipticcurvelist )
                      goto LABEL_86;
                    v29->tlsext_ellipticcurvelist_length = 0;
                    s->session->tlsext_ellipticcurvelist = (unsigned __int8 *)CRYPTO_malloc(v8, ".\\ssl\\t1_lib.c", 822);
                    v30 = s->session;
                    if ( !v30->tlsext_ellipticcurvelist )
                    {
LABEL_90:
                      *al = 80;
                      return 0;
                    }
                    v30->tlsext_ellipticcurvelist_length = v8;
                    memcpy((int)s->session->tlsext_ellipticcurvelist, (const __m128i *)(v15 + 2), v8);
                  }
                }
                break;
              case 0x23:
                tls_session_ticket_ext_cb = s->tls_session_ticket_ext_cb;
                if ( tls_session_ticket_ext_cb
                  && !tls_session_ticket_ext_cb(s, (const unsigned __int8 *)v15, v14, s->tls_session_ticket_ext_cb_arg) )
                {
LABEL_88:
                  *al = 80;
                  return 0;
                }
                break;
              case 0xFF01:
                if ( !ssl_parse_clienthello_renegotiate_ext(s, (unsigned __int8 *)v15, v14, al) )
                  return 0;
                v44 = 1;
                break;
              default:
                if ( (_WORD)v8 == 5 && s->version != 65279 && s->ctx->tlsext_status_cb )
                {
                  if ( (unsigned __int16)sa < 5u )
                    goto LABEL_86;
                  v32 = *(unsigned __int8 *)v15;
                  sa = (ssl_st *)((char *)sa + 0xFFFF);
                  ++v15;
                  s->tlsext_status_type = v32;
                  if ( v32 == 1 )
                  {
                    v33 = (char *)&sa[176].init_buf + 2;
                    v34 = *(unsigned __int8 *)(v15 + 1) | (*(unsigned __int8 *)v15 << 8);
                    v35 = (unsigned __int8 *)(v15 + 2);
                    if ( v34 > (unsigned __int16)((_WORD)sa - 2) )
                      goto LABEL_73;
                    if ( v34 > 0 )
                    {
                      while ( v34 >= 4 )
                      {
                        v36 = (const unsigned __int8 **)(v35[1] | (*v35 << 8));
                        v34 += -2 - (_DWORD)v36;
                        v37 = v35 + 2;
                        v33 += 65534 - (_DWORD)v36;
                        if ( v34 < 0 )
                          goto LABEL_86;
                        n = v37;
                        v35 = &v37[(_DWORD)v36];
                        sb = d2i_OCSP_RESPID(0, &n, v36);
                        if ( !sb )
                          goto LABEL_73;
                        if ( v35 != n )
                        {
                          OCSP_RESPID_free(sb);
                          goto LABEL_86;
                        }
                        if ( !s->tlsext_ocsp_ids )
                        {
                          v38 = (stack_st_OCSP_RESPID *)sk_new_null();
                          s->tlsext_ocsp_ids = v38;
                          if ( !v38 )
                          {
                            OCSP_RESPID_free(sb);
                            goto LABEL_88;
                          }
                        }
                        if ( !sk_push(&s->tlsext_ocsp_ids->stack, (char *)sb) )
                        {
                          OCSP_RESPID_free(sb);
                          goto LABEL_90;
                        }
                        if ( v34 <= 0 )
                          goto LABEL_66;
                      }
LABEL_28:
                      *al = 50;
                      return 0;
                    }
LABEL_66:
                    if ( (unsigned __int16)v33 < 2u )
                      goto LABEL_28;
                    v8 = (unsigned int)(v33 + 65534);
                    v39 = (const unsigned __int8 *)(v35[1] | (*v35 << 8));
                    v15 = (unsigned int)(v35 + 2);
                    LOWORD(sa) = v8;
                    if ( v39 != (const unsigned __int8 *)(unsigned __int16)v8 )
                      goto LABEL_86;
                    n = (unsigned __int8 *)v15;
                    if ( (int)v39 > 0 )
                    {
                      tlsext_ocsp_exts = s->tlsext_ocsp_exts;
                      if ( tlsext_ocsp_exts )
                        sk_pop_free(&tlsext_ocsp_exts->stack, (void (__cdecl *)(void *))X509_EXTENSION_free);
                      v41 = d2i_X509_EXTENSIONS(0, &n, v39);
                      s->tlsext_ocsp_exts = v41;
                      if ( !v41 || &v39[v15] != n )
                      {
LABEL_73:
                        *al = 50;
                        return 0;
                      }
                    }
                  }
                  else
                  {
                    s->tlsext_status_type = -1;
                  }
                }
                break;
            }
          }
          else
          {
            if ( (unsigned __int16)v13 < 2u )
              goto LABEL_73;
            LOWORD(sa) = v13 - 2;
            v17 = *(unsigned __int8 *)(v15 + 1) | (*(unsigned __int8 *)v15 << 8);
            v15 += 2;
            v47 = v17;
            if ( v17 > (unsigned __int16)(v13 - 2) )
              goto LABEL_28;
            v8 = v15;
            if ( v17 > 3 )
            {
              while ( 1 )
              {
                v18 = *(unsigned __int8 *)v8;
                v19 = _byteswap_ushort(*(_WORD *)(v8 + 1));
                v20 = v19;
                v8 += 3;
                v21 = v19 <= v47 - 3;
                v48 = v47 - 3;
                if ( !v21 )
                  break;
                if ( !s->servername_done && !v18 )
                {
                  if ( s->hit )
                  {
                    v23 = s->session;
                    tlsext_hostname = v23->tlsext_hostname;
                    v25 = tlsext_hostname
                       && strlen(v23->tlsext_hostname) == v20
                       && !strncmp(tlsext_hostname, (const char *)v8, v20);
                    s->servername_done = v25;
                  }
                  else
                  {
                    if ( s->session->tlsext_hostname )
                      goto LABEL_73;
                    if ( v19 > 0xFFu )
                    {
                      *al = 112;
                      return 0;
                    }
                    s->session->tlsext_hostname = (char *)CRYPTO_malloc(v19 + 1, ".\\ssl\\t1_lib.c", 729);
                    v22 = s->session->tlsext_hostname;
                    if ( !v22 )
                    {
                      *al = 80;
                      return 0;
                    }
                    memcpy((int)v22, (const __m128i *)v8, v20);
                    s->session->tlsext_hostname[v20] = 0;
                    if ( strlen(s->session->tlsext_hostname) != v20 )
                    {
                      CRYPTO_free(s->session->tlsext_hostname);
                      v42 = al;
                      s->session->tlsext_hostname = 0;
                      *v42 = 112;
                      return 0;
                    }
                    s->servername_done = 1;
                  }
                }
                v17 = v48 - v20;
                v47 = v48 - v20;
                if ( v47 <= 3 )
                  goto LABEL_27;
              }
LABEL_86:
              *al = 50;
              return 0;
            }
LABEL_27:
            if ( v17 )
              goto LABEL_28;
          }
          v9 = (unsigned __int16)sa + v15;
          if ( v9 > (unsigned int)(v43 - 4) )
            goto LABEL_77;
        }
      }
      if ( v44 )
        return 1;
    }
  }
  if ( !s->new_session || (s->options & 0x40000) != 0 )
    return 1;
  *al = 40;
  ERR_put_error(v8, 0x14u, 302, 338, ".\\ssl\\t1_lib.c", 1013);
  return 0;
}
