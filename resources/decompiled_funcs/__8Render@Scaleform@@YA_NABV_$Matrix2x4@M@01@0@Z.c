char __cdecl Scaleform::Render::operator==(
        const Scaleform::Render::Matrix2x4<float> *m1,
        const Scaleform::Render::Matrix2x4<float> *m2)
{
  unsigned int v4; // eax

  v4 = 32;
  while ( LODWORD(m1->M[0][0]) == LODWORD(m2->M[0][0]) )
  {
    v4 -= 4;
    m2 = (const Scaleform::Render::Matrix2x4<float> *)((char *)m2 + 4);
    m1 = (const Scaleform::Render::Matrix2x4<float> *)((char *)m1 + 4);
    if ( v4 < 4 )
      return 1;
  }
  return 0;
}
