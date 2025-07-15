int __usercall ssl2_read_internal@<eax>(ssl_st *s@<esi>, unsigned __int8 *buf, int len, int peek)
{
  int result; // eax
  ssl2_state_st *s2; // edx
  char *packet; // eax
  char v7; // al
  unsigned __int8 *v8; // eax
  ssl2_state_st *v9; // ecx
  ssl2_state_st *v10; // eax
  unsigned int rlength; // ecx
  int three_byte_header; // edx
  signed int packet_length; // eax
  int v14; // ebx
  ssl2_state_st *v15; // eax
  unsigned __int8 *v16; // ebx
  ssl2_state_st *v17; // eax
  ssl2_state_st *v18; // eax
  unsigned int v19; // edi
  ui_string_st *object; // eax
  signed int v21; // eax
  ssl2_state_st *v22; // ebx
  unsigned __int8 *mac_data; // eax
  unsigned __int8 *v24; // ecx
  signed int ract_data_length; // edi
  const ssl_st *v26; // [esp+0h] [ebp-2Ch]
  unsigned __int8 md[20]; // [esp+14h] [ebp-18h] BYREF

  while ( 1 )
  {
    if ( (SSL_state(v26) & 0x3000) != 0 && !s->in_handshake )
    {
      result = s->handshake_func(s);
      if ( result < 0 )
        return result;
      if ( !result )
      {
        ERR_put_error(0x14u, 236, 229, ".\\ssl\\s2_pkt.c", 142);
        return -1;
      }
    }
    SetLastError(0);
    s->rwstate = 1;
    if ( len <= 0 )
      return len;
    s2 = s->s2;
    if ( s2->ract_data_length )
      break;
    if ( s->rstate == 240 )
    {
      if ( s->first_packet )
      {
        result = read_n(s, 5, 0x8001u, 0);
        if ( result <= 0 )
          return result;
        packet = (char *)s->packet;
        s->first_packet = 0;
        if ( *packet >= 0 || (v7 = packet[2], v7 != 1) && v7 != 4 )
        {
          ERR_put_error(0x14u, 236, 175, ".\\ssl\\s2_pkt.c", 187);
          return -1;
        }
      }
      else
      {
        result = read_n(s, 2, 0x8001u, 0);
        if ( result <= 0 )
          return result;
      }
      v8 = s->packet;
      v9 = s->s2;
      s->rstate = 241;
      v9->escape = 0;
      s->s2->rlength = v8[1] | (*v8 << 8);
      if ( (*v8 & 0x80u) == 0 )
      {
        s->s2->three_byte_header = 1;
        s->s2->rlength &= 0x3FFFu;
        s->s2->escape = (*v8 >> 6) & 1;
      }
      else
      {
        s->s2->three_byte_header = 0;
        s->s2->rlength &= 0x7FFFu;
      }
    }
    if ( s->rstate != 241 )
    {
      ERR_put_error(0x14u, 236, 126, ".\\ssl\\s2_pkt.c", 304);
      return -1;
    }
    v10 = s->s2;
    rlength = v10->rlength;
    three_byte_header = v10->three_byte_header;
    packet_length = s->packet_length;
    v14 = rlength + three_byte_header + 2;
    if ( v14 > packet_length )
    {
      result = read_n(s, v14 - packet_length, v14 - packet_length, 1u);
      if ( result <= 0 )
        return result;
    }
    v15 = s->s2;
    v16 = s->packet + 2;
    s->rstate = 240;
    if ( v15->three_byte_header )
      v15->padding = *v16++;
    else
      v15->padding = 0;
    v17 = s->s2;
    if ( v17->clear_text )
    {
      v17->mac_data = v16;
      s->s2->ract_data = v16;
      v18 = s->s2;
      v19 = 0;
      if ( v18->padding )
      {
        ERR_put_error(0x14u, 236, 283, ".\\ssl\\s2_pkt.c", 243);
        return -1;
      }
    }
    else
    {
      object = X509_EXTENSION_get_object((ui_string_st *)s->read_hash);
      v21 = EVP_MD_size((const env_md_st *)object);
      v19 = v21;
      if ( v21 < 0 )
        return -1;
      if ( v21 > 20 )
        OpenSSLDie(v21, (unsigned int)s, ".\\ssl\\s2_pkt.c", 252, "mac_size <= MAX_MAC_SIZE");
      s->s2->mac_data = v16;
      s->s2->ract_data = &v16[v21];
      v18 = s->s2;
      if ( v19 + v18->padding > v18->rlength )
      {
        ERR_put_error(0x14u, 236, 283, ".\\ssl\\s2_pkt.c", 257);
        return -1;
      }
    }
    v18->ract_data_length = v18->rlength;
    v22 = s->s2;
    if ( !v22->clear_text && v22->rlength >= v19 )
    {
      ssl2_enc(s, 0);
      s->s2->ract_data_length -= v19;
      ssl2_mac(s, md, 0);
      s->s2->ract_data_length -= s->s2->padding;
      mac_data = s->s2->mac_data;
      v24 = md;
      if ( v19 >= 4 )
      {
        while ( *(_DWORD *)v24 == *(_DWORD *)mac_data )
        {
          v19 -= 4;
          mac_data += 4;
          v24 += 4;
          if ( v19 < 4 )
            goto LABEL_36;
        }
LABEL_53:
        ERR_put_error(0x14u, 236, 113, ".\\ssl\\s2_pkt.c", 276);
        return -1;
      }
LABEL_36:
      if ( v19 && (*mac_data != *v24 || v19 > 1 && (mac_data[1] != v24[1] || v19 > 2 && mac_data[2] != v24[2])) )
        goto LABEL_53;
      v22 = s->s2;
      if ( v22->rlength % (unsigned int)EVP_CIPHER_CTX_block_size((x509_st *)s->enc_read_ctx) )
        goto LABEL_53;
    }
    ++v22->read_sequence;
  }
  ract_data_length = s2->ract_data_length;
  if ( len <= ract_data_length )
    ract_data_length = len;
  memcpy(buf, s2->ract_data, ract_data_length);
  if ( !peek )
  {
    s->s2->ract_data_length -= ract_data_length;
    s->s2->ract_data += ract_data_length;
    if ( !s->s2->ract_data_length )
      s->rstate = 240;
  }
  return ract_data_length;
}
