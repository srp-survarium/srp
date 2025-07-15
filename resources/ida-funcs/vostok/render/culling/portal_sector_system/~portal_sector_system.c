void __thiscall vostok::render::culling::portal_sector_system::~portal_sector_system(
        vostok::render::culling::portal_sector_system *this)
{
  void **p_m_occlusion_results_buffer; // edi
  vostok::memory::doug_lea_allocator *v3; // esi
  char *m_preventer; // edi
  vostok::memory::doug_lea_allocator *v5; // ecx
  const char *v6; // [esp+0h] [ebp-10h]
  const char *v7; // [esp+4h] [ebp-Ch]
  unsigned int v8; // [esp+8h] [ebp-8h]

  this->__vftable = (vostok::render::culling::portal_sector_system_vtbl *)&vostok::render::culling::portal_sector_system::`vftable';
  p_m_occlusion_results_buffer = &this->m_occlusion_results_buffer;
  this->m_occlusion_results.m_end = this->m_occlusion_results.m_begin;
  if ( this->m_occlusion_results_buffer )
  {
    vostok::memory::doug_lea_allocator::free_impl(
      (vostok::memory::doug_lea_allocator *)this,
      (int)vostok::render::g_allocator,
      (char *)this->m_occlusion_results_buffer,
      v6,
      v7,
      v8);
    *p_m_occlusion_results_buffer = 0;
  }
  this->m_occlusion_bounds.m_end = this->m_occlusion_bounds.m_begin;
  if ( this->m_occlusion_bounds_buffer )
  {
    vostok::memory::doug_lea_allocator::free_impl(
      (vostok::memory::doug_lea_allocator *)this,
      (int)vostok::render::g_allocator,
      (char *)this->m_occlusion_bounds_buffer,
      v6,
      v7,
      v8);
    this->m_occlusion_bounds_buffer = 0;
  }
  v3 = vostok::render::g_allocator;
  m_preventer = (char *)this->m_preventer;
  if ( m_preventer )
  {
    vostok::render::culling::sector_double_query_preventer::~sector_double_query_preventer((vostok::render::culling::sector_double_query_preventer *)this);
    vostok::memory::doug_lea_allocator::free_impl(v5, (int)v3, m_preventer, v6, v7, v8);
    this->m_preventer = 0;
  }
  this->m_occlusion_results.m_end = this->m_occlusion_results.m_begin;
  this->m_occlusion_bounds.m_end = this->m_occlusion_bounds.m_begin;
  this->m_quads.m_end = this->m_quads.m_begin;
  vostok::intrusive_ptr<survarium::weapon_user_animations_container,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec((vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&this->m_structure);
  vostok::resources::unmanaged_resource::~unmanaged_resource(this);
}
