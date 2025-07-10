void __thiscall vostok::render::user_mesh_cook::create_resource(
        vostok::render::user_mesh_cook *this,
        vostok::resources::query_result_for_cook *in_out_query,
        vostok::const_buffer raw_file_data,
        vostok::mutable_buffer in_out_unmanaged_resource_buffer)
{
  vostok::vfs::base_node<1> *v4; // esi
  vostok::render::render_surface *render_surface; // edi
  void *v6; // eax
  vostok::render::user_render_model_instance *v7; // ecx
  int v8; // eax
  vostok::resources::query_result_for_cook *v9; // ecx
  vostok::intrusive_ptr<vostok::configs::binary_config,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> v10; // [esp-Ch] [ebp-6Ch] BYREF
  const vostok::resources::memory_type *v11; // [esp-8h] [ebp-68h]
  unsigned int v12; // [esp-4h] [ebp-64h]
  vostok::memory::chunk_reader::chunk_type *v13; // [esp+0h] [ebp-60h]
  unsigned int chunk_id; // [esp+10h] [ebp-50h] BYREF
  vostok::memory::chunk_reader chunk; // [esp+14h] [ebp-4Ch] BYREF
  unsigned __int8 dst[44]; // [esp+34h] [ebp-2Ch] BYREF

  chunk_id = 0;
  v4 = vostok::mutable_buffer::size((vostok::vfs::vfs_iterator *)&raw_file_data);
  chunk.m_reader.m_data = (const unsigned __int8 *)vostok::intrusive_ptr<survarium::weapon_core_base_state,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::c_ptr((vostok::intrusive_ptr<vostok::sound::encoded_sound_interface,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&raw_file_data);
  chunk.m_reader.m_pointer = chunk.m_reader.m_data;
  chunk.m_reader.m_size = (unsigned int)v4;
  memset(&chunk.m_chunks, 0, 16);
  vostok::memory::chunk_reader::chunk_size((vostok::memory::chunk_reader *)1, (const unsigned int)&chunk_id, v13);
  memcpy(dst, (unsigned __int8 *)chunk.m_reader.m_pointer, sizeof(dst));
  render_surface = vostok::render::model_factory::create_render_surface(dst[1]);
  ((void (__thiscall *)(vostok::render::render_surface *, vostok::memory::chunk_reader *))render_surface->__vftable[1].~vostok::render::render_surface)(
    render_surface,
    &chunk);
  v6 = vostok::memory::doug_lea_allocator::malloc_impl(
         (vostok::memory::doug_lea_allocator *)vostok::render::g_allocator.m_object,
         0x1A8u);
  if ( v6 )
    vostok::render::user_render_model_instance::user_render_model_instance(v7, (int)v6);
  else
    v8 = 0;
  v12 = 424;
  v11 = &vostok::resources::nocache_memory;
  *(_DWORD *)(v8 + 400) = v8 + 324;
  *(_DWORD *)(v8 + 392) = render_surface;
  *(_DWORD *)(v8 + 396) = render_surface;
  *(_DWORD *)(v8 + 404) = v8;
  *(_DWORD *)(v8 + 416) = 3;
  v10.m_object = 0;
  vostok::intrusive_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::set(
    &v10,
    (vostok::configs::binary_config *)v8);
  vostok::resources::query_result_for_cook::set_unmanaged_resource(
    in_out_query,
    (vostok::resources::resource_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base>)v10.m_object,
    v11,
    v12);
  vostok::resources::query_result_for_cook::finish_query_impl(v9, result_success, assert_on_fail_true, error_type_unset);
}
