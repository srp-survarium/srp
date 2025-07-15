int __usercall copy_issuer@<eax>(v3_ext_ctx *ctx@<ecx>, stack_st_GENERAL_NAME *gens@<ebx>)
{
  x509_st *issuer_cert; // eax
  int ext_by_NID; // eax
  X509_extension_st *ext; // eax
  const stack_st *v6; // eax
  stack_st *v7; // esi
  int v8; // edi
  char *v9; // eax

  if ( !ctx )
    goto LABEL_14;
  if ( ctx->flags == 1 )
    return 1;
  issuer_cert = ctx->issuer_cert;
  if ( !issuer_cert )
  {
LABEL_14:
    ERR_put_error(0x22u, 123, 127, ".\\crypto\\x509v3\\v3_alt.c", 281);
    return 0;
  }
  ext_by_NID = X509_get_ext_by_NID(issuer_cert, 0x55u, -1);
  if ( ext_by_NID < 0 )
    return 1;
  ext = X509_get_ext(ctx->issuer_cert, ext_by_NID);
  if ( !ext || (v6 = (const stack_st *)X509V3_EXT_d2i(ext), (v7 = (stack_st *)v6) == 0) )
  {
    ERR_put_error(0x22u, 123, 126, ".\\crypto\\x509v3\\v3_alt.c", 288);
    return 0;
  }
  v8 = 0;
  if ( sk_num(v6) <= 0 )
  {
LABEL_10:
    sk_free(v7);
    return 1;
  }
  while ( 1 )
  {
    v9 = sk_value(v7, v8);
    if ( !sk_push(&gens->stack, v9) )
      break;
    if ( ++v8 >= sk_num(v7) )
      goto LABEL_10;
  }
  ERR_put_error(0x22u, 123, 65, ".\\crypto\\x509v3\\v3_alt.c", 295);
  return 0;
}
