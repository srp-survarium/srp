int __cdecl XML_SetDoctypeDeclHandler(int a1, int a2, int a3)
{
  int result; // eax

  *(_DWORD *)(a1 + 84) = a2;
  result = a3;
  *(_DWORD *)(a1 + 88) = a3;
  return result;
}
