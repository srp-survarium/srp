void __thiscall btBvhTriangleMeshShape::performRaycast_::_2_::MyNodeOverlapCallback::processNode(
        btBvhTriangleMeshShape::performRaycast::__l2::MyNodeOverlapCallback *this,
        int nodeSubPart,
        int nodeTriangleIndex)
{
  unsigned __int16 *v4; // edx
  btVector3 *p_m_scaling; // eax
  int v6; // ecx
  int v7; // ecx
  __m128i v8; // xmm1
  float v9; // xmm0_4
  float v10; // xmm0_4
  float v11; // xmm0_4
  int v12; // ecx
  int v13; // ecx
  __m128i v14; // xmm1
  float v15; // xmm1_4
  float v16; // xmm1_4
  float v17; // xmm1_4
  int v18; // ecx
  int v19; // ecx
  __m128i v20; // xmm0
  float v21; // xmm1_4
  float v22; // xmm1_4
  btTriangleCallback *m_callback; // ecx
  int v24; // [esp+350h] [ebp-70h] BYREF
  int v25; // [esp+354h] [ebp-6Ch] BYREF
  int v26; // [esp+358h] [ebp-68h] BYREF
  int v27; // [esp+35Ch] [ebp-64h] BYREF
  int v28; // [esp+360h] [ebp-60h] BYREF
  int v29; // [esp+364h] [ebp-5Ch] BYREF
  int v30; // [esp+368h] [ebp-58h] BYREF
  int v31; // [esp+36Ch] [ebp-54h] BYREF
  __m128i v32; // [esp+370h] [ebp-50h] BYREF
  __m128i v33; // [esp+380h] [ebp-40h] BYREF
  _OWORD v34[3]; // [esp+390h] [ebp-30h] BYREF

  this->m_meshInterface->getLockedReadOnlyVertexIndexBase(
    this->m_meshInterface,
    (const unsigned __int8 **)&v27,
    &v31,
    (PHY_ScalarType *)&v25,
    &v26,
    (const unsigned __int8 **)&v29,
    &v28,
    &v30,
    (PHY_ScalarType *)&v24,
    nodeSubPart);
  v4 = (unsigned __int16 *)(v29 + nodeTriangleIndex * v28);
  p_m_scaling = &this->m_meshInterface->m_scaling;
  if ( v24 == 3 )
    v6 = v4[2];
  else
    v6 = *((_DWORD *)v4 + 2);
  v7 = v27 + v26 * v6;
  if ( v25 )
  {
    v9 = *(double *)v7;
    *(float *)v33.m128i_i32 = v9 * p_m_scaling->mVec128.m128_f32[0];
    v10 = *(double *)(v7 + 8);
    *(float *)&v33.m128i_i32[1] = v10 * p_m_scaling->mVec128.m128_f32[1];
    v11 = *(double *)(v7 + 16);
    *(float *)&v33.m128i_i32[2] = v11 * p_m_scaling->mVec128.m128_f32[2];
    v33.m128i_i32[3] = 0;
    v8 = _mm_load_si128(&v33);
  }
  else
  {
    *(float *)v32.m128i_i32 = p_m_scaling->mVec128.m128_f32[0] * *(float *)v7;
    *(float *)&v32.m128i_i32[1] = *(float *)(v7 + 4) * p_m_scaling->mVec128.m128_f32[1];
    *(float *)&v32.m128i_i32[2] = *(float *)(v7 + 8) * p_m_scaling->mVec128.m128_f32[2];
    v32.m128i_i32[3] = 0;
    v8 = _mm_load_si128(&v32);
  }
  v34[2] = v8;
  if ( v24 == 3 )
    v12 = v4[1];
  else
    v12 = *((_DWORD *)v4 + 1);
  v13 = v27 + v26 * v12;
  if ( v25 )
  {
    v15 = *(double *)v13;
    *(float *)v33.m128i_i32 = v15 * p_m_scaling->mVec128.m128_f32[0];
    v16 = *(double *)(v13 + 8);
    *(float *)&v33.m128i_i32[1] = v16 * p_m_scaling->mVec128.m128_f32[1];
    v17 = *(double *)(v13 + 16);
    *(float *)&v33.m128i_i32[2] = v17 * p_m_scaling->mVec128.m128_f32[2];
    v33.m128i_i32[3] = 0;
    v14 = _mm_load_si128(&v33);
  }
  else
  {
    *(float *)v32.m128i_i32 = p_m_scaling->mVec128.m128_f32[0] * *(float *)v13;
    *(float *)&v32.m128i_i32[1] = *(float *)(v13 + 4) * p_m_scaling->mVec128.m128_f32[1];
    *(float *)&v32.m128i_i32[2] = *(float *)(v13 + 8) * p_m_scaling->mVec128.m128_f32[2];
    v32.m128i_i32[3] = 0;
    v14 = _mm_load_si128(&v32);
  }
  v34[1] = v14;
  if ( v24 == 3 )
    v18 = *v4;
  else
    v18 = *(_DWORD *)v4;
  v19 = v27 + v26 * v18;
  if ( v25 )
  {
    v21 = *(double *)v19;
    *(float *)v33.m128i_i32 = v21 * p_m_scaling->mVec128.m128_f32[0];
    v22 = *(double *)(v19 + 8);
    *(float *)&v33.m128i_i32[1] = v22 * p_m_scaling->mVec128.m128_f32[1];
    *(float *)&v33.m128i_i32[2] = (float)*(double *)(v19 + 16) * p_m_scaling->mVec128.m128_f32[2];
    v33.m128i_i32[3] = 0;
    v20 = _mm_load_si128(&v33);
  }
  else
  {
    *(float *)v32.m128i_i32 = p_m_scaling->mVec128.m128_f32[0] * *(float *)v19;
    *(float *)&v32.m128i_i32[1] = *(float *)(v19 + 4) * p_m_scaling->mVec128.m128_f32[1];
    *(float *)&v32.m128i_i32[2] = *(float *)(v19 + 8) * p_m_scaling->mVec128.m128_f32[2];
    v32.m128i_i32[3] = 0;
    v20 = _mm_load_si128(&v32);
  }
  m_callback = this->m_callback;
  v34[0] = v20;
  m_callback->processTriangle(m_callback, (btVector3 *)v34, nodeSubPart, nodeTriangleIndex);
  this->m_meshInterface->unLockReadOnlyVertexBase(this->m_meshInterface, nodeSubPart);
}
