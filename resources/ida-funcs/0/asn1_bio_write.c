int __usercall asn1_bio_write@<eax>(int a1@<ebx>, bio_st *b, const char *in, int inl)
{
  int v4; // ebp
  BIO_ASN1_BUF_CTX_t *ptr; // esi
  int result; // eax
  asn1_bio_state_t state; // eax
  int v8; // eax
  bool v9; // cc
  int v10; // eax
  bool v11; // zf
  int copylen; // eax
  int v13; // eax
  int v14; // [esp+8h] [ebp-8h]
  unsigned __int8 *buf; // [esp+Ch] [ebp-4h] BYREF

  if ( !in )
    return 0;
  v4 = inl;
  if ( inl < 0 || !b->next_bio )
    return 0;
  ptr = (BIO_ASN1_BUF_CTX_t *)b->ptr;
  if ( !ptr )
    return 0;
  state = ptr->state;
  v14 = 0;
  while ( 2 )
  {
    switch ( state )
    {
      case ASN1_STATE_START:
        if ( !asn1_bio_setup_ex(b, ptr, ptr->prefix, ASN1_STATE_PRE_COPY, ASN1_STATE_HEADER) )
          goto LABEL_29;
        goto LABEL_27;
      case ASN1_STATE_PRE_COPY:
        a1 = asn1_bio_flush_ex(ptr, b, ptr->prefix_free, ASN1_STATE_HEADER);
        if ( a1 <= 0 )
          goto done_4;
        goto LABEL_27;
      case ASN1_STATE_HEADER:
        v8 = ASN1_object_size(0, v4, ptr->asn1_tag) - v4;
        v9 = v8 <= ptr->bufsize;
        ptr->buflen = v8;
        if ( !v9 )
          OpenSSLDie((int)b, (int)ptr, a1, ".\\crypto\\asn1\\bio_asn1.c", 237, "ctx->buflen <= ctx->bufsize");
        buf = ptr->buf;
        ASN1_put_object(&buf, 0, v4, ptr->asn1_tag, ptr->asn1_class);
        ptr->copylen = v4;
        ptr->state = ASN1_STATE_HEADER_COPY;
        goto LABEL_27;
      case ASN1_STATE_HEADER_COPY:
        v10 = BIO_write(a1, b->next_bio, (const char *)&ptr->buf[ptr->bufpos], ptr->buflen);
        a1 = v10;
        if ( v10 <= 0 )
          goto done_4;
        v11 = ptr->buflen == v10;
        ptr->buflen -= v10;
        if ( v11 )
        {
          ptr->bufpos = 0;
          ptr->state = ASN1_STATE_DATA_COPY;
        }
        else
        {
          ptr->bufpos += v10;
        }
LABEL_27:
        state = ptr->state;
        if ( ptr->state > (unsigned int)ASN1_STATE_DATA_COPY )
          goto LABEL_28;
        continue;
      case ASN1_STATE_DATA_COPY:
        copylen = ptr->copylen;
        if ( v4 <= copylen )
          copylen = v4;
        v13 = BIO_write(a1, b->next_bio, in, copylen);
        a1 = v13;
        if ( v13 <= 0 )
          goto LABEL_27;
        ptr->copylen -= v13;
        v14 += v13;
        in += v13;
        v4 -= v13;
        if ( !ptr->copylen )
          ptr->state = ASN1_STATE_HEADER;
        if ( v4 )
          goto LABEL_27;
done_4:
        BIO_clear_flags(b, 15);
        BIO_copy_next_retry(b);
        result = v14;
        if ( v14 <= 0 )
          return a1;
        return result;
      default:
LABEL_28:
        BIO_clear_flags(b, 15);
LABEL_29:
        result = 0;
        break;
    }
    return result;
  }
}
