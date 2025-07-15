int __cdecl cpy_asc(char value, _DWORD *arg)
{
  *(_BYTE *)(*arg)++ = value;
  return 1;
}
