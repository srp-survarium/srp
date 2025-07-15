int __cdecl XML_SetXmlDeclHandler(int a1, int a2)
{
  int result; // eax

  result = a1;
  *(_DWORD *)(a1 + 140) = a2;
  return result;
}
