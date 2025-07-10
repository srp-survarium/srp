int __cdecl BIO_read(bio_st *b, char *out, int outl)
{
  int (__cdecl *callback)(bio_st *, int, const char *, int, int, int); // edi
  int result; // eax

  if ( b && b->method && b->method->bread )
  {
    callback = b->callback;
    if ( !callback || (result = callback(b, 2, out, outl, 0, 1), result > 0) )
    {
      if ( b->init )
      {
        result = b->method->bread(b, out, outl);
        if ( result > 0 )
          b->num_read += result;
        if ( callback )
          return callback(b, 130, out, outl, 0, result);
      }
      else
      {
        ERR_put_error(0x20u, 111, 120, ".\\crypto\\bio\\bio_lib.c", 208);
        return -2;
      }
    }
  }
  else
  {
    ERR_put_error(0x20u, 111, 121, ".\\crypto\\bio\\bio_lib.c", 197);
    return -2;
  }
  return result;
}
