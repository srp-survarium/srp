int __cdecl png_handle_as_unknown(int a1, unsigned __int8 *lhs)
{
  unsigned int v3; // [esp+0h] [ebp-8h]
  unsigned __int8 *rhs; // [esp+4h] [ebp-4h]

  if ( !a1 || !lhs || *(int *)(a1 + 584) <= 0 )
    return 0;
  v3 = *(_DWORD *)(a1 + 588);
  rhs = (unsigned __int8 *)(v3 + 5 * *(_DWORD *)(a1 + 584));
  do
  {
    rhs -= 5;
    if ( !memcmp(lhs, rhs, 4u) )
      return rhs[4];
  }
  while ( (unsigned int)rhs > v3 );
  return 0;
}
