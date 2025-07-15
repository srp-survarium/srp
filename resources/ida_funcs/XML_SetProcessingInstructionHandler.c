int __cdecl XML_SetProcessingInstructionHandler(int a1, int a2)
{
  int result; // eax

  result = a1;
  *(_DWORD *)(a1 + 64) = a2;
  return result;
}
