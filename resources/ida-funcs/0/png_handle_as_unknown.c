int __cdecl png_handle_as_unknown(int a1, unsigned __int8 *a2)
{
  unsigned int v3; // [esp+0h] [ebp-8h]
  unsigned __int8 *v4; // [esp+4h] [ebp-4h]

  if ( !a1 || !a2 || *(int *)(a1 + 584) <= 0 )
    return 0;
  v3 = *(_DWORD *)(a1 + 588);
  v4 = (unsigned __int8 *)(v3 + 5 * *(_DWORD *)(a1 + 584));
  do
  {
    v4 -= 5;
    if ( !memcmp(a2, v4, 4u) )
      return v4[4];
  }
  while ( (unsigned int)v4 > v3 );
  return 0;
}
