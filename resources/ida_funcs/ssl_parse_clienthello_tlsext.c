int __cdecl ssl_parse_clienthello_tlsext(
        ssl_st *s,
        unsigned __int16 **p,
        unsigned __int8 *d,
        unsigned __int8 *n,
        int *al)
{
  int v5; // edx
  unsigned __int16 *v7; // edi
  unsigned __int16 v8; // bx
  unsigned __int8 *v9; // edi
  __int16 v10; // ax
  unsigned __int16 v11; // cx
  unsigned __int8 *v12; // edi
  unsigned __int16 v13; // bx
  int v14; // ecx
  int v15; // ebp
  unsigned __int8 *v16; // edi
  void (__cdecl *tlsext_debug_cb)(ssl_st *, int, int, unsigned __int8 *, int, void *); // eax
  int v18; // eax
  unsigned __int8 *v19; // ebx
  int v20; // edx
  unsigned __int16 v21; // ax
  unsigned int v22; // ebp
  bool v23; // cc
  unsigned __int8 *v24; // eax
  ssl_session_st *v25; // eax
  const char *tlsext_hostname; // edx
  BOOL v27; // eax
  unsigned int v29; // ebx
  ssl_session_st *session; // edx
  ssl_session_st *v31; // eax
  int v32; // ebx
  ssl_session_st *v33; // eax
  ssl_session_st *v34; // eax
  int (__cdecl *tls_session_ticket_ext_cb)(ssl_st *, const unsigned __int8 *, int, void *); // eax
  int v36; // eax
  unsigned __int16 v37; // bx
  int v38; // ebp
  unsigned __int8 *v39; // edi
  unsigned __int8 *v40; // eax
  int v41; // edi
  stack_st_OCSP_RESPID *v42; // eax
  int v43; // ebp
  stack_st_X509_EXTENSION *tlsext_ocsp_exts; // eax
  stack_st_X509_EXTENSION *v45; // eax
  int *v46; // eax
  unsigned __int8 *v47; // [esp+10h] [ebp-Ch]
  int v48; // [esp+14h] [ebp-8h]
  unsigned __int16 sa; // [esp+20h] [ebp+4h]
  ocsp_responder_id_st *sb; // [esp+20h] [ebp+4h]
  int v51; // [esp+28h] [ebp+Ch]
  int v52; // [esp+28h] [ebp+Ch]

  v5 = (int)n;
  v7 = *p;
  v48 = 0;
  s->servername_done = 0;
  s->tlsext_status_type = -1;
  v47 = &d[v5];
  if ( v7 < (unsigned __int16 *)&d[v5 - 2] )
  {
    v8 = _byteswap_ushort(*v7);
    v9 = (unsigned __int8 *)(v7 + 1);
    if ( v9 <= &d[v5 - v8] )
    {
      if ( v9 > &d[v5 - 4] )
      {
LABEL_77:
        *p = (unsigned __int16 *)v9;
      }
      else
      {
        while ( 1 )
        {
          v10 = v9[2];
          v11 = _byteswap_ushort(*(_WORD *)v9);
          v12 = v9 + 2;
          v13 = v11;
          v14 = (unsigned __int16)(v12[1] | (unsigned __int16)(v10 << 8));
          v15 = v14;
          v16 = v12 + 2;
          sa = v14;
          if ( &v16[v14] > v47 )
            break;
          tlsext_debug_cb = s->tlsext_debug_cb;
          if ( tlsext_debug_cb )
          {
            tlsext_debug_cb(s, 0, v13, v16, v14, s->tlsext_debug_arg);
            LOWORD(v14) = sa;
          }
          if ( v13 )
          {
            switch ( v13 )
            {
              case 0xBu:
                if ( s->version != 65279 )
                {
                  v29 = *v16;
                  if ( v29 != v15 - 1 )
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
                    s->session->tlsext_ecpointformatlist = (unsigned __int8 *)CRYPTO_malloc(
                                                                                v29,
                                                                                ".\\ssl\\t1_lib.c",
                                                                                786);
                    v31 = s->session;
                    if ( !v31->tlsext_ecpointformatlist )
                      goto LABEL_90;
                    v31->tlsext_ecpointformatlist_length = v29;
                    memcpy(s->session->tlsext_ecpointformatlist, v16 + 1, v29);
                  }
                }
                break;
              case 0xAu:
                if ( s->version != 65279 )
                {
                  v32 = v16[1] + (*v16 << 8);
                  if ( v32 != v15 - 2 )
                    goto LABEL_28;
                  if ( !s->hit )
                  {
                    v33 = s->session;
                    if ( v33->tlsext_ellipticcurvelist )
                      goto LABEL_86;
                    v33->tlsext_ellipticcurvelist_length = 0;
                    s->session->tlsext_ellipticcurvelist = (unsigned __int8 *)CRYPTO_malloc(
                                                                                v32,
                                                                                ".\\ssl\\t1_lib.c",
                                                                                822);
                    v34 = s->session;
                    if ( !v34->tlsext_ellipticcurvelist )
                    {
LABEL_90:
                      *al = 80;
                      return 0;
                    }
                    v34->tlsext_ellipticcurvelist_length = v32;
                    memcpy(s->session->tlsext_ellipticcurvelist, v16 + 2, v32);
                  }
                }
                break;
              case 0x23u:
                tls_session_ticket_ext_cb = s->tls_session_ticket_ext_cb;
                if ( tls_session_ticket_ext_cb
                  && !tls_session_ticket_ext_cb(s, v16, v15, s->tls_session_ticket_ext_cb_arg) )
                {
LABEL_88:
                  *al = 80;
                  return 0;
                }
                break;
              case 0xFF01:
                if ( !ssl_parse_clienthello_renegotiate_ext(s, v16, v15, al) )
                  return 0;
                v48 = 1;
                break;
              default:
                if ( v13 == 5 && s->version != 65279 && s->ctx->tlsext_status_cb )
                {
                  if ( sa < 5u )
                    goto LABEL_86;
                  v36 = *v16;
                  --sa;
                  ++v16;
                  s->tlsext_status_type = v36;
                  if ( v36 == 1 )
                  {
                    v37 = sa - 2;
                    v38 = v16[1] | (*v16 << 8);
                    v39 = v16 + 2;
                    if ( v38 > (unsigned __int16)(sa - 2) )
                      goto LABEL_73;
                    if ( v38 > 0 )
                    {
                      while ( v38 >= 4 )
                      {
                        v40 = (unsigned __int8 *)(v39[1] | (*v39 << 8));
                        v38 += -2 - (_DWORD)v40;
                        v41 = (int)(v39 + 2);
                        v37 += -2 - (_WORD)v40;
                        if ( v38 < 0 )
                          goto LABEL_86;
                        n = (unsigned __int8 *)v41;
                        v39 = &v40[v41];
                        sb = d2i_OCSP_RESPID(0, &n, v40);
                        if ( !sb )
                          goto LABEL_73;
                        if ( v39 != n )
                        {
                          OCSP_RESPID_free(sb);
                          goto LABEL_86;
                        }
                        if ( !s->tlsext_ocsp_ids )
                        {
                          v42 = (stack_st_OCSP_RESPID *)sk_new_null();
                          s->tlsext_ocsp_ids = v42;
                          if ( !v42 )
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
                        if ( v38 <= 0 )
                          goto LABEL_66;
                      }
LABEL_28:
                      *al = 50;
                      return 0;
                    }
LABEL_66:
                    if ( v37 < 2u )
                      goto LABEL_28;
                    v43 = v39[1] | (*v39 << 8);
                    v16 = v39 + 2;
                    sa = v37 - 2;
                    if ( v43 != (unsigned __int16)(v37 - 2) )
                      goto LABEL_86;
                    n = v16;
                    if ( v43 > 0 )
                    {
                      tlsext_ocsp_exts = s->tlsext_ocsp_exts;
                      if ( tlsext_ocsp_exts )
                        sk_pop_free(&tlsext_ocsp_exts->stack, (void (__cdecl *)(void *))X509_EXTENSION_free);
                      v45 = d2i_X509_EXTENSIONS(0, (const unsigned __int8 **)&n, v43);
                      s->tlsext_ocsp_exts = v45;
                      if ( !v45 || &v16[v43] != n )
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
            if ( (unsigned __int16)v14 < 2u )
              goto LABEL_73;
            sa = v14 - 2;
            v18 = v16[1] | (*v16 << 8);
            v16 += 2;
            v51 = v18;
            if ( v18 > (unsigned __int16)(v14 - 2) )
              goto LABEL_28;
            v19 = v16;
            if ( v18 > 3 )
            {
              while ( 1 )
              {
                v20 = *v19;
                v21 = _byteswap_ushort(*(_WORD *)(v19 + 1));
                v22 = v21;
                v19 += 3;
                v23 = v21 <= v51 - 3;
                v52 = v51 - 3;
                if ( !v23 )
                  break;
                if ( !s->servername_done && !v20 )
                {
                  if ( s->hit )
                  {
                    v25 = s->session;
                    tlsext_hostname = v25->tlsext_hostname;
                    v27 = tlsext_hostname
                       && strlen(v25->tlsext_hostname) == v22
                       && !strncmp(tlsext_hostname, (const char *)v19, v22);
                    s->servername_done = v27;
                  }
                  else
                  {
                    if ( s->session->tlsext_hostname )
                      goto LABEL_73;
                    if ( v21 > 0xFFu )
                    {
                      *al = 112;
                      return 0;
                    }
                    s->session->tlsext_hostname = (char *)CRYPTO_malloc(v21 + 1, ".\\ssl\\t1_lib.c", 729);
                    v24 = (unsigned __int8 *)s->session->tlsext_hostname;
                    if ( !v24 )
                    {
                      *al = 80;
                      return 0;
                    }
                    memcpy(v24, v19, v22);
                    s->session->tlsext_hostname[v22] = 0;
                    if ( strlen(s->session->tlsext_hostname) != v22 )
                    {
                      CRYPTO_free(s->session->tlsext_hostname);
                      v46 = al;
                      s->session->tlsext_hostname = 0;
                      *v46 = 112;
                      return 0;
                    }
                    s->servername_done = 1;
                  }
                }
                v18 = v52 - v22;
                v51 = v52 - v22;
                if ( v51 <= 3 )
                  goto LABEL_27;
              }
LABEL_86:
              *al = 50;
              return 0;
            }
LABEL_27:
            if ( v18 )
              goto LABEL_28;
          }
          v9 = &v16[sa];
          if ( v9 > v47 - 4 )
            goto LABEL_77;
        }
      }
      if ( v48 )
        return 1;
    }
  }
  if ( !s->new_session || (s->options & 0x40000) != 0 )
    return 1;
  *al = 40;
  ERR_put_error(0x14u, 302, 338, ".\\ssl\\t1_lib.c", 1013);
  return 0;
}
