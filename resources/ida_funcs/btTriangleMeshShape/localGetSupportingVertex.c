btVector3 *__thiscall btTriangleMeshShape::localGetSupportingVertex(
        btTriangleMeshShape *this,
        btVector3 *result,
        const btVector3 *vec)
{
  void (__thiscall *processAllTriangles)(struct btTriangleMeshShape *, btTriangleCallback *, const btVector3 *, const btVector3 *); // edx
  btVector3 *v5; // eax
  _DWORD v6[4]; // [esp+21Ch] [ebp-E0h] BYREF
  _DWORD v7[4]; // [esp+22Ch] [ebp-D0h] BYREF
  btTransform trans; // [esp+23Ch] [ebp-C0h] BYREF
  SupportVertexCallback v9; // [esp+27Ch] [ebp-80h] BYREF

  trans.m_basis.m_el[0].mVec128.m128_u64[0] = (unsigned int)clear_value;
  memset(&trans.m_basis.m_el[0].m_floats[2], 0, 12);
  *(unsigned __int64 *)((char *)trans.m_basis.m_el[1].mVec128.m128_u64 + 4) = (unsigned int)clear_value;
  memset(&trans.m_basis.m_el[1].m_floats[3], 0, 12);
  trans.m_basis.m_el[2].mVec128.m128_u64[1] = (unsigned int)clear_value;
  memset(&trans.m_origin, 0, sizeof(trans.m_origin));
  SupportVertexCallback::SupportVertexCallback(&v9);
  processAllTriangles = this->processAllTriangles;
  v7[0] = 1566444395;
  v7[1] = 1566444395;
  v7[2] = 1566444395;
  v7[3] = 0;
  v6[0] = -581039253;
  v6[1] = -581039253;
  v6[2] = -581039253;
  v6[3] = 0;
  processAllTriangles(this, &v9, (const btVector3 *)v6, (const btVector3 *)v7);
  v5 = result;
  *result = v9.m_supportVertexLocal;
  return v5;
}
