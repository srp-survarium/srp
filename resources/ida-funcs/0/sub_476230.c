_BYTE *__cdecl sub_476230(int a1, _BYTE *a2, _BYTE *a3)
{
  _BYTE *result; // eax
  unsigned int v4; // [esp+0h] [ebp-10h]
  _BYTE *v6; // [esp+8h] [ebp-8h]
  unsigned int i; // [esp+Ch] [ebp-4h]

  v4 = *(_DWORD *)(a1 + 4);
  result = a3;
  v6 = a3;
  for ( i = 0; i < v4; ++i )
  {
    *a2 += *v6;
    result = ++v6;
    ++a2;
  }
  return result;
}
