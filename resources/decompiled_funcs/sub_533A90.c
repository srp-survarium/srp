_DWORD *__cdecl sub_533A90(int a1, unsigned int *a2, unsigned int i, _DWORD *a4, int a5)
{
  _DWORD *result; // eax
  _BYTE *j; // [esp+0h] [ebp-8h]
  _BYTE *v7; // [esp+4h] [ebp-4h]

  if ( (int)(i - *a2) > a5 - *a4 )
  {
    for ( i = *a2 + a5 - *a4; i > *a2 && (*(_BYTE *)(i - 1) & 0xC0) == 0x80; --i )
      ;
  }
  v7 = (_BYTE *)*a4;
  for ( j = (_BYTE *)*a2; j != (_BYTE *)i; ++j )
    *v7++ = *j;
  *a2 = (unsigned int)j;
  result = a4;
  *a4 = v7;
  return result;
}
