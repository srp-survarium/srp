int __cdecl png_destroy_read_struct(unsigned __int8 **a1, void **a2, void **a3)
{
  int result; // eax
  void *v4; // [esp+0h] [ebp-14h]
  int v5; // [esp+4h] [ebp-10h]
  unsigned __int8 *src; // [esp+8h] [ebp-Ch]
  int v7; // [esp+Ch] [ebp-8h]
  void *pointer; // [esp+10h] [ebp-4h]

  src = 0;
  pointer = 0;
  v4 = 0;
  if ( a1 )
  {
    result = (int)a1;
    src = *a1;
  }
  if ( src )
  {
    v7 = *((_DWORD *)src + 154);
    v5 = *((_DWORD *)src + 152);
    if ( a2 )
      pointer = *a2;
    if ( a3 )
      v4 = *a3;
    png_read_destroy(src, (int)pointer, (int)v4);
    if ( pointer )
    {
      png_free_data((int)src, (int)pointer, 0x4000, -1);
      png_destroy_struct_2(pointer, v7, v5);
      *a2 = 0;
    }
    if ( v4 )
    {
      png_free_data((int)src, (int)v4, 0x4000, -1);
      png_destroy_struct_2(v4, v7, v5);
      *a3 = 0;
    }
    result = png_destroy_struct_2(src, v7, v5);
    *a1 = 0;
  }
  return result;
}
