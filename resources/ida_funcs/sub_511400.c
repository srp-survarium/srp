int __cdecl sub_511400(int a1, int a2, int a3)
{
  int result; // eax
  int v4; // [esp+0h] [ebp-4h]

  v4 = a2 - *(_DWORD *)(a3 + 24) - (*(unsigned __int8 *)(a1 + 3) | (*(unsigned __int8 *)(a1 + 2) << 8));
  *(_BYTE *)(a1 + 4) = (unsigned __int16)(a2 - *(_WORD *)(a3 + 24) - _byteswap_ushort(*(_WORD *)(a1 + 2))) >> 8;
  result = a1;
  *(_BYTE *)(a1 + 5) = v4;
  return result;
}
