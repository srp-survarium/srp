char __thiscall Scaleform::Render::ColorMatrixFilter::IsContributing(Scaleform::Render::ColorMatrixFilter *this)
{
  unsigned int v1; // eax
  float *v2; // edx
  float *i; // ecx

  v1 = 80;
  v2 = ColorMatrix_Identity;
  for ( i = this->MatrixData; *(_DWORD *)i == *(_DWORD *)v2; ++i )
  {
    v1 -= 4;
    ++v2;
    if ( v1 < 4 )
      return 0;
  }
  return 1;
}
