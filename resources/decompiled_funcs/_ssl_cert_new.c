cert_st *__cdecl ssl_cert_new()
{
  _DWORD *v0; // eax
  _DWORD *v1; // esi

  v0 = CRYPTO_malloc(116, ".\\ssl\\ssl_cert.c", 167);
  v1 = v0;
  if ( v0 )
  {
    memset((int)v0, 0, 0x74u);
    *v1 = v1 + 12;
    v1[28] = 1;
    return (cert_st *)v1;
  }
  else
  {
    ERR_put_error(0x14u, 162, 65, ".\\ssl\\ssl_cert.c", 170);
    return 0;
  }
}
