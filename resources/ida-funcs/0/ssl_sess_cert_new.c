sess_cert_st *__usercall ssl_sess_cert_new@<eax>(int a1@<ebx>)
{
  _DWORD *v1; // eax
  _DWORD *v2; // esi

  v1 = CRYPTO_malloc(92, ".\\ssl\\ssl_cert.c", 418);
  v2 = v1;
  if ( v1 )
  {
    memset((int)v1, 0, 92);
    v2[2] = v2 + 3;
    v2[22] = 1;
    return (sess_cert_st *)v2;
  }
  else
  {
    ERR_put_error(a1, 0x14u, 225, 65, ".\\ssl\\ssl_cert.c", 421);
    return 0;
  }
}
