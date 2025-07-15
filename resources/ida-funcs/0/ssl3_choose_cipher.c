ssl_cipher_st *__cdecl ssl3_choose_cipher(ssl_st *s, stack_st_SSL_CIPHER *clnt, stack_st_SSL_CIPHER *srvr)
{
  stack_st_SSL_CIPHER *v4; // eax
  int v5; // ebx
  bool v6; // zf
  int v7; // edi
  cert_st *cert; // edx
  x509_st *x509; // eax
  ssl_session_st *session; // ecx
  X509_pubkey_st *key; // eax
  asn1_string_st *public_key; // eax
  unsigned __int8 *data; // eax
  unsigned __int8 v14; // al
  char *ptr; // eax
  int v16; // esi
  const ssl_st **v17; // eax
  ssl_session_st *v18; // ecx
  unsigned int tlsext_ecpointformatlist_length; // edx
  int v20; // eax
  unsigned __int8 *tlsext_ecpointformatlist; // ecx
  ssl_session_st *v22; // ecx
  unsigned int v23; // edx
  int v24; // eax
  unsigned __int8 *v25; // ecx
  cert_st *v26; // ecx
  ssl_session_st *v27; // eax
  char *v28; // eax
  const ssl_st *v29; // eax
  int shutdown; // eax
  const ssl_st **v31; // ecx
  char v32; // bl
  char v33; // dl
  ssl_session_st *v34; // ecx
  unsigned int v35; // eax
  unsigned int v36; // esi
  unsigned __int8 *tlsext_ellipticcurvelist; // ecx
  ec_key_st *ecdh_tmp; // ecx
  ssl_session_st *v39; // eax
  int v40; // eax
  const ssl_st **group; // ecx
  char v42; // bl
  char v43; // dl
  ssl_session_st *v44; // ecx
  unsigned int v45; // eax
  unsigned int v46; // esi
  unsigned __int8 *v47; // ecx
  int v48; // eax
  char v50; // [esp+Ah] [ebp-1Ah]
  char v51; // [esp+Bh] [ebp-19h]
  int v52; // [esp+Ch] [ebp-18h]
  int v53; // [esp+10h] [ebp-14h]
  stack_st *p_stack; // [esp+14h] [ebp-10h]
  char *v55; // [esp+18h] [ebp-Ch]
  stack_st_SSL_CIPHER *v56; // [esp+1Ch] [ebp-8h]
  cert_st *c; // [esp+20h] [ebp-4h]
  int v58; // [esp+28h] [ebp+4h]

  v51 = 0;
  v50 = 0;
  c = s->cert;
  if ( ((unsigned int)&loc_400000 & s->options) != 0 )
  {
    v4 = srvr;
    v56 = clnt;
  }
  else
  {
    v4 = clnt;
    v56 = srvr;
  }
  p_stack = &v4->stack;
  v53 = 0;
  if ( sk_num(&v4->stack) > 0 )
  {
    while ( 1 )
    {
      v55 = sk_value(p_stack, v53);
      ssl_set_cert_masks(c, (const ssl_cipher_st *)v55);
      v5 = *((_DWORD *)v55 + 4);
      v52 = *((_DWORD *)v55 + 3);
      if ( (v52 & 0x100) != 0 && !s->psk_server_callback )
        goto LABEL_96;
      if ( (v55[32] & 2) != 0 )
      {
        if ( (c->export_mask_k & v52) != 0 )
        {
          v6 = (v5 & c->export_mask_a) == 0;
          goto LABEL_12;
        }
      }
      else if ( (c->mask_k & v52) != 0 )
      {
        v6 = (v5 & c->mask_a) == 0;
LABEL_12:
        v58 = 1;
        if ( !v6 )
          goto LABEL_14;
      }
      v58 = 0;
LABEL_14:
      v7 = *((_DWORD *)v55 + 4) & 0x40;
      if ( (v5 & 0x40) == 0 && (v5 & 0x10) == 0 )
        goto LABEL_44;
      cert = s->cert;
      x509 = cert->pkeys[5].x509;
      if ( !x509 )
        goto LABEL_44;
      session = s->session;
      if ( !session->tlsext_ecpointformatlist_length )
        goto LABEL_44;
      if ( !session->tlsext_ecpointformatlist )
        goto LABEL_44;
      if ( !x509->cert_info )
        goto LABEL_44;
      key = x509->cert_info->key;
      if ( !key )
        goto LABEL_44;
      public_key = key->public_key;
      if ( !public_key )
        goto LABEL_44;
      data = public_key->data;
      if ( !data )
        goto LABEL_44;
      v14 = *data;
      if ( v14 != 2 && v14 != 3 )
        goto LABEL_44;
      ptr = cert->pkeys[5].privatekey->pkey.ptr;
      v16 = 0;
      if ( ptr && (v17 = (const ssl_st **)*((_DWORD *)ptr + 1)) != 0 && *v17 && EVP_CIPHER_CTX_cipher(*v17) == 406 )
      {
        v18 = s->session;
        tlsext_ecpointformatlist_length = v18->tlsext_ecpointformatlist_length;
        v20 = 0;
        if ( tlsext_ecpointformatlist_length )
        {
          tlsext_ecpointformatlist = v18->tlsext_ecpointformatlist;
          while ( tlsext_ecpointformatlist[v20] != 1 )
          {
            if ( ++v20 >= tlsext_ecpointformatlist_length )
              goto LABEL_41;
          }
LABEL_40:
          v16 = 1;
        }
      }
      else if ( EVP_CIPHER_CTX_cipher(**((const ssl_st ***)s->cert->pkeys[5].privatekey->pkey.ptr + 1)) == 407 )
      {
        v22 = s->session;
        v23 = v22->tlsext_ecpointformatlist_length;
        v24 = 0;
        if ( v23 )
        {
          v25 = v22->tlsext_ecpointformatlist;
          while ( v25[v24] != 2 )
          {
            if ( ++v24 >= v23 )
              goto LABEL_41;
          }
          goto LABEL_40;
        }
      }
LABEL_41:
      if ( !v58 || (v58 = 1, !v16) )
        v58 = 0;
LABEL_44:
      if ( (v5 & 0x40) != 0 || (v5 & 0x10) != 0 )
      {
        v26 = s->cert;
        if ( v26->pkeys[5].x509 )
        {
          v27 = s->session;
          if ( v27->tlsext_ellipticcurvelist_length )
          {
            if ( v27->tlsext_ellipticcurvelist )
            {
              v28 = v26->pkeys[5].privatekey->pkey.ptr;
              v7 = 0;
              if ( !v28 )
                goto LABEL_67;
              v29 = (const ssl_st *)*((_DWORD *)v28 + 1);
              if ( !v29 )
                goto LABEL_67;
              shutdown = SSL_get_shutdown(v29);
              if ( shutdown || (v31 = (const ssl_st **)*((_DWORD *)s->cert->pkeys[5].privatekey->pkey.ptr + 1), !*v31) )
              {
                v32 = 0;
                v51 = 0;
                v33 = tls1_ec_nid2curve_id(shutdown);
                v50 = v33;
              }
              else
              {
                if ( EVP_CIPHER_CTX_cipher(*v31) == 406 )
                {
                  v32 = -1;
                  v33 = 1;
                  v51 = -1;
                  v50 = 1;
LABEL_60:
                  v34 = s->session;
                  v35 = 0;
                  v36 = v34->tlsext_ellipticcurvelist_length >> 1;
                  if ( v36 )
                  {
                    tlsext_ellipticcurvelist = v34->tlsext_ellipticcurvelist;
                    while ( *tlsext_ellipticcurvelist != v32 || tlsext_ellipticcurvelist[1] != v33 )
                    {
                      ++v35;
                      tlsext_ellipticcurvelist += 2;
                      if ( v35 >= v36 )
                        goto LABEL_67;
                    }
                    v7 = 1;
                  }
LABEL_67:
                  if ( !v58 || (v58 = 1, !v7) )
                    v58 = 0;
                  goto LABEL_70;
                }
                if ( EVP_CIPHER_CTX_cipher(**((const ssl_st ***)s->cert->pkeys[5].privatekey->pkey.ptr + 1)) == 407 )
                {
                  v32 = -1;
                  v33 = 2;
                  v51 = -1;
                  v50 = 2;
                  goto LABEL_60;
                }
                v32 = v51;
                v33 = v50;
                if ( v51 )
                  goto LABEL_60;
              }
              if ( v33 )
                goto LABEL_60;
              goto LABEL_67;
            }
          }
        }
      }
LABEL_70:
      if ( (v52 & 0x80u) == 0
        || (ecdh_tmp = s->cert->ecdh_tmp) == 0
        || (v39 = s->session, !v39->tlsext_ellipticcurvelist_length)
        || !v39->tlsext_ellipticcurvelist )
      {
        if ( !v58 )
          goto LABEL_96;
        goto LABEL_95;
      }
      v7 = 0;
      if ( ecdh_tmp->group )
      {
        v40 = SSL_get_shutdown((const ssl_st *)ecdh_tmp->group);
        if ( v40 || (group = (const ssl_st **)s->cert->ecdh_tmp->group, !*group) )
        {
          v42 = 0;
          v51 = 0;
          v43 = tls1_ec_nid2curve_id(v40);
          v50 = v43;
        }
        else
        {
          if ( EVP_CIPHER_CTX_cipher(*group) == 406 )
          {
            v42 = -1;
            v43 = 1;
            v51 = -1;
            v50 = 1;
            goto LABEL_84;
          }
          if ( EVP_CIPHER_CTX_cipher((const ssl_st *)s->cert->ecdh_tmp->group->meth) == 407 )
          {
            v42 = -1;
            v43 = 2;
            v51 = -1;
            v50 = 2;
            goto LABEL_84;
          }
          v42 = v51;
          v43 = v50;
          if ( v51 )
          {
LABEL_84:
            v44 = s->session;
            v45 = 0;
            v46 = v44->tlsext_ellipticcurvelist_length >> 1;
            if ( v46 )
            {
              v47 = v44->tlsext_ellipticcurvelist;
              while ( *v47 != v42 || v47[1] != v43 )
              {
                ++v45;
                v47 += 2;
                if ( v45 >= v46 )
                  goto LABEL_91;
              }
              v7 = 1;
            }
            goto LABEL_91;
          }
        }
        if ( !v43 )
          goto LABEL_91;
        goto LABEL_84;
      }
LABEL_91:
      if ( !v58 || !v7 )
        goto LABEL_96;
LABEL_95:
      v48 = sk_find(v7, &v56->stack, v55);
      if ( v48 >= 0 )
        return (ssl_cipher_st *)sk_value(&v56->stack, v48);
LABEL_96:
      if ( ++v53 >= sk_num(p_stack) )
        return 0;
    }
  }
  return 0;
}
