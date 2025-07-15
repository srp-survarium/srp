void __userpurge btTriangleMeshShape::processAllTriangles_::_2_::FilteredCallback::FilteredCallback(
        btTriangleCallback *callback@<esi>,
        const btVector3 *aabbMin@<edx>,
        const btVector3 *aabbMax@<ecx>,
        btTriangleMeshShape::processAllTriangles::__l2::FilteredCallback *this)
{
  this->__vftable = (btTriangleMeshShape::processAllTriangles::__l2::FilteredCallback_vtbl *)&`btTriangleMeshShape::processAllTriangles'::`2'::FilteredCallback::`vftable';
  this->m_callback = callback;
  this->m_aabbMin = (btVector3)aabbMin->mVec128;
  this->m_aabbMax = (btVector3)aabbMax->mVec128;
}
