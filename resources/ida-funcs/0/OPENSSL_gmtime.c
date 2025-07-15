tm *__usercall OPENSSL_gmtime@<eax>(unsigned int a1@<ebx>, const __int64 *timer, tm *result)
{
  tm *v3; // eax
  tm *v4; // esi

  v3 = _gmtime64(a1, timer);
  if ( v3 )
  {
    v4 = v3;
    v3 = result;
    qmemcpy(result, v4, sizeof(tm));
  }
  return v3;
}
