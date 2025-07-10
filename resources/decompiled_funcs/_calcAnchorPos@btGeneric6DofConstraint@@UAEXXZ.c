void __thiscall btGeneric6DofConstraint::calcAnchorPos(btGeneric6DofConstraint *this)
{
  float m_inverseMass; // xmm1_4
  float v2; // xmm3_4
  btVector3 v3; // [esp+0h] [ebp-10h]

  m_inverseMass = this->m_rbB->m_inverseMass;
  if ( m_inverseMass == 0.0 )
    v2 = *(float *)&clear_value;
  else
    v2 = this->m_rbA->m_inverseMass / (float)(m_inverseMass + this->m_rbA->m_inverseMass);
  v3.mVec128.m128_f32[0] = (float)(this->m_calculatedTransformA.m_origin.mVec128.m128_f32[0] * v2)
                         + (float)(this->m_calculatedTransformB.m_origin.mVec128.m128_f32[0]
                                 * (float)(*(float *)&clear_value - v2));
  v3.mVec128.m128_f32[1] = (float)(this->m_calculatedTransformA.m_origin.mVec128.m128_f32[1] * v2)
                         + (float)(this->m_calculatedTransformB.m_origin.mVec128.m128_f32[1]
                                 * (float)(*(float *)&clear_value - v2));
  v3.mVec128.m128_f32[2] = (float)(this->m_calculatedTransformA.m_origin.mVec128.m128_f32[2] * v2)
                         + (float)(this->m_calculatedTransformB.m_origin.mVec128.m128_f32[2]
                                 * (float)(*(float *)&clear_value - v2));
  v3.mVec128.m128_i32[3] = 0;
  this->m_AnchorPos = (btVector3)v3.mVec128;
}
