void __thiscall btBvhTriangleMeshShape::processAllTriangles(
        btBvhTriangleMeshShape *this,
        btTriangleCallback *callback,
        const btVector3 *aabbMin,
        const btVector3 *aabbMax)
{
  btStridingMeshInterface *m_meshInterface; // eax
  btOptimizedBvh *m_bvh; // ecx
  btNodeOverlapCallback nodeCallback; // [esp+0h] [ebp-40h] BYREF
  btStridingMeshInterface *v7; // [esp+4h] [ebp-3Ch]
  btTriangleCallback *v8; // [esp+8h] [ebp-38h]

  m_meshInterface = this->m_meshInterface;
  m_bvh = this->m_bvh;
  v7 = m_meshInterface;
  nodeCallback.__vftable = (btNodeOverlapCallback_vtbl *)&`btBvhTriangleMeshShape::processAllTriangles'::`2'::MyNodeOverlapCallback::`vftable';
  v8 = callback;
  btQuantizedBvh::reportAabbOverlappingNodex(m_bvh, &nodeCallback, aabbMin, aabbMax);
}
