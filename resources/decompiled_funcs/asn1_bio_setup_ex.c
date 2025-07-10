int __usercall asn1_bio_setup_ex@<eax>(
        bio_st *b@<edi>,
        BIO_ASN1_BUF_CTX_t *ctx@<esi>,
        int (__cdecl *setup)(bio_st *, unsigned __int8 **, int *, void *),
        asn1_bio_state_t ex_state,
        asn1_bio_state_t other_state)
{
  if ( !setup || setup(b, &ctx->ex_buf, &ctx->ex_len, &ctx->ex_arg) )
  {
    if ( ctx->ex_len <= 0 )
      ctx->state = other_state;
    else
      ctx->state = ex_state;
    return 1;
  }
  else
  {
    BIO_clear_flags(b, 15);
    return 0;
  }
}
