x509_st *__usercall ssl_get_server_send_cert@<eax>(int a1@<ebx>, ssl_st *s)
{
  cert_st *cert; // edi
  const ssl_cipher_st *new_cipher; // eax
  unsigned int algorithm_mkey; // ecx
  unsigned int algorithm_auth; // eax

  cert = s->cert;
  ssl_set_cert_masks(cert, s->s3->tmp.new_cipher);
  new_cipher = s->s3->tmp.new_cipher;
  algorithm_mkey = new_cipher->algorithm_mkey;
  algorithm_auth = new_cipher->algorithm_auth;
  if ( (algorithm_mkey & 0x60) != 0 || (algorithm_auth & 0x40) != 0 )
    return cert->pkeys[5].x509;
  if ( (algorithm_mkey & 2) != 0 )
    return cert->pkeys[3].x509;
  if ( (algorithm_mkey & 4) != 0 )
    return cert->pkeys[4].x509;
  if ( (algorithm_auth & 2) != 0 )
    return cert->pkeys[2].x509;
  if ( (algorithm_auth & 1) != 0 )
    return cert->pkeys[cert->pkeys[0].x509 == 0].x509;
  if ( (algorithm_auth & 0x20) == 0 )
  {
    if ( (algorithm_auth & 0x100) != 0 )
      return cert->pkeys[6].x509;
    if ( (algorithm_auth & 0x200) != 0 )
      return cert->pkeys[7].x509;
    ERR_put_error(a1, 0x14u, 182, 68, ".\\ssl\\ssl_lib.c", 2165);
  }
  return 0;
}
