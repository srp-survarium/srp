btOptimizedBvh::build::__l2::NodeTriangleCallback *__thiscall `btOptimizedBvh::build'::`3'::QuantizedNodeTriangleCallback::`scalar deleting destructor'(
        btOptimizedBvh::build::__l2::NodeTriangleCallback *this,
        char a2)
{
  this->__vftable = (btOptimizedBvh::build::__l2::NodeTriangleCallback_vtbl *)&btInternalTriangleIndexCallback::`vftable';
  if ( (a2 & 1) != 0 )
    operator delete(this);
  return this;
}
