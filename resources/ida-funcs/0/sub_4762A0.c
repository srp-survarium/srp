int __cdecl sub_4762A0(int a1, _BYTE *a2, unsigned __int8 *a3)
{
  int result; // eax
  unsigned int v4; // [esp+0h] [ebp-14h]
  unsigned int i; // [esp+Ch] [ebp-8h]
  unsigned int j; // [esp+Ch] [ebp-8h]
  unsigned int v9; // [esp+10h] [ebp-4h]

  result = (*(unsigned __int8 *)(a1 + 11) + 7) >> 3;
  v9 = result;
  v4 = *(_DWORD *)(a1 + 4) - result;
  for ( i = 0; i < v9; ++i )
  {
    *a2++ += *a3++ / 2;
    result = i + 1;
  }
  for ( j = 0; j < v4; ++j )
  {
    *a2 += ((unsigned __int8)a2[-v9] + *a3++) / 2;
    ++a2;
    result = j + 1;
  }
  return result;
}
