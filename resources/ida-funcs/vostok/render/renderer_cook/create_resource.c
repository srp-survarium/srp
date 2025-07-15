void __thiscall vostok::render::renderer_cook::create_resource(
        vostok::render::renderer_cook *this,
        vostok::resources::resource_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base> *in_out_query,
        vostok::const_buffer raw_file_data,
        vostok::mutable_buffer in_out_unmanaged_resource_buffer)
{
  vostok::render::resource_manager *v4; // ecx
  vostok::resources::resource_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base> *v5; // ebx
  vostok::resources::unmanaged_resource *m_object; // esi
  survarium::pure_game_effect_emitter_base *v7; // ecx
  survarium::pure_game_effect_emitter_base *m_data; // esi
  vostok::resources::query_result_for_cook *v9; // ecx
  vostok::resources::query_result_for_cook *v10; // ecx
  vostok::resources::resource_ptr<survarium::pure_game_effect_emitter_base,vostok::resources::unmanaged_intrusive_base> v11; // [esp-Ch] [ebp-18h] BYREF
  const vostok::resources::memory_type *v12; // [esp-8h] [ebp-14h]
  unsigned int v13; // [esp-4h] [ebp-10h]

  if ( `vostok::render::renderer_cook::create_resource'::`2'::first_call )
  {
    vostok::render::system_renderer::system_renderer(
      (vostok::render::system_renderer *)this,
      (vostok::render::system_renderer *)&s_system_renderer_buffer);
    vostok::render::resource_manager::initialize_texture_pools(v4);
  }
  v5 = in_out_query;
  m_object = in_out_query[66].m_object;
  `vostok::render::renderer_cook::create_resource'::`2'::first_call = 0;
  vostok::variant<32>::try_get<vostok::render::engine::world *>(
    (vostok::variant<32> *)this,
    (int)m_object,
    (vostok::render::engine::world **)&in_out_query);
  vostok::render::engine::world::reset_renderer((vostok::render::engine::world *)in_out_query, 1);
  m_data = (survarium::pure_game_effect_emitter_base *)in_out_unmanaged_resource_buffer.m_data;
  if ( in_out_unmanaged_resource_buffer.m_data )
  {
    vostok::resources::unmanaged_resource::unmanaged_resource(
      v7,
      in_out_unmanaged_resource_buffer.m_data,
      fs_iterator_class);
    m_data->__vftable = (survarium::pure_game_effect_emitter_base_vtbl *)&vostok::render::renderer_cook::renderer_resource::`vftable';
  }
  else
  {
    m_data = 0;
  }
  v13 = 264;
  v12 = &vostok::resources::nocache_memory;
  v11.m_object = v7;
  vostok::resources::resource_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base>::resource_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base>(
    &v11,
    m_data);
  vostok::resources::query_result_for_cook::set_unmanaged_resource(
    v9,
    v5,
    (vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>)v11.m_object,
    v12,
    v13);
  vostok::resources::query_result_for_cook::finish_query_impl(
    v10,
    (vostok::memory::single_size_buffer_allocator<76,vostok::threading::single_threading_policy> *)v5,
    result_out_of_memory,
    assert_on_fail_true,
    result_fail);
}
