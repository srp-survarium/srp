cert_st *__usercall ssl_cert_new@<eax>(int a1@<ebx>)
{
  _DWORD *v1; // eax
  _DWORD *v2; // esi

  v1 = CRYPTO_malloc(116, ".\\ssl\\ssl_cert.c", 167);
  v2 = v1;
  if ( v1 )
  {
    memset((int)v1, 0, 116);
    *v2 = v2 + 12;
    v2[28] = 1;
    return (cert_st *)v2;
  }
  else
  {
    ERR_put_error(a1, 0x14u, 162, 65, ".\\ssl\\ssl_cert.c", 170);
    return 0;
  }
}
