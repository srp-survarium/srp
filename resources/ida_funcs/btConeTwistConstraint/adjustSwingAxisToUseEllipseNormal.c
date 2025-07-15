void __usercall btConeTwistConstraint::adjustSwingAxisToUseEllipseNormal(
        btConeTwistConstraint *this@<eax>,
        btVector3 *vSwingAxis@<esi>)
{
  float v2; // xmm2_4
  float v3; // xmm0_4
  long double v4; // st7
  float v5; // [esp+4h] [ebp-10h]
  float v6; // [esp+8h] [ebp-Ch]
  float v7; // [esp+Ch] [ebp-8h]

  v2 = -vSwingAxis->mVec128.m128_f32[2];
  v7 = vSwingAxis->mVec128.m128_f32[1];
  if ( COERCE_FLOAT(LODWORD(v7) & _mask__AbsFloat_) > 0.00000011920929 )
  {
    LODWORD(v3) = COERCE_UNSIGNED_INT(
                    (float)((float)((float)(v2 / vSwingAxis->mVec128.m128_f32[1]) / this->m_swingSpan1)
                          * this->m_swingSpan2)
                  * vSwingAxis->mVec128.m128_f32[1])
                & _mask__AbsFloat_;
    if ( v2 <= 0.0 )
      v3 = -v3;
    v6 = vSwingAxis->mVec128.m128_f32[0];
    v4 = 1.0
       / sqrtf(
           (float)((float)(v6 * v6) + (float)((float)-v3 * (float)-v3))
         + (float)(vSwingAxis->mVec128.m128_f32[1] * vSwingAxis->mVec128.m128_f32[1]));
    v5 = v4;
    vSwingAxis->mVec128.m128_f32[0] = v6 * v5;
    vSwingAxis->mVec128.m128_f32[1] = v4 * v7;
    vSwingAxis->mVec128.m128_f32[2] = (float)-v3 * v5;
  }
}
