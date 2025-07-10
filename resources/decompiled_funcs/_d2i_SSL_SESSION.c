ssl_session_st *__usercall d2i_SSL_SESSION@<eax>(
        unsigned int a1@<edi>,
        ssl_session_st **a,
        const unsigned __int8 **pp,
        int length)
{
  ssl_session_st *v4; // ebp
  const unsigned __int8 *v5; // eax
  signed int v6; // esi
  int v7; // eax
  unsigned int v8; // eax
  unsigned int v9; // eax
  unsigned __int8 v10; // bl
  int object; // eax
  int v12; // ebx
  int v13; // eax
  int v14; // ebx
  unsigned __int8 *slen; // eax
  const unsigned __int8 *p; // ecx
  int v17; // eax
  int v18; // ebx
  int v19; // eax
  int v20; // ebx
  int v21; // eax
  int v22; // ebx
  int v23; // eax
  int v24; // ebx
  int v25; // eax
  int v26; // ebx
  int v27; // eax
  int v28; // ebx
  int v29; // eax
  int v30; // ebx
  int v31; // eax
  int v32; // ebx
  asn1_string_st *aa; // [esp+10h] [ebp-60h] BYREF
  asn1_string_st *p_count; // [esp+14h] [ebp-5Ch] BYREF
  int plength; // [esp+18h] [ebp-58h] BYREF
  int pclass; // [esp+1Ch] [ebp-54h] BYREF
  int ptag; // [esp+20h] [ebp-50h] BYREF
  unsigned int count; // [esp+24h] [ebp-4Ch] BYREF
  unsigned __int8 *src; // [esp+2Ch] [ebp-44h]
  int v41; // [esp+34h] [ebp-3Ch] BYREF
  void *str; // [esp+3Ch] [ebp-34h]
  asn1_const_ctx_st c; // [esp+44h] [ebp-2Ch] BYREF

  c.q = *pp;
  c.pp = pp;
  c.error = 58;
  if ( a && *a )
  {
    v4 = *a;
  }
  else
  {
    v4 = SSL_SESSION_new();
    if ( !v4 )
    {
      c.line = 364;
      goto err_245;
    }
  }
  v5 = *pp;
  aa = (asn1_string_st *)&v41;
  p_count = (asn1_string_st *)&count;
  c.p = v5;
  if ( length )
    c.max = &v5[length];
  else
    c.max = 0;
  if ( !asn1_GetSequence(&c, (unsigned __int8 **)&length) )
  {
    c.line = 370;
    goto err_245;
  }
  c.q = c.p;
  str = 0;
  v41 = 0;
  if ( !d2i_ASN1_INTEGER(&aa, &c.p, c.slen) )
  {
    c.line = 373;
    goto err_245;
  }
  c.slen += c.q - c.p;
  if ( str )
  {
    CRYPTO_free(str);
    str = 0;
    v41 = 0;
  }
  c.q = c.p;
  if ( !d2i_ASN1_INTEGER(&aa, &c.p, c.slen) )
  {
    c.line = 377;
    goto err_245;
  }
  c.slen += c.q - c.p;
  v6 = ASN1_INTEGER_get(aa);
  v4->ssl_version = v6;
  if ( str )
  {
    CRYPTO_free(str);
    str = 0;
    v41 = 0;
  }
  c.q = c.p;
  src = 0;
  count = 0;
  if ( !d2i_ASN1_OCTET_STRING(&p_count, &c.p, c.slen) )
  {
    c.line = 383;
    goto err_245;
  }
  a1 = 3;
  c.slen += c.q - c.p;
  if ( v6 == 2 )
  {
    if ( count != 3 )
    {
      c.error = 137;
      goto err_245;
    }
    v7 = src[2] | ((src[1] | ((*src | 0x200) << 8)) << 8);
  }
  else
  {
    v6 &= 0xFFFFFF00;
    if ( v6 < 768 )
    {
      c.error = 254;
err_245:
      ERR_put_error(0xDu, 103, c.error, ".\\ssl\\ssl_asn1.c", c.line);
      asn1_add_error(*pp, c.q - *pp);
      if ( v4 && (!a || *a != v4) )
        SSL_SESSION_free(a1, v4);
      return 0;
    }
    if ( count != 2 )
    {
      c.error = 137;
      goto err_245;
    }
    v7 = src[1] | ((*src | 0x30000) << 8);
  }
  v4->cipher_id = v7;
  v4->cipher = 0;
  c.q = c.p;
  if ( !d2i_ASN1_OCTET_STRING(&p_count, &c.p, c.slen) )
  {
    c.line = 416;
    goto err_245;
  }
  v8 = count;
  c.slen += c.q - c.p;
  if ( (int)count > 32 )
  {
    v8 = 32;
    count = 32;
  }
  v4->session_id_length = v8;
  if ( (int)count > 32 )
    OpenSSLDie(3u, v6, ".\\ssl\\ssl_asn1.c", 428, "os.length <= (int)sizeof(ret->session_id)");
  memcpy(v4->session_id, src, count);
  c.q = c.p;
  if ( !d2i_ASN1_OCTET_STRING(&p_count, &c.p, c.slen) )
  {
    c.line = 431;
    goto err_245;
  }
  c.slen += c.q - c.p;
  if ( (int)count <= 48 )
    v4->master_key_length = count;
  else
    v4->master_key_length = 48;
  memcpy(v4->master_key, src, v4->master_key_length);
  v9 = 0;
  count = 0;
  if ( !c.slen )
    goto LABEL_46;
  v10 = *c.p;
  if ( (*c.p & 0xDF) != 0x80 )
    goto LABEL_46;
  *c.p = v10 & 0x20 | 4;
  c.q = c.p;
  if ( !d2i_ASN1_OCTET_STRING(&p_count, &c.p, c.slen) )
  {
    c.line = 458;
    *c.q = v10;
    goto err_245;
  }
  c.slen += c.q - c.p;
  *c.q = v10;
  v9 = count;
  if ( (int)count > 8 )
    v4->key_arg_length = 8;
  else
LABEL_46:
    v4->key_arg_length = v9;
  memcpy(v4->key_arg, src, v4->key_arg_length);
  if ( src )
    CRYPTO_free(src);
  v41 = 0;
  if ( c.slen && *c.p == 0xA1 )
  {
    c.q = c.p;
    object = ASN1_get_object(&c.p, &plength, &ptag, &pclass, (unsigned __int8 *)c.slen);
    v12 = object;
    if ( (object & 0x80u) != 0 )
    {
      c.error = 59;
      c.line = 467;
      goto err_245;
    }
    if ( object == 33 )
      plength = (int)&c.q[c.slen - (unsigned int)c.p - 2];
    if ( !d2i_ASN1_INTEGER(&aa, &c.p, plength) )
    {
      c.line = 467;
      goto err_245;
    }
    if ( v12 == 33 )
    {
      plength = (int)&c.q[c.slen - (unsigned int)c.p];
      if ( !ASN1_const_check_infinite_end(&c.p, plength) )
      {
        c.error = 63;
        c.line = 467;
        goto err_245;
      }
    }
    c.slen += c.q - c.p;
  }
  if ( str )
  {
    v4->time = ASN1_INTEGER_get(aa);
    CRYPTO_free(str);
    str = 0;
  }
  else
  {
    v4->time = _time64(0);
  }
  v41 = 0;
  if ( c.slen && *c.p == 0xA2 )
  {
    c.q = c.p;
    v13 = ASN1_get_object(&c.p, &plength, &pclass, &ptag, (unsigned __int8 *)c.slen);
    v14 = v13;
    if ( (v13 & 0x80u) != 0 )
    {
      c.error = 59;
      c.line = 477;
      goto err_245;
    }
    if ( v13 == 33 )
      plength = (int)&c.q[c.slen - (unsigned int)c.p - 2];
    if ( !d2i_ASN1_INTEGER(&aa, &c.p, plength) )
    {
      c.line = 477;
      goto err_245;
    }
    if ( v14 == 33 )
    {
      plength = (int)&c.q[c.slen - (unsigned int)c.p];
      if ( !ASN1_const_check_infinite_end(&c.p, plength) )
      {
        c.error = 63;
        c.line = 477;
        goto err_245;
      }
    }
    c.slen += c.q - c.p;
  }
  if ( str )
  {
    v4->timeout = ASN1_INTEGER_get(aa);
    CRYPTO_free(str);
    str = 0;
    v41 = 0;
  }
  else
  {
    v4->timeout = 3;
  }
  a1 = 0;
  if ( v4->peer )
  {
    X509_free(v4->peer);
    v4->peer = 0;
  }
  slen = (unsigned __int8 *)c.slen;
  p = c.p;
  if ( c.slen && *c.p == 0xA3 )
  {
    c.q = c.p;
    v17 = ASN1_get_object(&c.p, &plength, &pclass, &ptag, (unsigned __int8 *)c.slen);
    v18 = v17;
    if ( (v17 & 0x80u) != 0 )
    {
      c.error = 59;
      c.line = 491;
      goto err_245;
    }
    if ( v17 == 33 )
      plength = (int)&c.q[c.slen - (unsigned int)c.p - 2];
    if ( !d2i_X509(&v4->peer, &c.p, plength) )
    {
      c.line = 491;
      goto err_245;
    }
    if ( v18 == 33 )
    {
      plength = (int)&c.q[c.slen - (unsigned int)c.p];
      if ( !ASN1_const_check_infinite_end(&c.p, plength) )
      {
        c.error = 63;
        c.line = 491;
        goto err_245;
      }
    }
    p = c.p;
    slen = (unsigned __int8 *)(c.q - c.p + c.slen);
    c.slen = (int)slen;
  }
  count = 0;
  src = 0;
  if ( !slen || *p != 0xA4 )
    goto LABEL_108;
  c.q = p;
  v19 = ASN1_get_object(&c.p, &plength, &pclass, &ptag, slen);
  v20 = v19;
  if ( (v19 & 0x80u) != 0 )
  {
    c.error = 59;
    c.line = 495;
    goto err_245;
  }
  if ( v19 == 33 )
    plength = (int)&c.q[c.slen - (unsigned int)c.p - 2];
  if ( !d2i_ASN1_OCTET_STRING(&p_count, &c.p, plength) )
  {
    c.line = 495;
    goto err_245;
  }
  if ( v20 == 33 )
  {
    plength = (int)&c.q[c.slen - (unsigned int)c.p];
    if ( !ASN1_const_check_infinite_end(&c.p, plength) )
    {
      c.error = 63;
      c.line = 495;
      goto err_245;
    }
  }
  c.slen += c.q - c.p;
  if ( src )
  {
    if ( (int)count > 32 )
    {
      c.error = 271;
      goto err_245;
    }
    v4->sid_ctx_length = count;
    memcpy(v4->sid_ctx, src, count);
    CRYPTO_free(src);
    src = 0;
    count = 0;
  }
  else
  {
LABEL_108:
    v4->sid_ctx_length = 0;
  }
  v41 = 0;
  if ( c.slen && *c.p == 0xA5 )
  {
    c.q = c.p;
    v21 = ASN1_get_object(&c.p, &plength, &pclass, &ptag, (unsigned __int8 *)c.slen);
    v22 = v21;
    if ( (v21 & 0x80u) != 0 )
    {
      c.error = 59;
      c.line = 515;
      goto err_245;
    }
    if ( v21 == 33 )
      plength = (int)&c.q[c.slen - (unsigned int)c.p - 2];
    if ( !d2i_ASN1_INTEGER(&aa, &c.p, plength) )
    {
      c.line = 515;
      goto err_245;
    }
    if ( v22 == 33 )
    {
      plength = (int)&c.q[c.slen - (unsigned int)c.p];
      if ( !ASN1_const_check_infinite_end(&c.p, plength) )
      {
        c.error = 63;
        c.line = 515;
        goto err_245;
      }
    }
    c.slen += c.q - c.p;
  }
  if ( str )
  {
    v4->verify_result = ASN1_INTEGER_get(aa);
    CRYPTO_free(str);
    str = 0;
    v41 = 0;
  }
  else
  {
    v4->verify_result = 0;
  }
  count = 0;
  src = 0;
  if ( !c.slen || *c.p != 0xA6 )
    goto LABEL_137;
  c.q = c.p;
  v23 = ASN1_get_object(&c.p, &plength, &pclass, &ptag, (unsigned __int8 *)c.slen);
  v24 = v23;
  if ( (v23 & 0x80u) != 0 )
  {
    c.error = 59;
    c.line = 527;
    goto err_245;
  }
  if ( v23 == 33 )
    plength = (int)&c.q[c.slen - (unsigned int)c.p - 2];
  if ( !d2i_ASN1_OCTET_STRING(&p_count, &c.p, plength) )
  {
    c.line = 527;
    goto err_245;
  }
  if ( v24 == 33 )
  {
    plength = (int)&c.q[c.slen - (unsigned int)c.p];
    if ( !ASN1_const_check_infinite_end(&c.p, plength) )
    {
      c.error = 63;
      c.line = 527;
      goto err_245;
    }
  }
  c.slen += c.q - c.p;
  if ( src )
  {
    v4->tlsext_hostname = BUF_strndup((const char *)src, count);
    CRYPTO_free(src);
  }
  else
  {
LABEL_137:
    v4->tlsext_hostname = 0;
  }
  count = 0;
  src = 0;
  if ( !c.slen || *c.p != 0xA7 )
    goto LABEL_151;
  c.q = c.p;
  v25 = ASN1_get_object(&c.p, &plength, &pclass, &ptag, (unsigned __int8 *)c.slen);
  v26 = v25;
  if ( (v25 & 0x80u) != 0 )
  {
    c.error = 59;
    c.line = 542;
    goto err_245;
  }
  if ( v25 == 33 )
    plength = (int)&c.q[c.slen - (unsigned int)c.p - 2];
  if ( !d2i_ASN1_OCTET_STRING(&p_count, &c.p, plength) )
  {
    c.line = 542;
    goto err_245;
  }
  if ( v26 == 33 )
  {
    plength = (int)&c.q[c.slen - (unsigned int)c.p];
    if ( !ASN1_const_check_infinite_end(&c.p, plength) )
    {
      c.error = 63;
      c.line = 542;
      goto err_245;
    }
  }
  c.slen += c.q - c.p;
  if ( src )
  {
    v4->psk_identity_hint = BUF_strndup((const char *)src, count);
    CRYPTO_free(src);
    src = 0;
    count = 0;
  }
  else
  {
LABEL_151:
    v4->psk_identity_hint = 0;
  }
  v41 = 0;
  if ( c.slen && *c.p == 0xA9 )
  {
    c.q = c.p;
    v27 = ASN1_get_object(&c.p, &plength, &pclass, &ptag, (unsigned __int8 *)c.slen);
    v28 = v27;
    if ( (v27 & 0x80u) != 0 )
    {
      c.error = 59;
      c.line = 556;
      goto err_245;
    }
    if ( v27 == 33 )
      plength = (int)&c.q[c.slen - (unsigned int)c.p - 2];
    if ( !d2i_ASN1_INTEGER(&aa, &c.p, plength) )
    {
      c.line = 556;
      goto err_245;
    }
    if ( v28 == 33 )
    {
      plength = (int)&c.q[c.slen - (unsigned int)c.p];
      if ( !ASN1_const_check_infinite_end(&c.p, plength) )
      {
        c.error = 63;
        c.line = 556;
        goto err_245;
      }
    }
    c.slen += c.q - c.p;
  }
  if ( str )
  {
    v4->tlsext_tick_lifetime_hint = ASN1_INTEGER_get(aa);
    CRYPTO_free(str);
    str = 0;
    v41 = 0;
  }
  else if ( v4->tlsext_ticklen && v4->session_id_length )
  {
    v4->tlsext_tick_lifetime_hint = -1;
  }
  else
  {
    v4->tlsext_tick_lifetime_hint = 0;
  }
  count = 0;
  src = 0;
  if ( !c.slen || *c.p != 0xAA )
    goto LABEL_183;
  c.q = c.p;
  v29 = ASN1_get_object(&c.p, &plength, &pclass, &ptag, (unsigned __int8 *)c.slen);
  v30 = v29;
  if ( (v29 & 0x80u) != 0 )
  {
    c.error = 59;
    c.line = 568;
    goto err_245;
  }
  if ( v29 == 33 )
    plength = (int)&c.q[c.slen - (unsigned int)c.p - 2];
  if ( !d2i_ASN1_OCTET_STRING(&p_count, &c.p, plength) )
  {
    c.line = 568;
    goto err_245;
  }
  if ( v30 == 33 )
  {
    plength = (int)&c.q[c.slen - (unsigned int)c.p];
    if ( !ASN1_const_check_infinite_end(&c.p, plength) )
    {
      c.error = 63;
      c.line = 568;
      goto err_245;
    }
  }
  c.slen += c.q - c.p;
  if ( src )
  {
    v4->tlsext_tick = src;
    v4->tlsext_ticklen = count;
  }
  else
  {
LABEL_183:
    v4->tlsext_tick = 0;
  }
  count = 0;
  src = 0;
  if ( c.slen && *c.p == 0xAB )
  {
    c.q = c.p;
    v31 = ASN1_get_object(&c.p, &plength, &pclass, &ptag, (unsigned __int8 *)c.slen);
    v32 = v31;
    if ( (v31 & 0x80u) != 0 )
    {
      c.error = 59;
      c.line = 582;
      goto err_245;
    }
    if ( v31 == 33 )
      plength = (int)&c.q[c.slen - (unsigned int)c.p - 2];
    if ( !d2i_ASN1_OCTET_STRING(&p_count, &c.p, plength) )
    {
      c.line = 582;
      goto err_245;
    }
    if ( v32 == 33 )
    {
      plength = (int)&c.q[c.slen - (unsigned int)c.p];
      if ( !ASN1_const_check_infinite_end(&c.p, plength) )
      {
        c.error = 63;
        c.line = 582;
        goto err_245;
      }
    }
    c.slen += c.q - c.p;
    if ( src )
    {
      v4->compress_meth = *src;
      CRYPTO_free(src);
      src = 0;
    }
  }
  if ( !asn1_const_Finish(&c) )
  {
    c.line = 591;
    goto err_245;
  }
  *pp = c.p;
  if ( a )
    *a = v4;
  return v4;
}
