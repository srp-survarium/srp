unsigned __int8 *__cdecl png_calloc(int a1, unsigned int count)
{
  unsigned __int8 *dst; // [esp+0h] [ebp-4h]

  dst = (unsigned __int8 *)png_malloc(a1, count);
  if ( dst )
    memset((int)dst, 0, count);
  return dst;
}
