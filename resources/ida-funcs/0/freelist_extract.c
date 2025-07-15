ssl3_buf_freelist_entry_st *__usercall freelist_extract@<eax>(ssl_ctx_st *ctx@<edi>, int sz@<ebx>, int for_read)
{
  ssl3_buf_freelist_entry_st *v3; // esi
  ssl3_buf_freelist_st *rbuf_freelist; // eax
  ssl3_buf_freelist_entry_st *head; // ecx
  ssl3_buf_freelist_entry_st *next; // edx
  bool v7; // zf

  v3 = 0;
  CRYPTO_lock((int)ctx, sz, 9, 12, ".\\ssl\\s3_both.c", 655);
  if ( for_read )
    rbuf_freelist = ctx->rbuf_freelist;
  else
    rbuf_freelist = ctx->wbuf_freelist;
  if ( rbuf_freelist )
  {
    if ( sz == rbuf_freelist->chunklen )
    {
      head = rbuf_freelist->head;
      if ( head )
      {
        next = head->next;
        v7 = rbuf_freelist->len-- == 1;
        rbuf_freelist->head = next;
        v3 = head;
        if ( v7 )
          rbuf_freelist->chunklen = 0;
      }
    }
  }
  CRYPTO_lock((int)ctx, sz, 10, 12, ".\\ssl\\s3_both.c", 666);
  if ( v3 )
    return v3;
  else
    return (ssl3_buf_freelist_entry_st *)CRYPTO_malloc(sz, ".\\ssl\\s3_both.c", 668);
}
