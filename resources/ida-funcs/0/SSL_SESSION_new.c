ssl_session_st *__usercall SSL_SESSION_new@<eax>(int a1@<ebx>)
{
  _DWORD *v1; // eax
  _DWORD *v2; // esi

  v1 = CRYPTO_malloc(240, ".\\ssl\\ssl_sess.c", 192);
  v2 = v1;
  if ( v1 )
  {
    memset((int)v1, 0, 240);
    v2[40] = 1;
    v2[41] = 1;
    v2[42] = 304;
    v2[43] = _time64(0);
    v2[50] = 0;
    v2[51] = 0;
    v2[44] = 0;
    v2[52] = 0;
    v2[53] = 0;
    v2[54] = 0;
    v2[55] = 0;
    v2[56] = 0;
    CRYPTO_new_ex_data(0, a1);
    v2[35] = 0;
    v2[36] = 0;
    return (ssl_session_st *)v2;
  }
  else
  {
    ERR_put_error(a1, 0x14u, 189, 65, ".\\ssl\\ssl_sess.c", 195);
    return 0;
  }
}
