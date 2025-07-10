_BYTE *__thiscall FindCompleteObject(void **inptr)
{
  int v1; // edx
  _BYTE *result; // eax
  int v3; // edx

  v1 = *((_DWORD *)*inptr - 1);
  result = (char *)inptr - *(_DWORD *)(v1 + 4);
  v3 = *(_DWORD *)(v1 + 8);
  if ( v3 )
    result -= *(unsigned int *)((char *)inptr - v3);
  return result;
}
