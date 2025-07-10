void __thiscall btTriangleMeshShape::processAllTriangles(
        btTriangleMeshShape *this,
        btTriangleCallback *callback,
        const btVector3 *aabbMin,
        const btVector3 *aabbMax)
{
  btStridingMeshInterface *m_meshInterface; // ecx
  unsigned __int64 v5; // xmm0_8
  _DWORD v6[4]; // [esp+3Ch] [ebp-30h] BYREF
  btVector3 v7; // [esp+4Ch] [ebp-20h]
  unsigned __int64 v8; // [esp+5Ch] [ebp-10h]
  unsigned __int64 v9; // [esp+64h] [ebp-8h]

  m_meshInterface = this->m_meshInterface;
  v6[1] = callback;
  v7.mVec128 = aabbMin->mVec128;
  v8 = aabbMax->mVec128.m128_u64[0];
  v5 = aabbMax->mVec128.m128_u64[1];
  v6[0] = &`btTriangleMeshShape::processAllTriangles'::`2'::FilteredCallback::`vftable';
  v9 = v5;
  m_meshInterface->InternalProcessAllTriangles(m_meshInterface, (btInternalTriangleIndexCallback *)v6, aabbMin, aabbMax);
}
