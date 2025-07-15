void __usercall ssl2_write_error(int a1@<ebx>, ssl_st *s)
{
  char error_code; // cl
  unsigned int error; // edi
  int v4; // eax
  int v5; // eax
  int v6; // edi
  void (__cdecl *msg_callback)(int, int, int, const void *, unsigned int, ssl_st *, void *); // eax
  _BYTE v8[3]; // [esp+8h] [ebp-4h] BYREF
  char v9; // [esp+Bh] [ebp-1h] BYREF

  error_code = s->error_code;
  error = s->error;
  v4 = s->error_code >> 8;
  v8[0] = 0;
  v8[1] = v4;
  v8[2] = error_code;
  s->error = 0;
  if ( error > 3 )
    OpenSSLDie(error, (int)s, a1, ".\\ssl\\s2_lib.c", 528, "error >= 0 && error <= (int)sizeof(buf)");
  v5 = ssl2_write(s, (unsigned __int8 *)&v9 - error, error);
  if ( v5 >= 0 )
  {
    v6 = error - v5;
    s->error = v6;
    if ( !v6 )
    {
      msg_callback = s->msg_callback;
      if ( msg_callback )
        msg_callback(1, s->version, 0, v8, 3u, s, s->msg_callback_arg);
    }
  }
  else
  {
    s->error = error;
  }
}
