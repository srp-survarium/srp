void __userpurge btBvhTriangleMeshShape::performRaycast(
        btBvhTriangleMeshShape *this@<eax>,
        const btVector3 *rayTarget@<edx>,
        btTriangleCallback *callback,
        const btVector3 *raySource)
{
  btStridingMeshInterface *m_meshInterface; // ecx
  btOptimizedBvh *m_bvh; // eax
  btNodeOverlapCallback nodeCallback; // [esp+4h] [ebp-2Ch] BYREF
  btStridingMeshInterface *v7; // [esp+8h] [ebp-28h]
  btTriangleCallback *v8; // [esp+Ch] [ebp-24h]
  btVector3 aabbMax; // [esp+10h] [ebp-20h] BYREF
  btVector3 aabbMin; // [esp+20h] [ebp-10h] BYREF

  m_meshInterface = this->m_meshInterface;
  m_bvh = this->m_bvh;
  v7 = m_meshInterface;
  v8 = callback;
  nodeCallback.__vftable = (btNodeOverlapCallback_vtbl *)&`btBvhTriangleMeshShape::performRaycast'::`2'::MyNodeOverlapCallback::`vftable';
  memset(&aabbMax, 0, sizeof(aabbMax));
  memset(&aabbMin, 0, sizeof(aabbMin));
  btQuantizedBvh::reportBoxCastOverlappingNodex(m_bvh, &nodeCallback, raySource, rayTarget, &aabbMin, &aabbMax);
}
