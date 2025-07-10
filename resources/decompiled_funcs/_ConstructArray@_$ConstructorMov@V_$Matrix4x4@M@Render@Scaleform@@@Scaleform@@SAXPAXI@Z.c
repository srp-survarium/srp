void __cdecl Scaleform::ConstructorMov<Scaleform::Render::Matrix4x4<float>>::ConstructArray(
        float *p,
        unsigned int count)
{
  unsigned int v3; // edi

  if ( count )
  {
    v3 = count;
    do
    {
      if ( p )
      {
        memset((int)p, 0, 0x40u);
        *p = 1.0;
        p[5] = 1.0;
        p[10] = 1.0;
        p[15] = 1.0;
      }
      p += 16;
      --v3;
    }
    while ( v3 );
  }
}
