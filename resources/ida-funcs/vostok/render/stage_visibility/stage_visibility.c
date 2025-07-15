void __thiscall vostok::render::stage_visibility::stage_visibility(
        vostok::render::renderer_context *context,
        vostok::render::stage_visibility *this,
        vostok::render::renderer *in_renderer)
{
  vostok::memory::doug_lea_allocator *v3; // esi
  char *v4; // eax
  vostok::memory::doug_lea_allocator *v5; // ecx
  char *v6; // eax
  vostok::render::hw_hiz_occlusion_manager *v7; // eax
  vostok::memory::doug_lea_allocator *v8; // esi
  char *v9; // eax
  vostok::memory::doug_lea_allocator *v10; // ecx
  char *v11; // eax
  vostok::memory::doug_lea_allocator *v12; // esi
  unsigned __int8 *v13; // eax
  const char *v14; // [esp+0h] [ebp-Ch]
  const char *v15; // [esp+0h] [ebp-Ch]
  const char *v16; // [esp+0h] [ebp-Ch]
  const char *v17; // [esp+4h] [ebp-8h]
  const char *v18; // [esp+4h] [ebp-8h]
  const char *v19; // [esp+4h] [ebp-8h]
  unsigned int v20; // [esp+8h] [ebp-4h]
  unsigned int v21; // [esp+8h] [ebp-4h]
  unsigned int v22; // [esp+8h] [ebp-4h]

  vostok::render::stage::stage(this, context, in_renderer);
  this->m_portals_offset_to_results = 0;
  v3 = vostok::render::g_allocator;
  this->__vftable = (vostok::render::stage_visibility_vtbl *)&vostok::render::stage_visibility::`vftable';
  this->m_use_hiz_culling = 1;
  this->m_data_ready = 1;
  v4 = type_info::raw_name(&vostok::render::hw_hiz_occlusion_manager `RTTI Type Descriptor');
  v6 = vostok::memory::doug_lea_allocator::malloc_impl(v5, (int)v3, 0x124u, v4, v14, v17, v20);
  if ( v6 )
    vostok::render::hw_hiz_occlusion_manager::hw_hiz_occlusion_manager(
      (vostok::render::hw_hiz_occlusion_manager *)vostok::quasi_singleton<vostok::render::options>::pinst,
      (unsigned int)v6,
      vostok::quasi_singleton<vostok::render::options>::pinst->current.m_hiz_occlusion_culling_width,
      vostok::quasi_singleton<vostok::render::options>::pinst->current.m_hiz_occlusion_culling_height);
  else
    v7 = 0;
  v8 = vostok::render::g_allocator;
  this->m_occlusion_manager = v7;
  v9 = type_info::raw_name(&vostok::math::float4 `RTTI Type Descriptor');
  v11 = vostok::memory::doug_lea_allocator::malloc_impl(v10, (int)v8, (unsigned int)&loc_100006 + 2, v9, v15, v18, v21);
  v12 = vostok::render::g_allocator;
  *(_DWORD *)v11 = &_sbh_sizeHeaderList;
  v11 += 4;
  *(_DWORD *)v11 = 16;
  this->m_static_bounds_array = (vostok::math::float4 *)(v11 + 4);
  v13 = vostok::memory::new_array_helper<unsigned char>::call<vostok::memory::doug_lea_allocator>(
          v12,
          (const unsigned int)&_sbh_sizeHeaderList,
          v16,
          v19,
          v22);
  this->m_current_occlusion_buffer_size = 0;
  this->m_static_results_array = v13;
}
