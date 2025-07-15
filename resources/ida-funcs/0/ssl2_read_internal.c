int __usercall ssl2_read_internal@<eax>(ssl_st *s@<esi>, int a2@<ebx>, unsigned __int8 *buf, int len, int peek)
{
  int result; // eax
  ssl2_state_st *s2; // edx
  char *packet; // eax
  char v8; // al
  unsigned __int8 *v9; // eax
  ssl2_state_st *v10; // ecx
  ssl2_state_st *v11; // eax
  unsigned int rlength; // ecx
  int three_byte_header; // edx
  signed int packet_length; // eax
  int v15; // ebx
  ssl2_state_st *v16; // eax
  unsigned __int8 *v17; // ebx
  ssl2_state_st *v18; // eax
  ssl2_state_st *v19; // eax
  unsigned int v20; // edi
  ui_string_st *object; // eax
  int v22; // eax
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
        ERR_put_error(a2, 0x14u, 236, 229, ".\\ssl\\s2_pkt.c", 142);
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
        a2 = 5;
        result = read_n(s, 5, 0x8001u, 0);
        if ( result <= 0 )
          return result;
        packet = (char *)s->packet;
        s->first_packet = 0;
        if ( *packet >= 0 || (v8 = packet[2], v8 != 1) && v8 != 4 )
        {
          ERR_put_error(5, 0x14u, 236, 175, ".\\ssl\\s2_pkt.c", 187);
          return -1;
        }
      }
      else
      {
        a2 = 2;
        result = read_n(s, 2, 0x8001u, 0);
        if ( result <= 0 )
          return result;
      }
      v9 = s->packet;
      v10 = s->s2;
      s->rstate = 241;
      v10->escape = 0;
      s->s2->rlength = v9[1] | (*v9 << 8);
      if ( (*v9 & 0x80u) == 0 )
      {
        s->s2->three_byte_header = 1;
        s->s2->rlength &= 0x3FFFu;
        s->s2->escape = (*v9 >> 6) & 1;
      }
      else
      {
        s->s2->three_byte_header = 0;
        s->s2->rlength &= 0x7FFFu;
      }
    }
    if ( s->rstate != 241 )
    {
      ERR_put_error(a2, 0x14u, 236, 126, ".\\ssl\\s2_pkt.c", 304);
      return -1;
    }
    v11 = s->s2;
    rlength = v11->rlength;
    three_byte_header = v11->three_byte_header;
    packet_length = s->packet_length;
    v15 = rlength + three_byte_header + 2;
    if ( v15 > packet_length )
    {
      result = read_n(s, v15 - packet_length, v15 - packet_length, 1u);
      if ( result <= 0 )
        return result;
    }
    v16 = s->s2;
    v17 = s->packet + 2;
    s->rstate = 240;
    if ( v16->three_byte_header )
      v16->padding = *v17++;
    else
      v16->padding = 0;
    v18 = s->s2;
    if ( v18->clear_text )
    {
      v18->mac_data = v17;
      s->s2->ract_data = v17;
      v19 = s->s2;
      v20 = 0;
      if ( v19->padding )
      {
        ERR_put_error((int)v17, 0x14u, 236, 283, ".\\ssl\\s2_pkt.c", 243);
        return -1;
      }
    }
    else
    {
      object = X509_EXTENSION_get_object((ui_string_st *)s->read_hash);
      v22 = EVP_MD_size((int)v17, (const env_md_st *)object);
      v20 = v22;
      if ( v22 < 0 )
        return -1;
      if ( v22 > 20 )
        OpenSSLDie(v22, (int)s, (int)v17, ".\\ssl\\s2_pkt.c", 252, "mac_size <= MAX_MAC_SIZE");
      s->s2->mac_data = v17;
      s->s2->ract_data = &v17[v22];
      v19 = s->s2;
      if ( v20 + v19->padding > v19->rlength )
      {
        ERR_put_error((int)v17, 0x14u, 236, 283, ".\\ssl\\s2_pkt.c", 257);
        return -1;
      }
    }
    v19->ract_data_length = v19->rlength;
    a2 = (int)s->s2;
    if ( !*(_DWORD *)(a2 + 4) && *(_DWORD *)(a2 + 64) >= v20 )
    {
      ssl2_enc(s, 0);
      s->s2->ract_data_length -= v20;
      ssl2_mac(s, md, 0);
      s->s2->ract_data_length -= s->s2->padding;
      mac_data = s->s2->mac_data;
      v24 = md;
      if ( v20 >= 4 )
      {
        while ( *(_DWORD *)v24 == *(_DWORD *)mac_data )
        {
          v20 -= 4;
          mac_data += 4;
          v24 += 4;
          if ( v20 < 4 )
            goto LABEL_36;
        }
LABEL_53:
        ERR_put_error(a2, 0x14u, 236, 113, ".\\ssl\\s2_pkt.c", 276);
        return -1;
      }
LABEL_36:
      if ( v20 && (*mac_data != *v24 || v20 > 1 && (mac_data[1] != v24[1] || v20 > 2 && mac_data[2] != v24[2])) )
        goto LABEL_53;
      a2 = (int)s->s2;
      if ( *(_DWORD *)(a2 + 64) % (unsigned int)EVP_CIPHER_CTX_block_size((x509_st *)s->enc_read_ctx) )
        goto LABEL_53;
    }
    ++*(_DWORD *)(a2 + 208);
  }
  ract_data_length = s2->ract_data_length;
  if ( len <= ract_data_length )
    ract_data_length = len;
  memcpy((int)buf, (const __m128i *)s2->ract_data, ract_data_length);
  if ( !peek )
  {
    s->s2->ract_data_length -= ract_data_length;
    s->s2->ract_data += ract_data_length;
    if ( !s->s2->ract_data_length )
      s->rstate = 240;
  }
  return ract_data_length;
}
