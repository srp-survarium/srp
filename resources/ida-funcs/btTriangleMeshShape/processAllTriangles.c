void __thiscall btTriangleMeshShape::processAllTriangles(
        btTriangleMeshShape *this,
        btTriangleCallback *callback,
        const btVector3 *aabbMin,
        const btVector3 *aabbMax)
{
  btStridingMeshInterface *m_meshInterface; // ecx
  _DWORD v5[4]; // [esp+10h] [ebp-30h] BYREF
  unsigned __int64 v6; // [esp+20h] [ebp-20h]
  unsigned __int64 v7; // [esp+28h] [ebp-18h]
  btVector3 v8; // [esp+30h] [ebp-10h]

  v5[0] = &`btTriangleMeshShape::processAllTriangles'::`2'::FilteredCallback::`vftable';
  v5[1] = callback;
  v6 = aabbMin->mVec128.m128_u64[0];
  m_meshInterface = this->m_meshInterface;
  v7 = aabbMin->mVec128.m128_u64[1];
  v8.mVec128 = aabbMax->mVec128;
  m_meshInterface->InternalProcessAllTriangles(m_meshInterface, (btInternalTriangleIndexCallback *)v5, aabbMin, aabbMax);
}
