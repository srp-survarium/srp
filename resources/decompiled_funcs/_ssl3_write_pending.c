int __cdecl ssl3_write_pending(ssl_st *s, int type, const unsigned __int8 *buf, signed int len)
{
  ssl3_state_st *s3; // esi
  bio_st *wbio; // eax
  int result; // eax
  int left; // ecx
  ssl3_state_st *v8; // eax

  s3 = s->s3;
  if ( s3->wpend_tot <= len && (s3->wpend_buf == buf || (s->mode & 2) != 0) && s3->wpend_type == type )
  {
    while ( 1 )
    {
      SetLastError(0);
      wbio = s->wbio;
      if ( wbio )
      {
        s->rwstate = 2;
        result = BIO_write(wbio, (const char *)&s3->wbuf.buf[s3->wbuf.offset], s3->wbuf.left);
      }
      else
      {
        ERR_put_error(0x14u, 159, 128, ".\\ssl\\s3_pkt.c", 843);
        result = -1;
      }
      left = s3->wbuf.left;
      if ( result == left )
        break;
      if ( result <= 0 )
      {
        if ( s->version == 65279 || s->version == 256 )
          s3->wbuf.left = 0;
        return result;
      }
      s3->wbuf.offset += result;
      s3->wbuf.left = left - result;
    }
    s3->wbuf.offset += result;
    s3->wbuf.left = 0;
    if ( (s->mode & 0x10) != 0 && EVP_CIPHER_CTX_cipher(s) != 65279 && EVP_CIPHER_CTX_cipher(s) != 256 )
      ssl3_release_write_buffer(s);
    v8 = s->s3;
    s->rwstate = 1;
    return v8->wpend_ret;
  }
  else
  {
    ERR_put_error(0x14u, 159, 127, ".\\ssl\\s3_pkt.c", 827);
    return -1;
  }
}
