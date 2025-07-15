int __cdecl png_chunk_unknown_handling(int a1, int a2)
{
  unsigned __int8 v3[8]; // [esp+0h] [ebp-Ch] BYREF

  v3[0] = HIBYTE(a2);
  v3[1] = BYTE2(a2);
  v3[2] = BYTE1(a2);
  v3[3] = a2;
  v3[4] = 0;
  return png_handle_as_unknown(a1, v3);
}
