int __cdecl XML_SetCharacterDataHandler(int a1, int a2)
{
  int result; // eax

  result = a1;
  *(_DWORD *)(a1 + 60) = a2;
  return result;
}
