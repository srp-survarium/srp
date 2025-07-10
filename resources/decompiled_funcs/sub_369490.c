int __cdecl sub_369490(int a1)
{
  int result; // eax
  int v2; // [esp+0h] [ebp-4h]

  v2 = (*(unsigned __int8 *)(a1 + 318) + 7) >> 3;
  *(_DWORD *)(a1 + 692) = sub_369500;
  result = a1;
  *(_DWORD *)(a1 + 696) = sub_369570;
  *(_DWORD *)(a1 + 700) = sub_3695E0;
  if ( v2 == 1 )
  {
    *(_DWORD *)(a1 + 704) = sub_3696C0;
  }
  else
  {
    result = a1;
    *(_DWORD *)(a1 + 704) = sub_3697F0;
  }
  return result;
}
