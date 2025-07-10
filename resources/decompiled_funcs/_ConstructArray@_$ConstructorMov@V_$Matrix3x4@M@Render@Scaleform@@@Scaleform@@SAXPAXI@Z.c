void __cdecl Scaleform::ConstructorMov<Scaleform::Render::Matrix3x4<float>>::ConstructArray(
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
        memset((int)p, 0, 0x30u);
        *p = 1.0;
        p[5] = 1.0;
        p[10] = 1.0;
      }
      p += 12;
      --v3;
    }
    while ( v3 );
  }
}
