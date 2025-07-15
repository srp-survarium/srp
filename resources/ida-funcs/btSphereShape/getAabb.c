void __thiscall btSphereShape::getAabb(
        btSphereShape *this,
        const btTransform *t,
        btVector3 *aabbMin,
        btVector3 *aabbMax)
{
  double v5; // st7
  float v6; // [esp+8h] [ebp-18h]
  float v7; // [esp+Ch] [ebp-14h]
  btVector3 v8; // [esp+10h] [ebp-10h]

  v7 = this->getMargin(this);
  v6 = this->getMargin(this);
  v5 = ((double (__thiscall *)(btSphereShape *))this->getMargin)(this);
  v8.mVec128.m128_i32[3] = 0;
  v8.mVec128.m128_f32[0] = t->m_origin.mVec128.m128_f32[0] - v5;
  v8.mVec128.m128_f32[1] = t->m_origin.mVec128.m128_f32[1] - v6;
  v8.mVec128.m128_f32[2] = t->m_origin.mVec128.m128_f32[2] - v7;
  *aabbMin = (btVector3)v8.mVec128;
  v8.mVec128.m128_i32[3] = 0;
  v8.mVec128.m128_f32[0] = v5 + t->m_origin.mVec128.m128_f32[0];
  v8.mVec128.m128_f32[1] = v6 + t->m_origin.mVec128.m128_f32[1];
  v8.mVec128.m128_f32[2] = v7 + t->m_origin.mVec128.m128_f32[2];
  *aabbMax = (btVector3)v8.mVec128;
}
