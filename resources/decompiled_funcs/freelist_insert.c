void __usercall freelist_insert(
        ssl_ctx_st *ctx@<ebx>,
        unsigned int sz@<edi>,
        ssl3_buf_freelist_entry_st *mem@<ecx>,
        int for_read)
{
  ssl3_buf_freelist_st *rbuf_freelist; // eax
  ssl3_buf_freelist_entry_st *head; // edx

  CRYPTO_lock(sz, 9, 12, ".\\ssl\\s3_both.c", 678);
  if ( for_read )
    rbuf_freelist = ctx->rbuf_freelist;
  else
    rbuf_freelist = ctx->wbuf_freelist;
  if ( rbuf_freelist
    && (sz == rbuf_freelist->chunklen || !rbuf_freelist->chunklen)
    && rbuf_freelist->len < ctx->freelist_max_len
    && sz >= 4 )
  {
    head = rbuf_freelist->head;
    rbuf_freelist->chunklen = sz;
    mem->next = head;
    ++rbuf_freelist->len;
    rbuf_freelist->head = mem;
    mem = 0;
  }
  CRYPTO_lock(sz, 10, 12, ".\\ssl\\s3_both.c", 693);
  if ( mem )
    CRYPTO_free(mem);
}
