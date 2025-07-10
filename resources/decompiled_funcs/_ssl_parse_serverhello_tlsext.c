int __cdecl ssl_parse_serverhello_tlsext(ssl_st *s, unsigned __int16 **p, unsigned __int8 *d, int n, int *al)
{
  unsigned __int16 *v5; // esi
  unsigned __int8 *v6; // edx
  int v7; // eax
  unsigned int v8; // esi
  unsigned __int16 v10; // ax
  __int16 v11; // cx
  unsigned __int8 *v12; // esi
  unsigned __int16 v13; // bp
  unsigned __int16 v14; // cx
  int v15; // ebx
  unsigned __int8 *v16; // esi
  void (__cdecl *tlsext_debug_cb)(ssl_st *, int, int, unsigned __int8 *, int, void *); // eax
  unsigned int v18; // ebp
  unsigned __int8 *v19; // esi
  ssl_session_st *session; // eax
  int (__cdecl *tls_session_ticket_ext_cb)(ssl_st *, const unsigned __int8 *, int, void *); // eax
  unsigned int options; // eax
  int v23; // [esp+10h] [ebp-Ch]
  int v24; // [esp+14h] [ebp-8h]
  unsigned __int8 *v25; // [esp+18h] [ebp-4h]
  unsigned int v26; // [esp+28h] [ebp+Ch]
  unsigned __int16 v27; // [esp+2Ch] [ebp+10h]

  v5 = *p;
  v6 = &d[n];
  v23 = 0;
  v24 = 0;
  v25 = &d[n];
  if ( *p >= (unsigned __int16 *)&d[n - 2] )
    goto LABEL_50;
  v7 = _byteswap_ushort(*v5);
  v8 = (unsigned int)(v5 + 1);
  if ( (unsigned __int8 *)(v8 + v7) == v6 )
  {
    if ( v8 <= (unsigned int)(v6 - 4) )
    {
      while ( 1 )
      {
        v10 = _byteswap_ushort(*(_WORD *)v8);
        v11 = *(unsigned __int8 *)(v8 + 3);
        v12 = (unsigned __int8 *)(v8 + 2);
        v13 = v10;
        v14 = v11 | (*v12 << 8);
        v15 = v14;
        v16 = v12 + 2;
        v27 = v14;
        v26 = (unsigned int)&v16[v14];
        if ( v26 > (unsigned int)v6 )
          break;
        tlsext_debug_cb = s->tlsext_debug_cb;
        if ( tlsext_debug_cb )
        {
          tlsext_debug_cb(s, 1, v13, v16, v14, s->tlsext_debug_arg);
          v14 = v27;
        }
        if ( v13 )
        {
          switch ( v13 )
          {
            case 0xBu:
              if ( s->version != 65279 )
              {
                v18 = *v16;
                v19 = v16 + 1;
                if ( v18 != v15 - 1 )
                  goto LABEL_3;
                s->session->tlsext_ecpointformatlist_length = 0;
                if ( s->session->tlsext_ecpointformatlist )
                  CRYPTO_free(s->session->tlsext_ecpointformatlist);
                s->session->tlsext_ecpointformatlist = (unsigned __int8 *)CRYPTO_malloc(v18, ".\\ssl\\t1_lib.c", 1075);
                session = s->session;
                if ( !session->tlsext_ecpointformatlist )
                {
                  *al = 80;
                  return 0;
                }
                session->tlsext_ecpointformatlist_length = v18;
                memcpy(s->session->tlsext_ecpointformatlist, v19, v18);
              }
              break;
            case 0x23u:
              tls_session_ticket_ext_cb = s->tls_session_ticket_ext_cb;
              if ( tls_session_ticket_ext_cb
                && !tls_session_ticket_ext_cb(s, v16, v15, s->tls_session_ticket_ext_cb_arg) )
              {
                *al = 80;
                return 0;
              }
              if ( (SSL_ctrl(s, 32, 0, 0) & 0x4000) != 0 || v27 )
              {
                *al = 110;
                return 0;
              }
              s->tlsext_ticket_expected = 1;
              break;
            case 5u:
              if ( s->version != 65279 )
              {
                if ( s->tlsext_status_type == -1 || v14 )
                {
                  *al = 110;
                  return 0;
                }
                s->tlsext_status_expected = 1;
              }
              break;
            case 0xFF01:
              if ( !ssl_parse_serverhello_renegotiate_ext(s, v16, v15, al) )
                return 0;
              v24 = 1;
              break;
          }
        }
        else
        {
          if ( !s->tlsext_hostname || v14 )
          {
            *al = 112;
            return 0;
          }
          v23 = 1;
        }
        v6 = v25;
        v8 = v26;
        if ( v26 > (unsigned int)(v25 - 4) )
          goto LABEL_35;
      }
ri_check_0:
      if ( v24 )
        return 1;
LABEL_50:
      options = s->options;
      if ( (options & 4) == 0 && (options & 0x40000) == 0 )
      {
        *al = 40;
        ERR_put_error(0x14u, 303, 338, ".\\ssl\\t1_lib.c", 1207);
        return 0;
      }
      return 1;
    }
LABEL_35:
    if ( (unsigned __int8 *)v8 != v6 )
    {
LABEL_36:
      *al = 50;
      return 0;
    }
    if ( !s->hit && v23 == 1 && s->tlsext_hostname )
    {
      if ( s->session->tlsext_hostname )
        goto LABEL_36;
      s->session->tlsext_hostname = BUF_strdup(s->tlsext_hostname);
      if ( !s->session->tlsext_hostname )
      {
        *al = 112;
        return 0;
      }
    }
    *p = (unsigned __int16 *)v8;
    goto ri_check_0;
  }
LABEL_3:
  *al = 50;
  return 0;
}
