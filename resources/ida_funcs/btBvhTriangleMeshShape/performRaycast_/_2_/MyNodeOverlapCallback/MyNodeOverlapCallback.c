void __userpurge btBvhTriangleMeshShape::performRaycast_::_2_::MyNodeOverlapCallback::MyNodeOverlapCallback(
        btBvhTriangleMeshShape::performRaycast::__l2::MyNodeOverlapCallback *this@<eax>,
        btStridingMeshInterface *meshInterface@<ecx>,
        btTriangleCallback *callback)
{
  this->__vftable = (btBvhTriangleMeshShape::performRaycast::__l2::MyNodeOverlapCallback_vtbl *)&`btBvhTriangleMeshShape::performRaycast'::`2'::MyNodeOverlapCallback::`vftable';
  this->m_meshInterface = meshInterface;
  this->m_callback = callback;
}
