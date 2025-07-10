void __usercall vostok::render::stage_visibility::stage_visibility(
        vostok::render::stage_visibility *this@<edi>,
        vostok::render::renderer *in_renderer@<ecx>,
        vostok::render::renderer_context *context@<eax>)
{
  vostok::render::hw_hiz_occlusion_manager *v3; // eax
  char *v4; // eax
  _DWORD *v5; // eax
  unsigned __int8 *v6; // eax
  unsigned __int8 *v7; // ecx
  unsigned int v8; // [esp+0h] [ebp-4h]

  this->m_context = context;
  this->m_renderer = in_renderer;
  this->m_enabled = 1;
  this->m_prev_enabled = 1;
  this->__vftable = (vostok::render::stage_visibility_vtbl *)&vostok::render::stage_visibility::`vftable';
  this->m_portals_offset_to_results = 0;
  this->m_data_ready = 1;
  if ( vostok::memory::doug_lea_allocator::malloc_impl(
         (vostok::memory::doug_lea_allocator *)vostok::render::g_allocator.m_object,
         0x120u) )
  {
    vostok::render::hw_hiz_occlusion_manager::hw_hiz_occlusion_manager(
      *((vostok::render::hw_hiz_occlusion_manager **)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_action_ids._M_impl._M_start
      + 39),
      *((_DWORD *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_action_ids._M_impl._M_start
      + 39),
      *((_DWORD *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_action_ids._M_impl._M_start
      + 40),
      v8);
  }
  else
  {
    v3 = 0;
  }
  this->m_occlusion_manager = v3;
  v4 = (char *)vostok::memory::doug_lea_allocator::malloc_impl(
                 (vostok::memory::doug_lea_allocator *)vostok::render::g_allocator.m_object,
                 0x40008u);
  *(_DWORD *)v4 = 0x4000;
  v4 += 4;
  *(_DWORD *)v4 = 16;
  this->m_static_bounds_array = (vostok::math::float4 *)(v4 + 4);
  v5 = vostok::memory::doug_lea_allocator::malloc_impl(
         (vostok::memory::doug_lea_allocator *)vostok::render::g_allocator.m_object,
         0x4008u);
  *v5 = 0x4000;
  v6 = (unsigned __int8 *)(v5 + 2);
  *((_DWORD *)v6 - 1) = 1;
  v7 = v6;
  do
  {
    if ( v7 )
      *v7 = 0;
    ++v7;
  }
  while ( v7 != v6 + 0x4000 );
  this->m_static_results_array = v6;
  this->m_current_occlusion_buffer_size = 0;
}
