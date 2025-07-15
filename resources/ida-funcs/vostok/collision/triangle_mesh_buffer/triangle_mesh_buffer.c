void __userpurge vostok::collision::triangle_mesh_buffer::triangle_mesh_buffer(
        vostok::collision::triangle_mesh_buffer *this@<ecx>,
        unsigned int vertex_count@<eax>,
        unsigned int allocator,
        signed int vertices,
        unsigned int *indices,
        unsigned int index_count,
        const unsigned int *triangle_data,
        unsigned int triangle_count)
{
  vostok::memory::base_allocator *v8; // ebx
  unsigned __int8 *v11; // edi
  __int64 v12; // rax
  vostok::math::float3 *v13; // eax
  vostok::math::float3 *v14; // ecx
  unsigned __int8 *v15; // eax
  unsigned int *v16; // edx
  unsigned __int8 *v17; // edi
  unsigned int *v18; // eax
  unsigned int *v19; // ecx
  unsigned __int8 *v20; // eax
  unsigned __int8 *v21; // [esp-Ch] [ebp-1Ch]
  unsigned __int8 *v22; // [esp-Ch] [ebp-1Ch]

  v8 = (vostok::memory::base_allocator *)allocator;
  vostok::collision::triangle_mesh_geometry::triangle_mesh_geometry(
    this,
    (int)this,
    (vostok::memory::base_allocator *)allocator);
  v11 = (unsigned __int8 *)(vertices + 12 * vertex_count);
  this->__vftable = (vostok::collision::triangle_mesh_buffer_vtbl *)&vostok::collision::triangle_mesh_buffer::`vftable';
  this->m_vertices._M_impl._M_start = 0;
  this->m_vertices._M_impl._M_finish = 0;
  this->m_vertices._M_impl._M_end_of_storage._M_data = 0;
  v12 = (int)&v11[-vertices];
  this->m_vertices._M_impl._M_end_of_storage.m_allocator = v8;
  allocator = v12 / 12;
  v13 = stlp_std::priv::_STLP_alloc_proxy<vostok::math::float3 *,vostok::math::float3,vostok::vectora_allocator<vostok::math::float3>>::allocate(
          allocator,
          &allocator,
          &this->m_vertices._M_impl._M_end_of_storage);
  v14 = &v13[allocator];
  v21 = (unsigned __int8 *)vertices;
  this->m_vertices._M_impl._M_start = v13;
  this->m_vertices._M_impl._M_end_of_storage._M_data = v14;
  v15 = stlp_std::priv::__ucopy_trivial(v21, v11, (unsigned __int8 *)v13);
  v16 = indices;
  this->m_vertices._M_impl._M_finish = (vostok::math::float3 *)v15;
  v17 = (unsigned __int8 *)&v16[index_count];
  this->m_indices._M_impl._M_start = 0;
  this->m_indices._M_impl._M_finish = 0;
  this->m_indices._M_impl._M_end_of_storage._M_data = 0;
  this->m_indices._M_impl._M_end_of_storage.m_allocator = v8;
  vertices = (v17 - (unsigned __int8 *)v16) >> 2;
  v18 = stlp_std::priv::_STLP_alloc_proxy<unsigned int *,unsigned int,vostok::vectora_allocator<unsigned int>>::allocate(
          vertices,
          (unsigned int *)&vertices,
          &this->m_indices._M_impl._M_end_of_storage);
  v22 = (unsigned __int8 *)indices;
  v19 = &v18[vertices];
  this->m_indices._M_impl._M_start = v18;
  this->m_indices._M_impl._M_end_of_storage._M_data = v19;
  v20 = stlp_std::priv::__ucopy_trivial(v22, v17, (unsigned __int8 *)v18);
  this->m_indices._M_impl._M_finish = (unsigned int *)v20;
  vostok::collision::triangle_mesh_geometry::initialize(
    this,
    v8,
    this->m_vertices._M_impl._M_start,
    this->m_vertices._M_impl._M_finish - this->m_vertices._M_impl._M_start,
    (const IceMaths::IndexedTriangle *)this->m_indices._M_impl._M_start,
    (v20 - (unsigned __int8 *)this->m_indices._M_impl._M_start) >> 2);
}
