int __usercall ssl3_get_record@<eax>(ssl_st *s@<esi>, int a2@<ebx>)
{
  ssl3_state_st *s3; // edi
  int v3; // ebp
  int result; // eax
  int v5; // ebx
  unsigned __int8 *packet; // eax
  __int16 v7; // cx
  int v8; // ebx
  unsigned int v9; // ecx
  unsigned int length; // eax
  unsigned __int8 *v11; // eax
  unsigned __int8 *v12; // eax
  int v13; // eax
  ui_string_st *object; // eax
  unsigned int v15; // eax
  unsigned __int8 *data; // ecx
  unsigned int v17; // eax
  unsigned __int8 *v18; // ecx
  unsigned int v19; // eax
  _BYTE *v20; // ebp
  int v21; // edi
  __int16 v22; // [esp-10h] [ebp-70h]
  int v23; // [esp-8h] [ebp-68h]
  int v24; // [esp+8h] [ebp-58h]
  int v25; // [esp+Ch] [ebp-54h]
  int v26; // [esp+10h] [ebp-50h]
  unsigned __int8 *v27; // [esp+14h] [ebp-4Ch]
  ssl_session_st *session; // [esp+18h] [ebp-48h]
  _BYTE v29[64]; // [esp+1Ch] [ebp-44h] BYREF

  s3 = s->s3;
  v26 = 0;
  v25 = 0;
  v27 = 0;
  session = s->session;
  if ( (s->options & 0x20) == 0 )
  {
    v24 = 0;
    v3 = 0;
    goto again_3;
  }
  v3 = 0x4000;
  v24 = 0x4000;
  if ( !s3->init_extra )
  {
    ERR_put_error(a2, 0x14u, 143, 68, ".\\ssl\\s3_pkt.c", 309);
    return -1;
  }
  while ( 1 )
  {
again_3:
    v5 = 241;
    if ( s->rstate == 241 && s->packet_length >= 5 )
      goto LABEL_12;
    result = ssl3_read_n(s, 5, s->s3->rbuf.len, 0);
    if ( result <= 0 )
      return result;
    packet = s->packet;
    s->rstate = 241;
    s3->rrec.type = *packet;
    v7 = *++packet;
    v8 = (unsigned __int16)(packet[1] | (unsigned __int16)(v7 << 8));
    v9 = packet[3] | (packet[2] << 8);
    s3->rrec.length = v9;
    if ( !s->first_packet && (__int16)v8 != s->version )
      break;
    v5 = v8 & 0xFF00;
    if ( (_WORD)v5 != 768 )
    {
      ERR_put_error(v5, 0x14u, 143, 267, ".\\ssl\\s3_pkt.c", 350);
      return -1;
    }
    if ( v9 > s->s3->rbuf.len - 5 )
    {
      v23 = 357;
      v22 = 198;
LABEL_60:
      v21 = 22;
      ERR_put_error(v5, 0x14u, 143, v22, ".\\ssl\\s3_pkt.c", v23);
      goto LABEL_61;
    }
LABEL_12:
    length = s3->rrec.length;
    if ( length > s->packet_length - 5 )
    {
      result = ssl3_read_n(s, length, length, 1);
      if ( result <= 0 )
        return result;
    }
    v11 = s->packet;
    s->rstate = 240;
    v12 = v11 + 5;
    s3->rrec.input = v12;
    if ( s3->rrec.length > v3 + 17728 )
    {
      v23 = 397;
      v22 = 150;
      goto LABEL_60;
    }
    s3->rrec.data = v12;
    v13 = s->method->ssl3_enc->enc(s, 0);
    if ( v13 <= 0 )
    {
      if ( !v13 )
        return -1;
      v25 = 1;
    }
    if ( session && s->enc_read_ctx && X509_EXTENSION_get_object((ui_string_st *)s->read_hash) )
    {
      if ( !v26 )
      {
        object = X509_EXTENSION_get_object((ui_string_st *)s->read_hash);
        v5 = EVP_MD_size(v5, (const env_md_st *)object);
        if ( v5 < 0 )
          OpenSSLDie((int)s3, (int)s, v5, ".\\ssl\\s3_pkt.c", 434, "mac_size >= 0");
        v15 = s3->rrec.length;
        if ( v15 > v5 + v3 + 17408 )
          v25 = 1;
        if ( v15 < v5 )
        {
          v25 = 1;
          s3->rrec.length = 0;
        }
        else
        {
          data = s3->rrec.data;
          v17 = v15 - v5;
          s3->rrec.length = v17;
          v27 = &data[v17];
        }
        if ( s->method->ssl3_enc->mac(s, v29, 0) < 0 )
          goto LABEL_56;
        v18 = v27;
        if ( !v27 )
          goto LABEL_56;
        v19 = v5;
        v20 = v29;
        if ( (unsigned int)v5 >= 4 )
        {
          while ( *(_DWORD *)v20 == *(_DWORD *)v18 )
          {
            v19 -= 4;
            v18 += 4;
            v20 += 4;
            if ( v19 < 4 )
              goto LABEL_35;
          }
LABEL_56:
          v21 = 20;
          ERR_put_error(v5, 0x14u, 143, 281, ".\\ssl\\s3_pkt.c", 479);
LABEL_61:
          ssl3_send_alert(s, 2, v21);
          return -1;
        }
LABEL_35:
        if ( v19 && (*v18 != *v20 || v19 > 1 && (v18[1] != v20[1] || v19 > 2 && v18[2] != v20[2])) )
          goto LABEL_56;
        v3 = v24;
      }
    }
    else
    {
      v26 = 1;
    }
    v5 = 0;
    if ( v25 )
      goto LABEL_56;
    if ( s->expand )
    {
      if ( s3->rrec.length > v3 + 17408 )
      {
        v23 = 489;
        v22 = 140;
        goto LABEL_60;
      }
      if ( !ssl3_do_uncompress(s) )
      {
        v21 = 30;
        ERR_put_error(0, 0x14u, 143, 107, ".\\ssl\\s3_pkt.c", 495);
        goto LABEL_61;
      }
    }
    if ( s3->rrec.length > v3 + 0x4000 )
    {
      v23 = 503;
      v22 = 146;
      goto LABEL_60;
    }
    s3->rrec.off = 0;
    s->packet_length = 0;
    if ( s3->rrec.length )
      return 1;
  }
  ERR_put_error(v8, 0x14u, 143, 267, ".\\ssl\\s3_pkt.c", 339);
  if ( (((unsigned __int16)v8 ^ s->version) & 0xFF00) == 0 )
    s->version = (unsigned __int16)v8;
  ssl3_send_alert(s, 2, 70);
  return -1;
}
