int __cdecl ssl3_new(ssl_st *s)
{
  int result; // eax
  int v2; // esi
  const ssl_method_st *method; // ecx

  result = (int)CRYPTO_malloc(1052, ".\\ssl\\s3_lib.c", 2124);
  v2 = result;
  if ( result )
  {
    memset(result, 0, 1052);
    *(_DWORD *)(v2 + 296) = 0;
    *(_DWORD *)(v2 + 300) = 0;
    *(_DWORD *)(v2 + 332) = 0;
    *(_DWORD *)(v2 + 336) = 0;
    method = s->method;
    s->s3 = (ssl3_state_st *)v2;
    method->ssl_clear(s);
    return 1;
  }
  return result;
}
