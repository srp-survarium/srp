void __cdecl ssl3_cleanup_key_block(ssl_st *s)
{
  ssl3_state_st *s3; // eax

  s3 = s->s3;
  if ( s3->tmp.key_block )
  {
    OPENSSL_cleanse(s3->tmp.key_block, s3->tmp.key_block_length);
    CRYPTO_free(s->s3->tmp.key_block);
    s->s3->tmp.key_block = 0;
    s->s3->tmp.key_block_length = 0;
  }
  else
  {
    s3->tmp.key_block_length = 0;
  }
}
