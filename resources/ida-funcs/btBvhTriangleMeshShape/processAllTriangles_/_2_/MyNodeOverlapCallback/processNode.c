void __thiscall btBvhTriangleMeshShape::processAllTriangles_::_2_::MyNodeOverlapCallback::processNode(
        btBvhTriangleMeshShape::processAllTriangles::__l2::MyNodeOverlapCallback *this,
        int nodeSubPart,
        int nodeTriangleIndex)
{
  int v4; // ecx
  int v5; // edx
  btVector3 *p_m_scaling; // eax
  int v7; // edx
  int v8; // edx
  __m128 *p_mVec128; // edi
  float *v10; // esi
  float v11; // xmm1_4
  float v12; // xmm1_4
  int *v13; // edi
  int *v14; // esi
  btVector3 *v15; // [esp+24h] [ebp-48h]
  int v16; // [esp+28h] [ebp-44h]
  int v17; // [esp+2Ch] [ebp-40h] BYREF
  int v18; // [esp+30h] [ebp-3Ch] BYREF
  int v19; // [esp+34h] [ebp-38h] BYREF
  int v20; // [esp+38h] [ebp-34h] BYREF
  int v21; // [esp+3Ch] [ebp-30h] BYREF
  int v22; // [esp+40h] [ebp-2Ch] BYREF
  int v23; // [esp+44h] [ebp-28h] BYREF
  char v24[4]; // [esp+48h] [ebp-24h] BYREF
  float v25[4]; // [esp+4Ch] [ebp-20h] BYREF
  float v26[4]; // [esp+5Ch] [ebp-10h] BYREF

  this->m_meshInterface->getLockedReadOnlyVertexIndexBase(
    this->m_meshInterface,
    (const unsigned __int8 **)&v19,
    (int *)v24,
    (PHY_ScalarType *)&v22,
    &v18,
    (const unsigned __int8 **)&v21,
    &v20,
    &v23,
    (PHY_ScalarType *)&v17,
    nodeSubPart);
  v4 = v21 + nodeTriangleIndex * v20;
  v5 = 2;
  p_m_scaling = &this->m_meshInterface->m_scaling;
  v16 = 2;
  v15 = &this->m_triangle[2];
  while ( 1 )
  {
    if ( v17 == 3 )
      v7 = *(unsigned __int16 *)(v4 + 2 * v5);
    else
      v7 = v17 == 2 ? *(_DWORD *)(v4 + 4 * v5) : *(unsigned __int8 *)(v5 + v4);
    v8 = v19 + v18 * v7;
    p_mVec128 = &v15->mVec128;
    if ( v22 )
    {
      v11 = *(double *)v8;
      v26[0] = v11 * p_m_scaling->mVec128.m128_f32[0];
      v12 = *(double *)(v8 + 8);
      v26[1] = v12 * p_m_scaling->mVec128.m128_f32[1];
      v26[2] = (float)*(double *)(v8 + 16) * p_m_scaling->mVec128.m128_f32[2];
      v26[3] = 0.0;
      v10 = v26;
    }
    else
    {
      v25[0] = p_m_scaling->mVec128.m128_f32[0] * *(float *)v8;
      v25[1] = *(float *)(v8 + 4) * p_m_scaling->mVec128.m128_f32[1];
      v25[2] = *(float *)(v8 + 8) * p_m_scaling->mVec128.m128_f32[2];
      v25[3] = 0.0;
      v10 = v25;
    }
    --v16;
    --v15;
    p_mVec128->m128_f32[0] = *v10;
    v14 = (int *)(v10 + 1);
    v13 = &p_mVec128->m128_i32[1];
    *v13 = *v14++;
    *++v13 = *v14;
    v13[1] = v14[1];
    if ( v16 < 0 )
      break;
    v5 = v16;
  }
  this->m_callback->processTriangle(this->m_callback, this->m_triangle, nodeSubPart, nodeTriangleIndex);
  this->m_meshInterface->unLockReadOnlyVertexBase(this->m_meshInterface, nodeSubPart);
}
