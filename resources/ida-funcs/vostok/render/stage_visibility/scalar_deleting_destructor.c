vostok::render::stage_visibility *__thiscall vostok::render::stage_visibility::`scalar deleting destructor'(
        vostok::render::stage_visibility *this,
        char a2)
{
  vostok::math::float4 *m_static_bounds_array; // eax
  unsigned __int8 *m_static_results_array; // eax
  vostok::render::hw_hiz_occlusion_manager *m_occlusion_manager; // esi
  vostok::memory::doug_lea_allocator *v6; // ebx
  vostok::memory::doug_lea_allocator *v7; // ecx
  const char *v9; // [esp+0h] [ebp-Ch]
  const char *v10; // [esp+4h] [ebp-8h]
  unsigned int v11; // [esp+8h] [ebp-4h]

  this->__vftable = (vostok::render::stage_visibility_vtbl *)&vostok::render::stage_visibility::`vftable';
  m_static_bounds_array = this->m_static_bounds_array;
  if ( m_static_bounds_array )
    vostok::memory::doug_lea_allocator::free_impl(
      (vostok::memory::doug_lea_allocator *)this,
      (int)vostok::render::g_allocator,
      (char *)&m_static_bounds_array[-1].elements[2],
      v9,
      v10,
      v11);
  m_static_results_array = this->m_static_results_array;
  if ( m_static_results_array )
    vostok::memory::doug_lea_allocator::free_impl(
      (vostok::memory::doug_lea_allocator *)this,
      (int)vostok::render::g_allocator,
      (char *)m_static_results_array - 8,
      v9,
      v10,
      v11);
  m_occlusion_manager = this->m_occlusion_manager;
  v6 = vostok::render::g_allocator;
  if ( m_occlusion_manager )
  {
    vostok::render::hw_hiz_occlusion_manager::~hw_hiz_occlusion_manager(
      (vostok::render::hw_hiz_occlusion_manager *)this,
      (int)m_occlusion_manager);
    vostok::memory::doug_lea_allocator::free_impl(
      v7,
      (int)v6,
      (char *)&m_occlusion_manager->m_use_scene_depth_buffer,
      v9,
      v10,
      v11);
    this->m_occlusion_manager = 0;
  }
  this->__vftable = (vostok::render::stage_visibility_vtbl *)&vostok::render::stage::`vftable';
  if ( (a2 & 1) != 0 )
    operator delete(this);
  return this;
}
