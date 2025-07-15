void __cdecl png_write_image(int a1, unsigned __int8 **a2)
{
  int i; // [esp+0h] [ebp-10h]
  int v3; // [esp+4h] [ebp-Ch]
  unsigned __int8 **v4; // [esp+8h] [ebp-8h]
  unsigned int v5; // [esp+Ch] [ebp-4h]

  if ( a1 )
  {
    v3 = png_set_interlace_handling(a1);
    for ( i = 0; i < v3; ++i )
    {
      v5 = 0;
      v4 = a2;
      while ( v5 < *(_DWORD *)(a1 + 232) )
      {
        png_write_row(a1, *v4);
        ++v5;
        ++v4;
      }
    }
  }
}
