void __usercall crl_akid_check(x509_store_ctx_st *ctx@<esi>, X509_crl_st *crl, x509_st **pissuer, int *pcrl_score)
{
  X509_name_st *issuer; // ebp
  int error_depth; // edi
  x509_st *v6; // ebx
  int v7; // edi
  x509_st *v8; // ebx
  const X509_name_st *v9; // eax
  int v10; // ebx
  x509_st *v11; // edi
  const X509_name_st *subject_name; // eax

  issuer = crl->crl->issuer;
  error_depth = ctx->error_depth;
  if ( error_depth != sk_num(&ctx->chain->stack) - 1 )
    ++error_depth;
  v6 = (x509_st *)sk_value(&ctx->chain->stack, error_depth);
  if ( X509_check_akid(v6, crl->akid) || (*pcrl_score & 0x20) == 0 )
  {
    v7 = error_depth + 1;
    if ( v7 >= sk_num(&ctx->chain->stack) )
    {
LABEL_10:
      if ( (ctx->param->flags & 0x1000) != 0 )
      {
        v10 = 0;
        if ( sk_num(&ctx->untrusted->stack) > 0 )
        {
          while ( 1 )
          {
            v11 = (x509_st *)sk_value(&ctx->untrusted->stack, v10);
            subject_name = X509_get_subject_name(v11);
            if ( !X509_NAME_cmp(subject_name, issuer) && !X509_check_akid(v11, crl->akid) )
              break;
            if ( ++v10 >= sk_num(&ctx->untrusted->stack) )
              return;
          }
          *pissuer = v11;
          *pcrl_score |= 4u;
        }
      }
    }
    else
    {
      while ( 1 )
      {
        v8 = (x509_st *)sk_value(&ctx->chain->stack, v7);
        v9 = X509_get_subject_name(v8);
        if ( !X509_NAME_cmp(v9, issuer) && !X509_check_akid(v8, crl->akid) )
          break;
        if ( ++v7 >= sk_num(&ctx->chain->stack) )
          goto LABEL_10;
      }
      *pcrl_score |= 0xCu;
      *pissuer = v8;
    }
  }
  else
  {
    *pcrl_score |= 0x1Cu;
    *pissuer = v6;
  }
}
