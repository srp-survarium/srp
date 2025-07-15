int __cdecl sub_3624D0(int a1)
{
  int result; // eax
  void *v2; // [esp+0h] [ebp-Ch]
  void *v3; // [esp+4h] [ebp-8h]
  void *pointer; // [esp+8h] [ebp-4h]

  result = a1;
  *(_BYTE *)(a1 + 517) = 0;
  *(_BYTE *)(a1 + 516) = 1;
  if ( *(_DWORD *)(a1 + 520) )
  {
    pointer = *(void **)(a1 + 520);
    *(_DWORD *)(a1 + 520) = 0;
    result = png_free(a1, pointer);
  }
  if ( *(_DWORD *)(a1 + 524) )
  {
    v3 = *(void **)(a1 + 524);
    *(_DWORD *)(a1 + 524) = 0;
    result = png_free(a1, v3);
  }
  if ( *(_DWORD *)(a1 + 528) )
  {
    v2 = *(void **)(a1 + 528);
    *(_DWORD *)(a1 + 528) = 0;
    return png_free(a1, v2);
  }
  return result;
}
