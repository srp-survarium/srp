int __usercall ssl3_send_server_certificate@<eax>(int a1@<ebx>, ssl_st *s)
{
  x509_st *server_send_cert; // eax
  const ssl_cipher_st *new_cipher; // ecx
  int v5; // eax

  if ( s->state == 8512 )
  {
    server_send_cert = ssl_get_server_send_cert(a1, s);
    if ( !server_send_cert )
    {
      new_cipher = s->s3->tmp.new_cipher;
      if ( new_cipher->algorithm_auth != 32 || (new_cipher->algorithm_mkey & 0x10) != 0 )
      {
        ERR_put_error(a1, 0x14u, 154, 68, ".\\ssl\\s3_srvr.c", 3056);
        return 0;
      }
    }
    v5 = ssl3_output_cert_chain(s, server_send_cert);
    s->state = 8513;
    s->init_num = v5;
    s->init_off = 0;
  }
  return ssl3_do_write(s, 22);
}
