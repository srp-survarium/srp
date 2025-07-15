void __thiscall btBoxBoxDetector::getClosestPoints(
        btBoxBoxDetector *this,
        const btDiscreteCollisionDetectorInterface::ClosestPointInput *input,
        btDiscreteCollisionDetectorInterface::Result *output,
        btIDebugDraw *__formal,
        bool a5)
{
  float *v5; // eax
  int v6; // ecx
  int v7; // ebx
  double v8; // st7
  int v9; // ebx
  int v10; // ebx
  btVector3 *HalfExtentsWithMargin; // eax
  btBoxShape *v12; // ecx
  btVector3 *v13; // eax
  btVector3 *v14; // [esp-8h] [ebp-D8h]
  int v15; // [esp+0h] [ebp-D0h] BYREF
  int v16; // [esp+Ch] [ebp-C4h]
  btBoxBoxDetector *v17; // [esp+10h] [ebp-C0h] BYREF
  int v18; // [esp+14h] [ebp-BCh] BYREF
  int v19; // [esp+18h] [ebp-B8h]
  int v20; // [esp+1Ch] [ebp-B4h]
  btVector3 v21; // [esp+20h] [ebp-B0h] BYREF
  btVector3 v22; // [esp+30h] [ebp-A0h] BYREF
  float v23; // [esp+40h] [ebp-90h] BYREF
  _BYTE v24[44]; // [esp+44h] [ebp-8Ch] BYREF
  float v25; // [esp+70h] [ebp-60h] BYREF
  char v26; // [esp+74h] [ebp-5Ch] BYREF
  btVector3 v27; // [esp+A0h] [ebp-30h] BYREF
  btVector3 v28; // [esp+B0h] [ebp-20h] BYREF
  btVector3 v29; // [esp+C0h] [ebp-10h] BYREF

  v17 = this;
  v20 = (char *)&v25 - (char *)&input->m_transformB;
  v19 = v24 - (_BYTE *)&input->m_transformB;
  v16 = -64;
  v18 = &v26 - (char *)&input->m_transformB;
  v5 = &input->m_transformB.m_basis.m_el[0].mVec128.m128_f32[1];
  v6 = 0;
  do
  {
    v7 = v16;
    *(float *)&v24[v6 * 16 - 4] = input->m_transformA.m_basis.m_el[v6].mVec128.m128_f32[0];
    *(float *)&v24[++v6 * 16 + 28] = *(v5 - 1);
    v8 = *(float *)((char *)v5 + v7);
    v9 = v20;
    *(float *)((char *)v5 + (char *)&v15 - (char *)input) = v8;
    *(float *)((char *)v5 + v9) = *v5;
    *(float *)((char *)v5 + v19) = input->m_transformA.m_basis.m_el[v6 - 1].mVec128.m128_f32[2];
    *(float *)((char *)v5 + v18) = v5[1];
    v5 += 4;
  }
  while ( v6 < 3 );
  v10 = (int)v17;
  HalfExtentsWithMargin = btBoxShape::getHalfExtentsWithMargin((btBoxShape *)(v6 * 16), (btVector3 *)v17->m_box2, &v28);
  v21.mVec128.m128_f32[0] = HalfExtentsWithMargin->mVec128.m128_f32[0] * 2.0;
  v21.mVec128.m128_f32[1] = HalfExtentsWithMargin->mVec128.m128_f32[1] * 2.0;
  v14 = *(btVector3 **)(v10 + 4);
  v21.mVec128.m128_f32[2] = HalfExtentsWithMargin->mVec128.m128_f32[2] * 2.0;
  v21.mVec128.m128_i32[3] = 0;
  v13 = btBoxShape::getHalfExtentsWithMargin(v12, v14, &v27);
  v22.mVec128.m128_f32[0] = v13->mVec128.m128_f32[0] * 2.0;
  v22.mVec128.m128_f32[1] = v13->mVec128.m128_f32[1] * 2.0;
  v22.mVec128.m128_f32[2] = v13->mVec128.m128_f32[2] * 2.0;
  v22.mVec128.m128_i32[3] = 0;
  dBoxBox2(
    &v22,
    &v21,
    &input->m_transformA.m_origin,
    &v23,
    &input->m_transformB.m_origin,
    &v25,
    &v29,
    (float *)&v18,
    (int *)&v17,
    (int *)output);
}
