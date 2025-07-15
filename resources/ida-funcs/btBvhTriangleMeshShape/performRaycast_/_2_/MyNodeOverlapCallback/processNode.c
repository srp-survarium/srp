void __thiscall btBvhTriangleMeshShape::performRaycast_::_2_::MyNodeOverlapCallback::processNode(
        btBvhTriangleMeshShape::performRaycast::__l2::MyNodeOverlapCallback *this,
        int nodeSubPart,
        int nodeTriangleIndex)
{
  int v4; // ecx
  int v5; // edx
  btVector3 *p_m_scaling; // eax
  int v7; // edx
  int v8; // edx
  char *v9; // edi
  float *v10; // esi
  float v11; // xmm1_4
  float v12; // xmm1_4
  _DWORD *v13; // edi
  _DWORD *v14; // esi
  char *v15; // [esp+24h] [ebp-78h]
  int v16; // [esp+28h] [ebp-74h]
  int v17; // [esp+2Ch] [ebp-70h] BYREF
  int v18; // [esp+30h] [ebp-6Ch] BYREF
  int v19; // [esp+34h] [ebp-68h] BYREF
  int v20; // [esp+38h] [ebp-64h] BYREF
  int v21; // [esp+3Ch] [ebp-60h] BYREF
  int v22; // [esp+40h] [ebp-5Ch] BYREF
  int v23; // [esp+44h] [ebp-58h] BYREF
  _BYTE v24[4]; // [esp+48h] [ebp-54h] BYREF
  float v25[4]; // [esp+4Ch] [ebp-50h] BYREF
  float v26[4]; // [esp+5Ch] [ebp-40h] BYREF
  _BYTE v27[32]; // [esp+6Ch] [ebp-30h] BYREF
  char v28; // [esp+8Ch] [ebp-10h] BYREF

  this->m_meshInterface->getLockedReadOnlyVertexIndexBase(
    this->m_meshInterface,
    (const unsigned __int8 **)&v18,
    (int *)v24,
    (PHY_ScalarType *)&v22,
    &v17,
    (const unsigned __int8 **)&v20,
    &v19,
    &v23,
    (PHY_ScalarType *)&v21,
    nodeSubPart);
  v4 = v20 + nodeTriangleIndex * v19;
  v5 = 2;
  p_m_scaling = &this->m_meshInterface->m_scaling;
  v16 = 2;
  v15 = &v28;
  while ( 1 )
  {
    v7 = v21 == 3 ? *(unsigned __int16 *)(v4 + 2 * v5) : *(_DWORD *)(v4 + 4 * v5);
    v8 = v18 + v17 * v7;
    v9 = v15;
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
    v15 -= 16;
    *(float *)v9 = *v10;
    v14 = v10 + 1;
    v13 = v9 + 4;
    *v13 = *v14++;
    *++v13 = *v14;
    v13[1] = v14[1];
    if ( v16 < 0 )
      break;
    v5 = v16;
  }
  this->m_callback->processTriangle(this->m_callback, (btVector3 *)v27, nodeSubPart, nodeTriangleIndex);
  this->m_meshInterface->unLockReadOnlyVertexBase(this->m_meshInterface, nodeSubPart);
}
