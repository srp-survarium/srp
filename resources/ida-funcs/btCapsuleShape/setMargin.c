void __thiscall btCapsuleShape::setMargin(btCapsuleShape *this, float collisionMargin)
{
  float (__thiscall *getMargin)(struct btCapsuleShape *); // edx
  float v4; // [esp+C8h] [ebp-28h]
  float v5; // [esp+C8h] [ebp-28h]
  float v6; // [esp+CCh] [ebp-24h]
  float v7; // [esp+CCh] [ebp-24h]
  float v8; // [esp+D0h] [ebp-20h]
  float v9; // [esp+D4h] [ebp-1Ch]
  float v10; // [esp+D8h] [ebp-18h]
  float v11; // [esp+E0h] [ebp-10h]
  float v12; // [esp+E0h] [ebp-10h]
  btVector3 v13; // [esp+E0h] [ebp-10h]

  v6 = this->getMargin(this);
  v4 = this->getMargin(this);
  v11 = this->getMargin(this);
  getMargin = this->getMargin;
  v8 = this->m_implicitShapeDimensions.mVec128.m128_f32[0] + v11;
  v9 = this->m_implicitShapeDimensions.mVec128.m128_f32[1] + v4;
  v10 = this->m_implicitShapeDimensions.mVec128.m128_f32[2] + v6;
  this->m_collisionMargin = collisionMargin;
  v5 = getMargin(this);
  v7 = this->getMargin(this);
  v12 = this->getMargin(this);
  v13.mVec128.m128_f32[0] = v8 - v12;
  v13.mVec128.m128_f32[1] = v9 - v7;
  v13.mVec128.m128_f32[2] = v10 - v5;
  v13.mVec128.m128_i32[3] = 0;
  this->m_implicitShapeDimensions = (btVector3)v13.mVec128;
}
