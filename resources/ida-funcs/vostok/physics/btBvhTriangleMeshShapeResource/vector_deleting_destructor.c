vostok::physics::btBvhTriangleMeshShapeResource *__thiscall vostok::physics::btBvhTriangleMeshShapeResource::`vector deleting destructor'(
        vostok::physics::btBvhTriangleMeshShapeResource *this,
        char a2)
{
  vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock>::dec(&this->m_raw_indices);
  vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock>::dec(&this->m_raw_vertices);
  btBvhTriangleMeshShape::~btBvhTriangleMeshShape(this);
  if ( (a2 & 1) != 0 )
    btAlignedFreeInternal(this);
  return this;
}
