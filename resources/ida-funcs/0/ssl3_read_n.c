int __cdecl ssl3_read_n(ssl_st *s, int n, int max, int extend)
{
  int result; // eax
  ssl3_buffer_st *p_rbuf; // ebx
  unsigned __int8 *buf; // ecx
  int v7; // ebp
  int left; // esi
  const __m128i *v9; // eax
  unsigned __int8 *v10; // eax
  const __m128i *packet; // ecx
  int v12; // eax
  int v13; // eax
  bio_st *rbio; // eax
  int v15; // eax
  int v16; // ebp
  unsigned int packet_length; // [esp+0h] [ebp-8h]
  unsigned __int8 *v18; // [esp+4h] [ebp-4h]

  result = n;
  if ( n <= 0 )
    return result;
  p_rbuf = &s->s3->rbuf;
  if ( !p_rbuf->buf && !ssl3_setup_read_buffer(s) )
    return -1;
  buf = p_rbuf->buf;
  v7 = (3 - (unsigned __int8)p_rbuf->buf) & 7;
  left = p_rbuf->left;
  if ( !extend )
  {
    if ( left )
    {
      if ( ((3 - (_BYTE)buf) & 7) == 0 )
        goto LABEL_13;
      if ( left < 5 )
        goto LABEL_13;
      v9 = (const __m128i *)&buf[p_rbuf->offset];
      if ( v9->m128i_i8[0] != 23 || (v9->m128i_u8[4] | (v9->m128i_u8[3] << 8)) < 128 )
        goto LABEL_13;
      memmove((int)&p_rbuf->buf[v7], v9, p_rbuf->left);
    }
    p_rbuf->offset = v7;
LABEL_13:
    v10 = &p_rbuf->buf[p_rbuf->offset];
    s->packet_length = 0;
    s->packet = v10;
  }
  if ( (EVP_CIPHER_CTX_cipher(s) == 65279 || EVP_CIPHER_CTX_cipher(s) == 256) && left > 0 )
  {
    result = n;
    if ( n > left )
    {
      result = left;
      s->packet_length += left;
      p_rbuf->offset += left;
      p_rbuf->left = 0;
      return result;
    }
    goto LABEL_21;
  }
  if ( left >= n )
  {
    result = n;
LABEL_21:
    s->packet_length += result;
    p_rbuf->offset += result;
    p_rbuf->left = left - result;
    return result;
  }
  packet = (const __m128i *)s->packet;
  v12 = (int)&p_rbuf->buf[v7];
  packet_length = s->packet_length;
  v18 = (unsigned __int8 *)v12;
  if ( packet != (const __m128i *)v12 )
  {
    memmove(v12, packet, left + s->packet_length);
    s->packet = v18;
    p_rbuf->offset = v7 + packet_length;
  }
  v13 = p_rbuf->len - p_rbuf->offset;
  if ( n <= v13 )
  {
    if ( s->read_ahead )
    {
      if ( max < n )
        max = n;
      if ( max > v13 )
        max = p_rbuf->len - p_rbuf->offset;
    }
    else
    {
      max = n;
    }
    while ( 1 )
    {
      SetLastError(0);
      rbio = s->rbio;
      if ( !rbio )
        break;
      s->rwstate = 3;
      v15 = BIO_read((int)p_rbuf, rbio, (char *)&v18[packet_length + left], max - left);
      v16 = v15;
      if ( v15 <= 0 )
        goto LABEL_39;
      left += v15;
      if ( EVP_CIPHER_CTX_cipher(s) == 65279 || EVP_CIPHER_CTX_cipher(s) == 256 )
      {
        if ( n > left )
          n = left;
        result = n;
LABEL_48:
        p_rbuf->offset += result;
        p_rbuf->left = left - result;
        s->packet_length += result;
        s->rwstate = 1;
        return result;
      }
      result = n;
      if ( left >= n )
        goto LABEL_48;
    }
    ERR_put_error((int)p_rbuf, 0x14u, 149, 211, ".\\ssl\\s3_pkt.c", 242);
    v16 = -1;
LABEL_39:
    p_rbuf->left = left;
    if ( (s->mode & 0x10) != 0
      && EVP_CIPHER_CTX_cipher(s) != 65279
      && EVP_CIPHER_CTX_cipher(s) != 256
      && !(left + packet_length) )
    {
      ssl3_release_read_buffer(s);
    }
    return v16;
  }
  else
  {
    ERR_put_error((int)p_rbuf, 0x14u, 149, 68, ".\\ssl\\s3_pkt.c", 213);
    return -1;
  }
}
