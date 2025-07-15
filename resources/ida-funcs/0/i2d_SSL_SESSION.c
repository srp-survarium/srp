int __cdecl i2d_SSL_SESSION(ssl_session_st *in, unsigned __int8 **pp)
{
  const ssl_cipher_st *cipher; // eax
  unsigned int id; // eax
  unsigned int sid_ctx_length; // eax
  unsigned int key_arg_length; // eax
  int time; // eax
  unsigned __int8 *tlsext_hostname; // edx
  unsigned __int8 *tlsext_tick; // eax
  unsigned __int8 *psk_identity_hint; // edx
  unsigned __int8 *psk_identity; // edx
  int v12; // edi
  int v13; // edi
  int v14; // edi
  int v15; // edi
  int v16; // edi
  x509_st *peer; // eax
  int v18; // ebx
  int v19; // edi
  int v20; // ebp
  unsigned __int8 *v21; // edi
  int ssl_version; // [esp-14h] [ebp-188h]
  int timeout; // [esp-Ch] [ebp-180h]
  int verify_result; // [esp-Ch] [ebp-180h]
  int tlsext_tick_lifetime_hint; // [esp-Ch] [ebp-180h]
  unsigned __int8 *ppa; // [esp+8h] [ebp-16Ch] BYREF
  char compress_meth; // [esp+Fh] [ebp-165h] BYREF
  char v28; // [esp+10h] [ebp-164h] BYREF
  char v29; // [esp+11h] [ebp-163h]
  char v30; // [esp+12h] [ebp-162h]
  int v31; // [esp+14h] [ebp-160h]
  int v32; // [esp+18h] [ebp-15Ch]
  int v33; // [esp+1Ch] [ebp-158h]
  unsigned __int8 **v34; // [esp+20h] [ebp-154h]
  int v35; // [esp+24h] [ebp-150h]
  int v36; // [esp+28h] [ebp-14Ch]
  int v37; // [esp+2Ch] [ebp-148h]
  int v38; // [esp+30h] [ebp-144h]
  int v39; // [esp+34h] [ebp-140h]
  int length; // [esp+38h] [ebp-13Ch]
  int v41; // [esp+3Ch] [ebp-138h]
  asn1_string_st a; // [esp+40h] [ebp-134h] BYREF
  asn1_string_st v43; // [esp+50h] [ebp-124h] BYREF
  asn1_string_st v44; // [esp+60h] [ebp-114h] BYREF
  asn1_string_st v45; // [esp+70h] [ebp-104h] BYREF
  asn1_string_st v46; // [esp+80h] [ebp-F4h] BYREF
  asn1_string_st v47; // [esp+90h] [ebp-E4h] BYREF
  asn1_string_st v48; // [esp+A0h] [ebp-D4h] BYREF
  asn1_string_st v49; // [esp+B0h] [ebp-C4h] BYREF
  asn1_string_st v50; // [esp+C0h] [ebp-B4h] BYREF
  asn1_string_st v51; // [esp+D0h] [ebp-A4h] BYREF
  asn1_string_st v52; // [esp+E0h] [ebp-94h] BYREF
  asn1_string_st v53; // [esp+F0h] [ebp-84h] BYREF
  asn1_string_st v54; // [esp+100h] [ebp-74h] BYREF
  asn1_string_st v55; // [esp+110h] [ebp-64h] BYREF
  asn1_string_st v56; // [esp+120h] [ebp-54h] BYREF
  asn1_string_st v57; // [esp+130h] [ebp-44h] BYREF
  char v58; // [esp+140h] [ebp-34h] BYREF
  char v59; // [esp+148h] [ebp-2Ch] BYREF
  char v60; // [esp+150h] [ebp-24h] BYREF
  char v61; // [esp+158h] [ebp-1Ch] BYREF
  char v62; // [esp+160h] [ebp-14h] BYREF
  char v63; // [esp+168h] [ebp-Ch] BYREF

  v34 = pp;
  length = 0;
  v33 = 0;
  v39 = 0;
  v35 = 0;
  v38 = 0;
  v37 = 0;
  v41 = 0;
  v31 = 0;
  v36 = 0;
  v32 = 0;
  if ( !in || !in->cipher && !in->cipher_id )
    return 0;
  a.length = 8;
  a.type = 2;
  a.data = (unsigned __int8 *)&v58;
  ASN1_INTEGER_set(&a, 1);
  ssl_version = in->ssl_version;
  v43.length = 8;
  v43.type = 2;
  v43.data = (unsigned __int8 *)&v63;
  ASN1_INTEGER_set(&v43, ssl_version);
  v44.data = (unsigned __int8 *)&v28;
  cipher = in->cipher;
  v44.type = 4;
  if ( cipher )
    id = cipher->id;
  else
    id = in->cipher_id;
  if ( in->ssl_version == 2 )
  {
    v28 = BYTE2(id);
    v44.length = 3;
    v29 = BYTE1(id);
    v30 = id;
  }
  else
  {
    v44.length = 2;
    v28 = BYTE1(id);
    v29 = id;
  }
  if ( in->compress_meth )
  {
    compress_meth = in->compress_meth;
    v45.length = 1;
    v45.type = 4;
    v45.data = (unsigned __int8 *)&compress_meth;
  }
  v46.length = in->master_key_length;
  v47.length = in->session_id_length;
  sid_ctx_length = in->sid_ctx_length;
  v46.data = in->master_key;
  v48.length = sid_ctx_length;
  key_arg_length = in->key_arg_length;
  v47.data = in->session_id;
  v49.length = key_arg_length;
  time = in->time;
  v48.data = in->sid_ctx;
  v46.type = 4;
  v47.type = 4;
  v48.type = 4;
  v49.type = 4;
  v49.data = in->key_arg;
  if ( time )
  {
    v50.type = 2;
    v50.length = 8;
    v50.data = (unsigned __int8 *)&v60;
    ASN1_INTEGER_set(&v50, time);
  }
  if ( in->timeout )
  {
    timeout = in->timeout;
    v51.length = 8;
    v51.type = 2;
    v51.data = (unsigned __int8 *)&v62;
    ASN1_INTEGER_set(&v51, timeout);
  }
  if ( in->verify_result )
  {
    verify_result = in->verify_result;
    v52.length = 8;
    v52.type = 2;
    v52.data = (unsigned __int8 *)&v59;
    ASN1_INTEGER_set(&v52, verify_result);
  }
  tlsext_hostname = (unsigned __int8 *)in->tlsext_hostname;
  if ( tlsext_hostname )
  {
    v53.length = strlen(in->tlsext_hostname);
    v53.type = 4;
    v53.data = tlsext_hostname;
  }
  tlsext_tick = in->tlsext_tick;
  if ( tlsext_tick )
  {
    v55.length = in->tlsext_ticklen;
    v55.type = 4;
    v55.data = tlsext_tick;
  }
  if ( in->tlsext_tick_lifetime_hint > 0 )
  {
    tlsext_tick_lifetime_hint = in->tlsext_tick_lifetime_hint;
    v54.length = 8;
    v54.type = 2;
    v54.data = (unsigned __int8 *)&v61;
    ASN1_INTEGER_set(&v54, tlsext_tick_lifetime_hint);
  }
  psk_identity_hint = (unsigned __int8 *)in->psk_identity_hint;
  if ( psk_identity_hint )
  {
    v56.length = strlen(in->psk_identity_hint);
    v56.type = 4;
    v56.data = psk_identity_hint;
  }
  psk_identity = (unsigned __int8 *)in->psk_identity;
  if ( psk_identity )
  {
    v57.length = strlen(in->psk_identity);
    v57.type = 4;
    v57.data = psk_identity;
  }
  v12 = i2d_ASN1_INTEGER(&a, 0);
  v13 = i2d_ASN1_INTEGER(&v43, 0) + v12;
  v14 = i2d_ASN1_OCTET_STRING(&v44, 0) + v13;
  v15 = i2d_ASN1_OCTET_STRING(&v47, 0) + v14;
  v16 = i2d_ASN1_OCTET_STRING(&v46, 0) + v15;
  if ( in->key_arg_length )
    v16 += i2d_ASN1_OCTET_STRING(&v49, 0);
  if ( in->time )
  {
    length = i2d_ASN1_INTEGER(&v50, 0);
    v16 += ASN1_object_size(1, length, 1);
  }
  if ( in->timeout )
  {
    v33 = i2d_ASN1_INTEGER(&v51, 0);
    v16 += ASN1_object_size(1, v33, 2);
  }
  peer = in->peer;
  if ( peer )
  {
    v39 = i2d_X509(peer, 0);
    v16 += ASN1_object_size(1, v39, 3);
  }
  v18 = i2d_ASN1_OCTET_STRING(&v48, 0);
  v19 = ASN1_object_size(1, v18, 4) + v16;
  if ( in->verify_result )
  {
    v35 = i2d_ASN1_INTEGER(&v52, 0);
    v19 += ASN1_object_size(1, v35, 5);
  }
  if ( in->tlsext_tick_lifetime_hint > 0 )
  {
    v31 = i2d_ASN1_INTEGER(&v54, 0);
    v19 += ASN1_object_size(1, v31, 9);
  }
  if ( in->tlsext_tick )
  {
    v36 = i2d_ASN1_OCTET_STRING(&v55, 0);
    v19 += ASN1_object_size(1, v36, 10);
  }
  if ( in->tlsext_hostname )
  {
    v41 = i2d_ASN1_OCTET_STRING(&v53, 0);
    v19 += ASN1_object_size(1, v41, 6);
  }
  if ( in->compress_meth )
  {
    v32 = i2d_ASN1_OCTET_STRING(&v45, 0);
    v19 += ASN1_object_size(1, v32, 11);
  }
  if ( in->psk_identity_hint )
  {
    v38 = i2d_ASN1_OCTET_STRING(&v56, 0);
    v19 += ASN1_object_size(1, v38, 7);
  }
  if ( in->psk_identity )
  {
    v37 = i2d_ASN1_OCTET_STRING(&v57, 0);
    v19 += ASN1_object_size(1, v37, 8);
  }
  v20 = ASN1_object_size(1, v19, 16);
  if ( v34 )
  {
    ppa = *v34;
    ASN1_put_object(&ppa, 1, v19, 16, 0);
    i2d_ASN1_INTEGER(&a, &ppa);
    i2d_ASN1_INTEGER(&v43, &ppa);
    i2d_ASN1_OCTET_STRING(&v44, &ppa);
    i2d_ASN1_OCTET_STRING(&v47, &ppa);
    i2d_ASN1_OCTET_STRING(&v46, &ppa);
    if ( in->key_arg_length )
    {
      v21 = ppa;
      i2d_ASN1_OCTET_STRING(&v49, &ppa);
      *v21 = *v21 & 0x20 | 0x80;
    }
    if ( in->time )
    {
      ASN1_put_object(&ppa, 1, length, 1, 128);
      i2d_ASN1_INTEGER(&v50, &ppa);
    }
    if ( in->timeout )
    {
      ASN1_put_object(&ppa, 1, v33, 2, 128);
      i2d_ASN1_INTEGER(&v51, &ppa);
    }
    if ( in->peer )
    {
      ASN1_put_object(&ppa, 1, v39, 3, 128);
      i2d_X509(in->peer, &ppa);
    }
    ASN1_put_object(&ppa, 1, v18, 4, 128);
    i2d_ASN1_OCTET_STRING(&v48, &ppa);
    if ( in->verify_result )
    {
      ASN1_put_object(&ppa, 1, v35, 5, 128);
      i2d_ASN1_INTEGER(&v52, &ppa);
    }
    if ( in->tlsext_hostname )
    {
      ASN1_put_object(&ppa, 1, v41, 6, 128);
      i2d_ASN1_OCTET_STRING(&v53, &ppa);
    }
    if ( in->psk_identity_hint )
    {
      ASN1_put_object(&ppa, 1, v38, 7, 128);
      i2d_ASN1_OCTET_STRING(&v56, &ppa);
    }
    if ( in->psk_identity )
    {
      ASN1_put_object(&ppa, 1, v37, 8, 128);
      i2d_ASN1_OCTET_STRING(&v57, &ppa);
    }
    if ( in->tlsext_tick_lifetime_hint > 0 )
    {
      ASN1_put_object(&ppa, 1, v31, 9, 128);
      i2d_ASN1_INTEGER(&v54, &ppa);
    }
    if ( in->tlsext_tick )
    {
      ASN1_put_object(&ppa, 1, v36, 10, 128);
      i2d_ASN1_OCTET_STRING(&v55, &ppa);
    }
    if ( in->compress_meth )
    {
      ASN1_put_object(&ppa, 1, v32, 11, 128);
      i2d_ASN1_OCTET_STRING(&v45, &ppa);
    }
    *v34 = ppa;
  }
  return v20;
}
