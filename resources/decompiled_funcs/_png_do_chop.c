int __cdecl png_do_chop(int a1, _BYTE *a2)
{
  int result; // eax
  unsigned int v3; // [esp+0h] [ebp-Ch]
  _BYTE *v4; // [esp+4h] [ebp-8h]
  _BYTE *v5; // [esp+8h] [ebp-4h]

  result = a1;
  if ( *(_BYTE *)(a1 + 9) == 16 )
  {
    v5 = a2;
    v4 = a2;
    v3 = (unsigned int)&a2[*(_DWORD *)(a1 + 4)];
    while ( (unsigned int)v5 < v3 )
    {
      *v4++ = *v5;
      v5 += 2;
    }
    *(_BYTE *)(a1 + 9) = 8;
    *(_BYTE *)(a1 + 11) = 8 * *(_BYTE *)(a1 + 10);
    result = a1;
    *(_DWORD *)(a1 + 4) = *(_DWORD *)a1 * *(unsigned __int8 *)(a1 + 10);
  }
  return result;
}
