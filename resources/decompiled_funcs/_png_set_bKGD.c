int __cdecl png_set_bKGD(int a1, int a2, unsigned __int8 *src)
{
  int result; // eax

  if ( a1 )
  {
    if ( a2 )
    {
      memcpy((unsigned __int8 *)(a2 + 90), src, 0xAu);
      result = *(_DWORD *)(a2 + 8) | 0x20;
      *(_DWORD *)(a2 + 8) = result;
    }
  }
  return result;
}
