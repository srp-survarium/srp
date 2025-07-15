int __cdecl sub_50F610(int a1)
{
  int size; // [esp+0h] [ebp-8h]
  unsigned __int8 *dst; // [esp+4h] [ebp-4h]

  size = 2 * *(_DWORD *)(a1 + 52);
  if ( size > 409600 )
    size = 409600;
  if ( *(int *)(a1 + 52) >= 409600 || size - *(_DWORD *)(a1 + 52) < 100 )
    return 72;
  dst = (unsigned __int8 *)pcre_malloc(size);
  if ( !dst )
    return 21;
  memcpy(dst, *(unsigned __int8 **)(a1 + 16), *(_DWORD *)(a1 + 52));
  *(_DWORD *)(a1 + 36) = &dst[*(_DWORD *)(a1 + 36) - *(_DWORD *)(a1 + 16)];
  if ( *(int *)(a1 + 52) > 4096 )
    pcre_free(*(void **)(a1 + 16));
  *(_DWORD *)(a1 + 16) = dst;
  *(_DWORD *)(a1 + 52) = size;
  return 0;
}
