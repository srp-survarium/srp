void __usercall btGeneric6DofConstraint::calculateTransforms(
        btGeneric6DofConstraint *this@<esi>,
        btGeneric6DofConstraint *transA@<ecx>,
        const btTransform *transB@<eax>)
{
  float v3; // xmm0_4
  float v4; // xmm2_4
  float v5; // xmm1_4
  float v6; // xmm7_4
  float v7; // xmm5_4
  float v8; // xmm6_4
  float v9; // xmm4_4
  unsigned int v10; // xmm3_4
  float v11; // xmm0_4
  float v12; // xmm2_4
  float v13; // xmm3_4
  float v14; // xmm6_4
  float v15; // xmm5_4
  float v16; // xmm3_4
  float v17; // xmm4_4
  float v18; // xmm2_4
  float v19; // xmm6_4
  float v20; // xmm5_4
  unsigned int v21; // xmm7_4
  unsigned int v22; // xmm4_4
  float v23; // xmm5_4
  btGeneric6DofConstraint *v24; // ecx
  float m_inverseMass; // xmm2_4
  float v26; // xmm1_4
  bool v27; // al
  float v28; // [esp+Ch] [ebp-74h]
  float v29; // [esp+18h] [ebp-68h]
  float v30; // [esp+1Ch] [ebp-64h]
  float v31; // [esp+24h] [ebp-5Ch]
  float v32; // [esp+28h] [ebp-58h]
  unsigned __int64 v33; // [esp+34h] [ebp-4Ch]
  btVector3 v34; // [esp+40h] [ebp-40h]
  unsigned __int64 v35; // [esp+50h] [ebp-30h]
  unsigned int v36; // [esp+58h] [ebp-28h]
  unsigned int v37; // [esp+58h] [ebp-28h]
  unsigned __int64 v38; // [esp+60h] [ebp-20h]
  unsigned __int64 v39; // [esp+60h] [ebp-20h]
  unsigned int v40; // [esp+68h] [ebp-18h]
  unsigned int v41; // [esp+68h] [ebp-18h]
  unsigned __int64 v42; // [esp+70h] [ebp-10h]
  unsigned __int64 v43; // [esp+78h] [ebp-8h]

  v3 = this->m_frameInA.m_origin.mVec128.m128_f32[0];
  v4 = this->m_frameInA.m_origin.mVec128.m128_f32[1];
  v5 = this->m_frameInA.m_origin.mVec128.m128_f32[2];
  v32 = *(float *)&transA->m_userConstraintType;
  v6 = this->m_frameInA.m_basis.m_el[1].mVec128.m128_f32[1];
  v31 = *(float *)&transA->m_objectType;
  v7 = this->m_frameInA.m_basis.m_el[1].mVec128.m128_f32[2];
  v8 = (float)((float)((float)(v3 * *(float *)&transA->__vftable) + (float)(v4 * v31)) + (float)(v5 * v32))
     + transA->m_frameInA.m_basis.m_el[0].mVec128.m128_f32[0];
  v9 = this->m_frameInA.m_basis.m_el[2].mVec128.m128_f32[2];
  v34.mVec128.m128_f32[1] = (float)((float)((float)(*(float *)&transA->m_isEnabled * v4)
                                          + (float)(*(float *)&transA->m_rbA * v5))
                                  + (float)(v3 * transA->m_breakingImpulseThreshold))
                          + transA->m_frameInA.m_basis.m_el[0].mVec128.m128_f32[1];
  *(float *)&v10 = (float)((float)((float)(transA->m_dbgDrawSize * v4)
                                 + (float)(*((float *)&transA->btTypedConstraint + 10) * v5))
                         + (float)(v3 * transA->m_appliedImpulse))
                 + transA->m_frameInA.m_basis.m_el[0].mVec128.m128_f32[2];
  v11 = this->m_frameInA.m_basis.m_el[0].mVec128.m128_f32[2];
  v34.mVec128.m128_u64[1] = v10;
  v34.mVec128.m128_f32[0] = v8;
  v29 = this->m_frameInA.m_basis.m_el[2].mVec128.m128_f32[1];
  v12 = this->m_frameInA.m_basis.m_el[0].mVec128.m128_f32[1];
  *((float *)&v33 + 1) = (float)((float)(transA->m_dbgDrawSize * v6)
                               + (float)(*((float *)&transA->btTypedConstraint + 10) * v29))
                       + (float)(v12 * transA->m_appliedImpulse);
  v30 = this->m_frameInA.m_basis.m_el[2].mVec128.m128_f32[0];
  v28 = this->m_frameInA.m_basis.m_el[1].mVec128.m128_f32[0];
  v13 = this->m_frameInA.m_basis.m_el[0].mVec128.m128_f32[0];
  *(float *)&v33 = (float)((float)(*((float *)&transA->btTypedConstraint + 10) * v30)
                         + (float)(transA->m_dbgDrawSize * v28))
                 + (float)(v13 * transA->m_appliedImpulse);
  v14 = (float)((float)(*(float *)&transA->m_rbA * v30) + (float)(*(float *)&transA->m_isEnabled * v28))
      + (float)(v13 * transA->m_breakingImpulseThreshold);
  *(float *)&v36 = (float)((float)(v11 * *(float *)&transA->__vftable) + (float)(v7 * v31)) + (float)(v9 * v32);
  *((float *)&v38 + 1) = (float)((float)(*(float *)&transA->m_isEnabled * v6) + (float)(*(float *)&transA->m_rbA * v29))
                       + (float)(v12 * transA->m_breakingImpulseThreshold);
  *(float *)&v40 = (float)((float)(*(float *)&transA->m_isEnabled * v7) + (float)(*(float *)&transA->m_rbA * v9))
                 + (float)(v11 * transA->m_breakingImpulseThreshold);
  *(float *)&v43 = (float)((float)(transA->m_dbgDrawSize * v7)
                         + (float)(*((float *)&transA->btTypedConstraint + 10) * v9))
                 + (float)(v11 * transA->m_appliedImpulse);
  *(float *)&v35 = (float)((float)(v13 * *(float *)&transA->__vftable) + (float)(v28 * v31)) + (float)(v30 * v32);
  *((float *)&v35 + 1) = (float)((float)(v12 * *(float *)&transA->__vftable) + (float)(v6 * v31)) + (float)(v29 * v32);
  this->m_calculatedTransformA.m_basis.m_el[0].mVec128.m128_u64[0] = v35;
  this->m_calculatedTransformA.m_basis.m_el[0].mVec128.m128_u64[1] = v36;
  *(float *)&v38 = v14;
  this->m_calculatedTransformA.m_basis.m_el[1].mVec128.m128_u64[0] = v38;
  this->m_calculatedTransformA.m_basis.m_el[1].mVec128.m128_u64[1] = v40;
  HIDWORD(v43) = 0;
  this->m_calculatedTransformA.m_basis.m_el[2].mVec128.m128_u64[0] = v33;
  this->m_calculatedTransformA.m_basis.m_el[2].mVec128.m128_u64[1] = v43;
  this->m_calculatedTransformA.m_origin = (btVector3)v34.mVec128;
  v15 = this->m_frameInB.m_origin.mVec128.m128_f32[1];
  v16 = transB->m_basis.m_el[0].mVec128.m128_f32[1];
  v17 = this->m_frameInB.m_origin.mVec128.m128_f32[2];
  v18 = transB->m_basis.m_el[0].mVec128.m128_f32[2];
  v34.mVec128.m128_f32[0] = (float)((float)((float)(transB->m_basis.m_el[0].mVec128.m128_f32[0]
                                                  * this->m_frameInB.m_origin.mVec128.m128_f32[0])
                                          + (float)(v16 * v15))
                                  + (float)(v18 * v17))
                          + transB->m_origin.mVec128.m128_f32[0];
  v19 = (float)(transB->m_basis.m_el[1].mVec128.m128_f32[1] * v15)
      + (float)(transB->m_basis.m_el[1].mVec128.m128_f32[2] * v17);
  v20 = this->m_frameInB.m_origin.mVec128.m128_f32[0];
  v34.mVec128.m128_f32[1] = (float)(v19 + (float)(transB->m_basis.m_el[1].mVec128.m128_f32[0] * v20))
                          + transB->m_origin.mVec128.m128_f32[1];
  *(float *)&v21 = (float)((float)((float)(transB->m_basis.m_el[2].mVec128.m128_f32[1]
                                         * this->m_frameInB.m_origin.mVec128.m128_f32[1])
                                 + (float)(transB->m_basis.m_el[2].mVec128.m128_f32[2] * v17))
                         + (float)(transB->m_basis.m_el[2].mVec128.m128_f32[0] * v20))
                 + transB->m_origin.mVec128.m128_f32[2];
  *(float *)&v22 = (float)((float)(transB->m_basis.m_el[2].mVec128.m128_f32[1]
                                 * this->m_frameInB.m_basis.m_el[1].mVec128.m128_f32[2])
                         + (float)(transB->m_basis.m_el[2].mVec128.m128_f32[2]
                                 * this->m_frameInB.m_basis.m_el[2].mVec128.m128_f32[2]))
                 + (float)(transB->m_basis.m_el[2].mVec128.m128_f32[0]
                         * this->m_frameInB.m_basis.m_el[0].mVec128.m128_f32[2]);
  v23 = (float)((float)(transB->m_basis.m_el[2].mVec128.m128_f32[1]
                      * this->m_frameInB.m_basis.m_el[1].mVec128.m128_f32[1])
              + (float)(transB->m_basis.m_el[2].mVec128.m128_f32[2]
                      * this->m_frameInB.m_basis.m_el[2].mVec128.m128_f32[1]))
      + (float)(transB->m_basis.m_el[2].mVec128.m128_f32[0] * this->m_frameInB.m_basis.m_el[0].mVec128.m128_f32[1]);
  *(float *)&v35 = (float)((float)(transB->m_basis.m_el[0].mVec128.m128_f32[0]
                                 * this->m_frameInB.m_basis.m_el[0].mVec128.m128_f32[0])
                         + (float)(v16 * this->m_frameInB.m_basis.m_el[1].mVec128.m128_f32[0]))
                 + (float)(v18 * this->m_frameInB.m_basis.m_el[2].mVec128.m128_f32[0]);
  *(float *)&v37 = (float)((float)(transB->m_basis.m_el[0].mVec128.m128_f32[0]
                                 * this->m_frameInB.m_basis.m_el[0].mVec128.m128_f32[2])
                         + (float)(v16 * this->m_frameInB.m_basis.m_el[1].mVec128.m128_f32[2]))
                 + (float)(v18 * this->m_frameInB.m_basis.m_el[2].mVec128.m128_f32[2]);
  v39 = __PAIR64__(
          (float)((float)(transB->m_basis.m_el[1].mVec128.m128_f32[1]
                        * this->m_frameInB.m_basis.m_el[1].mVec128.m128_f32[1])
                + (float)(transB->m_basis.m_el[1].mVec128.m128_f32[2]
                        * this->m_frameInB.m_basis.m_el[2].mVec128.m128_f32[1]))
        + (float)(transB->m_basis.m_el[1].mVec128.m128_f32[0] * this->m_frameInB.m_basis.m_el[0].mVec128.m128_f32[1]),
          (float)((float)(transB->m_basis.m_el[1].mVec128.m128_f32[1]
                        * this->m_frameInB.m_basis.m_el[1].mVec128.m128_f32[0])
                + (float)(transB->m_basis.m_el[1].mVec128.m128_f32[2]
                        * this->m_frameInB.m_basis.m_el[2].mVec128.m128_f32[0]))
        + (float)(transB->m_basis.m_el[1].mVec128.m128_f32[0] * this->m_frameInB.m_basis.m_el[0].mVec128.m128_f32[0]));
  *(float *)&v41 = (float)((float)(transB->m_basis.m_el[1].mVec128.m128_f32[1]
                                 * this->m_frameInB.m_basis.m_el[1].mVec128.m128_f32[2])
                         + (float)(transB->m_basis.m_el[1].mVec128.m128_f32[2]
                                 * this->m_frameInB.m_basis.m_el[2].mVec128.m128_f32[2]))
                 + (float)(transB->m_basis.m_el[1].mVec128.m128_f32[0]
                         * this->m_frameInB.m_basis.m_el[0].mVec128.m128_f32[2]);
  *(float *)&v42 = (float)((float)(transB->m_basis.m_el[2].mVec128.m128_f32[1]
                                 * this->m_frameInB.m_basis.m_el[1].mVec128.m128_f32[0])
                         + (float)(transB->m_basis.m_el[2].mVec128.m128_f32[2]
                                 * this->m_frameInB.m_basis.m_el[2].mVec128.m128_f32[0]))
                 + (float)(transB->m_basis.m_el[2].mVec128.m128_f32[0]
                         * this->m_frameInB.m_basis.m_el[0].mVec128.m128_f32[0]);
  *((float *)&v35 + 1) = (float)((float)(transB->m_basis.m_el[0].mVec128.m128_f32[0]
                                       * this->m_frameInB.m_basis.m_el[0].mVec128.m128_f32[1])
                               + (float)(v16 * this->m_frameInB.m_basis.m_el[1].mVec128.m128_f32[1]))
                       + (float)(v18 * this->m_frameInB.m_basis.m_el[2].mVec128.m128_f32[1]);
  this->m_calculatedTransformB.m_basis.m_el[0].mVec128.m128_u64[0] = v35;
  this->m_calculatedTransformB.m_basis.m_el[0].mVec128.m128_u64[1] = v37;
  this->m_calculatedTransformB.m_basis.m_el[1].mVec128.m128_u64[0] = v39;
  this->m_calculatedTransformB.m_basis.m_el[1].mVec128.m128_u64[1] = v41;
  *((float *)&v42 + 1) = v23;
  this->m_calculatedTransformB.m_basis.m_el[2].mVec128.m128_u64[0] = v42;
  this->m_calculatedTransformB.m_basis.m_el[2].mVec128.m128_u64[1] = v22;
  this->m_calculatedTransformB.m_origin.mVec128.m128_u64[0] = v34.mVec128.m128_u64[0];
  this->m_calculatedTransformB.m_origin.mVec128.m128_u64[1] = v21;
  btGeneric6DofConstraint::calculateLinearInfo(transA, (int)this);
  btGeneric6DofConstraint::calculateAngleInfo(v24, (btVector3 *)this);
  if ( this->m_useOffsetForConstraintFrame )
  {
    m_inverseMass = this->m_rbA->m_inverseMass;
    v26 = this->m_rbB->m_inverseMass;
    v27 = m_inverseMass < 0.00000011920929 || v26 < 0.00000011920929;
    this->m_hasStaticBody = v27;
    if ( (float)(v26 + m_inverseMass) <= 0.0 )
      this->m_factA = FLOAT_0_5;
    else
      this->m_factA = v26 / (float)(v26 + m_inverseMass);
    this->m_factB = *(float *)&clear_value - this->m_factA;
  }
}
