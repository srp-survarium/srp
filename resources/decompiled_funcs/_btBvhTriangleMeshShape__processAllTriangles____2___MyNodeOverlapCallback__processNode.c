void __thiscall btBvhTriangleMeshShape::processAllTriangles_::_2_::MyNodeOverlapCallback::processNode(
        btBvhTriangleMeshShape::processAllTriangles::__l2::MyNodeOverlapCallback *this,
        int nodeSubPart,
        int nodeTriangleIndex)
{
  unsigned __int16 *v4; // edx
  btVector3 *p_m_scaling; // eax
  int v6; // ecx
  int v7; // edi
  int v8; // ecx
  unsigned __int64 v9; // xmm1_8
  float v10; // xmm0_4
  float v11; // xmm0_4
  float v12; // xmm0_4
  int v13; // ecx
  int v14; // ecx
  int v15; // ebx
  int v16; // ecx
  unsigned __int64 v17; // xmm1_8
  float v18; // xmm1_4
  float v19; // xmm1_4
  float v20; // xmm1_4
  int v21; // ecx
  int v22; // ecx
  int v23; // ecx
  unsigned __int64 v24; // xmm0_8
  float v25; // xmm1_4
  float v26; // xmm1_4
  double v27; // xmm1_8
  __int64 v28; // [esp+19Ch] [ebp-44h] BYREF
  int v29; // [esp+1A4h] [ebp-3Ch] BYREF
  int v30; // [esp+1A8h] [ebp-38h] BYREF
  int v31; // [esp+1ACh] [ebp-34h] BYREF
  int v32; // [esp+1B0h] [ebp-30h] BYREF
  int v33; // [esp+1B4h] [ebp-2Ch] BYREF
  int v34; // [esp+1B8h] [ebp-28h] BYREF
  _BYTE v35[4]; // [esp+1BCh] [ebp-24h] BYREF
  unsigned __int64 v36; // [esp+1C0h] [ebp-20h]
  unsigned __int64 v37; // [esp+1C8h] [ebp-18h]
  unsigned __int64 v38; // [esp+1D0h] [ebp-10h]
  unsigned __int64 v39; // [esp+1D8h] [ebp-8h]

  this->m_meshInterface->getLockedReadOnlyVertexIndexBase(
    this->m_meshInterface,
    (const unsigned __int8 **)((char *)&v28 + 4),
    (int *)v35,
    (PHY_ScalarType *)&v30,
    &v31,
    (const unsigned __int8 **)&v33,
    &v32,
    &v34,
    (PHY_ScalarType *)&v29,
    nodeSubPart);
  v4 = (unsigned __int16 *)(v33 + nodeTriangleIndex * v32);
  p_m_scaling = &this->m_meshInterface->m_scaling;
  if ( v29 == 3 )
  {
    v6 = v4[2];
  }
  else if ( v29 == 2 )
  {
    v6 = *((_DWORD *)v4 + 2);
  }
  else
  {
    v6 = *((unsigned __int8 *)v4 + 2);
  }
  v7 = v31;
  v8 = HIDWORD(v28) + v31 * v6;
  if ( v30 )
  {
    v10 = *(double *)v8;
    *(float *)&v38 = v10 * p_m_scaling->mVec128.m128_f32[0];
    v11 = *(double *)(v8 + 8);
    *((float *)&v38 + 1) = v11 * p_m_scaling->mVec128.m128_f32[1];
    v12 = *(double *)(v8 + 16);
    *(float *)&v39 = v12 * p_m_scaling->mVec128.m128_f32[2];
    HIDWORD(v39) = 0;
    this->m_triangle[2].mVec128.m128_u64[0] = v38;
    v9 = v39;
  }
  else
  {
    *(float *)&v36 = p_m_scaling->mVec128.m128_f32[0] * *(float *)v8;
    *((float *)&v36 + 1) = *(float *)(v8 + 4) * p_m_scaling->mVec128.m128_f32[1];
    *(float *)&v37 = *(float *)(v8 + 8) * p_m_scaling->mVec128.m128_f32[2];
    HIDWORD(v37) = 0;
    this->m_triangle[2].mVec128.m128_u64[0] = v36;
    v9 = v37;
  }
  v13 = v29;
  this->m_triangle[2].mVec128.m128_u64[1] = v9;
  if ( v13 == 3 )
  {
    v14 = v4[1];
  }
  else if ( v13 == 2 )
  {
    v14 = *((_DWORD *)v4 + 1);
  }
  else
  {
    v14 = *((unsigned __int8 *)v4 + 1);
  }
  v15 = HIDWORD(v28);
  v16 = HIDWORD(v28) + v7 * v14;
  if ( v30 )
  {
    v18 = *(double *)v16;
    *(float *)&v38 = v18 * p_m_scaling->mVec128.m128_f32[0];
    v19 = *(double *)(v16 + 8);
    *((float *)&v38 + 1) = v19 * p_m_scaling->mVec128.m128_f32[1];
    v20 = *(double *)(v16 + 16);
    *(float *)&v39 = v20 * p_m_scaling->mVec128.m128_f32[2];
    HIDWORD(v39) = 0;
    this->m_triangle[1].mVec128.m128_u64[0] = v38;
    v17 = v39;
  }
  else
  {
    *(float *)&v36 = p_m_scaling->mVec128.m128_f32[0] * *(float *)v16;
    *((float *)&v36 + 1) = *(float *)(v16 + 4) * p_m_scaling->mVec128.m128_f32[1];
    *(float *)&v37 = *(float *)(v16 + 8) * p_m_scaling->mVec128.m128_f32[2];
    HIDWORD(v37) = 0;
    this->m_triangle[1].mVec128.m128_u64[0] = v36;
    v17 = v37;
  }
  v21 = v29;
  this->m_triangle[1].mVec128.m128_u64[1] = v17;
  if ( v21 == 3 )
  {
    v22 = *v4;
  }
  else if ( v21 == 2 )
  {
    v22 = *(_DWORD *)v4;
  }
  else
  {
    v22 = *(unsigned __int8 *)v4;
  }
  v23 = v15 + v7 * v22;
  if ( v30 )
  {
    v25 = *(double *)v23;
    *(float *)&v38 = v25 * p_m_scaling->mVec128.m128_f32[0];
    v26 = *(double *)(v23 + 8);
    *((float *)&v38 + 1) = v26 * p_m_scaling->mVec128.m128_f32[1];
    v27 = *(double *)(v23 + 16);
    HIDWORD(v39) = 0;
    *(float *)&v39 = (float)v27 * p_m_scaling->mVec128.m128_f32[2];
    this->m_triangle[0].mVec128.m128_u64[0] = v38;
    v24 = v39;
  }
  else
  {
    *(float *)&v36 = p_m_scaling->mVec128.m128_f32[0] * *(float *)v23;
    *((float *)&v36 + 1) = *(float *)(v23 + 4) * p_m_scaling->mVec128.m128_f32[1];
    v37 = COERCE_UNSIGNED_INT(*(float *)(v23 + 8) * p_m_scaling->mVec128.m128_f32[2]);
    this->m_triangle[0].mVec128.m128_u64[0] = v36;
    v24 = v37;
  }
  this->m_triangle[0].mVec128.m128_u64[1] = v24;
  this->m_callback->processTriangle(this->m_callback, this->m_triangle, nodeSubPart, nodeTriangleIndex);
  this->m_meshInterface->unLockReadOnlyVertexBase(this->m_meshInterface, nodeSubPart);
}
