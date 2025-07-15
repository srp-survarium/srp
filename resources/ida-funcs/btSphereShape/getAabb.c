void __thiscall btSphereShape::getAabb(
        btSphereShape *this,
        const btTransform *t,
        btVector3 *aabbMin,
        btVector3 *aabbMax)
{
  double v5; // st7
  float v6; // [esp+18h] [ebp-18h]
  float v7; // [esp+1Ch] [ebp-14h]
  unsigned __int64 v8; // [esp+20h] [ebp-10h]
  unsigned int v9; // [esp+28h] [ebp-8h]
  unsigned int v10; // [esp+28h] [ebp-8h]

  v7 = this->getMargin(this);
  v6 = this->getMargin(this);
  v5 = ((double (__thiscall *)(btSphereShape *))this->getMargin)(this);
  *(float *)&v8 = t->m_origin.mVec128.m128_f32[0] - v5;
  *((float *)&v8 + 1) = t->m_origin.mVec128.m128_f32[1] - v6;
  *(float *)&v9 = t->m_origin.mVec128.m128_f32[2] - v7;
  aabbMin->mVec128.m128_u64[0] = v8;
  aabbMin->mVec128.m128_u64[1] = v9;
  *(float *)&v8 = v5 + t->m_origin.mVec128.m128_f32[0];
  *((float *)&v8 + 1) = t->m_origin.mVec128.m128_f32[1] + v6;
  *(float *)&v10 = t->m_origin.mVec128.m128_f32[2] + v7;
  aabbMax->mVec128.m128_u64[0] = v8;
  aabbMax->mVec128.m128_u64[1] = v10;
}
