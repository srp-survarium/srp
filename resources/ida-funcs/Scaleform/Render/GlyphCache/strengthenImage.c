void __thiscall Scaleform::Render::GlyphCache::strengthenImage(
        Scaleform::Render::GlyphCache *this,
        unsigned __int8 *img,
        unsigned int pitch,
        unsigned int sx,
        unsigned int sy,
        unsigned int w,
        unsigned int h,
        float ratio,
        int bias)
{
  double v9; // st7
  unsigned __int8 *v10; // edi
  unsigned int v11; // ebx
  unsigned __int8 *i; // esi
  int v13; // eax
  unsigned int v14; // [esp+1Ch] [ebp+1Ch]

  v9 = ratio;
  if ( ratio != 1.0 && h )
  {
    v14 = h;
    v10 = &img[sy * pitch + sx];
    do
    {
      v11 = w;
      for ( i = v10; v11; --v11 )
      {
        v13 = bias + (int)((double)(*i - bias) * v9 + 0.5);
        if ( v13 >= 0 )
        {
          if ( v13 > 255 )
            LOBYTE(v13) = -1;
        }
        else
        {
          LOBYTE(v13) = 0;
        }
        *i++ = v13;
      }
      v10 += pitch;
      --v14;
    }
    while ( v14 );
  }
}
