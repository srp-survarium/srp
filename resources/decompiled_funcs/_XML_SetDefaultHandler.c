int __cdecl XML_SetDefaultHandler(int a1, int a2)
{
  int result; // eax

  result = a1;
  *(_DWORD *)(a1 + 80) = a2;
  *(_BYTE *)(a1 + 308) = 0;
  return result;
}
