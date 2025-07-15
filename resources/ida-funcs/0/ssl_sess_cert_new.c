sess_cert_st *__cdecl ssl_sess_cert_new()
{
  _DWORD *v0; // eax
  _DWORD *v1; // esi

  v0 = CRYPTO_malloc(92, ".\\ssl\\ssl_cert.c", 418);
  v1 = v0;
  if ( v0 )
  {
    memset((int)v0, 0, 0x5Cu);
    v1[2] = v1 + 3;
    v1[22] = 1;
    return (sess_cert_st *)v1;
  }
  else
  {
    ERR_put_error(0x14u, 225, 65, ".\\ssl\\ssl_cert.c", 421);
    return 0;
  }
}
