int __cdecl XML_SetElementHandler(int a1, int a2, int a3)
{
  int result; // eax

  *(_DWORD *)(a1 + 52) = a2;
  result = a3;
  *(_DWORD *)(a1 + 56) = a3;
  return result;
}
