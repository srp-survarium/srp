void __thiscall btBoxShape::getVertex(btBoxShape *this, int i, btVector3 *vtx)
{
  unsigned int v3; // xmm1_4
  unsigned __int64 v4; // [esp+20h] [ebp-20h]
  btVector3 v5; // [esp+30h] [ebp-10h] BYREF

  btBoxShape::getHalfExtentsWithMargin((btCylinderShape *)this, this, &v5);
  *(float *)&v4 = (float)((float)(1 - (i & 1)) * v5.mVec128.m128_f32[0])
                - (float)((float)(i & 1) * v5.mVec128.m128_f32[0]);
  *((float *)&v4 + 1) = (float)((float)(1 - ((i >> 1) & 1)) * v5.mVec128.m128_f32[1])
                      - (float)((float)((i >> 1) & 1) * v5.mVec128.m128_f32[1]);
  *(float *)&v3 = (float)((float)(1 - ((i >> 2) & 1)) * v5.mVec128.m128_f32[2])
                - (float)((float)((i >> 2) & 1) * v5.mVec128.m128_f32[2]);
  vtx->mVec128.m128_u64[0] = v4;
  vtx->mVec128.m128_u64[1] = v3;
}
