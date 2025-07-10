ssl_cipher_st *__cdecl ssl3_choose_cipher(ssl_st *s, stack_st_SSL_CIPHER *clnt, stack_st_SSL_CIPHER *srvr)
{
  stack_st_SSL_CIPHER *v4; // eax
  int v5; // ebx
  bool v6; // zf
  cert_st *cert; // edx
  x509_st *x509; // eax
  ssl_session_st *session; // ecx
  X509_pubkey_st *key; // eax
  asn1_string_st *public_key; // eax
  unsigned __int8 *v12; // eax
  unsigned __int8 v13; // al
  char *ptr; // eax
  int v15; // esi
  const ssl_st **v16; // eax
  ssl_session_st *v17; // ecx
  unsigned int tlsext_ecpointformatlist_length; // edx
  int v19; // eax
  unsigned __int8 *tlsext_ecpointformatlist; // ecx
  ssl_session_st *v21; // ecx
  unsigned int v22; // edx
  int v23; // eax
  unsigned __int8 *v24; // ecx
  cert_st *v25; // ecx
  ssl_session_st *v26; // eax
  char *v27; // eax
  int v28; // edi
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
  int v40; // edi
  int v41; // eax
  const ssl_st **group; // ecx
  char v43; // bl
  char v44; // dl
  ssl_session_st *v45; // ecx
  unsigned int v46; // eax
  unsigned int v47; // esi
  unsigned __int8 *v48; // ecx
  int v49; // eax
  char v51; // [esp+Ah] [ebp-1Ah]
  char v52; // [esp+Bh] [ebp-19h]
  int v53; // [esp+Ch] [ebp-18h]
  int i; // [esp+10h] [ebp-14h]
  stack_st *p_stack; // [esp+14h] [ebp-10h]
  char *data; // [esp+18h] [ebp-Ch]
  stack_st_SSL_CIPHER *v57; // [esp+1Ch] [ebp-8h]
  cert_st *c; // [esp+20h] [ebp-4h]
  int v59; // [esp+28h] [ebp+4h]

  v52 = 0;
  v51 = 0;
  c = s->cert;
  if ( ((unsigned int)Scaleform::GFx::AS2::CreateShadow & s->options) != 0 )
  {
    v4 = srvr;
    v57 = clnt;
  }
  else
  {
    v4 = clnt;
    v57 = srvr;
  }
  p_stack = &v4->stack;
  i = 0;
  if ( sk_num(&v4->stack) > 0 )
  {
    while ( 1 )
    {
      data = sk_value(p_stack, i);
      ssl_set_cert_masks(c, (const ssl_cipher_st *)data);
      v5 = *((_DWORD *)data + 4);
      v53 = *((_DWORD *)data + 3);
      if ( (v53 & 0x100) != 0 && !s->psk_server_callback )
        goto LABEL_96;
      if ( (data[32] & 2) != 0 )
      {
        if ( (c->export_mask_k & v53) != 0 )
        {
          v6 = (v5 & c->export_mask_a) == 0;
          goto LABEL_12;
        }
      }
      else if ( (c->mask_k & v53) != 0 )
      {
        v6 = (v5 & c->mask_a) == 0;
LABEL_12:
        v59 = 1;
        if ( !v6 )
          goto LABEL_14;
      }
      v59 = 0;
LABEL_14:
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
      v12 = public_key->data;
      if ( !v12 )
        goto LABEL_44;
      v13 = *v12;
      if ( v13 != 2 && v13 != 3 )
        goto LABEL_44;
      ptr = cert->pkeys[5].privatekey->pkey.ptr;
      v15 = 0;
      if ( ptr && (v16 = (const ssl_st **)*((_DWORD *)ptr + 1)) != 0 && *v16 && EVP_CIPHER_CTX_cipher(*v16) == 406 )
      {
        v17 = s->session;
        tlsext_ecpointformatlist_length = v17->tlsext_ecpointformatlist_length;
        v19 = 0;
        if ( tlsext_ecpointformatlist_length )
        {
          tlsext_ecpointformatlist = v17->tlsext_ecpointformatlist;
          while ( tlsext_ecpointformatlist[v19] != 1 )
          {
            if ( ++v19 >= tlsext_ecpointformatlist_length )
              goto LABEL_41;
          }
LABEL_40:
          v15 = 1;
        }
      }
      else if ( EVP_CIPHER_CTX_cipher(**((const ssl_st ***)s->cert->pkeys[5].privatekey->pkey.ptr + 1)) == 407 )
      {
        v21 = s->session;
        v22 = v21->tlsext_ecpointformatlist_length;
        v23 = 0;
        if ( v22 )
        {
          v24 = v21->tlsext_ecpointformatlist;
          while ( v24[v23] != 2 )
          {
            if ( ++v23 >= v22 )
              goto LABEL_41;
          }
          goto LABEL_40;
        }
      }
LABEL_41:
      if ( !v59 || (v59 = 1, !v15) )
        v59 = 0;
LABEL_44:
      if ( (v5 & 0x40) != 0 || (v5 & 0x10) != 0 )
      {
        v25 = s->cert;
        if ( v25->pkeys[5].x509 )
        {
          v26 = s->session;
          if ( v26->tlsext_ellipticcurvelist_length )
          {
            if ( v26->tlsext_ellipticcurvelist )
            {
              v27 = v25->pkeys[5].privatekey->pkey.ptr;
              v28 = 0;
              if ( !v27 )
                goto LABEL_67;
              v29 = (const ssl_st *)*((_DWORD *)v27 + 1);
              if ( !v29 )
                goto LABEL_67;
              shutdown = SSL_get_shutdown(v29);
              if ( shutdown || (v31 = (const ssl_st **)*((_DWORD *)s->cert->pkeys[5].privatekey->pkey.ptr + 1), !*v31) )
              {
                v32 = 0;
                v52 = 0;
                v33 = tls1_ec_nid2curve_id(shutdown);
                v51 = v33;
              }
              else
              {
                if ( EVP_CIPHER_CTX_cipher(*v31) == 406 )
                {
                  v32 = -1;
                  v33 = 1;
                  v52 = -1;
                  v51 = 1;
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
                    v28 = 1;
                  }
LABEL_67:
                  if ( !v59 || (v59 = 1, !v28) )
                    v59 = 0;
                  goto LABEL_70;
                }
                if ( EVP_CIPHER_CTX_cipher(**((const ssl_st ***)s->cert->pkeys[5].privatekey->pkey.ptr + 1)) == 407 )
                {
                  v32 = -1;
                  v33 = 2;
                  v52 = -1;
                  v51 = 2;
                  goto LABEL_60;
                }
                v32 = v52;
                v33 = v51;
                if ( v52 )
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
      if ( (v53 & 0x80u) == 0
        || (ecdh_tmp = s->cert->ecdh_tmp) == 0
        || (v39 = s->session, !v39->tlsext_ellipticcurvelist_length)
        || !v39->tlsext_ellipticcurvelist )
      {
        if ( !v59 )
          goto LABEL_96;
        goto LABEL_95;
      }
      v40 = 0;
      if ( ecdh_tmp->group )
      {
        v41 = SSL_get_shutdown((const ssl_st *)ecdh_tmp->group);
        if ( v41 || (group = (const ssl_st **)s->cert->ecdh_tmp->group, !*group) )
        {
          v43 = 0;
          v52 = 0;
          v44 = tls1_ec_nid2curve_id(v41);
          v51 = v44;
        }
        else
        {
          if ( EVP_CIPHER_CTX_cipher(*group) == 406 )
          {
            v43 = -1;
            v44 = 1;
            v52 = -1;
            v51 = 1;
            goto LABEL_84;
          }
          if ( EVP_CIPHER_CTX_cipher((const ssl_st *)s->cert->ecdh_tmp->group->meth) == 407 )
          {
            v43 = -1;
            v44 = 2;
            v52 = -1;
            v51 = 2;
            goto LABEL_84;
          }
          v43 = v52;
          v44 = v51;
          if ( v52 )
          {
LABEL_84:
            v45 = s->session;
            v46 = 0;
            v47 = v45->tlsext_ellipticcurvelist_length >> 1;
            if ( v47 )
            {
              v48 = v45->tlsext_ellipticcurvelist;
              while ( *v48 != v43 || v48[1] != v44 )
              {
                ++v46;
                v48 += 2;
                if ( v46 >= v47 )
                  goto LABEL_91;
              }
              v40 = 1;
            }
            goto LABEL_91;
          }
        }
        if ( !v44 )
          goto LABEL_91;
        goto LABEL_84;
      }
LABEL_91:
      if ( !v59 || !v40 )
        goto LABEL_96;
LABEL_95:
      v49 = sk_find(&v57->stack, data);
      if ( v49 >= 0 )
        return (ssl_cipher_st *)sk_value(&v57->stack, v49);
LABEL_96:
      if ( ++i >= sk_num(p_stack) )
        return 0;
    }
  }
  return 0;
}
