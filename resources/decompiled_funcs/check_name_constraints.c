int __usercall check_name_constraints@<eax>(x509_store_ctx_st *ctx@<esi>)
{
  int v1; // ebp
  x509_st *v2; // eax
  x509_st *v3; // ebx
  int v4; // edi
  NAME_CONSTRAINTS_st *v5; // eax
  int v6; // eax
  int (__cdecl *verify_cb)(int, x509_store_ctx_st *); // ecx

  v1 = sk_num(&ctx->chain->stack) - 1;
  if ( v1 < 0 )
    return 1;
  while ( 1 )
  {
    v2 = (x509_st *)sk_value(&ctx->chain->stack, v1);
    v3 = v2;
    if ( !v1 || (v2->ex_flags & 0x20) == 0 )
    {
      v4 = sk_num(&ctx->chain->stack) - 1;
      if ( v4 > v1 )
        break;
    }
LABEL_9:
    if ( --v1 < 0 )
      return 1;
  }
  while ( 1 )
  {
    v5 = (NAME_CONSTRAINTS_st *)*((_DWORD *)sk_value(&ctx->chain->stack, v4) + 19);
    if ( v5 )
    {
      v6 = NAME_CONSTRAINTS_check(v3, v5);
      if ( v6 )
      {
        verify_cb = ctx->verify_cb;
        ctx->error = v6;
        ctx->error_depth = v1;
        ctx->current_cert = v3;
        if ( !verify_cb(0, ctx) )
          return 0;
      }
    }
    if ( --v4 <= v1 )
      goto LABEL_9;
  }
}
