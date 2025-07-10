unsigned __int8 *__cdecl ssl_add_clienthello_tlsext(ssl_st *s, unsigned __int8 *p, unsigned __int8 *limit)
{
  unsigned __int8 *result; // eax
  ssl_st *v4; // esi
  bool v5; // zf
  unsigned __int8 *v6; // ebp
  unsigned __int8 *v7; // eax
  char *tlsext_hostname; // ebx
  unsigned __int8 v9; // cl
  unsigned int v10; // ebx
  unsigned int tlsext_ecpointformatlist_length; // edx
  unsigned int v12; // ecx
  unsigned int tlsext_ellipticcurvelist_length; // edx
  unsigned int v14; // ecx
  ssl_session_st *session; // eax
  unsigned int tlsext_ticklen; // ebx
  tls_session_ticket_ext_st *v17; // eax
  int v18; // ebx
  int v19; // edi
  char *v20; // eax
  int v21; // eax
  stack_st_X509_EXTENSION *tlsext_ocsp_exts; // eax
  int v23; // edi
  ssl_st *v24; // eax
  tls_session_ticket_ext_st *tlsext_session_ticket; // eax
  ssl_session_st *v26; // edx
  const stack_st *p_stack; // eax
  unsigned __int8 *v28; // ebx
  char *v29; // eax
  __int16 v30; // ax
  ssl_st *v31; // eax
  unsigned __int8 *v32; // esi
  unsigned __int8 *v33; // ecx
  __int16 v34; // ax
  unsigned __int8 *v35; // [esp-14h] [ebp-1Ch]
  unsigned __int8 *tlsext_ecpointformatlist; // [esp-14h] [ebp-1Ch]
  unsigned __int8 *tlsext_ellipticcurvelist; // [esp-14h] [ebp-1Ch]
  unsigned int v38; // [esp-10h] [ebp-18h]
  unsigned int v39; // [esp-10h] [ebp-18h]
  unsigned __int8 *dst; // [esp+4h] [ebp-4h] BYREF

  result = p;
  v4 = s;
  v5 = s->client_version == 768;
  dst = p;
  if ( v5 && !s->s3->send_connection_binding )
    return result;
  v6 = limit;
  v7 = p + 2;
  dst = p + 2;
  if ( p + 2 >= limit )
    return 0;
  tlsext_hostname = s->tlsext_hostname;
  if ( tlsext_hostname )
  {
    if ( limit - v7 - 9 < 0 )
      return 0;
    v10 = strlen(tlsext_hostname);
    if ( v10 > limit - v7 - 9 )
      return 0;
    *v7 = v9;
    dst[1] = v9;
    dst += 2;
    *dst = (unsigned __int16)(v10 + 5) >> 8;
    dst[1] = v10 + 5;
    dst += 2;
    *dst = (unsigned __int16)(v10 + 3) >> 8;
    dst[1] = v10 + 3;
    dst += 2;
    *dst++ = 0;
    *dst = BYTE1(v10);
    dst[1] = v10;
    v35 = (unsigned __int8 *)v4->tlsext_hostname;
    dst += 2;
    memcpy(dst, v35, v10);
    v7 = &dst[v10];
    dst += v10;
  }
  if ( v4->new_session )
  {
    if ( !ssl_add_clienthello_renegotiate_ext(v4, 0, (int *)&s, 0) )
    {
      ERR_put_error(0x14u, 277, 68, ".\\ssl\\t1_lib.c", 326);
      return 0;
    }
    if ( v6 - (unsigned __int8 *)s - (int)p - 4 < 0 )
      return 0;
    *dst = -1;
    dst[1] = 1;
    dst += 2;
    *dst = BYTE1(s);
    dst[1] = (unsigned __int8)s;
    dst += 2;
    if ( !ssl_add_clienthello_renegotiate_ext(v4, dst, (int *)&s, (int)s) )
    {
      ERR_put_error(0x14u, 277, 68, ".\\ssl\\t1_lib.c", 337);
      return 0;
    }
    v7 = &dst[(_DWORD)s];
    dst = &dst[(_DWORD)s];
  }
  if ( v4->tlsext_ecpointformatlist && v4->version != 65279 )
  {
    if ( v6 - v7 - 5 < 0 )
      return 0;
    tlsext_ecpointformatlist_length = v4->tlsext_ecpointformatlist_length;
    if ( tlsext_ecpointformatlist_length > v6 - v7 - 5 )
      return 0;
    if ( tlsext_ecpointformatlist_length > 0xFF )
    {
      ERR_put_error(0x14u, 277, 68, ".\\ssl\\t1_lib.c", 355);
      return 0;
    }
    *v7 = 0;
    dst[1] = 11;
    v12 = v4->tlsext_ecpointformatlist_length;
    dst += 2;
    *dst = (unsigned __int16)(v12 + 1) >> 8;
    dst[1] = LOBYTE(v4->tlsext_ecpointformatlist_length) + 1;
    LOBYTE(v12) = v4->tlsext_ecpointformatlist_length;
    dst += 2;
    *dst = v12;
    v38 = v4->tlsext_ecpointformatlist_length;
    tlsext_ecpointformatlist = v4->tlsext_ecpointformatlist;
    memcpy(++dst, tlsext_ecpointformatlist, v38);
    v7 = &dst[v4->tlsext_ecpointformatlist_length];
    dst = v7;
  }
  if ( v4->tlsext_ellipticcurvelist && v4->version != 65279 )
  {
    if ( v6 - v7 - 6 < 0 )
      return 0;
    tlsext_ellipticcurvelist_length = v4->tlsext_ellipticcurvelist_length;
    if ( tlsext_ellipticcurvelist_length > v6 - v7 - 6 )
      return 0;
    if ( tlsext_ellipticcurvelist_length > 0xFFFC )
    {
      ERR_put_error(0x14u, 277, 68, ".\\ssl\\t1_lib.c", 375);
      return 0;
    }
    *v7 = 0;
    dst[1] = 10;
    v14 = v4->tlsext_ellipticcurvelist_length;
    dst += 2;
    *dst = (unsigned __int16)(v14 + 2) >> 8;
    dst[1] = LOBYTE(v4->tlsext_ellipticcurvelist_length) + 2;
    LOBYTE(v14) = BYTE1(v4->tlsext_ellipticcurvelist_length);
    dst += 2;
    *dst = v14;
    dst[1] = v4->tlsext_ellipticcurvelist_length;
    v39 = v4->tlsext_ellipticcurvelist_length;
    tlsext_ellipticcurvelist = v4->tlsext_ellipticcurvelist;
    dst += 2;
    memcpy(dst, tlsext_ellipticcurvelist, v39);
    dst += v4->tlsext_ellipticcurvelist_length;
  }
  if ( (SSL_ctrl(v4, 32, 0, 0) & 0x4000) != 0 )
    goto skip_ext;
  if ( !v4->new_session )
  {
    session = v4->session;
    if ( session )
    {
      if ( session->tlsext_tick )
      {
        tlsext_ticklen = session->tlsext_ticklen;
        goto LABEL_36;
      }
    }
  }
  if ( v4->session )
  {
    tlsext_session_ticket = v4->tlsext_session_ticket;
    if ( tlsext_session_ticket )
    {
      if ( tlsext_session_ticket->data )
      {
        tlsext_ticklen = tlsext_session_ticket->length;
        v4->session->tlsext_tick = (unsigned __int8 *)CRYPTO_malloc(tlsext_ticklen, ".\\ssl\\t1_lib.c", 402);
        v26 = v4->session;
        if ( !v26->tlsext_tick )
          return 0;
        memcpy(v26->tlsext_tick, (unsigned __int8 *)v4->tlsext_session_ticket->data, tlsext_ticklen);
        v4->session->tlsext_ticklen = tlsext_ticklen;
LABEL_36:
        if ( tlsext_ticklen )
        {
LABEL_39:
          if ( &v6[-tlsext_ticklen] - dst - 4 < 0 )
            return 0;
          *dst = 0;
          dst[1] = 35;
          dst += 2;
          *dst = BYTE1(tlsext_ticklen);
          dst[1] = tlsext_ticklen;
          dst += 2;
          if ( tlsext_ticklen )
          {
            memcpy(dst, v4->session->tlsext_tick, tlsext_ticklen);
            dst += tlsext_ticklen;
          }
          goto skip_ext;
        }
        goto LABEL_37;
      }
    }
  }
  tlsext_ticklen = 0;
LABEL_37:
  v17 = v4->tlsext_session_ticket;
  if ( !v17 || v17->data )
    goto LABEL_39;
skip_ext:
  if ( v4->tlsext_status_type == 1 && v4->version != 65279 )
  {
    v18 = 0;
    v19 = 0;
    if ( sk_num(&v4->tlsext_ocsp_ids->stack) > 0 )
    {
      do
      {
        v20 = sk_value(&v4->tlsext_ocsp_ids->stack, v19);
        v21 = i2d_OCSP_RESPID((ocsp_responder_id_st *)v20, 0);
        if ( v21 <= 0 )
          return 0;
        v18 += v21 + 2;
      }
      while ( ++v19 < sk_num(&v4->tlsext_ocsp_ids->stack) );
    }
    tlsext_ocsp_exts = v4->tlsext_ocsp_exts;
    v23 = 0;
    if ( tlsext_ocsp_exts )
    {
      v24 = (ssl_st *)i2d_X509_EXTENSIONS(tlsext_ocsp_exts, 0);
      s = v24;
      if ( (int)v24 < 0 )
        return 0;
    }
    else
    {
      s = 0;
      v24 = 0;
    }
    if ( v6 - (unsigned __int8 *)v24 - v18 - (int)dst - 7 < 0 )
      return 0;
    *dst = 0;
    dst[1] = 5;
    dst += 2;
    if ( (int)v24 + v18 > 65520 )
      return 0;
    *dst = (unsigned __int16)((_WORD)v24 + v18 + 5) >> 8;
    dst[1] = (_BYTE)v24 + v18 + 5;
    dst += 2;
    *dst++ = 1;
    *dst = BYTE1(v18);
    dst[1] = v18;
    p_stack = &v4->tlsext_ocsp_ids->stack;
    dst += 2;
    if ( sk_num(p_stack) > 0 )
    {
      do
      {
        v28 = dst;
        v29 = sk_value(&v4->tlsext_ocsp_ids->stack, v23);
        dst += 2;
        v30 = i2d_OCSP_RESPID((ocsp_responder_id_st *)v29, &dst);
        *v28 = HIBYTE(v30);
        v28[1] = v30;
        ++v23;
      }
      while ( v23 < sk_num(&v4->tlsext_ocsp_ids->stack) );
    }
    v31 = s;
    *dst = BYTE1(s);
    dst[1] = (unsigned __int8)v31;
    dst += 2;
    if ( (int)v31 > 0 )
      i2d_X509_EXTENSIONS(v4->tlsext_ocsp_exts, &dst);
  }
  v32 = dst;
  v33 = p;
  v34 = (_WORD)dst - (_WORD)p - 2;
  if ( dst - p == 2 )
    return p;
  p[1] = v34;
  *v33 = HIBYTE(v34);
  return v32;
}
