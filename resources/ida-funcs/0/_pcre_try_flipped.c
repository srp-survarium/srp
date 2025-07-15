int __cdecl _pcre_try_flipped(_DWORD *a1, int a2, _DWORD *a3, _DWORD *a4)
{
  if ( sub_63F540(*a1, 4) != 1346589253 )
    return 0;
  qmemcpy((void *)a2, a1, 0x28u);
  *(_DWORD *)(a2 + 4) = sub_63F540(a1[1], 4);
  *(_DWORD *)(a2 + 8) = sub_63F540(a1[2], 4);
  *(_WORD *)(a2 + 12) = sub_63F540(*((unsigned __int16 *)a1 + 6), 2);
  *(_WORD *)(a2 + 16) = sub_63F540(*((unsigned __int16 *)a1 + 8), 2);
  *(_WORD *)(a2 + 18) = sub_63F540(*((unsigned __int16 *)a1 + 9), 2);
  *(_WORD *)(a2 + 20) = sub_63F540(*((unsigned __int16 *)a1 + 10), 2);
  *(_WORD *)(a2 + 22) = sub_63F540(*((unsigned __int16 *)a1 + 11), 2);
  *(_WORD *)(a2 + 24) = sub_63F540(*((unsigned __int16 *)a1 + 12), 2);
  *(_WORD *)(a2 + 26) = sub_63F540(*((unsigned __int16 *)a1 + 13), 2);
  *(_WORD *)(a2 + 28) = sub_63F540(*((unsigned __int16 *)a1 + 14), 2);
  if ( a3 )
  {
    qmemcpy(a4, a3, 0x2Cu);
    *a4 = sub_63F540(*a3, 4);
    a4[1] = sub_63F540(a3[1], 4);
    a4[10] = sub_63F540(a3[10], 4);
  }
  return a2;
}
