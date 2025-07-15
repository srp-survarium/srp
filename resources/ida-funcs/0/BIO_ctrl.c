int __usercall BIO_ctrl@<eax>(int a1@<ebx>, bio_st *b, int cmd, int larg, void *parg)
{
  int result; // eax
  int (__cdecl *callback)(bio_st *, int, const char *, int, int, int); // edi

  if ( !b )
    return 0;
  if ( b->method && b->method->ctrl )
  {
    callback = b->callback;
    if ( !callback || (result = callback(b, 6, (const char *)parg, cmd, larg, 1), result > 0) )
    {
      result = b->method->ctrl(b, cmd, larg, parg);
      if ( callback )
        return callback(b, 134, (const char *)parg, cmd, larg, result);
    }
  }
  else
  {
    ERR_put_error(a1, 0x20u, 103, 121, ".\\crypto\\bio\\bio_lib.c", 360);
    return -2;
  }
  return result;
}
