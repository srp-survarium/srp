int __cdecl OPENSSL_atomic_add(volatile signed __int32 *a1, int a2)
{
  signed __int32 v2; // eax
  int v3; // ebx
  signed __int32 v4; // ett

  v2 = *a1;
  do
  {
    v3 = v2 + a2;
    v4 = v2;
    v2 = _InterlockedCompareExchange(a1, v2 + a2, v2);
  }
  while ( v4 != v2 );
  return v3;
}
