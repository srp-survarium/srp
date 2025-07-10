unsigned __int8 *__cdecl ssl_add_serverhello_tlsext(ssl_st *s, unsigned __int8 *p, unsigned __int8 *limit)
{
  unsigned __int8 *result; // eax
  bool v4; // zf
  unsigned __int8 *v5; // ebp
  int v6; // eax
  _BYTE *v7; // ebp
  unsigned __int8 *v8; // ebp
  unsigned int tlsext_ecpointformatlist_length; // ecx
  unsigned __int8 *v10; // ebp
  _BYTE *v11; // ebp
  _BYTE *v12; // ebp
  int id; // eax
  _BYTE *v14; // ecx
  int v15; // eax
  int v16; // edx
  int len; // [esp+8h] [ebp-30h] BYREF
  unsigned __int8 *v18; // [esp+Ch] [ebp-2Ch]
  _BYTE v19[36]; // [esp+10h] [ebp-28h] BYREF

  result = p;
  v4 = s->version == 768;
  v18 = p;
  if ( v4 && !s->s3->send_connection_binding )
    return result;
  v5 = p + 2;
  if ( p + 2 >= limit )
    return 0;
  if ( s->hit || s->servername_done != 1 || !s->session->tlsext_hostname )
    goto LABEL_9;
  if ( limit - v5 - 4 < 0 )
    return 0;
  *v5 = 0;
  p[3] = 0;
  p[4] = 0;
  p[5] = 0;
  v5 = p + 6;
LABEL_9:
  if ( s->s3->send_connection_binding )
  {
    if ( !ssl_add_serverhello_renegotiate_ext(s, 0, &len, 0) )
    {
      ERR_put_error(0x14u, 278, 68, ".\\ssl\\t1_lib.c", 530);
      return 0;
    }
    v6 = len;
    if ( limit - v18 - len - 4 < 0 )
      return 0;
    *v5 = -1;
    v5[1] = 1;
    v7 = v5 + 2;
    v7[1] = v6;
    *v7 = BYTE1(v6);
    v8 = v7 + 2;
    if ( !ssl_add_serverhello_renegotiate_ext(s, v8, &len, v6) )
    {
      ERR_put_error(0x14u, 278, 68, ".\\ssl\\t1_lib.c", 541);
      return 0;
    }
    v5 = &v8[len];
  }
  if ( s->tlsext_ecpointformatlist && s->version != 65279 )
  {
    if ( limit - v5 - 5 < 0 )
      return 0;
    tlsext_ecpointformatlist_length = s->tlsext_ecpointformatlist_length;
    if ( tlsext_ecpointformatlist_length > limit - v5 - 5 )
      return 0;
    if ( tlsext_ecpointformatlist_length > 0xFF )
    {
      ERR_put_error(0x14u, 278, 68, ".\\ssl\\t1_lib.c", 559);
      return 0;
    }
    *v5 = 0;
    v5[1] = 11;
    v10 = v5 + 2;
    *v10 = (unsigned __int16)(LOWORD(s->tlsext_ecpointformatlist_length) + 1) >> 8;
    v10[1] = LOBYTE(s->tlsext_ecpointformatlist_length) + 1;
    v10 += 2;
    *v10++ = s->tlsext_ecpointformatlist_length;
    memcpy(v10, s->tlsext_ecpointformatlist, s->tlsext_ecpointformatlist_length);
    v5 = &v10[s->tlsext_ecpointformatlist_length];
  }
  if ( s->tlsext_ticket_expected && (SSL_ctrl(s, 32, 0, 0) & 0x4000) == 0 )
  {
    if ( limit - v5 - 4 < 0 )
      return 0;
    *v5 = 0;
    v5[1] = 35;
    v11 = v5 + 2;
    *v11 = 0;
    v11[1] = 0;
    v5 = v11 + 2;
  }
  if ( s->tlsext_status_expected )
  {
    if ( limit - v5 - 4 < 0 )
      return 0;
    *v5 = 0;
    v5[1] = 5;
    v12 = v5 + 2;
    *v12 = 0;
    v12[1] = 0;
    v5 = v12 + 2;
  }
  id = (unsigned __int16)s->s3->tmp.new_cipher->id;
  if ( (id == 128 || id == 129) && SSL_ctrl(s, 32, 0, 0) < 0 )
  {
    v19[2] = 0;
    v19[0] = -3;
    v19[1] = -24;
    v19[3] = 32;
    v19[4] = 48;
    v19[5] = 30;
    v19[6] = 48;
    v19[7] = 8;
    v19[8] = 6;
    v19[9] = 6;
    v19[10] = 42;
    v19[11] = -123;
    v19[12] = 3;
    v19[13] = 2;
    v19[14] = 2;
    v19[15] = 9;
    v19[16] = 48;
    v19[17] = 8;
    v19[18] = 6;
    v19[19] = 6;
    v19[20] = 42;
    v19[21] = -123;
    v19[22] = 3;
    v19[23] = 2;
    v19[24] = 2;
    v19[25] = 22;
    v19[26] = 48;
    v19[27] = 8;
    v19[28] = 6;
    v19[29] = 6;
    v19[30] = 42;
    v19[31] = -123;
    v19[32] = 3;
    v19[33] = 2;
    v19[34] = 2;
    v19[35] = 23;
    if ( limit - v5 < 36 )
      return 0;
    qmemcpy(v5, v19, 0x24u);
    v5 += 36;
  }
  v14 = v18;
  v15 = v5 - v18 - 2;
  if ( v5 - v18 == 2 )
    return v18;
  v16 = v15 >> 8;
  v18[1] = v15;
  result = v5;
  *v14 = v16;
  return result;
}
