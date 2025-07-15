ssl_session_st *__usercall d2i_SSL_SESSION@<eax>(
        int a1@<edi>,
        ssl_session_st **a,
        const unsigned __int8 **pp,
        int length)
{
  int v4; // ebx
  ssl_session_st *v5; // ebp
  const unsigned __int8 *v6; // eax
  int v7; // esi
  unsigned int v8; // eax
  unsigned int v9; // eax
  unsigned int v10; // eax
  int object; // eax
  int v12; // eax
  const unsigned __int8 *slen; // eax
  const unsigned __int8 *v14; // ecx
  int v15; // eax
  int v16; // eax
  int v17; // eax
  int v18; // eax
  int v19; // eax
  int v20; // eax
  int v21; // eax
  int v22; // eax
  asn1_string_st *aa; // [esp+10h] [ebp-60h] BYREF
  asn1_string_st *p_count; // [esp+14h] [ebp-5Ch] BYREF
  const unsigned __int8 *v26; // [esp+18h] [ebp-58h] BYREF
  int v27; // [esp+1Ch] [ebp-54h] BYREF
  int v28; // [esp+20h] [ebp-50h] BYREF
  unsigned int count; // [esp+24h] [ebp-4Ch] BYREF
  unsigned __int8 *src; // [esp+2Ch] [ebp-44h]
  int v31; // [esp+34h] [ebp-3Ch] BYREF
  void *str; // [esp+3Ch] [ebp-34h]
  asn1_const_ctx_st p; // [esp+44h] [ebp-2Ch] BYREF

  p.q = *pp;
  v4 = 0;
  p.pp = pp;
  p.error = 58;
  if ( a && *a )
  {
    v5 = *a;
  }
  else
  {
    v5 = SSL_SESSION_new(0);
    if ( !v5 )
    {
      p.line = 364;
      goto err_247;
    }
  }
  v6 = *pp;
  aa = (asn1_string_st *)&v31;
  p_count = (asn1_string_st *)&count;
  p.p = v6;
  if ( length )
    p.max = &v6[length];
  else
    p.max = 0;
  if ( !asn1_GetSequence(&p, (const unsigned __int8 **)&length) )
  {
    p.line = 370;
    goto err_247;
  }
  p.q = p.p;
  str = 0;
  v31 = 0;
  if ( !d2i_ASN1_INTEGER(&aa, (unsigned __int8 **)&p, (const unsigned __int8 *)p.slen) )
  {
    p.line = 373;
    goto err_247;
  }
  p.slen += p.q - p.p;
  if ( str )
  {
    CRYPTO_free(str);
    str = 0;
    v31 = 0;
  }
  p.q = p.p;
  if ( !d2i_ASN1_INTEGER(&aa, (unsigned __int8 **)&p, (const unsigned __int8 *)p.slen) )
  {
    p.line = 377;
    goto err_247;
  }
  p.slen += p.q - p.p;
  v7 = ASN1_INTEGER_get(aa);
  v5->ssl_version = v7;
  if ( str )
  {
    CRYPTO_free(str);
    str = 0;
    v31 = 0;
  }
  p.q = p.p;
  src = 0;
  count = 0;
  if ( !d2i_ASN1_OCTET_STRING(&p_count, (unsigned __int8 **)&p, (const unsigned __int8 *)p.slen) )
  {
    p.line = 383;
    goto err_247;
  }
  a1 = 3;
  p.slen += p.q - p.p;
  if ( v7 == 2 )
  {
    if ( count != 3 )
    {
      p.error = 137;
      goto err_247;
    }
    v8 = src[2] | ((src[1] | ((*src | 0x200) << 8)) << 8);
  }
  else
  {
    v7 &= 0xFFFFFF00;
    if ( v7 < 768 )
    {
      p.error = 254;
err_247:
      ERR_put_error(v4, 0xDu, 103, p.error, ".\\ssl\\ssl_asn1.c", p.line);
      asn1_add_error(*pp, p.q - *pp);
      if ( v5 && (!a || *a != v5) )
        SSL_SESSION_free(a1, v4, v5);
      return 0;
    }
    if ( count != 2 )
    {
      p.error = 137;
      goto err_247;
    }
    v8 = src[1] | (((unsigned int)&loc_30000 | *src) << 8);
  }
  v5->cipher_id = v8;
  v5->cipher = 0;
  p.q = p.p;
  if ( !d2i_ASN1_OCTET_STRING(&p_count, (unsigned __int8 **)&p, (const unsigned __int8 *)p.slen) )
  {
    p.line = 416;
    goto err_247;
  }
  v9 = count;
  p.slen += p.q - p.p;
  if ( (int)count > 32 )
  {
    v9 = 32;
    count = 32;
  }
  v5->session_id_length = v9;
  if ( (int)count > 32 )
    OpenSSLDie(3, v7, 0, ".\\ssl\\ssl_asn1.c", 428, "os.length <= (int)sizeof(ret->session_id)");
  memcpy((int)v5->session_id, (const __m128i *)src, count);
  p.q = p.p;
  if ( !d2i_ASN1_OCTET_STRING(&p_count, (unsigned __int8 **)&p, (const unsigned __int8 *)p.slen) )
  {
    p.line = 431;
    goto err_247;
  }
  p.slen += p.q - p.p;
  if ( (int)count <= 48 )
    v5->master_key_length = count;
  else
    v5->master_key_length = 48;
  memcpy((int)v5->master_key, (const __m128i *)src, v5->master_key_length);
  v10 = 0;
  count = 0;
  if ( !p.slen )
    goto LABEL_46;
  LOBYTE(v4) = *p.p;
  if ( (*p.p & 0xDF) != 0x80 )
    goto LABEL_46;
  *p.p = v4 & 0x20 | 4;
  p.q = p.p;
  if ( !d2i_ASN1_OCTET_STRING(&p_count, (unsigned __int8 **)&p, (const unsigned __int8 *)p.slen) )
  {
    p.line = 458;
    *p.q = v4;
    goto err_247;
  }
  p.slen += p.q - p.p;
  *p.q = v4;
  v10 = count;
  if ( (int)count > 8 )
    v5->key_arg_length = 8;
  else
LABEL_46:
    v5->key_arg_length = v10;
  memcpy((int)v5->key_arg, (const __m128i *)src, v5->key_arg_length);
  if ( src )
    CRYPTO_free(src);
  v31 = 0;
  if ( p.slen && *p.p == 0xA1 )
  {
    p.q = p.p;
    object = ASN1_get_object(
               (const unsigned __int8 **)v4,
               &p.p,
               (unsigned int *)&v26,
               &v28,
               &v27,
               (const unsigned __int8 *)p.slen);
    v4 = object;
    if ( (object & 0x80u) != 0 )
    {
      p.error = 59;
      p.line = 467;
      goto err_247;
    }
    if ( object == 33 )
      v26 = &p.q[p.slen - (unsigned int)p.p - 2];
    if ( !d2i_ASN1_INTEGER(&aa, (unsigned __int8 **)&p, v26) )
    {
      p.line = 467;
      goto err_247;
    }
    if ( v4 == 33 )
    {
      v26 = &p.q[p.slen - (unsigned int)p.p];
      if ( !ASN1_const_check_infinite_end(&p.p, (int)v26) )
      {
        p.error = 63;
        p.line = 467;
        goto err_247;
      }
    }
    p.slen += p.q - p.p;
  }
  if ( str )
  {
    v5->time = ASN1_INTEGER_get(aa);
    CRYPTO_free(str);
    str = 0;
  }
  else
  {
    v5->time = _time64(0);
  }
  v31 = 0;
  if ( p.slen && *p.p == 0xA2 )
  {
    p.q = p.p;
    v12 = ASN1_get_object(
            (const unsigned __int8 **)v4,
            &p.p,
            (unsigned int *)&v26,
            &v27,
            &v28,
            (const unsigned __int8 *)p.slen);
    v4 = v12;
    if ( (v12 & 0x80u) != 0 )
    {
      p.error = 59;
      p.line = 477;
      goto err_247;
    }
    if ( v12 == 33 )
      v26 = &p.q[p.slen - (unsigned int)p.p - 2];
    if ( !d2i_ASN1_INTEGER(&aa, (unsigned __int8 **)&p, v26) )
    {
      p.line = 477;
      goto err_247;
    }
    if ( v4 == 33 )
    {
      v26 = &p.q[p.slen - (unsigned int)p.p];
      if ( !ASN1_const_check_infinite_end(&p.p, (int)v26) )
      {
        p.error = 63;
        p.line = 477;
        goto err_247;
      }
    }
    p.slen += p.q - p.p;
  }
  if ( str )
  {
    v5->timeout = ASN1_INTEGER_get(aa);
    CRYPTO_free(str);
    str = 0;
    v31 = 0;
  }
  else
  {
    v5->timeout = 3;
  }
  a1 = 0;
  if ( v5->peer )
  {
    X509_free(v5->peer);
    v5->peer = 0;
  }
  slen = (const unsigned __int8 *)p.slen;
  v14 = p.p;
  if ( p.slen && *p.p == 0xA3 )
  {
    p.q = p.p;
    v15 = ASN1_get_object(
            (const unsigned __int8 **)v4,
            &p.p,
            (unsigned int *)&v26,
            &v27,
            &v28,
            (const unsigned __int8 *)p.slen);
    v4 = v15;
    if ( (v15 & 0x80u) != 0 )
    {
      p.error = 59;
      p.line = 491;
      goto err_247;
    }
    if ( v15 == 33 )
      v26 = &p.q[p.slen - (unsigned int)p.p - 2];
    if ( !d2i_X509(&v5->peer, (unsigned __int8 **)&p, v26) )
    {
      p.line = 491;
      goto err_247;
    }
    if ( v4 == 33 )
    {
      v26 = &p.q[p.slen - (unsigned int)p.p];
      if ( !ASN1_const_check_infinite_end(&p.p, (int)v26) )
      {
        p.error = 63;
        p.line = 491;
        goto err_247;
      }
    }
    v14 = p.p;
    slen = (const unsigned __int8 *)(p.q - p.p + p.slen);
    p.slen = (int)slen;
  }
  count = 0;
  src = 0;
  if ( !slen || *v14 != 0xA4 )
    goto LABEL_108;
  p.q = v14;
  v16 = ASN1_get_object((const unsigned __int8 **)v4, &p.p, (unsigned int *)&v26, &v27, &v28, slen);
  v4 = v16;
  if ( (v16 & 0x80u) != 0 )
  {
    p.error = 59;
    p.line = 495;
    goto err_247;
  }
  if ( v16 == 33 )
    v26 = &p.q[p.slen - (unsigned int)p.p - 2];
  if ( !d2i_ASN1_OCTET_STRING(&p_count, (unsigned __int8 **)&p, v26) )
  {
    p.line = 495;
    goto err_247;
  }
  if ( v4 == 33 )
  {
    v26 = &p.q[p.slen - (unsigned int)p.p];
    if ( !ASN1_const_check_infinite_end(&p.p, (int)v26) )
    {
      p.error = 63;
      p.line = 495;
      goto err_247;
    }
  }
  p.slen += p.q - p.p;
  if ( src )
  {
    if ( (int)count > 32 )
    {
      p.error = 271;
      goto err_247;
    }
    v5->sid_ctx_length = count;
    memcpy((int)v5->sid_ctx, (const __m128i *)src, count);
    CRYPTO_free(src);
    src = 0;
    count = 0;
  }
  else
  {
LABEL_108:
    v5->sid_ctx_length = 0;
  }
  v31 = 0;
  if ( p.slen && *p.p == 0xA5 )
  {
    p.q = p.p;
    v17 = ASN1_get_object(
            (const unsigned __int8 **)v4,
            &p.p,
            (unsigned int *)&v26,
            &v27,
            &v28,
            (const unsigned __int8 *)p.slen);
    v4 = v17;
    if ( (v17 & 0x80u) != 0 )
    {
      p.error = 59;
      p.line = 515;
      goto err_247;
    }
    if ( v17 == 33 )
      v26 = &p.q[p.slen - (unsigned int)p.p - 2];
    if ( !d2i_ASN1_INTEGER(&aa, (unsigned __int8 **)&p, v26) )
    {
      p.line = 515;
      goto err_247;
    }
    if ( v4 == 33 )
    {
      v26 = &p.q[p.slen - (unsigned int)p.p];
      if ( !ASN1_const_check_infinite_end(&p.p, (int)v26) )
      {
        p.error = 63;
        p.line = 515;
        goto err_247;
      }
    }
    p.slen += p.q - p.p;
  }
  if ( str )
  {
    v5->verify_result = ASN1_INTEGER_get(aa);
    CRYPTO_free(str);
    str = 0;
    v31 = 0;
  }
  else
  {
    v5->verify_result = 0;
  }
  count = 0;
  src = 0;
  if ( !p.slen || *p.p != 0xA6 )
    goto LABEL_137;
  p.q = p.p;
  v18 = ASN1_get_object(
          (const unsigned __int8 **)v4,
          &p.p,
          (unsigned int *)&v26,
          &v27,
          &v28,
          (const unsigned __int8 *)p.slen);
  v4 = v18;
  if ( (v18 & 0x80u) != 0 )
  {
    p.error = 59;
    p.line = 527;
    goto err_247;
  }
  if ( v18 == 33 )
    v26 = &p.q[p.slen - (unsigned int)p.p - 2];
  if ( !d2i_ASN1_OCTET_STRING(&p_count, (unsigned __int8 **)&p, v26) )
  {
    p.line = 527;
    goto err_247;
  }
  if ( v4 == 33 )
  {
    v26 = &p.q[p.slen - (unsigned int)p.p];
    if ( !ASN1_const_check_infinite_end(&p.p, (int)v26) )
    {
      p.error = 63;
      p.line = 527;
      goto err_247;
    }
  }
  p.slen += p.q - p.p;
  if ( src )
  {
    v5->tlsext_hostname = BUF_strndup((char *)src, count);
    CRYPTO_free(src);
  }
  else
  {
LABEL_137:
    v5->tlsext_hostname = 0;
  }
  count = 0;
  src = 0;
  if ( !p.slen || *p.p != 0xA7 )
    goto LABEL_151;
  p.q = p.p;
  v19 = ASN1_get_object(
          (const unsigned __int8 **)v4,
          &p.p,
          (unsigned int *)&v26,
          &v27,
          &v28,
          (const unsigned __int8 *)p.slen);
  v4 = v19;
  if ( (v19 & 0x80u) != 0 )
  {
    p.error = 59;
    p.line = 542;
    goto err_247;
  }
  if ( v19 == 33 )
    v26 = &p.q[p.slen - (unsigned int)p.p - 2];
  if ( !d2i_ASN1_OCTET_STRING(&p_count, (unsigned __int8 **)&p, v26) )
  {
    p.line = 542;
    goto err_247;
  }
  if ( v4 == 33 )
  {
    v26 = &p.q[p.slen - (unsigned int)p.p];
    if ( !ASN1_const_check_infinite_end(&p.p, (int)v26) )
    {
      p.error = 63;
      p.line = 542;
      goto err_247;
    }
  }
  p.slen += p.q - p.p;
  if ( src )
  {
    v5->psk_identity_hint = BUF_strndup((char *)src, count);
    CRYPTO_free(src);
    src = 0;
    count = 0;
  }
  else
  {
LABEL_151:
    v5->psk_identity_hint = 0;
  }
  v31 = 0;
  if ( p.slen && *p.p == 0xA9 )
  {
    p.q = p.p;
    v20 = ASN1_get_object(
            (const unsigned __int8 **)v4,
            &p.p,
            (unsigned int *)&v26,
            &v27,
            &v28,
            (const unsigned __int8 *)p.slen);
    v4 = v20;
    if ( (v20 & 0x80u) != 0 )
    {
      p.error = 59;
      p.line = 556;
      goto err_247;
    }
    if ( v20 == 33 )
      v26 = &p.q[p.slen - (unsigned int)p.p - 2];
    if ( !d2i_ASN1_INTEGER(&aa, (unsigned __int8 **)&p, v26) )
    {
      p.line = 556;
      goto err_247;
    }
    if ( v4 == 33 )
    {
      v26 = &p.q[p.slen - (unsigned int)p.p];
      if ( !ASN1_const_check_infinite_end(&p.p, (int)v26) )
      {
        p.error = 63;
        p.line = 556;
        goto err_247;
      }
    }
    p.slen += p.q - p.p;
  }
  if ( str )
  {
    v5->tlsext_tick_lifetime_hint = ASN1_INTEGER_get(aa);
    CRYPTO_free(str);
    str = 0;
    v31 = 0;
  }
  else if ( v5->tlsext_ticklen && v5->session_id_length )
  {
    v5->tlsext_tick_lifetime_hint = -1;
  }
  else
  {
    v5->tlsext_tick_lifetime_hint = 0;
  }
  count = 0;
  src = 0;
  if ( !p.slen || *p.p != 0xAA )
    goto LABEL_183;
  p.q = p.p;
  v21 = ASN1_get_object(
          (const unsigned __int8 **)v4,
          &p.p,
          (unsigned int *)&v26,
          &v27,
          &v28,
          (const unsigned __int8 *)p.slen);
  v4 = v21;
  if ( (v21 & 0x80u) != 0 )
  {
    p.error = 59;
    p.line = 568;
    goto err_247;
  }
  if ( v21 == 33 )
    v26 = &p.q[p.slen - (unsigned int)p.p - 2];
  if ( !d2i_ASN1_OCTET_STRING(&p_count, (unsigned __int8 **)&p, v26) )
  {
    p.line = 568;
    goto err_247;
  }
  if ( v4 == 33 )
  {
    v26 = &p.q[p.slen - (unsigned int)p.p];
    if ( !ASN1_const_check_infinite_end(&p.p, (int)v26) )
    {
      p.error = 63;
      p.line = 568;
      goto err_247;
    }
  }
  p.slen += p.q - p.p;
  if ( src )
  {
    v5->tlsext_tick = src;
    v5->tlsext_ticklen = count;
  }
  else
  {
LABEL_183:
    v5->tlsext_tick = 0;
  }
  count = 0;
  src = 0;
  if ( p.slen && *p.p == 0xAB )
  {
    p.q = p.p;
    v22 = ASN1_get_object(
            (const unsigned __int8 **)v4,
            &p.p,
            (unsigned int *)&v26,
            &v27,
            &v28,
            (const unsigned __int8 *)p.slen);
    v4 = v22;
    if ( (v22 & 0x80u) != 0 )
    {
      p.error = 59;
      p.line = 582;
      goto err_247;
    }
    if ( v22 == 33 )
      v26 = &p.q[p.slen - (unsigned int)p.p - 2];
    if ( !d2i_ASN1_OCTET_STRING(&p_count, (unsigned __int8 **)&p, v26) )
    {
      p.line = 582;
      goto err_247;
    }
    if ( v4 == 33 )
    {
      v26 = &p.q[p.slen - (unsigned int)p.p];
      if ( !ASN1_const_check_infinite_end(&p.p, (int)v26) )
      {
        p.error = 63;
        p.line = 582;
        goto err_247;
      }
    }
    p.slen += p.q - p.p;
    if ( src )
    {
      v5->compress_meth = *src;
      CRYPTO_free(src);
      src = 0;
    }
  }
  if ( !asn1_const_Finish(&p) )
  {
    p.line = 591;
    goto err_247;
  }
  *pp = p.p;
  if ( a )
    *a = v5;
  return v5;
}
