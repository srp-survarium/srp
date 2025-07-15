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


char __cdecl Scaleform::Render::operator==(
        const Scaleform::Render::Matrix3x4<float> *m1,
        const Scaleform::Render::Matrix3x4<float> *m2)
{
  unsigned int v4; // eax

  v4 = 48;
  while ( LODWORD(m1->M[0][0]) == LODWORD(m2->M[0][0]) )
  {
    v4 -= 4;
    m2 = (const Scaleform::Render::Matrix3x4<float> *)((char *)m2 + 4);
    m1 = (const Scaleform::Render::Matrix3x4<float> *)((char *)m1 + 4);
    if ( v4 < 4 )
      return 1;
  }
  return 0;
}


const Scaleform::Render::Matrix2x4<float> *__cdecl Scaleform::Render::operator*(
        Scaleform::Render::Matrix2x4<float> *result,
        const Scaleform::Render::Matrix2x4<float> *m1,
        const Scaleform::Render::Matrix2x4<float> *m2)
{
  const Scaleform::Render::Matrix2x4<float> *v3; // eax
  Scaleform::Render::Matrix2x4<float> v5; // [esp+0h] [ebp-20h] BYREF

  Scaleform::Render::Matrix2x4<float>::SetMatrix(&v5, m1);
  v3 = Scaleform::Render::Matrix2x4<float>::Prepend(&v5, m2);
  Scaleform::Render::Matrix2x4<float>::SetMatrix(result, v3);
  return result;
}
