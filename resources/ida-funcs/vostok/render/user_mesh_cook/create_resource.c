void __thiscall vostok::render::user_mesh_cook::create_resource(
        vostok::render::user_mesh_cook *this,
        vostok::resources::resource_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base> *in_out_query,
        vostok::const_buffer raw_file_data,
        vostok::mutable_buffer in_out_unmanaged_resource_buffer)
{
  vostok::memory::chunk_reader *v4; // ecx
  vostok::render::render_surface *render_surface; // ebx
  vostok::memory::doug_lea_allocator *v6; // esi
  char *v7; // eax
  vostok::memory::doug_lea_allocator *v8; // ecx
  char *v9; // eax
  vostok::render::render_model_instance_impl *v10; // ecx
  char *v11; // edi
  vostok::render::render_surface_instance *v12; // ecx
  vostok::resources::query_result_for_cook *v13; // ecx
  vostok::resources::query_result_for_cook *v14; // ecx
  vostok::resources::resource_ptr<survarium::pure_game_effect_emitter_base,vostok::resources::unmanaged_intrusive_base> v15; // [esp-Ch] [ebp-74h] BYREF
  const vostok::resources::memory_type *v16; // [esp-8h] [ebp-70h]
  unsigned int v17; // [esp-4h] [ebp-6Ch]
  const char *v18; // [esp+0h] [ebp-68h]
  const char *v19; // [esp+4h] [ebp-64h]
  unsigned int v20; // [esp+8h] [ebp-60h]
  const unsigned __int8 *v21[3]; // [esp+10h] [ebp-58h] BYREF
  vostok::memory::chunk_reader v22; // [esp+1Ch] [ebp-4Ch] BYREF
  unsigned __int8 dst[44]; // [esp+3Ch] [ebp-2Ch] BYREF

  vostok::memory::chunk_reader::chunk_reader(
    &v22,
    (const unsigned __int8 *)raw_file_data.m_data,
    (vostok::memory::chunk_reader *)this,
    raw_file_data.m_size,
    (vostok::memory::chunk_reader::chunk_type)v18);
  vostok::memory::chunk_reader::open_reader(
    v4,
    &v22,
    v21,
    (vostok::memory::chunk_reader::chunk_type *)1,
    (unsigned int)v18);
  memcpy(dst, (unsigned __int8 *)v21[1], sizeof(dst));
  render_surface = vostok::render::model_factory::create_render_surface(dst[1]);
  ((void (__thiscall *)(vostok::render::render_surface *, vostok::memory::chunk_reader *))render_surface->__vftable[1].~vostok::render::render_surface)(
    render_surface,
    &v22);
  v6 = vostok::render::g_allocator;
  v7 = type_info::raw_name(&vostok::render::user_render_model_instance `RTTI Type Descriptor');
  v9 = vostok::memory::doug_lea_allocator::malloc_impl(v8, (int)v6, 0x2A0u, v7, v18, v19, v20);
  v11 = v9;
  if ( v9 )
  {
    vostok::render::render_model_instance_impl::render_model_instance_impl(v10, (int)v9);
    *(_DWORD *)v11 = &vostok::render::user_render_model_instance::`vftable';
    vostok::render::render_surface_instance::render_surface_instance(v12, (int)(v11 + 612));
  }
  else
  {
    v11 = 0;
  }
  *((_DWORD *)v11 + 152) = render_surface;
  *((_DWORD *)v11 + 157) = render_surface;
  v17 = 672;
  v16 = &vostok::resources::nocache_memory;
  *((_DWORD *)v11 + 162) = v11 + 332;
  v15.m_object = (survarium::pure_game_effect_emitter_base *)v10;
  *((_DWORD *)v11 + 163) = v11 + 396;
  *((_DWORD *)v11 + 158) = v11;
  *((_DWORD *)v11 + 160) = 3;
  vostok::resources::resource_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base>::resource_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base>(
    &v15,
    (survarium::pure_game_effect_emitter_base *)v11);
  vostok::resources::query_result_for_cook::set_unmanaged_resource(
    v13,
    in_out_query,
    (vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>)v15.m_object,
    v16,
    v17);
  vostok::resources::query_result_for_cook::finish_query_impl(
    v14,
    (vostok::memory::single_size_buffer_allocator<76,vostok::threading::single_threading_policy> *)in_out_query,
    result_out_of_memory,
    assert_on_fail_true,
    result_fail);
}
