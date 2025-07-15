void __thiscall vostok::particle::particle_system_cook::create_resource(
        vostok::particle::particle_system_cook *this,
        vostok::resources::resource_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base> *in_out_query,
        vostok::mutable_buffer in_out_unmanaged_resource_buffer)
{
  vostok::particle::particle_emitter *v3; // eax
  vostok::particle::particle_emitter *v4; // edi
  survarium::pure_game_effect_emitter_base *v5; // ecx
  vostok::resources::query_result_for_cook *v6; // ecx
  vostok::resources::query_result_for_cook *v7; // ecx
  vostok::resources::resource_ptr<survarium::pure_game_effect_emitter_base,vostok::resources::unmanaged_intrusive_base> v8; // [esp-Ch] [ebp-1Ch] BYREF
  const vostok::resources::memory_type *v9; // [esp-8h] [ebp-18h]
  unsigned int m_size; // [esp-4h] [ebp-14h]
  vostok::mutable_buffer v11; // [esp+8h] [ebp-8h] BYREF

  if ( in_out_unmanaged_resource_buffer.m_data )
  {
    vostok::particle::particle_system::particle_system(
      (vostok::particle::particle_system *)this,
      in_out_unmanaged_resource_buffer.m_data);
    v4 = v3;
  }
  else
  {
    v4 = 0;
  }
  v11.m_data = in_out_unmanaged_resource_buffer.m_data + 280;
  v11.m_size = in_out_unmanaged_resource_buffer.m_size - 280;
  vostok::particle::particle_system::load_binary((vostok::particle::particle_system *)this, v4, &v11);
  m_size = in_out_unmanaged_resource_buffer.m_size;
  v9 = &vostok::resources::unmanaged_memory;
  v8.m_object = v5;
  vostok::resources::resource_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base>::resource_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base>(
    &v8,
    (survarium::pure_game_effect_emitter_base *)v4);
  vostok::resources::query_result_for_cook::set_unmanaged_resource(
    v6,
    in_out_query,
    (vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>)v8.m_object,
    v9,
    m_size);
  vostok::resources::query_result_for_cook::finish_query_impl(
    v7,
    (vostok::memory::single_size_buffer_allocator<76,vostok::threading::single_threading_policy> *)in_out_query,
    result_out_of_memory,
    assert_on_fail_true,
    result_fail);
}
