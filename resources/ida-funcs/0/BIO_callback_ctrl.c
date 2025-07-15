int __usercall BIO_callback_ctrl@<eax>(
        int a1@<ebx>,
        bio_st *b,
        int cmd,
        void (__cdecl *fp)(bio_st *, int, const char *, int, int, int))
{
  int result; // eax
  int (__cdecl *callback)(bio_st *, int, const char *, int, int, int); // edi

  if ( !b )
    return 0;
  if ( b->method && b->method->callback_ctrl )
  {
    callback = b->callback;
    if ( !callback || (result = callback(b, 6, (const char *)&fp, cmd, 0, 1), result > 0) )
    {
      result = b->method->callback_ctrl(b, cmd, fp);
      if ( callback )
        return callback(b, 134, (const char *)&fp, cmd, 0, result);
    }
  }
  else
  {
    ERR_put_error(a1, 0x20u, 131, 121, ".\\crypto\\bio\\bio_lib.c", 387);
    return -2;
  }
  return result;
}
