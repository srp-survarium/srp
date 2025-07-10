int __cdecl ssl3_send_finished(ssl_st *s, int a, int b, const char *sender, int slen)
{
  char *data; // edi
  int v6; // ebx
  _BYTE *v7; // edi

  if ( s->state == a )
  {
    data = s->init_buf->data;
    v6 = s->method->ssl3_enc->final_finish_mac(s, sender, slen, s->s3->tmp.finish_md);
    s->s3->tmp.finish_md_len = v6;
    memcpy((unsigned __int8 *)data + 4, s->s3->tmp.finish_md, v6);
    if ( s->type == 4096 )
    {
      if ( v6 > 64 )
        OpenSSLDie((unsigned int)data, (unsigned int)s, ".\\ssl\\s3_both.c", 173, "i <= EVP_MAX_MD_SIZE");
      memcpy(s->s3->previous_client_finished, s->s3->tmp.finish_md, v6);
      s->s3->previous_client_finished_len = v6;
    }
    else
    {
      if ( v6 > 64 )
        OpenSSLDie((unsigned int)data, (unsigned int)s, ".\\ssl\\s3_both.c", 180, "i <= EVP_MAX_MD_SIZE");
      memcpy(s->s3->previous_server_finished, s->s3->tmp.finish_md, v6);
      s->s3->previous_server_finished_len = v6;
    }
    *data = 20;
    v7 = data + 1;
    v7[2] = v6;
    *v7 = BYTE2(v6);
    v7[1] = BYTE1(v6);
    s->init_num = v6 + 4;
    s->init_off = 0;
    s->state = b;
  }
  return ssl3_do_write(s, 22);
}
