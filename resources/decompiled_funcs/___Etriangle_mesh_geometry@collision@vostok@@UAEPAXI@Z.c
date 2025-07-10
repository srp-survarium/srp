vostok::collision::triangle_mesh_geometry *__thiscall vostok::collision::triangle_mesh_geometry::`vector deleting destructor'(
        vostok::collision::triangle_mesh_geometry *this,
        char a2)
{
  unsigned int *M_start; // eax

  this->__vftable = (vostok::collision::triangle_mesh_geometry_vtbl *)&stru_955E40.m_children_resources.m_thread_id;
  M_start = this->m_triangle_data._M_impl._M_start;
  if ( M_start )
    this->m_triangle_data._M_impl._M_end_of_storage.m_allocator->call_free(
      this->m_triangle_data._M_impl._M_end_of_storage.m_allocator,
      M_start);
  this->__vftable = (vostok::collision::triangle_mesh_geometry_vtbl *)&vostok::collision::geometry::`vftable';
  vostok::resources::unmanaged_resource::~unmanaged_resource(this);
  if ( (a2 & 1) != 0 )
    operator delete(this);
  return this;
}
