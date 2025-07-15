int __cdecl XML_SetCommentHandler(int a1, int a2)
{
  int result; // eax

  result = a1;
  *(_DWORD *)(a1 + 68) = a2;
  return result;
}
