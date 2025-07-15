int __usercall check_chain_extensions@<eax>(x509_store_ctx_st *ctx@<esi>, int a2@<edi>)
{
  int (__cdecl *verify_cb)(int, x509_store_ctx_st *); // ebx
  int v3; // ebp
  x509_st *v4; // eax
  x509_st *v5; // edi
  int result; // eax
  int v7; // eax
  int v8; // ecx
  bool v9; // zf
  int v10; // eax
  int ex_pathlen; // eax
  unsigned int ex_flags; // eax
  int ex_pcpathlen; // eax
  int v14; // [esp+Ch] [ebp-14h]
  unsigned int v15; // [esp+10h] [ebp-10h]
  int v16; // [esp+14h] [ebp-Ch]
  int v17; // [esp+18h] [ebp-8h]
  int id; // [esp+1Ch] [ebp-4h]

  verify_cb = ctx->verify_cb;
  v3 = 0;
  v16 = 0;
  v17 = 0;
  v14 = -1;
  if ( ctx->parent )
  {
    v15 = 0;
    id = 6;
  }
  else
  {
    v15 = (ctx->param->flags >> 6) & 1;
    if ( getenv((int)verify_cb, a2, "OPENSSL_ALLOW_PROXY_CERTS") )
      v15 = 1;
    id = ctx->param->purpose;
  }
  if ( ctx->last_untrusted > 0 )
  {
    while ( 1 )
    {
      v4 = (x509_st *)sk_value(&ctx->chain->stack, v3);
      v5 = v4;
      if ( (ctx->param->flags & 0x10) == 0 && (v4->ex_flags & 0x200) != 0 )
      {
        ctx->error = 34;
        ctx->error_depth = v3;
        ctx->current_cert = v4;
        result = verify_cb(0, ctx);
        if ( !result )
          return result;
      }
      if ( !v15 && (v5->ex_flags & 0x400) != 0 )
      {
        ctx->error = 40;
        ctx->error_depth = v3;
        ctx->current_cert = v5;
        result = verify_cb(0, ctx);
        if ( !result )
          return result;
      }
      v7 = X509_check_ca((int)v5, v5);
      v8 = v14;
      if ( v14 == -1 )
        break;
      if ( !v14 )
      {
        if ( !v7 )
          goto LABEL_27;
        ctx->error = 37;
        goto LABEL_25;
      }
      if ( v7 )
      {
        if ( (ctx->param->flags & 0x20) == 0 )
          goto LABEL_27;
        v9 = v7 == 1;
LABEL_23:
        if ( v9 )
          goto LABEL_27;
      }
      ctx->error = 24;
LABEL_25:
      ctx->error_depth = v3;
      ctx->current_cert = v5;
      result = verify_cb(0, ctx);
      if ( !result )
        return result;
      v8 = v14;
LABEL_27:
      if ( ctx->param->purpose > 0 )
      {
        v10 = X509_check_purpose((int)v5, v5, id, v8 > 0);
        if ( !v10 || (ctx->param->flags & 0x20) != 0 && v10 != 1 )
        {
          ctx->error = 26;
          ctx->error_depth = v3;
          ctx->current_cert = v5;
          result = verify_cb(0, ctx);
          if ( !result )
            return result;
        }
      }
      if ( v3 > 1 && (v5->ex_flags & 0x20) == 0 )
      {
        ex_pathlen = v5->ex_pathlen;
        if ( ex_pathlen != -1 && v16 > ex_pathlen + v17 + 1 )
        {
          ctx->error = 25;
          ctx->error_depth = v3;
          ctx->current_cert = v5;
          result = verify_cb(0, ctx);
          if ( !result )
            return result;
        }
      }
      ex_flags = v5->ex_flags;
      if ( (ex_flags & 0x20) == 0 )
        ++v16;
      if ( (ex_flags & 0x400) != 0 )
      {
        ex_pcpathlen = v5->ex_pcpathlen;
        if ( ex_pcpathlen != -1 && v3 > ex_pcpathlen )
        {
          ctx->error = 38;
          ctx->error_depth = v3;
          ctx->current_cert = v5;
          result = verify_cb(0, ctx);
          if ( !result )
            return result;
        }
        ++v17;
        v14 = 0;
      }
      else
      {
        v14 = 1;
      }
      if ( ++v3 >= ctx->last_untrusted )
        return 1;
    }
    if ( (ctx->param->flags & 0x20) == 0 || v7 == 1 )
      goto LABEL_27;
    v9 = v7 == 0;
    goto LABEL_23;
  }
  return 1;
}
