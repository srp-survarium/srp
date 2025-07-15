char *__cdecl stlp_std::priv::__write_integer(char *buf, __int16 flags, int x)
{
  char *v3; // eax
  char *v4; // esi
  int v5; // eax
  int v7; // [esp+48h] [ebp-4h] BYREF

  v3 = stlp_std::priv::__write_integer_backward<long>((char *)&v7, flags, x);
  v4 = (char *)((char *)&v7 - v3);
  if ( &v7 == (int *)v3 )
    return buf;
  memmove((unsigned __int8 *)buf, (unsigned __int8 *)v3, (char *)&v7 - v3);
  return &v4[v5];
}
