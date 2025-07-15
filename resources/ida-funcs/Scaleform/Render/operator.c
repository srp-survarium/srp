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
        const Scaleform::Render::Matrix2x4<float> *result,
        const Scaleform::Render::Matrix2x4<float> *m1,
        const Scaleform::Render::Matrix2x4<float> *m2)
{
  float v3; // xmm5_4
  float v4; // xmm6_4
  float v5; // xmm4_4
  float v6; // xmm3_4
  float v7; // xmm1_4
  float v8; // xmm0_4
  float v9; // xmm2_4
  unsigned int v10; // xmm3_4
  unsigned int v11; // xmm5_4
  float v12; // xmm0_4
  float v13; // xmm1_4
  float v14; // xmm7_4
  float v15; // xmm0_4
  float v16; // xmm4_4
  const Scaleform::Render::Matrix2x4<float> *v17; // eax
  float v18; // [esp+30h] [ebp-10h]

  v3 = m1->M[1][1];
  v4 = m1->M[1][0];
  v5 = m1->M[0][1];
  v6 = m2->M[1][0];
  v7 = m2->M[0][1];
  v18 = (float)(m2->M[0][0] * v4) + (float)(v6 * v3);
  v8 = m2->M[1][1];
  v9 = (float)(m2->M[0][0] * m1->M[0][0]) + (float)(v6 * v5);
  *(float *)&v10 = (float)(v7 * m1->M[0][0]) + (float)(v8 * v5);
  *(float *)&v11 = (float)(v8 * v3) + (float)(v7 * v4);
  v12 = m2->M[0][3];
  v13 = (float)(v12 * m1->M[0][0]) + (float)(m2->M[1][3] * v5);
  v14 = m1->M[0][3];
  v15 = (float)(v12 * v4) + (float)(m2->M[1][3] * m1->M[1][1]);
  v16 = m1->M[1][3];
  v17 = result;
  result->M[0][0] = v9;
  result->M[0][3] = v13 + v14;
  *(_QWORD *)&result->M[0][1] = v10;
  result->M[1][0] = v18;
  *(_QWORD *)&result->M[1][1] = v11;
  result->M[1][3] = v15 + v16;
  return v17;
}
