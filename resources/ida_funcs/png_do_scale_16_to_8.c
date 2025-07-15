int __cdecl png_do_scale_16_to_8(int a1, unsigned __int8 *a2)
{
  int result; // eax
  int v3; // [esp+0h] [ebp-10h]
  int v4; // [esp+0h] [ebp-10h]
  unsigned int v5; // [esp+4h] [ebp-Ch]
  unsigned __int8 *v6; // [esp+8h] [ebp-8h]
  unsigned __int8 *v7; // [esp+Ch] [ebp-4h]
  unsigned __int8 *v8; // [esp+Ch] [ebp-4h]

  result = a1;
  if ( *(_BYTE *)(a1 + 9) == 16 )
  {
    v7 = a2;
    v6 = a2;
    v5 = (unsigned int)&a2[*(_DWORD *)(a1 + 4)];
    while ( (unsigned int)v7 < v5 )
    {
      v3 = *v7;
      v8 = v7 + 1;
      v4 = v3 + ((0xFFFF * (*v8 - v3 + 128)) >> 24);
      v7 = v8 + 1;
      *v6++ = v4;
    }
    *(_BYTE *)(a1 + 9) = 8;
    *(_BYTE *)(a1 + 11) = 8 * *(_BYTE *)(a1 + 10);
    result = *(_DWORD *)a1 * *(unsigned __int8 *)(a1 + 10);
    *(_DWORD *)(a1 + 4) = result;
  }
  return result;
}
