void *__cdecl png_create_struct_2(int a1, int (__cdecl *a2)(_BYTE *, unsigned int), int a3)
{
  _BYTE v4[608]; // [esp+4h] [ebp-2D8h] BYREF
  int v5; // [esp+264h] [ebp-78h]
  unsigned int size; // [esp+2D4h] [ebp-8h]
  void *v7; // [esp+2D8h] [ebp-4h]

  if ( a1 == 2 )
  {
    size = 236;
  }
  else
  {
    if ( a1 != 1 )
      return 0;
    size = 708;
  }
  if ( a2 )
  {
    v5 = a3;
    v7 = (void *)a2(v4, size);
    if ( v7 )
      memset((int)v7, 0, size);
    return v7;
  }
  else
  {
    v7 = malloc(size);
    if ( v7 )
      memset((int)v7, 0, size);
    return v7;
  }
}
