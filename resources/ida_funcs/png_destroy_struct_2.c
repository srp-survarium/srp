void __cdecl png_destroy_struct_2(void *pointer, void (__cdecl *a2)(_BYTE *, void *), int a3)
{
  _BYTE v3[608]; // [esp+4h] [ebp-2D0h] BYREF
  int v4; // [esp+264h] [ebp-70h]

  if ( pointer )
  {
    if ( a2 )
    {
      v4 = a3;
      a2(v3, pointer);
    }
    else
    {
      free(pointer);
    }
  }
}
