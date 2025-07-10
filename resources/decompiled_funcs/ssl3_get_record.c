int __usercall ssl3_get_record@<eax>(ssl_st *s@<esi>)
{
  ssl3_state_st *s3; // edi
  int v2; // ebp
  int result; // eax
  unsigned __int8 *packet; // eax
  __int16 v5; // cx
  unsigned __int16 v6; // bx
  unsigned int v7; // ecx
  unsigned int length; // eax
  unsigned __int8 *v9; // eax
  unsigned __int8 *v10; // eax
  int v11; // eax
  ui_string_st *object; // eax
  int v13; // ebx
  unsigned int v14; // eax
  unsigned __int8 *data; // ecx
  unsigned int v16; // eax
  unsigned __int8 *v17; // ecx
  unsigned int v18; // eax
  _BYTE *v19; // ebp
  int v20; // edi
  __int16 v21; // [esp-10h] [ebp-70h]
  int v22; // [esp-8h] [ebp-68h]
  int v23; // [esp+8h] [ebp-58h]
  int v24; // [esp+Ch] [ebp-54h]
  int v25; // [esp+10h] [ebp-50h]
  unsigned __int8 *v26; // [esp+14h] [ebp-4Ch]
  ssl_session_st *session; // [esp+18h] [ebp-48h]
  _BYTE v28[64]; // [esp+1Ch] [ebp-44h] BYREF

  s3 = s->s3;
  v25 = 0;
  v24 = 0;
  v26 = 0;
  session = s->session;
  if ( (s->options & 0x20) == 0 )
  {
    v23 = 0;
    v2 = 0;
    goto again_3;
  }
  v2 = 0x4000;
  v23 = 0x4000;
  if ( !s3->init_extra )
  {
    ERR_put_error(0x14u, 143, 68, ".\\ssl\\s3_pkt.c", 309);
    return -1;
  }
  while ( 1 )
  {
again_3:
    if ( s->rstate == 241 && s->packet_length >= 5 )
      goto LABEL_12;
    result = ssl3_read_n(s, 5, s->s3->rbuf.len, 0);
    if ( result <= 0 )
      return result;
    packet = s->packet;
    s->rstate = 241;
    s3->rrec.type = *packet;
    v5 = *++packet;
    v6 = packet[1] | (unsigned __int16)(v5 << 8);
    v7 = packet[3] | (packet[2] << 8);
    s3->rrec.length = v7;
    if ( !s->first_packet && (__int16)v6 != s->version )
      break;
    if ( (v6 & 0xFF00) != 0x300 )
    {
      ERR_put_error(0x14u, 143, 267, ".\\ssl\\s3_pkt.c", 350);
      return -1;
    }
    if ( v7 > s->s3->rbuf.len - 5 )
    {
      v22 = 357;
      v21 = 198;
LABEL_60:
      v20 = 22;
      ERR_put_error(0x14u, 143, v21, ".\\ssl\\s3_pkt.c", v22);
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
    v9 = s->packet;
    s->rstate = 240;
    v10 = v9 + 5;
    s3->rrec.input = v10;
    if ( s3->rrec.length > v2 + 17728 )
    {
      v22 = 397;
      v21 = 150;
      goto LABEL_60;
    }
    s3->rrec.data = v10;
    v11 = s->method->ssl3_enc->enc(s, 0);
    if ( v11 <= 0 )
    {
      if ( !v11 )
        return -1;
      v24 = 1;
    }
    if ( session && s->enc_read_ctx && X509_EXTENSION_get_object((ui_string_st *)s->read_hash) )
    {
      if ( !v25 )
      {
        object = X509_EXTENSION_get_object((ui_string_st *)s->read_hash);
        v13 = EVP_MD_size((const env_md_st *)object);
        if ( v13 < 0 )
          OpenSSLDie((unsigned int)s3, (unsigned int)s, ".\\ssl\\s3_pkt.c", 434, "mac_size >= 0");
        v14 = s3->rrec.length;
        if ( v14 > v13 + v2 + 17408 )
          v24 = 1;
        if ( v14 < v13 )
        {
          v24 = 1;
          s3->rrec.length = 0;
        }
        else
        {
          data = s3->rrec.data;
          v16 = v14 - v13;
          s3->rrec.length = v16;
          v26 = &data[v16];
        }
        if ( s->method->ssl3_enc->mac(s, v28, 0) < 0 )
          goto LABEL_56;
        v17 = v26;
        if ( !v26 )
          goto LABEL_56;
        v18 = v13;
        v19 = v28;
        if ( (unsigned int)v13 >= 4 )
        {
          while ( *(_DWORD *)v19 == *(_DWORD *)v17 )
          {
            v18 -= 4;
            v17 += 4;
            v19 += 4;
            if ( v18 < 4 )
              goto LABEL_35;
          }
LABEL_56:
          v20 = 20;
          ERR_put_error(0x14u, 143, 281, ".\\ssl\\s3_pkt.c", 479);
LABEL_61:
          ssl3_send_alert(s, 2, v20);
          return -1;
        }
LABEL_35:
        if ( v18 && (*v17 != *v19 || v18 > 1 && (v17[1] != v19[1] || v18 > 2 && v17[2] != v19[2])) )
          goto LABEL_56;
        v2 = v23;
      }
    }
    else
    {
      v25 = 1;
    }
    if ( v24 )
      goto LABEL_56;
    if ( s->expand )
    {
      if ( s3->rrec.length > v2 + 17408 )
      {
        v22 = 489;
        v21 = 140;
        goto LABEL_60;
      }
      if ( !ssl3_do_uncompress(s) )
      {
        v20 = 30;
        ERR_put_error(0x14u, 143, 107, ".\\ssl\\s3_pkt.c", 495);
        goto LABEL_61;
      }
    }
    if ( s3->rrec.length > v2 + 0x4000 )
    {
      v22 = 503;
      v21 = 146;
      goto LABEL_60;
    }
    s3->rrec.off = 0;
    s->packet_length = 0;
    if ( s3->rrec.length )
      return 1;
  }
  ERR_put_error(0x14u, 143, 267, ".\\ssl\\s3_pkt.c", 339);
  if ( ((v6 ^ s->version) & 0xFF00) == 0 )
    s->version = v6;
  ssl3_send_alert(s, 2, 70);
  return -1;
}
