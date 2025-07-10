int __cdecl ssl3_send_client_certificate(ssl_st *s)
{
  bool v1; // zf
  cert_st *cert; // eax
  cert_pkey_st *key; // eax
  int v4; // eax
  int v5; // edi
  ssl3_state_st *s3; // edx
  x509_st *x509; // eax
  x509_st *v9; // [esp-4h] [ebp-18h]
  evp_pkey_st *ppkey; // [esp+Ch] [ebp-8h] BYREF
  x509_st *px509; // [esp+10h] [ebp-4h] BYREF

  v1 = s->state == 4464;
  px509 = 0;
  ppkey = 0;
  if ( v1 )
  {
    cert = s->cert;
    if ( cert && (key = cert->key, key->x509) && key->privatekey )
      s->state = 4466;
    else
      s->state = 4465;
  }
  if ( s->state == 4465 )
  {
    v4 = ssl_do_client_cert_cb(s, &px509, &ppkey);
    v5 = v4;
    if ( v4 < 0 )
    {
      s->rwstate = 4;
      return -1;
    }
    s->rwstate = 1;
    if ( v4 == 1 )
    {
      if ( ppkey && px509 )
      {
        v9 = px509;
        s->state = 4465;
        if ( !SSL_use_certificate(s, v9) || !SSL_use_PrivateKey(s, ppkey) )
          v5 = 0;
      }
      else
      {
        v5 = 0;
        ERR_put_error(0x14u, 151, 106, ".\\ssl\\s3_clnt.c", 2829);
      }
    }
    if ( px509 )
      X509_free(px509);
    if ( ppkey )
      EVP_PKEY_free(ppkey);
    if ( !v5 )
    {
      if ( s->version == 768 )
      {
        s->s3->tmp.cert_req = 0;
        ssl3_send_alert(s, 1, 41);
        return 1;
      }
      s->s3->tmp.cert_req = 2;
    }
    s->state = 4466;
  }
  if ( s->state == 4466 )
  {
    s3 = s->s3;
    s->state = 4467;
    if ( s3->tmp.cert_req == 2 )
      x509 = 0;
    else
      x509 = s->cert->key->x509;
    s->init_num = ssl3_output_cert_chain(s, x509);
    s->init_off = 0;
  }
  return ssl3_do_write(s, 22);
}
