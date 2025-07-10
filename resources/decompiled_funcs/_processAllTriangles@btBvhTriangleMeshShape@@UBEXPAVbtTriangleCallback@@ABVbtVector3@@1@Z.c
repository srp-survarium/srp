void __thiscall btBvhTriangleMeshShape::processAllTriangles(
        btBvhTriangleMeshShape *this,
        btTriangleCallback *callback,
        const btVector3 *aabbMin,
        const btVector3 *aabbMax)
{
  btStridingMeshInterface *m_meshInterface; // eax
  btOptimizedBvh *m_bvh; // ecx
  btNodeOverlapCallback nodeCallback; // [esp+40h] [ebp-40h] BYREF
  btStridingMeshInterface *v7; // [esp+44h] [ebp-3Ch]
  btTriangleCallback *v8; // [esp+48h] [ebp-38h]

  m_meshInterface = this->m_meshInterface;
  m_bvh = this->m_bvh;
  v7 = m_meshInterface;
  v8 = callback;
  nodeCallback.__vftable = (btNodeOverlapCallback_vtbl *)&`btBvhTriangleMeshShape::processAllTriangles'::`2'::MyNodeOverlapCallback::`vftable';
  btQuantizedBvh::reportAabbOverlappingNodex(m_bvh, &nodeCallback, aabbMin, aabbMax);
}
