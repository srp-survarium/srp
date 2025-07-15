int __cdecl ssl3_release_read_buffer(ssl_st *s)
{
  ssl3_state_st *s3; // eax

  s3 = s->s3;
  if ( s3->rbuf.buf )
  {
    freelist_insert(s->ctx, s3->rbuf.len, (ssl3_buf_freelist_entry_st *)s3->rbuf.buf, 1);
    s->s3->rbuf.buf = 0;
  }
  return 1;
}
