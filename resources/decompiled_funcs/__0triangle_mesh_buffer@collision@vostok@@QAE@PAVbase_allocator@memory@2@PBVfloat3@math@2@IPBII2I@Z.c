void __userpurge vostok::collision::triangle_mesh_buffer::triangle_mesh_buffer(
        unsigned int vertex_count@<eax>,
        vostok::collision::triangle_mesh_geometry *a2@<ecx>,
        vostok::collision::triangle_mesh_buffer *this,
        vostok::memory::base_allocator *allocator,
        const vostok::math::float3 *vertices,
        const unsigned int *indices,
        stlp_std::priv::_Impl_vector<unsigned int,vostok::vectora_allocator<unsigned int> > *index_count,
        const unsigned int *triangle_data,
        unsigned int triangle_count)
{
  const stlp_std::forward_iterator_tag *v10; // [esp+0h] [ebp-10h]
  const stlp_std::forward_iterator_tag *v11; // [esp+0h] [ebp-10h]

  vostok::collision::triangle_mesh_geometry::triangle_mesh_geometry(a2, (int)this, allocator);
  this->__vftable = (vostok::collision::triangle_mesh_buffer_vtbl *)&vostok::collision::triangle_mesh_buffer::`vftable';
  this->m_vertices._M_impl._M_start = 0;
  this->m_vertices._M_impl._M_finish = 0;
  this->m_vertices._M_impl._M_end_of_storage._M_data = 0;
  this->m_vertices._M_impl._M_end_of_storage.m_allocator = allocator;
  stlp_std::priv::_Impl_vector<vostok::math::float3,vostok::vectora_allocator<vostok::math::float3>>::_M_range_initialize<vostok::math::float3 const *>(
    (stlp_std::priv::_Impl_vector<vostok::math::float3,vostok::vectora_allocator<vostok::math::float3> > *)(3 * vertex_count),
    (int)&this->m_vertices,
    (int)vertices,
    &vertices[vertex_count],
    v10);
  this->m_indices._M_impl._M_start = 0;
  this->m_indices._M_impl._M_finish = 0;
  this->m_indices._M_impl._M_end_of_storage._M_data = 0;
  this->m_indices._M_impl._M_end_of_storage.m_allocator = allocator;
  stlp_std::priv::_Impl_vector<unsigned int,vostok::vectora_allocator<unsigned int>>::_M_range_initialize<unsigned int const *>(
    index_count,
    (int)&this->m_indices,
    (int)indices,
    (unsigned __int8 *)&indices[(_DWORD)index_count],
    v11);
  vostok::collision::triangle_mesh_geometry::initialize(
    this,
    allocator,
    (const IceMaths::Point *)this->m_vertices._M_impl._M_start,
    this->m_vertices._M_impl._M_finish - this->m_vertices._M_impl._M_start,
    (const IceMaths::IndexedTriangle *)this->m_indices._M_impl._M_start,
    this->m_indices._M_impl._M_finish - this->m_indices._M_impl._M_start);
}
