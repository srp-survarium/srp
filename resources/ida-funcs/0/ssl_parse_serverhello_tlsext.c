int __usercall ssl_parse_serverhello_tlsext@<eax>(
        int a1@<ebx>,
        ssl_st *s,
        unsigned __int16 **p,
        unsigned __int8 *d,
        int n,
        int *al)
{
  unsigned __int16 *v6; // esi
  unsigned __int8 *v7; // edx
  int v8; // eax
  unsigned int v9; // esi
  unsigned __int16 v11; // ax
  __int16 v12; // cx
  unsigned __int8 *v13; // esi
  unsigned __int16 v14; // bp
  unsigned __int16 v15; // cx
  unsigned __int8 *v16; // esi
  void (__cdecl *tlsext_debug_cb)(ssl_st *, int, int, unsigned __int8 *, int, void *); // eax
  unsigned int v18; // ebp
  const __m128i *v19; // esi
  ssl_session_st *session; // eax
  int (__cdecl *tls_session_ticket_ext_cb)(ssl_st *, const unsigned __int8 *, int, void *); // eax
  unsigned int options; // eax
  int v23; // [esp+10h] [ebp-Ch]
  int v24; // [esp+14h] [ebp-8h]
  unsigned __int8 *v25; // [esp+18h] [ebp-4h]
  unsigned int v26; // [esp+28h] [ebp+Ch]
  unsigned __int16 v27; // [esp+2Ch] [ebp+10h]

  v6 = *p;
  v7 = &d[n];
  v23 = 0;
  v24 = 0;
  v25 = &d[n];
  if ( *p >= (unsigned __int16 *)&d[n - 2] )
    goto LABEL_50;
  v8 = _byteswap_ushort(*v6);
  v9 = (unsigned int)(v6 + 1);
  if ( (unsigned __int8 *)(v9 + v8) == v7 )
  {
    if ( v9 <= (unsigned int)(v7 - 4) )
    {
      while ( 1 )
      {
        v11 = _byteswap_ushort(*(_WORD *)v9);
        v12 = *(unsigned __int8 *)(v9 + 3);
        v13 = (unsigned __int8 *)(v9 + 2);
        v14 = v11;
        v15 = v12 | (*v13 << 8);
        a1 = v15;
        v16 = v13 + 2;
        v27 = v15;
        v26 = (unsigned int)&v16[v15];
        if ( v26 > (unsigned int)v7 )
          break;
        tlsext_debug_cb = s->tlsext_debug_cb;
        if ( tlsext_debug_cb )
        {
          tlsext_debug_cb(s, 1, v14, v16, v15, s->tlsext_debug_arg);
          v15 = v27;
        }
        if ( v14 )
        {
          switch ( v14 )
          {
            case 0xBu:
              if ( s->version != 65279 )
              {
                v18 = *v16;
                --a1;
                v19 = (const __m128i *)(v16 + 1);
                if ( v18 != a1 )
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
                memcpy((int)s->session->tlsext_ecpointformatlist, v19, v18);
              }
              break;
            case 0x23u:
              tls_session_ticket_ext_cb = s->tls_session_ticket_ext_cb;
              if ( tls_session_ticket_ext_cb && !tls_session_ticket_ext_cb(s, v16, a1, s->tls_session_ticket_ext_cb_arg) )
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
                if ( s->tlsext_status_type == -1 || v15 )
                {
                  *al = 110;
                  return 0;
                }
                s->tlsext_status_expected = 1;
              }
              break;
            case 0xFF01:
              if ( !ssl_parse_serverhello_renegotiate_ext((int)s, s, v16, a1, al) )
                return 0;
              v24 = 1;
              break;
          }
        }
        else
        {
          if ( !s->tlsext_hostname || v15 )
          {
            *al = 112;
            return 0;
          }
          v23 = 1;
        }
        v7 = v25;
        v9 = v26;
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
        ERR_put_error(a1, 0x14u, 303, 338, ".\\ssl\\t1_lib.c", 1207);
        return 0;
      }
      return 1;
    }
LABEL_35:
    if ( (unsigned __int8 *)v9 != v7 )
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
    *p = (unsigned __int16 *)v9;
    goto ri_check_0;
  }
LABEL_3:
  *al = 50;
  return 0;
}
