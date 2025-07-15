vostok::collision::triangle_mesh_buffer *__thiscall vostok::collision::triangle_mesh_buffer::`vector deleting destructor'(
        vostok::collision::triangle_mesh_buffer *this,
        char a2)
{
  vostok::math::float3 *M_start; // ecx

  stlp_std::priv::_Vector_base<unsigned int,vostok::vectora_allocator<unsigned int>>::~_Vector_base<unsigned int,vostok::vectora_allocator<unsigned int>>(
    (stlp_std::priv::_Vector_base<unsigned int,vostok::vectora_allocator<unsigned int> > *)this,
    (int)&this->m_indices);
  M_start = this->m_vertices._M_impl._M_start;
  if ( M_start )
    this->m_vertices._M_impl._M_end_of_storage.m_allocator->call_free(
      this->m_vertices._M_impl._M_end_of_storage.m_allocator,
      M_start,
      "vostok::detail::std_allocator<class vostok::math::float3>::deallocate",
      "c:\\survarium.deploy\\sources\\vostok/std_allocator_inline.h",
      102u);
  vostok::collision::triangle_mesh_geometry::~triangle_mesh_geometry(this);
  if ( (a2 & 1) != 0 )
    operator delete(this);
  return this;
}
