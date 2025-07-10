void __cdecl Scaleform::ConstructorMov<Scaleform::Render::Matrix2x4<float>>::ConstructArray(
        char *p,
        unsigned int count)
{
  unsigned int v2; // ecx
  float *v3; // eax

  v2 = count;
  if ( count )
  {
    v3 = (float *)(p + 8);
    do
    {
      if ( v3 != (float *)8 )
      {
        *(v3 - 2) = 1.0;
        v3[3] = 1.0;
        *(v3 - 1) = 0.0;
        *v3 = 0.0;
        v3[1] = 0.0;
        v3[2] = 0.0;
        v3[4] = 0.0;
        v3[5] = 0.0;
      }
      v3 += 8;
      --v2;
    }
    while ( v2 );
  }
}
