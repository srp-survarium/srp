int __cdecl sub_476150(int a1)
{
  int result; // eax
  int v2; // [esp+0h] [ebp-4h]

  v2 = (*(unsigned __int8 *)(a1 + 318) + 7) >> 3;
  *(_DWORD *)(a1 + 692) = sub_4761C0;
  result = a1;
  *(_DWORD *)(a1 + 696) = sub_476230;
  *(_DWORD *)(a1 + 700) = sub_4762A0;
  if ( v2 == 1 )
  {
    *(_DWORD *)(a1 + 704) = sub_476380;
  }
  else
  {
    result = a1;
    *(_DWORD *)(a1 + 704) = sub_4764B0;
  }
  return result;
}
