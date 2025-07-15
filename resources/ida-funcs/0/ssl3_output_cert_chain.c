unsigned int __cdecl ssl3_output_cert_chain(ssl_st *s, x509_st *x)
{
  ssl_st *v2; // edi
  bool v3; // zf
  unsigned int v4; // ebx
  BOOL v5; // ebp
  buf_mem_st *v6; // esi
  int v8; // ebp
  char *v9; // eax
  int v10; // eax
  int v11; // ebp
  char *v12; // eax
  int v13; // eax
  char *data; // eax
  unsigned int v15; // ebx
  char *v16; // eax
  unsigned int l; // [esp+10h] [ebp-90h] BYREF
  buf_mem_st *init_buf; // [esp+14h] [ebp-8Ch]
  x509_store_ctx_st ctx; // [esp+18h] [ebp-88h] BYREF

  v2 = s;
  v3 = (s->mode & 8) == 0;
  v4 = 7;
  l = 7;
  v5 = !v3 || s->ctx->extra_certs;
  init_buf = s->init_buf;
  v6 = init_buf;
  if ( !BUF_MEM_grow_clean(init_buf, 0xAu) )
  {
    ERR_put_error(0x14u, 147, 7, ".\\ssl\\s3_both.c", 335);
    return 0;
  }
  if ( x )
  {
    if ( v5 )
    {
      if ( ssl3_add_cert_to_buf(&l, x, init_buf) )
        return 0;
      v4 = l;
      v6 = init_buf;
      v2 = s;
    }
    else
    {
      if ( !X509_STORE_CTX_init(&ctx, s->ctx->cert_store, x, 0) )
      {
        ERR_put_error(0x14u, 147, 11, ".\\ssl\\s3_both.c", 351);
        return 0;
      }
      X509_verify_cert(&ctx);
      ERR_clear_error();
      v8 = 0;
      if ( sk_num(&ctx.chain->stack) > 0 )
      {
        while ( 1 )
        {
          v9 = sk_value(&ctx.chain->stack, v8);
          if ( ssl3_add_cert_to_buf(&l, (x509_st *)v9, v6) )
            break;
          ++v8;
          v10 = sk_num(&ctx.chain->stack);
          v6 = init_buf;
          if ( v8 >= v10 )
          {
            v4 = l;
            v2 = s;
            goto LABEL_18;
          }
        }
        X509_STORE_CTX_cleanup(&ctx);
        return 0;
      }
LABEL_18:
      X509_STORE_CTX_cleanup(&ctx);
    }
  }
  v11 = 0;
  if ( sk_num(&v2->ctx->extra_certs->stack) > 0 )
  {
    while ( 1 )
    {
      v12 = sk_value(&v2->ctx->extra_certs->stack, v11);
      if ( ssl3_add_cert_to_buf(&l, (x509_st *)v12, v6) )
        return 0;
      ++v11;
      v13 = sk_num(&s->ctx->extra_certs->stack);
      v6 = init_buf;
      if ( v11 >= v13 )
      {
        v4 = l;
        break;
      }
      v2 = s;
    }
  }
  data = v6->data;
  v15 = v4 - 7;
  data[6] = v15;
  data += 4;
  *data = BYTE2(v15);
  data[1] = BYTE1(v15);
  v16 = v6->data;
  v15 += 3;
  *v16++ = 11;
  v16[2] = v15;
  *v16 = BYTE2(v15);
  v16[1] = BYTE1(v15);
  return v15 + 4;
}
