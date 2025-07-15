char __thiscall btTriangleShape::isInside(btTriangleShape *this, const btVector3 *pt, float tolerance)
{
  float v4; // xmm0_4
  int v5; // edi
  float v6; // xmm2_4
  float v7; // xmm3_4
  float v8; // xmm0_4
  float v10; // [esp+B8h] [ebp-48h]
  btVector3 v11; // [esp+C0h] [ebp-40h] BYREF
  float v12; // [esp+D0h] [ebp-30h] BYREF
  float v13; // [esp+D4h] [ebp-2Ch]
  float v14; // [esp+D8h] [ebp-28h]
  float v15; // [esp+E0h] [ebp-20h]
  float v16; // [esp+E4h] [ebp-1Ch]
  float v17; // [esp+E8h] [ebp-18h]
  float v18; // [esp+F0h] [ebp-10h] BYREF
  float v19; // [esp+F4h] [ebp-Ch]
  float v20; // [esp+F8h] [ebp-8h]

  btTriangleShape::calcNormal(this, &v11);
  v4 = (float)((float)((float)(pt->mVec128.m128_f32[0] * v11.mVec128.m128_f32[0])
                     + (float)(pt->mVec128.m128_f32[1] * v11.mVec128.m128_f32[1]))
             + (float)(pt->mVec128.m128_f32[2] * v11.mVec128.m128_f32[2]))
     - (float)((float)((float)(this->m_vertices1[0].mVec128.m128_f32[1] * v11.mVec128.m128_f32[1])
                     + (float)(this->m_vertices1[0].mVec128.m128_f32[2] * v11.mVec128.m128_f32[2]))
             + (float)(this->m_vertices1[0].mVec128.m128_f32[0] * v11.mVec128.m128_f32[0]));
  if ( v4 >= (float)-tolerance && tolerance >= v4 )
  {
    v5 = 0;
    while ( 1 )
    {
      this->getEdge(this, v5, (btVector3 *)&v12, (btVector3 *)&v18);
      v6 = (float)((float)(v19 - v13) * v11.mVec128.m128_f32[2]) - (float)((float)(v20 - v14) * v11.mVec128.m128_f32[1]);
      v7 = (float)(v11.mVec128.m128_f32[1] * (float)(v18 - v12)) - (float)((float)(v19 - v13) * v11.mVec128.m128_f32[0]);
      v8 = (float)((float)(v20 - v14) * v11.mVec128.m128_f32[0]) - (float)((float)(v18 - v12) * v11.mVec128.m128_f32[2]);
      v17 = v7;
      v16 = v8;
      v15 = v6;
      v10 = 1.0 / sqrtf((float)((float)(v7 * v7) + (float)(v8 * v8)) + (float)(v6 * v6));
      if ( (float)-tolerance > (float)((float)((float)((float)(pt->mVec128.m128_f32[0] * (float)(v15 * v10))
                                                     + (float)(pt->mVec128.m128_f32[2] * (float)(v17 * v10)))
                                             + (float)(pt->mVec128.m128_f32[1] * (float)(v16 * v10)))
                                     - (float)((float)((float)((float)(v16 * v10) * v13)
                                                     + (float)((float)(v17 * v10) * v14))
                                             + (float)((float)(v15 * v10) * v12))) )
        break;
      if ( ++v5 >= 3 )
        return 1;
    }
  }
  return 0;
}
