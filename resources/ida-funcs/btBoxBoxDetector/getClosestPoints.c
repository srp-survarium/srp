void __thiscall btBoxBoxDetector::getClosestPoints(
        btBoxBoxDetector *this,
        const btDiscreteCollisionDetectorInterface::ClosestPointInput *input,
        btDiscreteCollisionDetectorInterface::Result *output,
        btIDebugDraw *__formal,
        bool a5)
{
  btBoxShape *m_box2; // edi
  float (__thiscall *getMargin)(struct btBoxShape *); // edx
  btBoxShape *m_box1; // edi
  float v9; // xmm1_4
  int v10; // [esp+204h] [ebp-98h] BYREF
  float v11; // [esp+208h] [ebp-94h] BYREF
  btVector3 side1; // [esp+20Ch] [ebp-90h] BYREF
  btVector3 side2; // [esp+21Ch] [ebp-80h] BYREF
  float v14[12]; // [esp+22Ch] [ebp-70h] BYREF
  float v15[12]; // [esp+25Ch] [ebp-40h] BYREF
  btVector3 v16; // [esp+28Ch] [ebp-10h] BYREF

  v15[0] = input->m_transformA.m_basis.m_el[0].mVec128.m128_f32[0];
  v14[0] = input->m_transformB.m_basis.m_el[0].mVec128.m128_f32[0];
  v15[1] = input->m_transformA.m_basis.m_el[0].mVec128.m128_f32[1];
  v14[1] = input->m_transformB.m_basis.m_el[0].mVec128.m128_f32[1];
  v15[2] = input->m_transformA.m_basis.m_el[0].mVec128.m128_f32[2];
  v14[2] = input->m_transformB.m_basis.m_el[0].mVec128.m128_f32[2];
  v15[4] = input->m_transformA.m_basis.m_el[1].mVec128.m128_f32[0];
  v14[4] = input->m_transformB.m_basis.m_el[1].mVec128.m128_f32[0];
  v15[5] = input->m_transformA.m_basis.m_el[1].mVec128.m128_f32[1];
  v14[5] = input->m_transformB.m_basis.m_el[1].mVec128.m128_f32[1];
  v15[6] = input->m_transformA.m_basis.m_el[1].mVec128.m128_f32[2];
  v14[6] = input->m_transformB.m_basis.m_el[1].mVec128.m128_f32[2];
  v15[8] = input->m_transformA.m_basis.m_el[2].mVec128.m128_f32[0];
  v14[8] = input->m_transformB.m_basis.m_el[2].mVec128.m128_f32[0];
  v15[9] = input->m_transformA.m_basis.m_el[2].mVec128.m128_f32[1];
  v14[9] = input->m_transformB.m_basis.m_el[2].mVec128.m128_f32[1];
  v15[10] = input->m_transformA.m_basis.m_el[2].mVec128.m128_f32[2];
  m_box2 = this->m_box2;
  getMargin = m_box2->getMargin;
  v14[10] = input->m_transformB.m_basis.m_el[2].mVec128.m128_f32[2];
  side1.mVec128 = (__m128)m_box2->m_implicitShapeDimensions;
  *(float *)&v10 = getMargin(m_box2);
  v11 = m_box2->getMargin(m_box2);
  side2.mVec128.m128_f32[0] = m_box2->getMargin(m_box2);
  m_box1 = this->m_box1;
  v9 = side1.mVec128.m128_f32[1] + v11;
  side2.mVec128.m128_f32[0] = (float)(side2.mVec128.m128_f32[0] + side1.mVec128.m128_f32[0]) * 2.0;
  side2.mVec128.m128_i32[3] = 0;
  side1.mVec128.m128_u64[0] = m_box1->m_implicitShapeDimensions.mVec128.m128_u64[0];
  side2.mVec128.m128_f32[1] = v9 * 2.0;
  side2.mVec128.m128_f32[2] = (float)(side1.mVec128.m128_f32[2] + *(float *)&v10) * 2.0;
  side1.mVec128.m128_u64[1] = m_box1->m_implicitShapeDimensions.mVec128.m128_u64[1];
  v11 = m_box1->getMargin(m_box1);
  *(float *)&v10 = m_box1->getMargin(m_box1);
  v16.mVec128.m128_f32[0] = m_box1->getMargin(m_box1);
  side1.mVec128.m128_f32[0] = (float)(v16.mVec128.m128_f32[0] + side1.mVec128.m128_f32[0]) * 2.0;
  side1.mVec128.m128_f32[1] = (float)(side1.mVec128.m128_f32[1] + *(float *)&v10) * 2.0;
  side1.mVec128.m128_f32[2] = (float)(side1.mVec128.m128_f32[2] + v11) * 2.0;
  side1.mVec128.m128_i32[3] = 0;
  dBoxBox2(
    &side2,
    &side1,
    &input->m_transformA.m_origin,
    v15,
    &input->m_transformB.m_origin,
    v14,
    &v16,
    &v11,
    &v10,
    output);
}
