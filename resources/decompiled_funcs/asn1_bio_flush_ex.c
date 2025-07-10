int __usercall asn1_bio_flush_ex@<eax>(
        BIO_ASN1_BUF_CTX_t *ctx@<esi>,
        bio_st *b,
        int (__cdecl *cleanup)(bio_st *, unsigned __int8 **, int *, void *),
        asn1_bio_state_t next)
{
  int ex_len; // eax
  int *p_ex_len; // ebx
  int result; // eax
  int v7; // edi

  ex_len = ctx->ex_len;
  p_ex_len = &ctx->ex_len;
  if ( ex_len <= 0 )
    return 1;
  v7 = BIO_write(b->next_bio, (const char *)&ctx->ex_buf[ctx->ex_pos], ex_len);
  if ( v7 > 0 )
  {
    while ( 1 )
    {
      *p_ex_len -= v7;
      if ( *p_ex_len <= 0 )
        break;
      ctx->ex_pos += v7;
      result = BIO_write(b->next_bio, (const char *)&ctx->ex_buf[ctx->ex_pos], *p_ex_len);
      v7 = result;
      if ( result <= 0 )
        return result;
    }
    if ( cleanup )
      cleanup(b, &ctx->ex_buf, &ctx->ex_len, &ctx->ex_arg);
    ctx->state = next;
    ctx->ex_pos = 0;
  }
  return v7;
}
