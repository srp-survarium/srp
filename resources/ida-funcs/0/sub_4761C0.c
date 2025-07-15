int __cdecl sub_4761C0(int a1, int a2)
{
  int result; // eax
  unsigned int v3; // [esp+0h] [ebp-10h]
  _BYTE *v4; // [esp+4h] [ebp-Ch]
  unsigned int i; // [esp+8h] [ebp-8h]
  int v6; // [esp+Ch] [ebp-4h]

  v3 = *(_DWORD *)(a1 + 4);
  result = (*(unsigned __int8 *)(a1 + 11) + 7) >> 3;
  v6 = result;
  v4 = (_BYTE *)(result + a2);
  for ( i = result; i < v3; ++i )
  {
    *v4 += v4[-v6];
    ++v4;
    result = i + 1;
  }
  return result;
}
