int __cdecl ssl3_send_cert_status(ssl_st *s)
{
  char *data; // eax

  if ( s->state == 8704 )
  {
    if ( !BUF_MEM_grow(s->init_buf, s->tlsext_ocsp_resplen + 8) )
      return -1;
    data = s->init_buf->data;
    *data++ = 22;
    *data = (unsigned int)(s->tlsext_ocsp_resplen + 4) >> 16;
    data[1] = (unsigned __int16)(LOWORD(s->tlsext_ocsp_resplen) + 4) >> 8;
    data[2] = LOBYTE(s->tlsext_ocsp_resplen) + 4;
    data[3] = s->tlsext_status_type;
    data += 4;
    *data = BYTE2(s->tlsext_ocsp_resplen);
    data[1] = BYTE1(s->tlsext_ocsp_resplen);
    data[2] = s->tlsext_ocsp_resplen;
    memcpy((int)(data + 3), (const __m128i *)s->tlsext_ocsp_resp, s->tlsext_ocsp_resplen);
    s->init_num = s->tlsext_ocsp_resplen + 8;
    s->state = 8705;
    s->init_off = 0;
  }
  return ssl3_do_write(s, 22);
}
