void __thiscall btCapsuleShape::setMargin(btCylinderShape *this, float collisionMargin)
{
  btCylinderShape_vtbl *v3; // eax
  float v4; // [esp+8h] [ebp-28h]
  float v5; // [esp+8h] [ebp-28h]
  float v6; // [esp+Ch] [ebp-24h]
  float v7; // [esp+Ch] [ebp-24h]
  float v8; // [esp+10h] [ebp-20h]
  float v9; // [esp+14h] [ebp-1Ch]
  float v10; // [esp+18h] [ebp-18h]
  float v11; // [esp+20h] [ebp-10h]
  float v12; // [esp+20h] [ebp-10h]

  v6 = this->getMargin(this);
  v4 = this->getMargin(this);
  v11 = this->getMargin(this);
  v3 = this->__vftable;
  v8 = this->m_implicitShapeDimensions.mVec128.m128_f32[0] + v11;
  v9 = this->m_implicitShapeDimensions.mVec128.m128_f32[1] + v4;
  v10 = this->m_implicitShapeDimensions.mVec128.m128_f32[2] + v6;
  this->m_collisionMargin = collisionMargin;
  v5 = v3->getMargin(this);
  v7 = this->getMargin(this);
  v12 = this->getMargin(this);
  this->m_implicitShapeDimensions.mVec128.m128_f32[0] = v8 - v12;
  this->m_implicitShapeDimensions.mVec128.m128_f32[1] = v9 - v7;
  this->m_implicitShapeDimensions.mVec128.m128_f32[2] = v10 - v5;
  this->m_implicitShapeDimensions.mVec128.m128_i32[3] = 0;
}
