int __cdecl BIO_write(bio_st *b, const char *in, int inl)
{
  int result; // eax
  int (__cdecl *callback)(bio_st *, int, const char *, int, int, int); // edi

  if ( !b )
    return 0;
  callback = b->callback;
  if ( b->method && b->method->bwrite )
  {
    if ( !callback || (result = callback(b, 3, in, inl, 0, 1), result > 0) )
    {
      if ( b->init )
      {
        result = b->method->bwrite(b, in, inl);
        if ( result > 0 )
          b->num_write += result;
        if ( callback )
          return callback(b, 131, in, inl, 0, result);
      }
      else
      {
        ERR_put_error(0x20u, 113, 120, ".\\crypto\\bio\\bio_lib.c", 243);
        return -2;
      }
    }
  }
  else
  {
    ERR_put_error(0x20u, 113, 121, ".\\crypto\\bio\\bio_lib.c", 233);
    return -2;
  }
  return result;
}
