int __cdecl ssl3_send_certificate_request(ssl_st *s)
{
  ssl_st *v1; // esi
  buf_mem_st *init_buf; // edi
  char *data; // eax
  _BYTE *v4; // ebp
  int req_cert_type; // eax
  int v6; // ebx
  stack_st_X509_NAME *client_CA_list; // ebp
  char *v8; // eax
  buf_mem_st *v9; // eax
  int v10; // ebx
  char *v12; // ebp
  bool v13; // zf
  char *v14; // edx
  ssl_st *v15; // [esp-8h] [ebp-30h]
  int v16; // [esp+10h] [ebp-18h]
  int v17; // [esp+14h] [ebp-14h]
  int i; // [esp+18h] [ebp-10h]
  stack_st *st; // [esp+1Ch] [ebp-Ch]
  char *v20; // [esp+20h] [ebp-8h]
  int v21; // [esp+24h] [ebp-4h]

  v1 = s;
  if ( s->state != 8544 )
    return ssl3_do_write(v1, 22);
  init_buf = s->init_buf;
  data = init_buf->data;
  v4 = data + 4;
  v15 = s;
  s = (ssl_st *)(data + 5);
  req_cert_type = ssl3_get_req_cert_type(v15, (unsigned __int8 *)data + 5);
  *v4 = req_cert_type;
  v21 = req_cert_type + 1;
  s = (ssl_st *)((char *)s + req_cert_type + 2);
  v6 = req_cert_type + 3;
  client_CA_list = SSL_get_client_CA_list(v1);
  st = &client_CA_list->stack;
  v16 = 0;
  if ( !client_CA_list || (i = 0, sk_num(&client_CA_list->stack) <= 0) )
  {
LABEL_4:
    s = (ssl_st *)&init_buf->data[v21 + 4];
    LOBYTE(s->version) = BYTE1(v16);
    BYTE1(s->version) = v16;
    s = (ssl_st *)((char *)s + 2);
    v8 = init_buf->data;
    *v8 = 13;
    v8[3] = v6;
    *++v8 = BYTE2(v6);
    v8[1] = BYTE1(v6);
    v9 = v1->init_buf;
    v10 = v6 + 4;
    v1->init_num = v10;
    v1->init_off = 0;
    s = (ssl_st *)&v9->data[v10];
    LOBYTE(s->version) = 14;
    s = (ssl_st *)((char *)s + 1);
    LOBYTE(s->version) = 0;
    s = (ssl_st *)((char *)s + 1);
    LOBYTE(s->version) = 0;
    s = (ssl_st *)((char *)s + 1);
    LOBYTE(s->version) = 0;
    s = (ssl_st *)((char *)s + 1);
    v1->init_num += 4;
    v1->state = 8545;
    return ssl3_do_write(v1, 22);
  }
  while ( 1 )
  {
    v12 = sk_value(&client_CA_list->stack, i);
    v17 = i2d_X509_NAME((X509_name_st *)v12, 0);
    if ( !BUF_MEM_grow_clean(init_buf, v17 + v6 + 6) )
      break;
    v13 = (v1->options & 0x20000000) == 0;
    v14 = init_buf->data;
    s = (ssl_st *)&v14[v6 + 4];
    if ( v13 )
    {
      v14[v6 + 4] = BYTE1(v17);
      BYTE1(s->version) = v17;
      s = (ssl_st *)((char *)s + 2);
      i2d_X509_NAME((X509_name_st *)v12, (unsigned __int8 **)&s);
      v6 += v17 + 2;
      v16 += v17 + 2;
    }
    else
    {
      v20 = &v14[v6 + 4];
      i2d_X509_NAME((X509_name_st *)v12, (unsigned __int8 **)&s);
      v20[1] = v17 - 2;
      v6 += v17;
      v16 += v17;
      *v20 = (unsigned __int16)(v17 - 2) >> 8;
    }
    if ( ++i >= sk_num(st) )
      goto LABEL_4;
    client_CA_list = (stack_st_X509_NAME *)st;
  }
  ERR_put_error(0x14u, 150, 7, ".\\ssl\\s3_srvr.c", 1898);
  return -1;
}
