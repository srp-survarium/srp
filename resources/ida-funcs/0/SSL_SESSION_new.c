ssl_session_st *__cdecl SSL_SESSION_new()
{
  _DWORD *v0; // eax
  _DWORD *v1; // esi

  v0 = CRYPTO_malloc(240, ".\\ssl\\ssl_sess.c", 192);
  v1 = v0;
  if ( v0 )
  {
    memset((int)v0, 0, 0xF0u);
    v1[40] = 1;
    v1[41] = 1;
    v1[42] = 304;
    v1[43] = _time64(0);
    v1[50] = 0;
    v1[51] = 0;
    v1[44] = 0;
    v1[52] = 0;
    v1[53] = 0;
    v1[54] = 0;
    v1[55] = 0;
    v1[56] = 0;
    CRYPTO_new_ex_data(0);
    v1[35] = 0;
    v1[36] = 0;
    return (ssl_session_st *)v1;
  }
  else
  {
    ERR_put_error(0x14u, 189, 65, ".\\ssl\\ssl_sess.c", 195);
    return 0;
  }
}
