btVector3 *__thiscall btTriangleShape::localGetSupportingVertexWithoutMargin(
        btTriangleShape *this,
        btVector3 *result,
        const btVector3 *dir)
{
  float v3; // xmm5_4
  float v4; // xmm4_4
  float v5; // xmm0_4
  float v6; // xmm1_4
  float v7; // xmm3_4
  int v8; // eax
  int v9; // edx
  btVector3 *v10; // eax

  v3 = dir->mVec128.m128_f32[1];
  v4 = dir->mVec128.m128_f32[2];
  v5 = (float)((float)(this->m_vertices1[0].mVec128.m128_f32[1] * v3)
             + (float)(this->m_vertices1[0].mVec128.m128_f32[2] * v4))
     + (float)(this->m_vertices1[0].mVec128.m128_f32[0] * dir->mVec128.m128_f32[0]);
  v6 = (float)((float)(this->m_vertices1[1].mVec128.m128_f32[1] * v3)
             + (float)(this->m_vertices1[1].mVec128.m128_f32[2] * v4))
     + (float)(this->m_vertices1[1].mVec128.m128_f32[0] * dir->mVec128.m128_f32[0]);
  v7 = (float)((float)(this->m_vertices1[2].mVec128.m128_f32[1] * v3)
             + (float)(this->m_vertices1[2].mVec128.m128_f32[2] * v4))
     + (float)(dir->mVec128.m128_f32[0] * this->m_vertices1[2].mVec128.m128_f32[0]);
  if ( v6 <= v5 )
  {
    if ( v7 <= v5 )
    {
      v8 = 0;
      goto LABEL_7;
    }
    goto LABEL_5;
  }
  if ( v7 > v6 )
  {
LABEL_5:
    v8 = 2;
    goto LABEL_7;
  }
  v8 = 1;
LABEL_7:
  v9 = v8 + 5;
  v10 = result;
  *result = (btVector3)*((_OWORD *)&this->btConvexShape + v9);
  return v10;
}
