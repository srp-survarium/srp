int __cdecl ssl3_release_write_buffer(ssl_st *s)
{
  ssl3_state_st *s3; // eax

  s3 = s->s3;
  if ( s3->wbuf.buf )
  {
    freelist_insert(s->ctx, s3->wbuf.len, (ssl3_buf_freelist_entry_st *)s3->wbuf.buf, 0);
    s->s3->wbuf.buf = 0;
  }
  return 1;
}
