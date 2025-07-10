unsigned int __cdecl png_do_swap(unsigned int a1, char *a2)
{
  unsigned int result; // eax
  char v3; // [esp+3h] [ebp-Dh]
  unsigned int v4; // [esp+4h] [ebp-Ch]
  unsigned int i; // [esp+Ch] [ebp-4h]

  result = a1;
  if ( *(_BYTE *)(a1 + 9) == 16 )
  {
    result = a1;
    v4 = *(_DWORD *)a1 * *(unsigned __int8 *)(a1 + 10);
    for ( i = 0; i < v4; ++i )
    {
      v3 = *a2;
      *a2 = a2[1];
      a2[1] = v3;
      result = i + 1;
      a2 += 2;
    }
  }
  return result;
}
