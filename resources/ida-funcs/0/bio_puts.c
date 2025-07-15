int __cdecl BIO_puts(bio_st *b, const char *in)
{
  int (__cdecl *callback)(bio_st *, int, const char *, int, int, int); // edi
  int result; // eax

  if ( b && b->method && b->method->bputs )
  {
    callback = b->callback;
    if ( !callback || (result = callback(b, 4, in, 0, 0, 1), result > 0) )
    {
      if ( b->init )
      {
        result = b->method->bputs(b, in);
        if ( result > 0 )
          b->num_write += result;
        if ( callback )
          return callback(b, 132, in, 0, 0, result);
      }
      else
      {
        ERR_put_error(0x20u, 110, 120, ".\\crypto\\bio\\bio_lib.c", 276);
        return -2;
      }
    }
  }
  else
  {
    ERR_put_error(0x20u, 110, 121, ".\\crypto\\bio\\bio_lib.c", 264);
    return -2;
  }
  return result;
}
