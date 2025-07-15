btBvhTriangleMeshShape::performRaycast::__l2::MyNodeOverlapCallback *__thiscall `btBvhTriangleMeshShape::performConvexcast'::`2'::MyNodeOverlapCallback::`scalar deleting destructor'(
        btBvhTriangleMeshShape::performRaycast::__l2::MyNodeOverlapCallback *this,
        char a2)
{
  this->__vftable = (btBvhTriangleMeshShape::performRaycast::__l2::MyNodeOverlapCallback_vtbl *)&btNodeOverlapCallback::`vftable';
  if ( (a2 & 1) != 0 )
    operator delete(this);
  return this;
}
