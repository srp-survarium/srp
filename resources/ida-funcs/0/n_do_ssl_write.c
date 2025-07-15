int __fastcall n_do_ssl_write(unsigned int len, ssl_st *s, const __m128i *buf)
{
  ssl2_state_st *s2; // eax
  unsigned int v5; // edi
  unsigned int v6; // ebx
  ssl2_state_st *v8; // eax
  ui_string_st *object; // eax
  unsigned int v10; // edi
  unsigned int v11; // ecx
  ssl2_state_st *v12; // ebp
  unsigned int v13; // ecx
  ssl2_state_st *v14; // eax
  ssl2_state_st *v15; // eax
  ssl2_state_st *v16; // ecx
  ssl2_state_st *v17; // eax
  unsigned int v18; // ecx
  unsigned __int8 *v19; // eax
  unsigned __int8 v20; // cl
  unsigned int wlength; // ecx
  int v22; // [esp+Ch] [ebp-8h]

  s2 = s->s2;
  v5 = 0;
  v6 = len;
  if ( s2->wpend_len )
    return write_pending(s, len, (const unsigned __int8 *)buf, len);
  if ( s2->clear_text )
  {
    v22 = 0;
  }
  else
  {
    object = X509_EXTENSION_get_object((ui_string_st *)s->write_hash);
    v22 = EVP_MD_size(v6, (const env_md_st *)object);
    if ( v22 < 0 )
      return -1;
  }
  v8 = s->s2;
  if ( v8->clear_text )
  {
    if ( v6 > 0x7FFF )
      v6 = 0x7FFF;
    v8->three_byte_header = 0;
  }
  else
  {
    v10 = (unsigned int)EVP_CIPHER_CTX_block_size((x509_st *)s->enc_read_ctx);
    v11 = v22 + v6;
    if ( v22 + v6 <= 0x3FFF || (v12 = s->s2, v12->escape) )
    {
      if ( v10 > 1 || (v14 = s->s2, v14->escape) )
      {
        if ( v11 % v10 )
          v5 = v10 - v11 % v10;
        else
          v5 = 0;
        v15 = s->s2;
        if ( v15->escape )
          v15->three_byte_header = 1;
        else
          v15->three_byte_header = v5 != 0;
      }
      else
      {
        v14->three_byte_header = 0;
        v5 = 0;
      }
    }
    else
    {
      if ( v11 > 0x7FFF )
        v11 = 0x7FFF;
      v12->three_byte_header = 0;
      v13 = v11 - v11 % v10 - v22;
      v5 = 0;
      v6 = v13;
    }
  }
  s->s2->wlength = v6;
  s->s2->padding = v5;
  s->s2->mac_data = s->s2->wbuf + 3;
  s->s2->wact_data = &s->s2->wbuf[v22 + 3];
  memcpy((int)s->s2->wact_data, buf, v6);
  if ( v5 )
    memset((int)&s->s2->wact_data[v6], 0, v5);
  v16 = s->s2;
  if ( !v16->clear_text )
  {
    v16->wact_data_length = v5 + v6;
    ssl2_mac(s, s->s2->mac_data, 1);
    s->s2->wlength += v22 + v5;
    ssl2_enc(s, 1);
  }
  s->s2->wpend_len = s->s2->wlength;
  v17 = s->s2;
  if ( v17->three_byte_header )
  {
    v18 = v17->wlength >> 8;
    v19 = v17->mac_data - 3;
    v20 = v18 & 0x3F;
    *v19 = v20;
    if ( s->s2->escape )
      *v19 = v20 | 0x40;
    v19[1] = s->s2->wlength;
    v19[2] = s->s2->padding;
    s->s2->wpend_len += 3;
  }
  else
  {
    wlength = v17->wlength;
    v19 = v17->mac_data - 2;
    *v19 = BYTE1(wlength) | 0x80;
    v19[1] = s->s2->wlength;
    s->s2->wpend_len += 2;
  }
  s->s2->write_ptr = v19;
  ++s->s2->write_sequence;
  s->s2->wpend_tot = len;
  s->s2->wpend_buf = (const unsigned __int8 *)buf;
  s->s2->wpend_ret = v6;
  s->s2->wpend_off = 0;
  return write_pending(s, v6, (const unsigned __int8 *)buf, len);
}
