btTriangleMeshShape::processAllTriangles::__l2::FilteredCallback *__thiscall `btOptimizedBvh::build'::`3'::QuantizedNodeTriangleCallback::`scalar deleting destructor'(
        btTriangleMeshShape::processAllTriangles::__l2::FilteredCallback *this,
        char a2)
{
  this->__vftable = (btTriangleMeshShape::processAllTriangles::__l2::FilteredCallback_vtbl *)&btInternalTriangleIndexCallback::`vftable';
  if ( (a2 & 1) != 0 )
    operator delete(this);
  return this;
}
