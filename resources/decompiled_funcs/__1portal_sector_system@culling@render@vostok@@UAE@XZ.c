void __thiscall vostok::render::culling::portal_sector_system::~portal_sector_system(
        vostok::render::culling::portal_sector_system *this)
{
  void *m_occlusion_results_buffer; // eax
  void *m_reconstruction_info_actuality_tick_high; // esi
  void *m_occlusion_bounds_buffer; // eax
  vostok::render::culling::sector_double_query_preventer *m_object; // ecx
  void *v6; // esi
  vostok::render::culling::sector_double_query_preventer *m_preventer; // edi
  vostok::render::culling::sector_double_query_preventer *v8; // esi
  vostok::render::culling::portal_sector_system::quad *M_start; // eax
  void *v10; // esi
  vostok::render::culling::portal_sector_structure *v11; // eax

  this->__vftable = (vostok::render::culling::portal_sector_system_vtbl *)&vostok::render::culling::portal_sector_system::`vftable';
  this->m_occlusion_results.m_end = this->m_occlusion_results.m_begin;
  m_occlusion_results_buffer = this->m_occlusion_results_buffer;
  if ( m_occlusion_results_buffer )
  {
    m_reconstruction_info_actuality_tick_high = (void *)HIDWORD(vostok::render::g_allocator.m_object->m_reconstruction_info_actuality_tick);
    BYTE2(vostok::render::g_allocator.m_object->m_children_resources.m_lock) = 0;
    vostok_mspace_free(m_reconstruction_info_actuality_tick_high, m_occlusion_results_buffer);
    this->m_occlusion_results_buffer = 0;
  }
  this->m_occlusion_bounds.m_end = this->m_occlusion_bounds.m_begin;
  m_occlusion_bounds_buffer = this->m_occlusion_bounds_buffer;
  m_object = (vostok::render::culling::sector_double_query_preventer *)vostok::render::g_allocator.m_object;
  if ( m_occlusion_bounds_buffer )
  {
    v6 = (void *)HIDWORD(vostok::render::g_allocator.m_object->m_reconstruction_info_actuality_tick);
    BYTE2(vostok::render::g_allocator.m_object->m_children_resources.m_lock) = 0;
    vostok_mspace_free(v6, m_occlusion_bounds_buffer);
    this->m_occlusion_bounds_buffer = 0;
    m_object = (vostok::render::culling::sector_double_query_preventer *)vostok::render::g_allocator.m_object;
  }
  m_preventer = this->m_preventer;
  v8 = m_object;
  if ( m_preventer )
  {
    vostok::render::culling::sector_double_query_preventer::~sector_double_query_preventer(m_object, m_preventer);
    BYTE2(v8[1].m_sectors_max_rects) = 0;
    vostok_mspace_free(v8->m_frustum_images._M_impl._M_finish, m_preventer);
    this->m_preventer = 0;
  }
  this->m_occlusion_results.m_end = this->m_occlusion_results.m_begin;
  this->m_occlusion_bounds.m_end = this->m_occlusion_bounds.m_begin;
  M_start = this->m_quads._M_impl._M_start;
  if ( M_start )
  {
    v10 = (void *)HIDWORD(vostok::render::g_allocator.m_object->m_reconstruction_info_actuality_tick);
    BYTE2(vostok::render::g_allocator.m_object->m_children_resources.m_lock) = 0;
    vostok_mspace_free(v10, M_start);
  }
  v11 = this->m_structure.m_object;
  if ( v11 && !_InterlockedExchangeAdd(&v11->m_reference_count, 0xFFFFFFFF) )
    vostok::resources::unmanaged_intrusive_base::destroy(
      &this->m_structure.m_object->vostok::resources::unmanaged_intrusive_base,
      this->m_structure.m_object);
  vostok::resources::unmanaged_resource::~unmanaged_resource(this);
}
