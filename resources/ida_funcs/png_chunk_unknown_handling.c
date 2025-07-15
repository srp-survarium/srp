int __cdecl png_chunk_unknown_handling(int a1, int a2)
{
  unsigned __int8 lhs[8]; // [esp+0h] [ebp-Ch] BYREF

  lhs[0] = HIBYTE(a2);
  lhs[1] = BYTE2(a2);
  lhs[2] = BYTE1(a2);
  lhs[3] = a2;
  lhs[4] = 0;
  return png_handle_as_unknown(a1, lhs);
}
