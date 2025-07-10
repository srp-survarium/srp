int __cdecl ssl3_send_client_verify(ssl_st *s)
{
  evp_pkey_ctx_st *v1; // ebp
  bool v2; // zf
  evp_pkey_st *privatekey; // ebx
  char *data; // esi
  const env_md_st *v5; // eax
  int type; // eax
  unsigned int v7; // eax
  const ssl_method_st *method; // ecx
  unsigned int v10; // eax
  int v11; // ecx
  unsigned int v12; // eax
  _BYTE *v13; // esi
  int v14; // [esp-4h] [ebp-88h]
  unsigned int v15; // [esp+10h] [ebp-74h] BYREF
  unsigned int siglen; // [esp+14h] [ebp-70h] BYREF
  unsigned int v17; // [esp+18h] [ebp-6Ch] BYREF
  unsigned __int8 m[16]; // [esp+1Ch] [ebp-68h] BYREF
  unsigned __int8 dgst[20]; // [esp+2Ch] [ebp-58h] BYREF
  unsigned __int8 sig[64]; // [esp+40h] [ebp-44h] BYREF

  v1 = 0;
  v2 = s->state == 4496;
  siglen = 0;
  if ( !v2 )
    goto LABEL_30;
  privatekey = s->cert->key->privatekey;
  data = s->init_buf->data;
  v1 = EVP_PKEY_CTX_new(privatekey, 0);
  EVP_PKEY_sign_init(v1);
  v5 = EVP_sha1();
  if ( EVP_PKEY_CTX_ctrl(v1, -1, 248, 1, 0, (void *)v5) <= 0 )
    ERR_clear_error();
  else
    s->method->ssl3_enc->cert_verify_mac(s, 64, dgst);
  type = privatekey->type;
  if ( privatekey->type == 6 )
  {
    s->method->ssl3_enc->cert_verify_mac(s, 4, m);
    if ( RSA_sign(0x72u, m, 0x24u, (unsigned __int8 *)data + 6, &siglen, privatekey->pkey.rsa) <= 0 )
    {
      ERR_put_error(0x14u, 153, 4, ".\\ssl\\s3_clnt.c", 2709);
LABEL_23:
      EVP_PKEY_CTX_free(v1);
      return -1;
    }
    data[4] = BYTE1(siglen);
    data[5] = siglen;
    v7 = siglen;
    goto LABEL_29;
  }
  if ( type == 116 )
  {
    if ( !DSA_sign(privatekey->save_type, dgst, 20, (unsigned __int8 *)data + 6, &v15, privatekey->pkey.dsa) )
    {
      ERR_put_error(0x14u, 153, 10, ".\\ssl\\s3_clnt.c", 2725);
      goto LABEL_23;
    }
    data[4] = BYTE1(v15);
    data[5] = v15;
    goto LABEL_28;
  }
  if ( type == 408 )
  {
    if ( !ECDSA_sign(privatekey->save_type, dgst, 20, (unsigned __int8 *)data + 6, &v15, privatekey->pkey.ec) )
    {
      ERR_put_error(0x14u, 153, 42, ".\\ssl\\s3_clnt.c", 2742);
      goto LABEL_23;
    }
    data[4] = BYTE1(v15);
    goto LABEL_27;
  }
  if ( type != 812 && type != 811 )
  {
    v14 = 2771;
LABEL_22:
    ERR_put_error(0x14u, 153, 68, ".\\ssl\\s3_clnt.c", v14);
    goto LABEL_23;
  }
  method = s->method;
  v17 = 64;
  method->ssl3_enc->cert_verify_mac(s, 809, m);
  if ( EVP_PKEY_sign(v1, sig, &v17, m, 0x20u) <= 0 )
  {
    v14 = 2760;
    goto LABEL_22;
  }
  v10 = 0;
  v11 = 63;
  v15 = 0;
  do
  {
    data[v10 + 6] = sig[v11];
    v10 = v15 + 1;
    --v11;
    ++v15;
  }
  while ( v11 >= 0 );
  data[4] = BYTE1(v10);
LABEL_27:
  data[5] = v15;
LABEL_28:
  v7 = v15;
LABEL_29:
  *data = 15;
  v12 = v7 + 2;
  v13 = data + 1;
  v13[2] = v12;
  *v13 = BYTE2(v12);
  v13[1] = BYTE1(v12);
  s->state = 4497;
  s->init_num = v12 + 4;
  s->init_off = 0;
LABEL_30:
  EVP_PKEY_CTX_free(v1);
  return ssl3_do_write(s, 22);
}
