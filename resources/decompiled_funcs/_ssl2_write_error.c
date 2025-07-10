void __cdecl ssl2_write_error(ssl_st *s)
{
  char error_code; // cl
  unsigned int error; // edi
  int v3; // eax
  int v4; // eax
  int v5; // edi
  void (__cdecl *msg_callback)(int, int, int, const void *, unsigned int, ssl_st *, void *); // eax
  _BYTE v7[3]; // [esp+8h] [ebp-4h] BYREF
  char v8; // [esp+Bh] [ebp-1h] BYREF

  error_code = s->error_code;
  error = s->error;
  v3 = s->error_code >> 8;
  v7[0] = 0;
  v7[1] = v3;
  v7[2] = error_code;
  s->error = 0;
  if ( error > 3 )
    OpenSSLDie(error, (unsigned int)s, ".\\ssl\\s2_lib.c", 528, "error >= 0 && error <= (int)sizeof(buf)");
  v4 = ssl2_write(s, &v8 - error, error);
  if ( v4 >= 0 )
  {
    v5 = error - v4;
    s->error = v5;
    if ( !v5 )
    {
      msg_callback = s->msg_callback;
      if ( msg_callback )
        msg_callback(1, s->version, 0, v7, 3u, s, s->msg_callback_arg);
    }
  }
  else
  {
    s->error = error;
  }
}
