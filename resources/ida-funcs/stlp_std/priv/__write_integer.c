char *__cdecl stlp_std::priv::__write_integer(char *buf, __int16 flags, int x)
{
  char *v3; // eax
  char *v4; // esi
  int v5; // eax
  char __buf[4]; // [esp+48h] [ebp-4h] BYREF

  v3 = stlp_std::priv::__write_integer_backward<long>(__buf, flags, x);
  v4 = (char *)(__buf - v3);
  if ( __buf == v3 )
    return buf;
  memmove((unsigned __int8 *)buf, (unsigned __int8 *)v3, __buf - v3);
  return &v4[v5];
}
