int __cdecl png_set_sBIT(int a1, int a2, unsigned __int8 *src)
{
  int result; // eax

  if ( a1 )
  {
    if ( a2 )
    {
      memcpy((unsigned __int8 *)(a2 + 68), src, 5u);
      result = *(_DWORD *)(a2 + 8) | 2;
      *(_DWORD *)(a2 + 8) = result;
    }
  }
  return result;
}
