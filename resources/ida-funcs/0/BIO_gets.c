int __usercall BIO_gets@<eax>(int a1@<ebx>, bio_st *b, char *in, int inl)
{
  int (__cdecl *callback)(bio_st *, int, const char *, int, int, int); // edi
  int result; // eax

  if ( b && b->method && b->method->bgets )
  {
    callback = b->callback;
    if ( !callback || (result = callback(b, 5, in, inl, 0, 1), result > 0) )
    {
      if ( b->init )
      {
        result = b->method->bgets(b, in, inl);
        if ( callback )
          return callback(b, 133, in, inl, 0, result);
      }
      else
      {
        ERR_put_error(inl, 0x20u, 104, 120, ".\\crypto\\bio\\bio_lib.c", 309);
        return -2;
      }
    }
  }
  else
  {
    ERR_put_error(a1, 0x20u, 104, 121, ".\\crypto\\bio\\bio_lib.c", 297);
    return -2;
  }
  return result;
}
