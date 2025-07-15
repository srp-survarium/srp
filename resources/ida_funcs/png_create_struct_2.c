unsigned __int8 *__cdecl png_create_struct_2(int a1, int (__cdecl *a2)(_BYTE *, unsigned int), int a3)
{
  _BYTE v4[608]; // [esp+4h] [ebp-2D8h] BYREF
  int v5; // [esp+264h] [ebp-78h]
  unsigned int count; // [esp+2D4h] [ebp-8h]
  unsigned __int8 *dst; // [esp+2D8h] [ebp-4h]

  if ( a1 == 2 )
  {
    count = 236;
  }
  else
  {
    if ( a1 != 1 )
      return 0;
    count = 708;
  }
  if ( a2 )
  {
    v5 = a3;
    dst = (unsigned __int8 *)a2(v4, count);
    if ( dst )
      memset((int)dst, 0, count);
    return dst;
  }
  else
  {
    dst = (unsigned __int8 *)malloc(count);
    if ( dst )
      memset((int)dst, 0, count);
    return dst;
  }
}
